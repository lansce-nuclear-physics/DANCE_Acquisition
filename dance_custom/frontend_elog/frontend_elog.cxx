#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <sys/types.h>
#include <sys/wait.h>

#include "midas.h"
#include "strlcpy.h"
#include "frontend_elog.h"
#include "vme_modules.h"
#include "experim.h"
#include "eventid.h"

using namespace std;
//using namespace DigitizerMIDAS;

// ------------------------------------------//
// Function Protoypes
// ------------------------------------------//

extern "C" {
  INT frontend_init();
  INT frontend_exit();
  INT begin_of_run( INT run_number, char *error );
  INT end_of_run( INT run_number, char *error );
  INT pause_run(INT run_number, char *error);
  INT resume_run(INT run_number, char *error);
  INT frontend_loop();
  INT poll_event( INT aSource, INT aCount, BOOL aTest)  ;
  INT interrupt_configure( INT cmd, INT source, PTYPE adr )  ;
  INT read_elog_event( char* anEvent, INT anOffset );
}

// -----------------------------------------//
// Midas Global Variables
// -----------------------------------------//

// The frontend name (client name) as seen by other MIDAS clients
const char *frontend_name = "frontend_elog";

// The frontend file name, don't change it
const char *frontend_file_name = __FILE__;

// frontend_loop is called periodically if this variable is TRUE
BOOL frontend_call_loop = FALSE;

//a frontend status page is displayed with this frequency in ms
INT display_period = 1*3000;

//maximum event size produced by this frontend
INT max_event_size = MAX_EVENT_SIZE;

// maximum event size for fragmented events (EQ_FRAGMENTED) 
INT max_event_size_frag = MAX_EVENT_SIZE;

//buffer size to hold events
INT event_buffer_size = 2 * MAX_EVENT_SIZE;

//----------------------------------------------------------------//
// Global ODB Parameters
//----------------------------------------------------------------//

// stopped updating here...

ELOG_PARAM elog_param;
RUNINFO runinfo;
extern HNDLE hDB;
EXP_PARAM exp_param; HNDLE runparamKey;
char exp_name[32];
char host_name[256];


// begin Equipment definition

EQUIPMENT equipment[] = {
  {"DANCE_Elog",                        // equipment name
   { ELOG_EVENTID,                     // event ID
     0,                             // trigger mask
     "",                         // event buffer 
     EQ_PERIODIC,                        // equipment type
     1,                                // event source
     "MIDAS",                          // data format
     TRUE,                             // enabled
     RO_BOR | RO_STOPPED | RO_EOR,     // Enable Readout at these times
     10000,                             // Readout Period (ms)
     0,                             // Event limit (force end_of_run)
     0,                             // number of subevents
     0,                               // Log history interval (s) (note: 0 disables)
     "",                               // Reserved
     "",                               // Reserved
     "",                               // Reserved
   },
   read_elog_event,                  // readout routine
  },
  {""}
};

// Begin function declarations

extern "C"
INT frontend_init() {  // I think I have updated this for the uac
  HNDLE hKey;
  int status;
  ELOG_PARAM_STR ( elog_param_str );
  RUNINFO_STR ( runinfo_str );
  EXP_PARAM_STR ( exp_param_str );

  // Create "Elog Parameters" if necessary //
  status = db_create_record( hDB, 0, "/Elog/Elog Parameters/", strcomb(elog_param_str) );
  if ( status != DB_SUCCESS && status != DB_OPEN_RECORD ) {
    cm_msg( MERROR, "frontend_init"," Failed to create record \"/Elog/Elog Parameters\": %i, EXITING ",status );
    sleep(2);
    return 0;
  }
  db_find_key( hDB, 0, "/Elog/Elog Parameters/", &hKey );
  if (db_open_record( hDB, hKey, &elog_param, sizeof(elog_param), MODE_READ, 0, 0) != DB_SUCCESS) {
    cm_msg( MERROR, "frontend_init", "cannot open \"/Elog/Elog Parameters\" tree in ODB");
    return 0;
  }
  
  // Create "Runinfo" if necessary //
  status = db_create_record( hDB, 0, "/Runinfo/",strcomb(runinfo_str) );
  if ( status != DB_SUCCESS && status != DB_OPEN_RECORD ) {
    cm_msg( MERROR, "frontend_init", " Failed to create record \"/Runinfo\": %i, EXITING ",status );
    sleep(2);
    return 0;
  }
  db_find_key( hDB, 0, "/Runinfo/", &hKey );
  if (db_open_record( hDB, hKey, &runinfo, sizeof(runinfo),MODE_READ, 0, 0) != DB_SUCCESS) {
    cm_msg( MERROR, "frontend_init","cannot open \"/Runinfo\" tree in ODB");
    return 0;
  }
  
  // Create "Run Parameters" if necessary //
  status = db_create_record( hDB, 0, "/Experiment/Run Parameters/", strcomb(exp_param_str) );
  if ( status != DB_SUCCESS && status != DB_OPEN_RECORD ) {
    cm_msg( MERROR, "frontend_init"," Failed to create record \"/Experiment/Run Parameters\": %i, EXITING ",status );
    return 0;
  }
  db_find_key( hDB, 0, "/Experiment/Run Parameters", &runparamKey);
  if (status = db_open_record( hDB, runparamKey,&exp_param, sizeof(exp_param), MODE_READ, 0, 0) != DB_SUCCESS) {
    char errMsg[128];
    cm_get_error( status, errMsg);
    cm_msg( MERROR, "uac_frontend_init","cannot open \"/Experiment/Run Parameters\" tree in ODB: %s",errMsg);
    return 0;
  }

  // Get host_name from the environment if MIDAS_SERVER_HOST is defined, else take the local host
  status =  cm_get_environment( host_name, sizeof( host_name ), exp_name, sizeof( exp_name ) );
  if ( status != DB_SUCCESS ) {
    cm_msg( MERROR, "frontend_init","cm_get_environment failed to get host, experiment: %d", status );
    sprintf (host_name, "Host Name not Found");
  }
  else if ( strcmp( host_name, "" ) == 0 ) { // If this is a local experiment, no MIDAS_SERVER_HOST defined
    if ( getenv( "HOSTNAME" ) ) {
      strlcpy( host_name, getenv( "HOSTNAME" ), sizeof(host_name) );
    }
  }

  // Get the experiment name from midas
  // we should have just gotten it from the environment, but 
  // that is taken from MIDAS_EXPT_NAME, which may not be as reliable (?)
  status = cm_get_experiment_name( exp_name, sizeof( exp_name ) );
  if ( status != DB_SUCCESS ) {
    cm_msg( MERROR, "frontend_init","cm_get_environment failed to get host, experiment: %d", status );
    sprintf (exp_name, "Experiment Name not Found (This is probably bad...)");
  }

  return SUCCESS;
}


extern "C"
INT frontend_exit() {
  cm_disconnect_experiment();
  return SUCCESS;
}


extern "C"
INT begin_of_run( INT run_number, char *error ) {  // I think this is updated for uac
  
  cm_msg( MINFO, "begin_of_run", "Enter begin_run_entry");
  elog_param.start_message_id=-1;
  
  string attrib_flag="-a";
  
  stringstream elog_cmd_str;
  elog_cmd_str.str();
  
  elog_cmd_str<<"elog";
  elog_cmd_str<<" -h " << elog_param.hostname;
  elog_cmd_str<<" -p " << elog_param.port;
  elog_cmd_str<<" -l \"" << elog_param.logbook_name <<"\"";
  
  elog_cmd_str<<" -a " <<"\"Run Number\"=" << setw(6) << setfill('0') << runinfo.run_number;
  elog_cmd_str<<" -a " <<"Author=DAQ";

  // dance elog doesn't have experiment field. Instead, we flag the DAQ-type as the experiment name
  elog_cmd_str<<" -a " <<"\"DAQ-type=" << exp_name << "\"";
 
  if ( strlen( elog_param.sample ) != 0 ) {
    elog_cmd_str<<" -a "  <<"\"Sample=" << elog_param.sample << "\"";
  }

  if ( strlen( elog_param.filter ) != 0 ) {
    elog_cmd_str<<" -a "  <<"\"Filter=" << elog_param.filter << "\"";
  }

  stringstream message;
  message << "\nDANCE Elog Begin of Run Entry\n";
  message << "Comment: " <<  exp_param.comment << "\n";
  message << "Run Number: " << runinfo.run_number << "\n";
  message << "Sample: " << elog_param.sample << "\n";
  message << "Filter: " << elog_param.filter << "\n";
  message << "Start Time: " << runinfo.start_time << "\n";
  //  message << "Modules: " << exp_param.Digitizer.modules.number << "\n";
  //  message << "Instruments: " << exp_param.Digitizer.instruments.number << "\n";
  //  message << "Max Channels Per Instrument: " << exp_param.Digitizer.instruments.maxChannelsPerInstrument << "\n";

  //Add the message to the elog entry
  elog_cmd_str <<" \"" << message.str() <<" \" -u " <<  elog_param.elog_user <<" "<<  elog_param.elog_passwd;
  // cm_msg(MERROR,"begin_of_run","Message: %s\n  END",elog_cmd_str.str().c_str());      // probably want to change this to midas

  pid_t child_pid;
  int status;
  int fd[2];
  if ( pipe(fd) < 0 ) {
    cm_msg(MERROR,"begin_of_run","pipe error");      // probably want to change this to midas
  }
  child_pid=fork();
  if (child_pid == 0) { // This is the child
    // cm_msg(MERROR, "begin_of_run", "Made it to child");
    close( fd[0] ); //close read end of pipe
    if ( fd[1] != STDOUT_FILENO ) {
      if ( dup2( fd[1], STDOUT_FILENO ) != STDOUT_FILENO ) {
	cm_msg(MERROR, "begin_of_run", "dup2 error to stdout");
      } 
      close( fd[1] );
    }
    // setuid( (uid_t)546 );
    system(elog_cmd_str.str().c_str());
    
    cm_msg(MERROR, "begin_of_run", "I am the child--but should never get here");
    _exit(127);
  }
  else {         // this is the parent 
    // cm_msg(MERROR,"begin_of_run","Made it to the parent");
    close( fd[1] );
    
    const size_t return_size=80;
    char return_text[return_size];
    char *last_message_ID;
    int ID;
    int max_wait=5;
    int i=0;
    pid_t finished_pid;
    while ( (finished_pid = waitpid(child_pid, &status, WNOHANG ) ) == 0 && i < max_wait ) {
      // cm_msg(MINFO,"begin_of_run","finished_PID=%d    i=%d", finished_pid, i);
      sleep(1);
      i++;
    }
    if (finished_pid == 0) {
      kill(child_pid,SIGTERM);  // Do a nice kill SIGKILL also possible
      cm_msg(MERROR, "begin_of_run", "LENZ elog call did not return after %d seconds--KILLED", i );
      ID=-1;
    }
    else if (finished_pid == child_pid) {
      read( fd[0], return_text, return_size);
      // cm_msg(MINFO, "begin_og_run", "From fd[0]: %s", return_text);
      if ( (last_message_ID=strrchr( return_text, '=' ) ) != NULL ) {
	last_message_ID++;
        ID = atoi( last_message_ID );
        cm_msg(MINFO, "begin_of_run", "MESSAGE ID = %d", ID );
      }
      else {
	cm_msg(MINFO, "begin_of_run", "MESSAGE ID not found" );
        ID=-1;
      }
    }
    else if (finished_pid < 0) {//wait pid failed, but not timed out
      cm_msg(MERROR,"begin_of_run", "Not able to get a return from elog call");
      ID=-1;
    }
    else {//This is wierd--we waited for the the wrong process--not sure how possible
      cm_msg(MERROR,"begin_of_run", "Waited for wrong process");
      ID=-1;
    }
    
    close( fd[0] ); 
    
    elog_param.start_message_id=ID;
  }
  
  return SUCCESS;
}

/*
  size_t enabledInstr = 0;
  size_t enabledChans = 0;
  for ( int i=0; i<exp_param.Digitizer.instruments.number; ++i ) 
  {
  if (! digParam( i).enabled) continue;

  ++enabledInstr;

  for ( int c=1; c<=digParam( i).number_channels; ++c ) 
  {
  if (!digParam( i, c).enabled) continue;

  ++enabledChans;
  }
  }
  message << "Enabled Instruments: " << enabledInstr << '\n';
  message << "Enabled Channels: " << enabledChans << '\n';
  for ( int i=0; i<exp_param.Digitizer.instruments.number; ++i ) 
  {
  message << "  instrument " << setw(2) << i
  << " s/n " << digParam( i).serial_number;
  if ( ! digParam( i).enabled ) 
  {
  message << endl;
  continue;
  }
  message << " channels";

  for (int c=1; c<=digParam( i).number_channels; ++c) 
  {
  if (digParam( i, c).enabled)
  message << setw(3) << c;
  else
  message << setw(3) << "";
  }
  message << "     ";
  message << '\n';
  }

  time_t gittime = exp_param.gittime;
  string gittimeStr (asctime(gmtime( &gittime)));
  gittimeStr.erase( gittimeStr.length()-1);
  message << '\n';
  message << "githash: " << exp_param.githash << '\n' 
  << "gittime: " << exp_param.gittime
  << " (" << gittimeStr << " UTC)\n";

*/
//}
  

  
extern "C"
INT end_of_run( INT run_number, char *error ) {  // Updated for uac--but still Logger issue

  int status,size;
  time_t now;
  int ID;

  cm_msg( MINFO, "end_of_run", "Enter end_run_entry");
  elog_param.start_message_id=-1;
  
  string attrib_flag="-a";
  
  stringstream elog_cmd_str;
  elog_cmd_str.str();
  
  elog_cmd_str<<"elog";
  elog_cmd_str<<" -h " << elog_param.hostname;
  elog_cmd_str<<" -p " << elog_param.port;
  elog_cmd_str<<" -l \"" << elog_param.logbook_name<<"\"";
  
  elog_cmd_str<<" -a " <<"\"Run Number\"=" << setw(6) << setfill('0') << runinfo.run_number;
  elog_cmd_str<<" -a " <<"Author=DAQ";

  // dance elog doesn't have experiment field. Instead, we flag the DAQ-type as the experiment name
  elog_cmd_str<<" -a " <<" \"DAQ-type=" << exp_name<<"\"";
 
  if ( strlen( elog_param.sample ) != 0 ) {
    elog_cmd_str<<" -a "  <<" \"Sample=" << elog_param.sample << "\"";
  }

  if ( strlen( elog_param.filter ) != 0 ) {
    elog_cmd_str<<" -a "  <<" \"Filter=" << elog_param.filter << "\"";
  }


  double mevents;
  bool logger_status = true;
  size = sizeof( mevents );
  // What if there is no Logger?? Should this be done?
  if ( (status=db_get_value( hDB, 0, "/Logger/Channels/0/Statistics/Events written",&mevents, &size, TID_DOUBLE, 0 ) ) != DB_SUCCESS) {
    cm_msg( MINFO, "end_of_run","Cannot get \"/Logger/Channels/0/Statistics/Events written\n Perhaps there is no Logger?\": %d", status );
    logger_status = false;
  }
  
  double bytes;
  size= sizeof( bytes );
  if ( (status=db_get_value( hDB, 0, "/Logger/Channels/0/Statistics/Bytes written",&bytes, &size, TID_DOUBLE, 0 ) ) != DB_SUCCESS) {
    cm_msg( MERROR, "end_of_run","Cannot get \"/Logger/Channels/0/Statistics/Bytes written\": %d", status );
    logger_status = false;
  }
  double Mibytes = bytes / ( 1024 * 1024 ) ;
  
  // Want to put scalers here...
  DWORD scaler[N_SCLR];  //we get n_sclr from vme_modules.h--n_sclr is the number of _modules_
  bool scaler_status = true;
  size = sizeof( scaler );
  if ( (status=db_get_value( hDB, 0, "/Equipment/DANCE_Scalers/Variables/SCLR",&scaler, &size, TID_DWORD, 0 ) ) != DB_SUCCESS ) {
    cm_msg( MERROR, "auto_elog_end_run_entry","Cannot get \"/Equipment/DANCE_Scalers/Variables/SCLR\": %d", status );
    // so there is a problem, but we shouldn't crash.
    cm_msg( MERROR, "end_of_run", "n_sclr=%d", n_sclr );
    // return 0;
    scaler_status = false;
  }

  stringstream message;
  message << "\nAuto Elog End of Run Entry\n";
  message << "Comment: " << exp_param.comment << "\n";
  message << "Run Number:        " << runinfo.run_number << "\n";
  message << "Start Time:        " << runinfo.start_time << "\n";
  message << "Stop Time:         " << runinfo.stop_time << "\n";
  DWORD elapsed_time;
  time( &now );
  elapsed_time = now - runinfo.start_time_binary;
  message << "Elapsed Time:      " << elapsed_time << "    (seconds)\n";
  if ( logger_status ) {
    message << "Events Written:    " << mevents << "         (MIDAS Events)\n";
    message << "MiBytes Written:   " << Mibytes << "\n";
    message << "Average Event Rate " << double(mevents)/elapsed_time << "     (s^-1)\n";
  }
  if ( scaler_status ) {
    message << "Raw T0:            " << scaler[0] << "\n";
    message << "Proton Scaler:     " << scaler[5] << "\n";
    message << "Total Charge:      " << "\n";
    message << "Fast Background:   " << scaler[6] << "      (First 200 us)\n";
    message << "Total Background:  " << scaler[11] << "\n";
    message << "Thermal 6Li(n,a)t: " << scaler[7] << "      (Silicon counter)\n";
    message << "Thermal 3He:       " << scaler[8] << "      (3He counter)\n";
    message << "Thermal Fission:   " << scaler[9] << "      (U fission counter)\n";
  }
  
  //Add the message to the elog entry
  elog_cmd_str <<" \" " << message.str() <<" \" ";
  elog_cmd_str<<" -u " <<  elog_param.elog_user <<" "<< elog_param.elog_passwd;
  // cm_msg(MERROR,"end_of_run","Message: %s\n  END",elog_cmd_str.str().c_str());      // probably want to change this to midas

  pid_t child_pid;
  int fd[2];
  if ( pipe(fd) < 0 ) {
    cm_msg(MERROR,"end_of_run","pipe error");      // probably want to change this to midas
  }
  child_pid=fork();
  if (child_pid == 0) { // This is the child
    close( fd[0] ); //close read end of pipe
    if ( fd[1] != STDOUT_FILENO ) {
      if ( dup2( fd[1], STDOUT_FILENO ) != STDOUT_FILENO ) {
        cm_msg(MERROR, "end_of_run", "dup2 error to stdout");
      }
      close( fd[1] );
    }
    // setuid( (uid_t)546 );
    system(elog_cmd_str.str().c_str());
    
    cm_msg(MERROR, "end_of_run", "I am the child--but should never get here");
    _exit(127);
  }
  else {          // this is the parent 
    
    close( fd[1] );
    
    const size_t return_size=80;
    char return_text[return_size];
    char *last_message_ID;
    int max_wait=5;
    int i=0;
    pid_t finished_pid;
    while ( (finished_pid = waitpid(child_pid, &status, WNOHANG ) ) == 0 && i < max_wait ) {
      cm_msg(MINFO,"end_of_run","finished_PID=%d    i=%d", finished_pid, i);
      sleep(1);
      i++;
    }
    if (finished_pid == 0) {
      kill(child_pid,SIGTERM);  // Do a nice kill SIGKILL also possible
      cm_msg(MERROR, "end_of_run", "Auto elog call did not return after %d seconds--KILLED", i );
      ID=-1;
    }
    else if (finished_pid == child_pid) {
      read( fd[0], return_text, return_size);
      if ( (last_message_ID=strrchr( return_text, '=' ) ) != NULL ) {
	last_message_ID++;
	ID = atoi( last_message_ID );
	cm_msg(MINFO, "end_of_run", "MESSAGE ID = %d", ID );
      }
      else {
	cm_msg(MINFO, "end_of_run", "MESSAGE ID not found" );
	ID=-1;
      }
    }
    else if (finished_pid < 0) {//wait pid failed, but not timed out
      cm_msg(MERROR,"end_of_run", "Not able to get a return from elog call");
      ID=-1;
    }
    else { //This is wierd--we waited for the the wrong process--not sure how possible
      cm_msg(MERROR,"end_of_run", "Waited for wrong process");
      ID=-1;
    }
    
    close( fd[0] ); 
    
    ID=0;  // set ID to default value after run
    
    elog_param.start_message_id=ID;
  }
}


INT pause_run( INT run_number, char *error )  
{
  return SUCCESS;
}


INT resume_run( INT run_number, char *error )  
{
  return SUCCESS;
}


// // Is this really needed?  I will try to remove it...
INT frontend_loop()  
{
  return SUCCESS;
}


// Is this really needed?  I will try to remove it...
INT poll_event( INT aSource, INT aCount, BOOL aTest)  
{
  // we never want to get a LAM from auto_elog
  ss_sleep(700);
  return 0;
}


// Is this really needed?  I will try to remove it...
INT interrupt_configure( INT cmd, INT source, PTYPE adr )  
{
  return SUCCESS;
}

INT read_elog_event( char *anEvent, INT anOffset )
{
  return 0;  // We should return the number of bytes read
}
