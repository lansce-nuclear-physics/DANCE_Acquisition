#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <unistd.h> //sleep,fork,close,etc

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>

#include "midas.h"
#include "strlcpy.h"
#include "frontend_hv.h"
#include "experim.h"
#include "eventid.h"


#ifndef MAX_EVENT_SIZE
#define MAX_EVENT_SIZE 134217728
#endif

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
  INT read_mhv4_event( char* anEvent, INT anOffset );
}

// -----------------------------------------//
// Midas Global Variables
// -----------------------------------------//

// The frontend name (client name) as seen by other MIDAS clients
const char *frontend_name = "frontend_hv";

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

MHV4_PARAM mhv4_param;

RUNINFO runinfo;
extern HNDLE hDB;
EXP_PARAM exp_param; HNDLE runparamKey;
char exp_name[32];
char host_name[256];

struct timeval timevalue;

// begin Equipment definition

EQUIPMENT equipment[] = {

  {"LENZ_MHV4",                        // equipment name
   { HV_EVENTID, 0,                           // event ID, trigger mask
     "SYSTEM",                         // event buffer 
     EQ_PERIODIC,                        // equipment type
     0,                                // event source
     "MIDAS",                          // data format
     TRUE,                             // enabled
     RO_RUNNING |
     RO_TRANSITIONS,               // read when running and on transitions
     5000,                             // Readout Period (ms)
     0,                             // Event limit (force end_of_run)
     0,                             // number of subevents
     0,                               // Log history interval (s) (note: 0 disables)
     "", "", "",                     // Reserved
   },
   read_mhv4_event,                  // readout routine
  },
  {""}
};

// Begin function declarations

extern "C"
INT frontend_init() {  // I think I have updated this for the uac
  HNDLE hKey;
  int status;
  MHV4_PARAM_STR ( mhv4_param_str );
  RUNINFO_STR ( runinfo_str );
  EXP_PARAM_STR ( exp_param_str );

  // Create "MHV4 Parameters" if necessary //
  status = db_create_record( hDB, 0, "/MHV4/MHV4 Parameters/",
                             strcomb(mhv4_param_str) );
  if ( status != DB_SUCCESS && status != DB_OPEN_RECORD ) 
    {
      cm_msg( MERROR, "frontend_init",
	      " Failed to create record \"/MHV4/MHV4 Parameters\": %i, EXITING ",
	      status );
      sleep(2);
      return 0;
    }
  db_find_key( hDB, 0, "/MHV4/MHV4 Parameters/", &hKey );
  if (db_open_record( hDB, hKey, &mhv4_param, sizeof(mhv4_param),
                      MODE_READ, 0, 0) 
      != DB_SUCCESS) 
    {
      cm_msg( MERROR, "frontend_init",
	      "cannot open \"/MHV4/MHV4 Parameters\" tree in ODB");
      return 0;
    }

  status = db_close_record(hDB,hKey);
  if ( status != DB_SUCCESS ) {
    cm_msg( MERROR, "frontend_init"," Failed to close record \"/MHV4/MHV4 Parameters\": %i, EXITING ", status );
    sleep(2);
    return 0;
  }
  
  // Create "Runinfo" if necessary //
  status = db_create_record( hDB, 0, "/Runinfo/",
                             strcomb(runinfo_str) );
  if ( status != DB_SUCCESS && status != DB_OPEN_RECORD ) 
    {
      cm_msg( MERROR, "frontend_init",
	      " Failed to create record \"/Runinfo\": %i, EXITING ",
	      status );
      sleep(2);
      return 0;
    }
  db_find_key( hDB, 0, "/Runinfo/", &hKey );
  if (db_open_record( hDB, hKey, &runinfo, sizeof(runinfo),
                      MODE_READ, 0, 0) 
      != DB_SUCCESS) 
    {
      cm_msg( MERROR, "frontend_init",
	      "cannot open \"/Runinfo\" tree in ODB");
      return 0;
    }
  
  // Create "Run Parameters" if necessary //
  status = db_create_record( hDB, 0, "/Experiment/Run Parameters/",
                             strcomb(exp_param_str) );
  if ( status != DB_SUCCESS && status != DB_OPEN_RECORD ) {
    cm_msg( MERROR, "frontend_init",
            " Failed to create record \"/Experiment/Run Parameters\": %i, EXITING ",
            status );
    return 0;
  }
  db_find_key( hDB, 0, "/Experiment/Run Parameters", &runparamKey);
  if (status = db_open_record( hDB, runparamKey,
                               &exp_param, sizeof(exp_param),
                               MODE_READ, 0, 0),
      status != DB_SUCCESS) {
    char errMsg[128];
    cm_get_error( status, errMsg);
    cm_msg( MERROR, "uac_frontend_init",
            "cannot open \"/Experiment/Run Parameters\" tree in ODB: %s",
            errMsg);
    return 0;
  }

  // Get host_name from the environment if MIDAS_SERVER_HOST is defined, else take the local host
  status =  cm_get_environment( host_name, sizeof( host_name ), exp_name, sizeof( exp_name ) );
  if ( status != DB_SUCCESS )
    {
      cm_msg( MERROR, "frontend_init",
	      "cm_get_environment failed to get host, experiment: %d", status );
      sprintf (host_name, "Host Name not Found");
    }
  else if ( strcmp( host_name, "" ) == 0 ) // If this is a local experiment, no MIDAS_SERVER_HOST defined
    {
      if ( getenv( "HOSTNAME" ) )
	strlcpy( host_name, getenv( "HOSTNAME" ), sizeof(host_name) );
    }

  // Get the experiment name from midas
  // we should have just gotten it from the environment, but 
  // that is taken from MIDAS_EXPT_NAME, which may not be as reliable (?)
  status = cm_get_experiment_name( exp_name, sizeof( exp_name ) );
  if ( status != DB_SUCCESS )
    {
      cm_msg( MERROR, "frontend_init",
	      "cm_get_environment failed to get host, experiment: %d", status );
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
  return SUCCESS;
}


  
extern "C"
INT end_of_run( INT run_number, char *error ) {  // Updated for uac--but still Logger issue
  
  return SUCCESS;
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
  //cm_msg( MINFO, "poll_event", "aSource = %d, aCount = %d, aTest = %d\n",
  //                              aSource,      aCount,      aTest );
  // printf( "aSource = %d, aCount = %d, aTest = %d\n",
  //                              aSource,      aCount,      aTest );
  return 0;
}


// Is this really needed?  I will try to remove it...
INT interrupt_configure( INT cmd, INT source, PTYPE adr )  
{
  return SUCCESS;
}

INT read_mhv4_event( char *anEvent, INT anOffset )
{

  HNDLE hKey;
  int status;
  
  //First open the ODB in read mode to obtain the directories and names of status files
  
  db_find_key( hDB, 0, "/MHV4/MHV4 Parameters/", &hKey );
  if (db_open_record( hDB, hKey, &mhv4_param, sizeof(mhv4_param),
                      MODE_READ, 0, 0) != DB_SUCCESS) {
    cm_msg( MERROR, "frontend_init",
	    "cannot open \"/MHV4/MHV4 Parameters\" tree in ODB");
    return 0;
  }
  
  status = db_close_record(hDB,hKey);
  if ( status != DB_SUCCESS ) {
    cm_msg( MERROR, "frontend_init"," Failed to close record \"/MHV4/MHV4 Parameters\": %i, EXITING ", status );
    sleep(2);
    return 0;
  }

  //Files
  ifstream fdata0;
  ifstream fdata1;
  ifstream vconfig;
  
  //Locations of files
  string directory_0 = mhv4_param.MHV4_0.statusfiledirectory;
  string name_0 = mhv4_param.MHV4_0.statusfilename;
  stringstream filenamestr_0;
  filenamestr_0.str();
  filenamestr_0<<directory_0<<"/"<<name_0;
  // const char *filename_0 = filenamestr_0.str().c_str(); 
  
  string directory_1 = mhv4_param.MHV4_1.statusfiledirectory;
  string name_1 = mhv4_param.MHV4_1.statusfilename;
  stringstream filenamestr_1;
  filenamestr_1.str();
  filenamestr_1<<directory_1<<"/"<<name_1;
  //  const char *filename_1 = filenamestr_1.str().c_str(); 

  db_find_key( hDB, 0, "/MHV4/MHV4 Parameters/", &hKey );
  if (db_open_record( hDB, hKey, &mhv4_param, sizeof(mhv4_param),
		      MODE_WRITE, 0, 0) != DB_SUCCESS) {
    cm_msg( MERROR, "read_mhv4_event",
	    "cannot open \"/MHV4/MHV4 Parameters\" tree in ODB");
    return 0;
  }
  
  //Stuff from voltage config
  int ndetectors=0;
  int nmodules=0;
  int refresh_period=0;
  bool module0=false;
  bool module1=false;

  //Read in the voltage config file
  vconfig.open("/home/daq/NAS_DAQ/VoltageConfig.txt");
  
  if(vconfig.is_open()) {
    
    vconfig>>ndetectors>>nmodules>>refresh_period;
    // cout<<ndetectors<<"  Detectors on "<<nmodules<<endl;
    
    if(ndetectors==0) {
      //No modules?  Why is this client even running
    }
    if(ndetectors>2)  {
      //The current ODB supports up to 2 modules
    }
    
    const int arrsize = ndetectors;
    int modulenumber[arrsize];
    string detname[arrsize];
    int channelnumber[arrsize];
    
    for(int a=0; a<arrsize; a++) {
      vconfig>>modulenumber[a]>>detname[a]>>channelnumber[a];

      if(modulenumber[a]==0) {
	module0=true;
	if(channelnumber[a]==0) {
	  memcpy(mhv4_param.MHV4_0.Channel_0.detector, detname[a].c_str(),detname[a].size()+1);
	}
	if(channelnumber[a]==1) {
	  memcpy(mhv4_param.MHV4_0.Channel_1.detector, detname[a].c_str(),detname[a].size()+1);
	}
	if(channelnumber[a]==2) {
	  memcpy(mhv4_param.MHV4_0.Channel_2.detector, detname[a].c_str(),detname[a].size()+1);
	}
	if(channelnumber[a]==3) {
	  memcpy(mhv4_param.MHV4_0.Channel_3.detector, detname[a].c_str(),detname[a].size()+1);
	}
      }
      if(modulenumber[a]==1) {
	module1=true;
if(channelnumber[a]==0) {
	  memcpy(mhv4_param.MHV4_1.Channel_0.detector, detname[a].c_str(),detname[a].size()+1);
	}
	if(channelnumber[a]==1) {
	  memcpy(mhv4_param.MHV4_1.Channel_1.detector, detname[a].c_str(),detname[a].size()+1);
	}
	if(channelnumber[a]==2) {
	  memcpy(mhv4_param.MHV4_1.Channel_2.detector, detname[a].c_str(),detname[a].size()+1);
	}
	if(channelnumber[a]==3) {
	  memcpy(mhv4_param.MHV4_1.Channel_3.detector, detname[a].c_str(),detname[a].size()+1);
	}
      } 
    } //End loop over reading vconfig
    
    if(module0) {
      
      fdata0.open(filenamestr_0.str().c_str());
      
      if(fdata0.is_open()) {   
	fdata0>>mhv4_param.MHV4_0.Channel_0.channelon;
	fdata0>>mhv4_param.MHV4_0.Channel_0.channelpolarity;
	fdata0>>mhv4_param.MHV4_0.Channel_0.channelvoltage;
	fdata0>>mhv4_param.MHV4_0.Channel_0.channelcurrent;
	fdata0>>mhv4_param.MHV4_0.Channel_0.channelvoltagelimit;
	fdata0>>mhv4_param.MHV4_0.Channel_0.channelcurrentlimit;
	fdata0>>mhv4_param.MHV4_0.Channel_1.channelon;
	fdata0>>mhv4_param.MHV4_0.Channel_1.channelpolarity;
	fdata0>>mhv4_param.MHV4_0.Channel_1.channelvoltage;
	fdata0>>mhv4_param.MHV4_0.Channel_1.channelcurrent;
	fdata0>>mhv4_param.MHV4_0.Channel_1.channelvoltagelimit;
	fdata0>>mhv4_param.MHV4_0.Channel_1.channelcurrentlimit;
	fdata0>>mhv4_param.MHV4_0.Channel_2.channelon;
	fdata0>>mhv4_param.MHV4_0.Channel_2.channelpolarity;
	fdata0>>mhv4_param.MHV4_0.Channel_2.channelvoltage;
	fdata0>>mhv4_param.MHV4_0.Channel_2.channelcurrent;
	fdata0>>mhv4_param.MHV4_0.Channel_2.channelvoltagelimit;
	fdata0>>mhv4_param.MHV4_0.Channel_2.channelcurrentlimit;
	fdata0>>mhv4_param.MHV4_0.Channel_3.channelon;
	fdata0>>mhv4_param.MHV4_0.Channel_3.channelpolarity;
	fdata0>>mhv4_param.MHV4_0.Channel_3.channelvoltage;
	fdata0>>mhv4_param.MHV4_0.Channel_3.channelcurrent;
	fdata0>>mhv4_param.MHV4_0.Channel_3.channelvoltagelimit;
	fdata0>>mhv4_param.MHV4_0.Channel_3.channelcurrentlimit;
	
	mhv4_param.MHV4_0.monitoringactive=1;
	fdata0.close();
      }
      else {
	cm_msg( MERROR, "read_mhv4_event"," Failed to open status file 0",0 );
      }
    }
    if(module1) {

      fdata1.open(filenamestr_1.str().c_str());
      
      if(fdata1.is_open()) {     
	fdata1>>mhv4_param.MHV4_1.Channel_0.channelon;
	fdata1>>mhv4_param.MHV4_1.Channel_0.channelpolarity;
	fdata1>>mhv4_param.MHV4_1.Channel_0.channelvoltage;
	fdata1>>mhv4_param.MHV4_1.Channel_0.channelcurrent;
	fdata1>>mhv4_param.MHV4_1.Channel_0.channelvoltagelimit;
	fdata1>>mhv4_param.MHV4_1.Channel_0.channelcurrentlimit;
	fdata1>>mhv4_param.MHV4_1.Channel_1.channelon;
	fdata1>>mhv4_param.MHV4_1.Channel_1.channelpolarity;
	fdata1>>mhv4_param.MHV4_1.Channel_1.channelvoltage;
	fdata1>>mhv4_param.MHV4_1.Channel_1.channelcurrent;
	fdata1>>mhv4_param.MHV4_1.Channel_1.channelvoltagelimit;
	fdata1>>mhv4_param.MHV4_1.Channel_1.channelcurrentlimit;
	fdata1>>mhv4_param.MHV4_1.Channel_2.channelon;
	fdata1>>mhv4_param.MHV4_1.Channel_2.channelpolarity;
	fdata1>>mhv4_param.MHV4_1.Channel_2.channelvoltage;
	fdata1>>mhv4_param.MHV4_1.Channel_2.channelcurrent;
	fdata1>>mhv4_param.MHV4_1.Channel_2.channelvoltagelimit;
	fdata1>>mhv4_param.MHV4_1.Channel_2.channelcurrentlimit;
	fdata1>>mhv4_param.MHV4_1.Channel_3.channelon;
	fdata1>>mhv4_param.MHV4_1.Channel_3.channelpolarity;
	fdata1>>mhv4_param.MHV4_1.Channel_3.channelvoltage;
	fdata1>>mhv4_param.MHV4_1.Channel_3.channelcurrent;
	fdata1>>mhv4_param.MHV4_1.Channel_3.channelvoltagelimit;
	fdata1>>mhv4_param.MHV4_1.Channel_3.channelcurrentlimit;
	    
	mhv4_param.MHV4_1.monitoringactive=1;
	fdata1.close();
	    
      }
      else {
	cm_msg( MERROR, "read_mhv4_event"," Failed to open status file 1",1 );
      }      
    }

    else {
      
      mhv4_param.MHV4_1.monitoringactive=0;
      
      mhv4_param.MHV4_1.Channel_0.channelon=0;
      mhv4_param.MHV4_1.Channel_0.channelpolarity=0;
      mhv4_param.MHV4_1.Channel_0.channelvoltage=0;
      mhv4_param.MHV4_1.Channel_0.channelcurrent=0;
      mhv4_param.MHV4_1.Channel_0.channelvoltagelimit=0;
      mhv4_param.MHV4_1.Channel_0.channelcurrentlimit=0;
      mhv4_param.MHV4_1.Channel_1.channelon=0;
      mhv4_param.MHV4_1.Channel_1.channelpolarity=0;
      mhv4_param.MHV4_1.Channel_1.channelvoltage=0;
      mhv4_param.MHV4_1.Channel_1.channelcurrent=0;
      mhv4_param.MHV4_1.Channel_1.channelvoltagelimit=0;
      mhv4_param.MHV4_1.Channel_1.channelcurrentlimit=0;
      mhv4_param.MHV4_1.Channel_2.channelon=0;
      mhv4_param.MHV4_1.Channel_2.channelpolarity=0;
      mhv4_param.MHV4_1.Channel_2.channelvoltage=0;
      mhv4_param.MHV4_1.Channel_2.channelcurrent=0;
      mhv4_param.MHV4_1.Channel_2.channelvoltagelimit=0;
      mhv4_param.MHV4_1.Channel_2.channelcurrentlimit=0;
      mhv4_param.MHV4_1.Channel_3.channelon=0;
      mhv4_param.MHV4_1.Channel_3.channelpolarity=0;
      mhv4_param.MHV4_1.Channel_3.channelvoltage=0;
      mhv4_param.MHV4_1.Channel_3.channelcurrent=0;
      mhv4_param.MHV4_1.Channel_3.channelvoltagelimit=0;
      mhv4_param.MHV4_1.Channel_3.channelcurrentlimit=0;
    }
    
    vconfig.close();

    //Update the ODB
    db_send_changed_records();
    
  }
  else {
    cm_msg( MERROR, "read_mhv4_event"," Failed to open Voltage Config File");
  }
  
  //cm_msg( MERROR, "read_mhv4_event"," MAKING BANK");

  bk_init( anEvent);

  gettimeofday(&timevalue,NULL);
  
  void *tdata;
  //Write time of day to file 
  bk_create(anEvent, "TIME", TID_STRUCT, &tdata);
  memcpy(tdata, &timevalue,sizeof(timevalue));
  bk_close(anEvent,tdata+sizeof(timevalue));
  
  void *vdata;
  // Write voltage data to file
  bk_create(anEvent, "MHV4", TID_STRUCT, &vdata);
  memcpy(vdata, &mhv4_param,sizeof(mhv4_param));
  bk_close(anEvent,vdata+sizeof(mhv4_param));
  
  // cout<<sizeof(mhv4_param)<<"  "<<bk_size(anEvent)<<endl;
  
  return bk_size( anEvent);
  // return 0;

}
