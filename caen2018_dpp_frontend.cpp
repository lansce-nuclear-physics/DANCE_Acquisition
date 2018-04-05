//*********************************//
//*    Christopher J. Prokop      *//
//*    cprokop@lanl.gov           *//
//*    caen2018_DPP_frontend.cpp  *// 
//*    Last Edit: 04/05/18        *//  
//*********************************//

//File includes
#include "global.h"
#include "program_digitizer.h"
#include "functions.h"
#include "experim.h"

//CAEN includes
#include "CAENDigitizer.h"
#include "CAENDigitizerType.h"

//C/C++ Includes
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <string.h>
#include <stdint.h>

#define WAIT_FOR_EVENT_SLEEP 10 /* ms */

// function prototypes
extern "C" {
  INT poll_event(INT source, INT count, BOOL test);
  INT interrupt_configure( INT cmd, INT source, PTYPE adr )  ;
}

//Return values for CAEN function calls
CAEN_DGTZ_ErrorCode ret;

//return of ODB calls
INT status;

//Register read and write stuff
uint32_t address;          //address of the regsister
uint32_t register_value;   //value from the register

//Diagnostics Variables
uint16_t ADC_Temp[MAXNB][MAXNCH];         //0x1nA8 ADC chip temperature storage (degrees C)
uint32_t Channel_Status[MAXNB][MAXNCH];   //0x1n88 Channel status registers
uint32_t Acquisition_Status[MAXNB];       //0x8104 Acquisition Status
uint32_t Failure_Status[MAXNB];           //0x8178 Board Failure Status
uint32_t Readout_Status[MAXNB];           //0xEF04 Readout Status
uint32_t Register_0x8504n[MAXNB][8];      //0x8504n is an undocumented diagnostics register that says the number of buffers acquired and waiting to be read out.

//Digitizer Rates
uint32_t Digitizer_Rates[MAXNB];          //Digitizer Read Rates (Bytes/s)

//Board information used by the frontend
int AMC_MinRev[MAXNB];               //AMC Minor Revision 
int AMC_MajRev[MAXNB];               //AMC Major Revision (136 is PSD, 139 is PHA)
int NChannels[MAXNB];                //Number of channels 8 or 16
int ModType[MAXNB];                  //725 or 730
int ModCode[MAXNB];                  //numerical way to say NIM, VME, etc
int SerialNumber[MAXNB];             //Serial number of the board

uint32_t firmware_version[MAXNB];    //firmware version to be written to the data stream

char *buffer[MAXNB];                 //Readout Buffer
int hasdata[MAXNB];                  //Flag to say if board has data
int handle[MAXNB];                   //handle of the digitizers
uint32_t AllocatedSize[MAXNB];       //Calculated max size of the readout buffers
uint32_t BufferSize[MAXNB];          //Buffer size of the read
uint32_t Nb=0;                       //Number of bytes read this read cycle
 
struct timeval timevalue;            //current time to be written to scalers

uint32_t Scaler_Totals[MAXNB];       //Readout rate from each board
INT Read_Fails[MAXNB];               //keep track of any failures to read data from the modules
INT Poll_Fails[MAXNB];               //keep track of any failures to poll the module

//enum HWScalerID { NumTriggers, PollErrors, ReadErrors, NumHWScalers };

/* ###########################################################################
 *  Functions
 *  ########################################################################### */

//This function inerprets the connection type (optilink vs USB) of the digitizer
CAEN_DGTZ_ConnectionType interpret_connection(const char *ltype) {
  if (strcmp(ltype,"CAEN_DGTZ_PCIE_OpticalLink") == 0) {
    return CAEN_DGTZ_PCIE_OpticalLink;
  }
  else if(strcmp(ltype,"CAEN_DGTZ_PCIE_USB") == 0) {
    return CAEN_DGTZ_USB;
  }
  else {
    cm_msg(MERROR,"interpret_connection","Could not interpret connection type %s\n", ltype);
    exit(1);
  }
}

/* make frontend functions callable from the C framework */
#ifdef __cplusplus
extern "C" {
#endif

  /* The frontend name (client name) as seen by other MIDAS clients   */
  char *frontend_name = "caen2018_dpp_frontend";

  /* The frontend file name, don't change it */
  char *frontend_file_name = __FILE__;

  /* frontend_loop is called periodically if this variable is TRUE    */
  BOOL frontend_call_loop = FALSE;

  /* a frontend status page is displayed with this frequency in ms */
  INT display_period = 3000;

  /* maximum event size produced by this frontend */
  //this should be taken from midas.h
  INT max_event_size = MAX_EVENT_SIZE;

  /* maximum event size for fragmented events (EQ_FRAGMENTED) */
  //INT max_event_size_frag = 8 * 512 * 1024;
  INT max_event_size_frag = MAX_EVENT_SIZE;

  /* buffer size to hold events */
  INT event_buffer_size = 2*MAX_EVENT_SIZE;
  INT nreads = 0;

  /*-- Function declarations -----------------------------------------*/
  int RegisterSetBits(int handle, uint16_t addr, int start_bit, int end_bit, int val)
  {
    uint32_t mask=0, reg;
    int ret;
    int i;
    
    ret = CAEN_DGTZ_ReadRegister(handle, addr, &reg);   
    for(i=start_bit; i<=end_bit; i++)
      mask |= 1<<i;
    reg = reg & ~mask | ((val<<start_bit) & mask);
    ret |= CAEN_DGTZ_WriteRegister(handle, addr, reg);   
    return ret;
  }

  INT frontend_init();
  INT frontend_exit();
  INT begin_of_run(INT run_number, char *error);
  INT end_of_run(INT run_number, char *error);
  INT pause_run(INT run_number, char *error);
  INT resume_run(INT run_number, char *error);
  INT frontend_loop();

  INT read_trigger_event(char *pevent, INT off);
  //INT read_scaler_event(char *pevent, INT off);
  INT read_diagnostics_event(char *pevent, INT off);

  void register_cnaf_callback(int debug);

  INT read_digitizer_event(char *pevent, INT off);

  /*-- Equipment list ------------------------------------------------*/

  EQUIPMENT equipment[] = {

    {"Digitizer",               /* equipment name */
     {1, 0,                   /* event ID, trigger mask */
      "SYSTEM",               /* event buffer */
      EQ_POLLED,              /* equipment type */
      0,
      "MIDAS",                /* format */
      TRUE,                   /* enabled */
      RO_RUNNING,             /* read only when running */
      50,                    /* poll for 500ms */
      0,                      /* stop run after this event limit */
      0,                      /* number of sub events */
      0,                      /* don't log history */
      "", "", "",},
     read_digitizer_event,      /* readout routine */
    },
  
    { "Diagnostics",                     // equipment name
      {
	8, 0,                    // event ID, trigger mask
	"SYSTEM",                     // event buffer
	EQ_PERIODIC,                  // equipment type
	0,                            // event source
	"MIDAS",                      // format
	TRUE,                         // enabled
	RO_RUNNING, 
	10000,                        // read interval in ms
	0,                            // stop run after this event limit
	0,                            // number of sub events
	0,                                // log history
	"", "", "",
      },
      read_diagnostics_event,        // readout routine
    },

    {""}
  };

#ifdef __cplusplus
}
#endif

//MIDAS ODB Stuff
EXP_PARAM exp_param;
HNDLE hDB;
HNDLE runparamKey;
HNDLE genHdl;
HNDLE activeBoards[MAXNB];
INT nactiveboards;
INT size;

/********************************************************************\
              Callback routines for system transitions

  These routines are called whenever a system transition like start/
  stop of a run occurs. The routines are called on the following
  occations:

  frontend_init:  When the frontend program is started. This routine
                  should initialize the hardware.

  frontend_exit:  When the frontend program is shut down. Can be used
                  to releas any locked resources like memory, commu-
                  nications ports etc.

  begin_of_run:   When a new run is started. Clear scalers, open
                  rungates, etc.

  end_of_run:     Called on a request to stop a run. Can send
                  end-of-run event and close run gates.

  pause_run:      When a run is paused. Should disable trigger events.

  resume_run:     When a run is resumed. Should enable trigger events.
\********************************************************************/

/*-- Frontend Init -------------------------------------------------*/

RUNINFO runInfo;
INT frontend_init()
{
 
  cm_msg(MINFO,"frontend_init","Begin frontend initialization\n");

  // initialize the buffer pointers here
  int zee=0;
  for (zee=0;zee<MAXNB;++zee) {
    buffer[zee] = NULL;
  }

  /*
  cm_msg(MINFO,"frontend_init","Telling cron to watch my status\n");
  //Write the original crontab file 
  system("crontab -l > .crontab_init");
  //Copy the file
  system("cp .crontab_init .crontab_run");
  //Add the caen2018 status to the crontab_run 
  system("echo \"14,29,44,59 * * * * /home/daq/caen2018/caen2018_status\" >> .crontab_run");
  //tell cron to change to running crontab
  system("crontab .crontab_run");
  */
  
  // ODB interactions start here
  cm_get_experiment_database( &hDB, NULL);
  EXP_PARAM_STR (runparam_str);
  db_create_record( hDB, 0,"/Experiment/Run Parameters", strcomb(runparam_str));
  db_find_key( hDB, 0, "/Experiment/Run Parameters", &runparamKey);
  if (status = db_open_record( hDB, runparamKey, &exp_param, sizeof(exp_param), MODE_READ, 0, 0),status != DB_SUCCESS) {
    char errMsg[128];
    cm_get_error( status, errMsg);
    cm_msg( MERROR, "frontend_init", "Cannot open \"/Experiment/Run Parameters\" tree in ODB: %s\n", errMsg);
    return 0;
  }
  
  //See how many boards we are running
  INT N_ODB_DIG_BOARDS;
  size = sizeof(N_ODB_DIG_BOARDS);
  db_find_key(hDB, runparamKey,"NDigitizers" , &genHdl);
  db_get_data(hDB,genHdl,&N_ODB_DIG_BOARDS,&size,TID_INT);
  cm_msg(MINFO,"frontend_init","ODB says we have %i boards\n",N_ODB_DIG_BOARDS);
  // end ODB basic interactions

  //Check to make sure that the number of digitizers does not exceed the MAXNB
  if(N_ODB_DIG_BOARDS > MAXNB) {
    cm_msg(MERROR,"frontend_init","NDigitizers (%i) > MAXNB (%i). Exiting",N_ODB_DIG_BOARDS,MAXNB);
    exit(1);
  }
  
  // Begin communicating with digitizers
  int eye;
  nactiveboards = 0;
  cm_msg(MINFO,"frontend_init","About to initialize boards\n");

  //See what boards are active
  for (eye = 0;eye<N_ODB_DIG_BOARDS;eye++) {
    cm_msg(MINFO,"frontend_init","Looking for board %i",eye);
    char buf[100];
    sprintf(buf,"Digitizer_%i/Enabled",eye);
    BOOL enabled;
    size = sizeof(enabled);
    db_find_key(hDB,runparamKey,buf, &genHdl);
    db_get_data(hDB,genHdl,&enabled,&size,TID_BOOL);
    if (enabled) {
      sprintf(buf,"Digitizer_%i",eye);
      db_find_key(hDB,runparamKey,buf,&activeBoards[nactiveboards]);
      nactiveboards += 1;
      cm_msg(MINFO,"frontend_init","found Board %i enabled; nactiveboards: %d  \n",eye,nactiveboards);
    }
  }

  // now open up communication for digitizers
  for (eye=0;eye<nactiveboards;++eye) {
    // get the link type
    char buf[100];
    char ltype[32];
    size = sizeof(ltype);
    sprintf(buf,"LinkType");
    db_find_key(hDB, activeBoards[eye],buf, &genHdl);
    db_get_data(hDB,genHdl,ltype,&size,TID_STRING);
    cm_msg(MINFO,"frontend_init","found Board %i link type %s",eye,ltype);
    CAEN_DGTZ_ConnectionType connect_type = interpret_connection(ltype);
    cm_msg(MINFO,"frontend_init","converted Board %i link type %i",eye,connect_type);
    
    // get the base address
    DWORD baddy = 0;
    size = sizeof(baddy);
    sprintf(buf,"VMEBaseAddress");
    db_find_key(hDB, activeBoards[eye],buf, &genHdl);
    db_get_data(hDB,genHdl,&baddy,&size,TID_DWORD);
    cm_msg(MINFO,"frontend_init","Board %i base address %i",eye,baddy);
    
    // get the link number
    INT linknum = 0;
    size = sizeof(linknum);
    sprintf(buf,"LinkNum",eye);
    db_find_key(hDB, activeBoards[eye],buf, &genHdl);
    db_get_data(hDB,genHdl,&linknum,&size,TID_INT);
    cm_msg(MINFO,"frontend_init","Board %i link number %i",eye,linknum);
    
    // Get the conet number
    INT conetnum = 0;
    size = sizeof(conetnum);
    sprintf(buf,"ConetNum",eye);
    db_find_key(hDB, activeBoards[eye],buf, &genHdl);
    db_get_data(hDB,genHdl,&conetnum,&size,TID_INT);
    cm_msg(MINFO,"frontend_init","Board %i conet number %i \n",eye,conetnum);
        
    //  CAEN_DGTZ_SWStopAcquisition(handle[eye]);
    //  CAEN_DGTZ_CloseDigitizer(handle[eye]);
    
    //Open the digitizer
    ret = CAEN_DGTZ_OpenDigitizer(connect_type, linknum, conetnum, baddy, &handle[eye]);
    if (ret != 0 && ret != 25) {
      cm_msg(MERROR,"frontend_init","Can't open digitizer %d. ret val: %d \n",eye,ret);
      
      //Reset the digitizer
      ret = CAEN_DGTZ_Reset(handle[eye]);
      cm_msg(MINFO,"frontend_init","Resetting the digitizer w/ retval %i",ret);
      
      if (ret) {
	printf("ERROR: can't reset digitizer %d \n", eye);
      }

      //if we cant open it on try 2 then quit
      ret = CAEN_DGTZ_OpenDigitizer(connect_type, linknum, conetnum, baddy, &handle[eye]);

      if (ret != 0 && ret != -25) {       
	cm_msg(MERROR,"frontend_init","Still can't open digitizer %d. Attempt 2. ret val: %d \n",eye,ret);
	exit(1);    
      }
    }

    //Reset the digitizer
    ret = CAEN_DGTZ_Reset(handle[eye]);
    cm_msg(MINFO,"frontend_init","Resetting the digitizer w/ retval %i\n",ret);
    
    if (ret) {
      printf("ERROR: can't reset digitizer %d \n", eye);
      exit(1);
    }

    //Allow digitizer to reset
    sleep(100);

  }

  
  // Now that the digitizers are open and we have handles close the ODB for reading for the moment
  db_close_record( hDB, 0);
  
  //Reopen it in write mode
  cm_get_experiment_database( &hDB, NULL);
  //EXP_PARAM_STR (runparam_str);
  db_create_record( hDB, 0, "/Experiment/Run Parameters", strcomb(runparam_str));
  db_find_key( hDB, 0, "/Experiment/Run Parameters", &runparamKey);
  if (status = db_open_record( hDB, runparamKey, &exp_param, sizeof(exp_param), MODE_WRITE, 0, 0),status != DB_SUCCESS) {
    char errMsg[128];
    cm_get_error( status, errMsg);
    cm_msg( MERROR, "frontend_init", "Cannot open \"/Experiment/Run Parameters\" tree in ODB for writing: %s\n", errMsg);
    return 0;
  }
    
  std::ifstream tmpfile;
  char buf[32];
  
  
  //Get the frontend version
  tmpfile.open(".version");
  std::string FEVersion;
  tmpfile >> FEVersion; //This first part is just the word "version"
  tmpfile >> FEVersion;

  std::stringstream ssFEVer;
  ssFEVer.str("");
  ssFEVer << FEVersion;

  char FEVerbuf[80];
  sprintf(FEVerbuf,"caen2018 version %s",ssFEVer.str().c_str());
  sprintf(buf,"Comment");
  db_find_key(hDB, runparamKey,buf, &genHdl);
  db_set_data(hDB,genHdl,&FEVerbuf,sizeof(FEVerbuf),1,TID_STRING);
  cm_msg(MINFO,"frontend_init","caen2018 frontend version %s",ssFEVer.str().c_str());
  tmpfile.close();
  
  //Get the information about the Comm libraries
  system("readlink $CAENCOMMSYS > .caencommversion");
  usleep(100);
  tmpfile.open(".caencommversion");
  std::string caencommver;
  tmpfile >> caencommver;

  std::stringstream sscaencommver;
  sscaencommver.str("");
  sscaencommver << caencommver;

  char caencommverbuf[32];
  sprintf(caencommverbuf,"%s",sscaencommver.str().c_str());
  sprintf(buf,"CAEN_Library_Information/CAENcommsys");
  db_find_key(hDB, runparamKey,buf, &genHdl);
  db_set_data(hDB,genHdl,&caencommverbuf,sizeof(caencommverbuf),1,TID_STRING);
  cm_msg(MINFO,"frontend_init","CAEN Comm Version: %s",sscaencommver.str().c_str());
  tmpfile.close();

 //Get the information about the Digitizer libraries
  system("readlink $CAENDIGITIZERSYS > .caendigitizerversion");
  usleep(100);
  tmpfile.open(".caendigitizerversion");
  std::string caendigver;
  tmpfile >> caendigver;

  std::stringstream sscaendigver;
  sscaendigver.str("");
  sscaendigver << caendigver;

  char caendigverbuf[32];
  sprintf(caendigverbuf,"%s",sscaendigver.str().c_str());
  sprintf(buf,"CAEN_Library_Information/CAENdigitizersys");
  db_find_key(hDB, runparamKey,buf, &genHdl);
  db_set_data(hDB,genHdl,&caendigverbuf,sizeof(caendigverbuf),1,TID_STRING);
  db_set_data(hDB,genHdl,&caendigverbuf,sizeof(caendigverbuf),1,TID_STRING);
  cm_msg(MINFO,"frontend_init","CAEN Digitizer Version: %s",sscaendigver.str().c_str());
  tmpfile.close();

//Get the information about the Upgrader libraries
  system("readlink $CAENUPGRADERSYS > .caenupgraderversion");
  usleep(100);
  tmpfile.open(".caenupgraderversion");
  std::string caenupgraderver;
  tmpfile >> caenupgraderver;

  std::stringstream sscaenupgraderver;
  sscaenupgraderver.str("");
  sscaenupgraderver << caenupgraderver;

  char caenupgraderverbuf[32];
  sprintf(caenupgraderverbuf,"%s",sscaenupgraderver.str().c_str());
  sprintf(buf,"CAEN_Library_Information/CAENupgradersys");
  db_find_key(hDB, runparamKey,buf, &genHdl);
  db_set_data(hDB,genHdl,&caenupgraderverbuf,sizeof(caenupgraderverbuf),1,TID_STRING);
  cm_msg(MINFO,"frontend_init","CAEN Upgrader Version: %s",sscaenupgraderver.str().c_str());
  tmpfile.close();

  //Get the information about the VME libraries
  system("readlink $CAENVMELIBSYS > .caenvmelibversion");
  usleep(100);
  tmpfile.open(".caenvmelibversion");
  std::string caenvmelibver;
  tmpfile >> caenvmelibver;

  std::stringstream sscaenvmelibver;
  sscaenvmelibver.str("");
  sscaenvmelibver << caenvmelibver;

  char caenvmelibverbuf[32];
  sprintf(caenvmelibverbuf,"%s",sscaenvmelibver.str().c_str());
  sprintf(buf,"CAEN_Library_Information/CAENvmelibsys");
  db_find_key(hDB, runparamKey,buf, &genHdl);
  db_set_data(hDB,genHdl,&caenvmelibverbuf,sizeof(caenvmelibverbuf),1,TID_STRING);
  cm_msg(MINFO,"frontend_init","CAEN VME Lib Version: %s",sscaenvmelibver.str().c_str());
  tmpfile.close();



//Get the information about the Digitizer libraries during compilation
  tmpfile.open(".caencommversion_compile");
  std::string caencommver_compile;
  tmpfile >> caencommver_compile;

  std::stringstream sscaencommver_compile;
  sscaencommver_compile.str("");
  sscaencommver_compile << caencommver_compile;

  char caencommver_compilebuf[32];
  sprintf(caencommver_compilebuf,"%s",sscaencommver_compile.str().c_str());
  sprintf(buf,"CAEN_Library_Information/CAENcommsys_Compile");
  db_find_key(hDB, runparamKey,buf, &genHdl);
  db_set_data(hDB,genHdl,&caencommver_compilebuf,sizeof(caencommver_compilebuf),1,TID_STRING);
  cm_msg(MINFO,"frontend_init","CAEN Comm Version Compile: %s",sscaencommver_compile.str().c_str());
  tmpfile.close();

  tmpfile.open(".caendigitizerversion_compile");
  std::string caendigver_compile;
  tmpfile >> caendigver_compile;

  std::stringstream sscaendigver_compile;
  sscaendigver_compile.str("");
  sscaendigver_compile << caendigver_compile;

  char caendigver_compilebuf[32];
  sprintf(caendigver_compilebuf,"%s",sscaendigver_compile.str().c_str());
  sprintf(buf,"CAEN_Library_Information/CAENdigitizersys_Compile");
  db_find_key(hDB, runparamKey,buf, &genHdl);
  db_set_data(hDB,genHdl,&caendigver_compilebuf,sizeof(caendigver_compilebuf),1,TID_STRING);
  db_set_data(hDB,genHdl,&caendigver_compilebuf,sizeof(caendigver_compilebuf),1,TID_STRING);
  cm_msg(MINFO,"frontend_init","CAEN Digitizer Version Compile: %s",sscaendigver_compile.str().c_str());
  tmpfile.close();

//Get the information about the Upgrader libraries
  tmpfile.open(".caenupgraderversion_compile");
  std::string caenupgraderver_compile;
  tmpfile >> caenupgraderver_compile;

  std::stringstream sscaenupgraderver_compile;
  sscaenupgraderver_compile.str("");
  sscaenupgraderver_compile << caenupgraderver_compile;

  char caenupgraderver_compilebuf[32];
  sprintf(caenupgraderver_compilebuf,"%s",sscaenupgraderver_compile.str().c_str());
  sprintf(buf,"CAEN_Library_Information/CAENupgradersys_Compile");
  db_find_key(hDB, runparamKey,buf, &genHdl);
  db_set_data(hDB,genHdl,&caenupgraderver_compilebuf,sizeof(caenupgraderver_compilebuf),1,TID_STRING);
  cm_msg(MINFO,"frontend_init","CAEN Upgrader Version Compile: %s",sscaenupgraderver_compile.str().c_str());
  tmpfile.close();

  //Get the information about the VME libraries
  tmpfile.open(".caenvmelibversion_compile");
  std::string caenvmelibver_compile;
  tmpfile >> caenvmelibver_compile;

  std::stringstream sscaenvmelibver_compile;
  sscaenvmelibver_compile.str("");
  sscaenvmelibver_compile << caenvmelibver_compile;

  char caenvmelibver_compilebuf[32];
  sprintf(buf,"CAEN_Library_Information/CAENvmelibsys_Compile");
  db_find_key(hDB, runparamKey,buf, &genHdl);
  db_set_data(hDB,genHdl,&caenvmelibver_compilebuf,sizeof(caenvmelibver_compilebuf),1,TID_STRING);
  cm_msg(MINFO,"frontend_init","CAEN VME Lib Version Compile: %s",sscaenvmelibver_compile.str().c_str());
  tmpfile.close();







  //Get the information from the boards
  for (eye=0;eye<nactiveboards;++eye) {    
    int function_return =0;
    function_return = get_board_information(handle,eye,hDB,activeBoards,ModType,ModCode,AMC_MajRev,AMC_MinRev,NChannels,SerialNumber);
    
    if(function_return != 0) {
      exit(1);
    }
  }
  
  // Now that the digitizers are open close the odb for writing
  db_close_record( hDB, 0);
  
  //Reopen it in read mode
  cm_get_experiment_database( &hDB, NULL);
  //EXP_PARAM_STR (runparam_str);
  db_create_record( hDB, 0, "/Experiment/Run Parameters", strcomb(runparam_str));
  db_find_key( hDB, 0, "/Experiment/Run Parameters", &runparamKey);
  if (status = db_open_record( hDB, runparamKey, &exp_param, sizeof(exp_param), MODE_READ, 0, 0),status != DB_SUCCESS) {
    char errMsg[128];
    cm_get_error( status, errMsg);
    cm_msg( MERROR, "frontend_init", "Cannot open \"/Experiment/Run Parameters\" tree in ODB for writing: %s\n", errMsg);
    return 0;
  }

  return SUCCESS;
}

/*-- Frontend Exit -------------------------------------------------*/

INT frontend_exit()
{
  int eye;
  CAEN_DGTZ_SWStopAcquisition(handle[0]);

  for (eye=0;eye<nactiveboards;++eye) {
    //  CAEN_DGTZ_SWStopAcquisition(handle[eye]);
    CAEN_DGTZ_CloseDigitizer(handle[eye]);
  }
  
  /*
  //tell cron to change to running crontab
  system("crontab .crontab_init");
  */

  return SUCCESS;
}

/*-- Begin of Run --------------------------------------------------*/

INT begin_of_run(INT run_number, char *error) {
  /* put here clear scalers etc. */
  nreads = 0;
  
  //Clear scalers
  for(int i=0; i<MAXNB; i++) {
    Scaler_Totals[i]=0; 
    Read_Fails[i]=0; 
    Poll_Fails[i]=0; 
  }
  
  return resume_run(run_number,error);
}

/*-- End of Run ----------------------------------------------------*/

INT end_of_run(INT run_number, char *error) {
  return pause_run(run_number,error);
}

/*-- Pause Run -----------------------------------------------------*/

INT pause_run(INT run_number, char *error) {
  // Stop Acquisition
  CAEN_DGTZ_SWStopAcquisition(handle[0]);
  for (int eye = 0;eye<nactiveboards;++eye) {
    //  CAEN_DGTZ_SWStopAcquisition(handle[eye]);
    
    //Save a register image
    SaveRegImage(handle[eye],run_number,0);
    
    cm_msg(MINFO,"pause_run","Acquisition Stopped for Board %d", eye);
  }
  return SUCCESS;
}

/*-- Resume Run ----------------------------------------------------*/

INT resume_run(INT run_number, char *error) {
  // Start Acquisition
  // NB: the acquisition for each board starts when the following line is executed
  // so in general the acquisition does NOT starts syncronously for different boards

  for (int eye = 0;eye<nactiveboards;++eye) {
    cm_msg(MINFO,"resume_run","Resuming run %i on board %i, active boards: %i",run_number,eye,nactiveboards);
    
    //Stop the acquisition
    ret = CAEN_DGTZ_SWStopAcquisition(handle[eye]);
    cm_msg(MINFO,"resume_run","Stopping the Acquisition w/ retval %i",ret);

    //Free the readout buffer
    ret = CAEN_DGTZ_FreeReadoutBuffer(&buffer[eye]);
    cm_msg(MINFO,"resume_run","Freeing the Readout Buffer w/ retval %i",ret);

    //Reset the digitizer
    ret = CAEN_DGTZ_Reset(handle[eye]);
    cm_msg(MINFO,"resume_run","Resetting the digitizer w/ retval %i",ret);
    
    if (ret) {
      printf("ERROR: can't reset digitizer %d \n", eye);
      exit(1);
    }
    
    //allow the digitizer to reset
    sleep(100);

    //Check to see if its ok to program and run
    address = 0x8104;
    ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&register_value);
    if(ret) {
      cm_msg(MERROR,"poll_event","Problem Obtaining Acquisition Status on Board: %d, ret val: %i\n",eye,ret);
    }
    
    if(!(register_value & 0x00000100)) {
      cm_msg(MERROR,"poll_event","Board: %d is not ready to start %i\n",eye);
    }
    
    //return of programming functions
    int function_return = 0;
    
    //Program the board-wide stuff
    function_return = program_general_board_registers(handle,eye,hDB,activeBoards,ModType,ModCode,AMC_MajRev,NChannels);
    if(function_return != 0) {
      exit(1);
    }

    //Program trigger validation masks
    function_return = program_trigger_validation_registers(handle,eye,hDB,activeBoards,ModType,ModCode,AMC_MajRev,NChannels);
    if(function_return != 0) {
      exit(1);
    }
    
    //Program channel by channel stuff
    function_return = program_channel_registers(handle,eye,hDB,activeBoards,ModType,ModCode,AMC_MajRev,NChannels);
    if(function_return != 0) {
      exit(1);
    }

    //Set the Memory Configuration on the boards.  I feel it is best to let it determine for itself
    ret = CAEN_DGTZ_SetNumEventsPerAggregate(handle[eye],1023);  //Set this to the max value
    if(ret != 0) {
      cm_msg(MERROR,"resume_run","Cannot set NumEventsPerAggregate on Board: %d, ret val: %i  Exiting. \n", eye,ret);
      exit(1);
    }
    ret = CAEN_DGTZ_SetDPPEventAggregation(handle[eye],0,0); //Let the board figure it out
    if(ret != 0) {
      cm_msg(MERROR,"resume_run","Cannot set DPPEventAggregation on Board: %d, ret val: %i  Exiting. \n", eye,ret);
      exit(1);      
    }
        
    //Make the 32-bit word that tells the analyzer what firmware is being run
    firmware_version[eye] = 0;
    firmware_version[eye] += AMC_MajRev[eye];           //bits 0 to 7 are Major Revision
    firmware_version[eye] += (AMC_MinRev[eye] << 8);    //bits 8 to 13 are Minor Revision
    firmware_version[eye] += (eye << 26);               //bits 26 to 31 are Board Number (redudancy) 

    //Calibrate ADC 
    ret = CAEN_DGTZ_WriteRegister(handle[eye], 0x809C, 0); // calibration command (direct access to register)
    if(ret != 0) {
      cm_msg(MERROR,"resume_run","Cannot Calibrate  Board: %d, ret val: %i \n", eye,ret);
    }
    
    //Sleep for 100 ms to allow calibration to complete
    sleep(100);

    //Save a register image
    SaveRegImage(handle[eye],run_number,1);

    // Allocate memory for the readout buffer /
    cm_msg(MINFO,"resume_run","About to Malloc Readout Buffer Handle %i\n",handle[eye]);
    ret = CAEN_DGTZ_MallocReadoutBuffer(handle[eye], &buffer[eye], &AllocatedSize[eye]);
    if(ret != 0) {
      cm_msg(MERROR,"resume_run","Cannot MallocReadoutBuffer  Board: %d, ret val: %i \n", eye,ret);
    }
    
    // cm_msg(MINFO,"resume_run","Allocated Size for Board: %d is %lu \n",eye,AllocatedSize[eye]);

    //Check to see if its ok to run
    address = 0x8104;
    ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&register_value);
    if(ret) {
      cm_msg(MERROR,"resume_run","Problem Obtaining Acquisition Status 2 on Board: %d, ret val: %i\n",eye,ret);
    }
    if(!(register_value & 0x00000100)) {
      cm_msg(MERROR,"resum_run","Board: %d is not ready to start 2  %i\n",eye);
    }
  }
  
  //Zero out the diagnostics
  for(int boardnum=0; boardnum<nactiveboards; boardnum++) {
    for(int channum=0; channum<MAXNCH; channum++) {
      ADC_Temp[boardnum][channum] = 0;
      Channel_Status[boardnum][channum] = 0;
    }
    Acquisition_Status[boardnum] = 0;
    Failure_Status[boardnum] = 0; 
    Readout_Status[boardnum] = 0;   
    for(int pairnum=0; pairnum<8; pairnum++) {
      Register_0x8504n[boardnum][pairnum]=0;
    }
  }
 
  //Start the acquisition
  ret = CAEN_DGTZ_SWStartAcquisition(handle[0]);
  if(ret) {
    cm_msg(MERROR,"resume_run","Failed to Start Acquisition, Ret Val: %i\n",ret);
  }
  else {
    cm_msg(MINFO,"resume_run","Starting Acquisition\n");

  }
  
  return SUCCESS;
}

/*-- Frontend Loop -------------------------------------------------*/

INT frontend_loop()
{
  /* if frontend_call_loop is true, this routine gets called when
     the frontend is idle or once between every event */
  return SUCCESS;
}

/*------------------------------------------------------------------*/

/********************************************************************\

  Readout routines for different events

\********************************************************************/

/*-- Trigger event routines ----------------------------------------*/

INT poll_event(INT source, INT count, BOOL test)
{
  static struct timeval old_time;
  static struct timeval new_time;
    
  //printf("commence poll\n");
  if (test == FALSE) {
    
    BOOL should_swpoll = FALSE;
    gettimeofday(&new_time,0);
    if (((new_time.tv_sec*1000000 + new_time.tv_usec) - (old_time.tv_sec*1000000 + old_time.tv_usec))>1000000) {
      old_time = new_time;
      should_swpoll = TRUE;
    }
    
    //Check some diagnostics things from the boards
    if(should_swpoll) {
      for(int boardnum=0; boardnum<nactiveboards; boardnum++) {
	for(int channum=0; channum<MAXNCH; channum++) {
	  
	  //Channel n temp
	  address = 0x10A8 + (channum<<8);
	  ret = CAEN_DGTZ_ReadRegister(handle[boardnum],address,&register_value);
	  if(ret) {
	    cm_msg(MERROR,"poll_event","Problem Obtaining ADC Temp Board: %d, Channel: %d, ret val: %i\n",boardnum,channum,ret);
	  }
	  ADC_Temp[boardnum][channum] = register_value & 0xFF;

	  //Channel n status
	  address = 0x1088 + (channum<<8);
	  ret = CAEN_DGTZ_ReadRegister(handle[boardnum],address,&register_value);
	  if(ret) {
	    cm_msg(MERROR,"poll_event","Problem Obtaining Channel Status Board: %d, Channel: %d, ret val: %i\n",boardnum,channum,ret);
	  }
	  Channel_Status[boardnum][channum] = register_value;
	  
	  //Make sure the ADC has not been powered down
	  if(register_value & 0x00000100) {
	    cm_msg(MERROR,"poll_event","ADC is Ostensibly Shut Down on Board: %d, Channel: %d, ret val: %i\n",boardnum,channum,ret);
	  }
	  if(!(register_value & 0x00000008)) {
	    cm_msg(MERROR,"poll_event","ADC is NOT Calibrated on Board: %d, Channel: %d, ret val: %i\n",boardnum,channum,ret);
	  }	  
	} //end loop on channum

	//Board things
	//Acquisition Status
	address = 0x8104;
	ret = CAEN_DGTZ_ReadRegister(handle[boardnum],address,&register_value);
	if(ret) {
	  cm_msg(MERROR,"poll_event","Problem Obtaining Aquisition Status Board: %d, ret val: %i\n",boardnum,ret);
	}
	Acquisition_Status[boardnum] = register_value;

	//Board Failure
	address = 0x8178;
	ret = CAEN_DGTZ_ReadRegister(handle[boardnum],address,&register_value);
	if(ret) {
	  cm_msg(MERROR,"poll_event","Problem Obtaining Board Failure Status Board: %d, ret val: %i\n",boardnum,ret);
	}
	Failure_Status[boardnum] = register_value;
	
	//Readout Status
	address = 0xEF04;
	ret = CAEN_DGTZ_ReadRegister(handle[boardnum],address,&register_value);
	if(ret) {
	  cm_msg(MERROR,"poll_event","Problem Obtaining Readout Status Board: %d, ret val: %i\n",boardnum,ret);
	}
	Readout_Status[boardnum] = register_value;

	//Pair Things
	
	//0x8504n
	for(int pairnum=0; pairnum<8; pairnum++) {
	  address = 0x8500 + 4*pairnum;

	  ret = CAEN_DGTZ_ReadRegister(handle[boardnum],address,&register_value);
	  if(ret) {
	    cm_msg(MERROR,"poll_event","Problem Obtaining Readout Status Board: %d, Pair: %d, ret val: %i\n",boardnum,pairnum,ret);
	  }
	  Register_0x8504n[boardnum][pairnum] = register_value;
	} //end loop on pairnum
      } //end loop on boardnum
    } //end check if swpoll
    

    //Set number of bytes read to be zero
    Nb = 0;

    // Read data from the boards 
    for(int boardnum=0; boardnum<nactiveboards; boardnum++) {
      hasdata[boardnum]=0;      
      ret = CAEN_DGTZ_ReadData(handle[boardnum], CAEN_DGTZ_SLAVE_TERMINATED_READOUT_MBLT, buffer[boardnum], &BufferSize[boardnum]);
      
      //Read Error
      if (ret) {
	cm_msg(MERROR,"poll_event","Readout Error 1 board: %d, buffer size: %lu, ret val: %i\n",boardnum,BufferSize[boardnum],ret);
	
	//try again
	ret = CAEN_DGTZ_ReadData(handle[boardnum], CAEN_DGTZ_SLAVE_TERMINATED_READOUT_MBLT, buffer[boardnum], &BufferSize[boardnum]);
	
	/*
	if(ret) {
	  cm_msg(MERROR,"poll_event","Readout Error 2 board: %d, buffer size: %lu, ret val: %i\n",boardnum,BufferSize[boardnum],ret);
	  Read_Fails[boardnum]++;  
	  BufferSize[boardnum]=0; //Dont put corrupt data into the data stream
	  // exit(1);
	}    
	else {
	  cm_msg(MERROR,"poll_event","Readout 2 successful board: %d, buffer size: %lu, ret val: %i\n",boardnum,BufferSize[boardnum],ret);
	  
	}
	*/
      }
      if (BufferSize[boardnum] == 0) {
	hasdata[boardnum]=0;
	continue;
      }
      else {
	/*
	// check error bit in the header
	uint32_t *header, d32;
	header = (uint32_t *)buffer[boardnum];
	if (header[1] & 0x04000000) {
	  cm_msg(MERROR,"poll_event","Severe Error Bit in header (board %d)!!!\n", boardnum);
	  CAEN_DGTZ_ReadRegister(handle[boardnum], 0x8178, &d32);
	  cm_msg(MERROR,"poll_event","Failure Register %lu \n", d32);
	  }
       	*/

	Nb += BufferSize[boardnum];
	Scaler_Totals[boardnum] += BufferSize[boardnum];
	hasdata[boardnum]=1;
	//	cm_msg(MINFO,"poll","polling for data, have data");
      }
    } // loop on boards

    if (Nb > 0) {
      //cm_msg(MINFO,"polling","Found some data\n");
      return TRUE;
    } 
    else {
      return FALSE;
    }
  }
  else {
    gettimeofday(&old_time,0);
    //printf("in a funny state...\n");
    // avoid calibration failure
    int j;
    for (j=0; j < count; ++j) {
      ss_sleep(WAIT_FOR_EVENT_SLEEP);
    }
  }
  
  return 0;
}

/*-- Interrupt configuration ---------------------------------------*/

INT interrupt_configure(INT cmd, INT source, POINTER_T adr)
{
  switch (cmd) {
  case CMD_INTERRUPT_ENABLE:
    break;
  case CMD_INTERRUPT_DISABLE:
    break;
  case CMD_INTERRUPT_ATTACH:
    break;
  case CMD_INTERRUPT_DETACH:
    break;
  }
  return SUCCESS;
}


INT read_digitizer_event(char *pevent, INT off) {

  bk_init32(pevent);
  
  // Store data 
  for(int boardnum=0; boardnum<nactiveboards; boardnum++) {
    
    //check to see if this board has data
    if(hasdata[boardnum]==1) {
      
      //data void pointer
      void *pdata;

      char bankname[5]; 
      sprintf(bankname, "B%03d", boardnum);
      //cm_msg(MINFO,"reading","bankname: %s, size: %lu \n",bankname,BufferSize[boardnum]);
      // bk_create(pevent, "DEVT", TID_CHAR, &pdata);
      bk_create(pevent, bankname, TID_CHAR, &pdata);

      //Add a word with the firmware major version as the very first thing
      memcpy(pdata, &firmware_version[boardnum],sizeof(firmware_version[boardnum]));
      
      //Then put the data in the bank
      memcpy(pdata+sizeof(firmware_version[boardnum]),buffer[boardnum],BufferSize[boardnum]);
     // memcpy(pdata,buffer[boardnum],BufferSize[boardnum]);
      bk_close(pevent, pdata+sizeof(firmware_version[boardnum])+BufferSize[boardnum]);
      // bk_close(pevent, pdata+BufferSize[boardnum]);

    }
  }
  nreads += 1;  
  // cm_msg(MINFO,"reading","nreads: %d, bk_size %d \n",nreads, bk_size(pevent));
  return bk_size(pevent);
}

//============================================================================

//Write the diagnostics

INT read_diagnostics_event (char *pevent, INT off) {

  //----------------------------------------------------------------------------

  double scaler_refresh = 10.0; //in seconds

  bk_init( pevent);
  
  gettimeofday(&timevalue,NULL);
  
  void *tdata;
  //Write time of day to file 
  bk_create(pevent, "TIME", TID_STRUCT, &tdata);
  memcpy(tdata, &timevalue,sizeof(timevalue));
  bk_close(pevent,tdata+sizeof(timevalue));

  //Write rate data to file
  void *pdata;
  bk_create(pevent, "SCLR", TID_DWORD, &pdata);
  
  for(int boardnum=0; boardnum<nactiveboards; boardnum++) {
    Digitizer_Rates[boardnum] = Scaler_Totals[boardnum]/scaler_refresh;
    Scaler_Totals[boardnum] = 0;
    
    memcpy(pdata+boardnum*sizeof(Digitizer_Rates[boardnum]), &Digitizer_Rates[boardnum],sizeof(Digitizer_Rates[boardnum]));
  }
  bk_close(pevent,pdata+nactiveboards*sizeof(uint32_t));
  
  //Write Acquisition Status to File
  void *acqstatdata;
  bk_create(pevent, "ACQS", TID_DWORD, &acqstatdata);
  for(int boardnum=0; boardnum<nactiveboards; boardnum++) {
    memcpy(acqstatdata+boardnum*sizeof(Acquisition_Status[boardnum]), &Acquisition_Status[boardnum],sizeof(Acquisition_Status[boardnum]));
  }
  bk_close(pevent,acqstatdata+nactiveboards*sizeof(uint32_t));
  
  //Write Board Failure Status to File
  void *faildata;
  bk_create(pevent, "FAIL", TID_DWORD, &faildata);
  for(int boardnum=0; boardnum<nactiveboards; boardnum++) {
    memcpy(faildata+boardnum*sizeof(Failure_Status[boardnum]), &Failure_Status[boardnum],sizeof(Failure_Status[boardnum]));
  }
  bk_close(pevent,faildata+nactiveboards*sizeof(uint32_t));
  
  //Write Readout Status to File
  void *readoutdata;
  bk_create(pevent, "READ", TID_DWORD, &readoutdata);
  for(int boardnum=0; boardnum<nactiveboards; boardnum++) {
    memcpy(readoutdata+boardnum*sizeof(Readout_Status[boardnum]), &Readout_Status[boardnum],sizeof(Readout_Status[boardnum]));
  }
  bk_close(pevent,readoutdata+nactiveboards*sizeof(uint32_t));

  int tempcounter=0;
  //Write Register 0x8504n to File
  void *reg8504ndata;
  bk_create(pevent, "DIAG", TID_DWORD, &reg8504ndata);
  for(int boardnum=0; boardnum<nactiveboards; boardnum++) {
    for(int pairnum=0; pairnum<8; pairnum++) {
      memcpy(reg8504ndata+tempcounter*sizeof(Register_0x8504n[boardnum][pairnum]), &Register_0x8504n[boardnum][pairnum],sizeof(Register_0x8504n[boardnum][pairnum]));
      tempcounter++;
    }
  }
  bk_close(pevent,reg8504ndata+tempcounter*sizeof(uint32_t));

  tempcounter=0;
  //Write ADC temp data to file
  void *tempdata;
  bk_create(pevent, "TEMP", TID_WORD, &tempdata);
  
  for(int boardnum=0; boardnum<nactiveboards; boardnum++) {
    for(int channum=0; channum<MAXNCH; channum++) {
      memcpy(tempdata+tempcounter*sizeof(ADC_Temp[boardnum][channum]), &ADC_Temp[boardnum][channum],sizeof(ADC_Temp[boardnum][channum]));
      tempcounter++;
    }
  }  
  bk_close(pevent,tempdata+tempcounter*sizeof(uint16_t));


  tempcounter=0;
  //Write Channel Status data to file
  void *chstatusdata;
  bk_create(pevent, "CHST", TID_DWORD, &chstatusdata);
  
  for(int boardnum=0; boardnum<nactiveboards; boardnum++) {
    for(int channum=0; channum<MAXNCH; channum++) {
      memcpy(chstatusdata+tempcounter*sizeof(Channel_Status[boardnum][channum]), &Channel_Status[boardnum][channum],sizeof(Channel_Status[boardnum][channum]));
      tempcounter++;
    }
  }  
  bk_close(pevent,chstatusdata+tempcounter*sizeof(uint32_t));

  return bk_size( pevent);
}
