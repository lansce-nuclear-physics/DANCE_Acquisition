/********************************************************************
  
  midas frontend for dance vme control
  This routine is used for reading DANCE scalers as well as I/O
  register.  Also, it handled the event "timestamps" for all frontends

  It was inherited from the frontend_camac code before the upgrade to
  VME.

  2 Sept. 2016--ajc
    We removed camac from the loop, so we now change the optical link
    to match the dancedaq A3818

*********************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <iostream>
#include "unistd.h"

#include "midas.h"
#include "mcstd.h"
#include "eventid.h"
#include "vme_modules.h"

#include "CAENVMEtypes.h"
#include "CAENVMElib.h"
#include "v560.h"

/* ---------- *
 * Prototypes *
 * ---------- */

extern "C" {
  INT frontend_init();
  INT frontend_exit();
  INT begin_of_run( INT run_number, char *error );
  INT end_of_run( INT run_number, char *error );
  INT pause_run( INT run_number, char *error );
  INT resume_run( INT run_number, char *error );
  INT frontend_loop();
}

/* ---------------------- *
 * Midas Global Variables *
 * ---------------------- */

/* The frontend name */
const char	*frontend_name		= "frontend_vme";

/* The frontend file name, DON'T CHANGE IT */
const char	*frontend_file_name	= __FILE__;	// don't change

/* frontend_loop is called periodically if this variable is TRUE */
BOOL	 frontend_call_loop	= FALSE;

/* A frontend status page is displayed with this frequency in ms */
INT	 display_period		= 1000;	// in ms

/* Maximum event size produced by this frontend */
INT	 max_event_size		= MAX_EVENT_SIZE;

/* maximum event size for fragmented events (EQ_FRAGMENTED) */
INT	 max_event_size_frag	= (MAX_EVENT_SIZE / 16);

/* Buffer size to hold events */
INT	 event_buffer_size	= DEFAULT_EVENT_BUFFER_SIZE;

/* Global ODB variables */
HNDLE	 hDB;
RUNINFO  runinfo;
int status;
INT eventCounter = 0;

// -----------------------------------------------------
// Annonymous Namespace declarations for frontend_vme   
// -----------------------------------------------------

namespace {
  // VME specific stuff
  CVBoardTypes VMEBoard = cvV2718;
  short Link = 7;
  short Device = 0;
  INT VMEHndl;

  // Midas-like things
  INT read_scaler_event( char *pevent, INT off );
  int Count;
};

/* ----------------- *
 * Setup ODB entries *
 * ----------------- */

/* -------------- *
 * Equipment list *
 * -------------- */
EQUIPMENT equipment[] = {

  { "DANCE_Scalers",           // equipment name
    { SCALER_EVENTID,         // event ID
      0,                      // trigger mask
      "SYSTEM",               // event buffer
      EQ_PERIODIC,            // equipment type
      0,                      // event source
      "MIDAS",                // format
      TRUE,                   // enabled
      RO_RUNNING |
      RO_TRANSITIONS,       // when to read, omit RO_ODB
      60000,                  // readout period ms
      0,                      // stop run after this event limit
      0,                      // number of subevents
      1,                      // log history
      "", "", "",
    },
    read_scaler_event,  // readout routine
  },
  { "" }

};


// ============================================================================ 
// ============================================================================ 
extern "C" INT frontend_init(){

  HNDLE hKey;
  int size;
  int data;

  RUNINFO_STR (runinfo_str);

  /* --------------------------------------------------------------------------- */

  // Get handle to ODB for this experiment //
  if ( cm_get_experiment_database( &hDB, NULL ) != CM_SUCCESS ) 
    {
      cm_msg( MERROR, "frontend_init",
	      " Failed to get ODB handle for experiment, EXITING " );
      sleep(2);
      return 0;
    }
  
  // Set start/stop priorities for this frontend 
  //  cm_set_transition_sequence(TR_START, 600);
  cm_set_transition_sequence(TR_STOP,  250);
  
  // Create runinfo if needed, and map to it 
  status = db_create_record( hDB, 0, "/Runinfo", strcomb(runinfo_str));
  if ( status != DB_SUCCESS && status != DB_OPEN_RECORD ) 
    {
      cm_msg( MERROR, "frontend_init",
	      " Failed to create record \"/Runinfo\": %i, EXITING ",
	      status );
      sleep(2);
      return 0;
    }
  
  if ( db_find_key( hDB, 0, "Runinfo", &hKey ) != DB_SUCCESS )
    {
      cm_msg( MERROR, "frontend_init",
	      " Cannot find key \"/Runinfo\" in ODB, EXITING ");
      sleep(2);
      return 0;
    }

  if ( db_open_record( hDB, hKey, &runinfo, sizeof(runinfo),
                       MODE_READ, NULL, NULL ) != DB_SUCCESS ) 
    {
      cm_msg( MERROR, "frontend_init",
	      " Cannot open \"/Runinfo\" tree in ODB, EXITING ");
      sleep(2);
      return 0;
    }


  // VME Initialization //
  if ( CAENVME_Init( VMEBoard, Link, Device, &VMEHndl ) != cvSuccess )
    {
      cm_msg (MERROR, "FE_vme", "Error initializing VME controller" );
      return 0;
    }
 
  // Initialize V560N scaler(s)
  uint16_t d16=0x0000;
  uint32_t d32=0x0000;

  for ( int i=0; i < n_sclr; ++i)
    {
      if ( CAENVME_WriteCycle( VMEHndl, sclr[i].baseaddr + V560::clear,
			       &d16, sclr[i].AddrMode, cvD16 )
	   != cvSuccess)
	{
	  cm_msg( MERROR, "FE_vme", "Failed to clear scaler %d with address %x",
		  i, sclr[i].baseaddr);
	  return 0;
	}
    }

  return SUCCESS;

}
/* --------------------------------------------------------------------------- */


// ============================================================================
// ============================================================================

extern "C" INT frontend_exit() {
  cm_disconnect_experiment();
  return SUCCESS;
}
/* --------------------------------------------------------------------------- */


// ============================================================================
// ============================================================================
extern "C" INT begin_of_run ( INT run_number, char *error ) {

  int i, size;
  int data;

  int status;
  /* --------------------------------------------------------------------------- */

  cm_msg( MINFO, "begin_of_run", " Start of Run %i ", run_number );

  // First we deal with the scalers, which are simple

  // Clear and reset all scalers
  
  // Loop over scaler modules defined in sclr[] array
  for ( i = 0; i < n_sclr; ++i ) {
    status = CAENVME_ReadCycle( VMEHndl, sclr[i].baseaddr + V560::clear, &data,
                                sclr[i].AddrMode, cvD16);
    if ( status != cvSuccess )
      cm_msg( MERROR, "FE_vme", 
              "Unable to clear scaler %d with address %x, Error code: %d",
              i, sclr[i].baseaddr, status );
    status = CAENVME_ReadCycle( VMEHndl, sclr[i].baseaddr + V560::reset_veto, &data,
                                sclr[i].AddrMode, cvD16);
    if ( status != cvSuccess )
      cm_msg( MERROR, "FE_vme", 
              "Unable to reset VME veto on scaler %d with address %x, Error code: %d",
              i, sclr[i].baseaddr, status );
  }

  cm_msg( MINFO, "begin_of_run", " Run %i started ", run_number );

  return SUCCESS;

}
/* --------------------------------------------------------------------------- */


// ============================================================================
// ============================================================================
extern "C" INT resume_run( INT run_number, char *error )
{
  return SUCCESS;
}
/* --------------------------------------------------------------------------- */


// ============================================================================
// ============================================================================
extern "C" INT end_of_run( INT run_number, char *error ) {

  pause_run( run_number, error );

  // cm_msg( MINFO, "FE_vme", " Run %i ended ", run_number );
  // std::cout << "Leave end_of_run" << std::endl;

  return SUCCESS;
}
/* --------------------------------------------------------------------------- */


// ============================================================================
// ============================================================================
extern "C" INT pause_run( INT run_number, char *error ) {

  // cm_msg( MINFO, "pause_run", " Enter Pause Run %i", run_number );
  // std::cout << "Enter pause_run" << std::endl;

  cm_msg( MINFO, "pause_run", " Paused Run %i", run_number );
  std::cout << " Leave pause_run" << std::endl;

  return SUCCESS;
}
/* --------------------------------------------------------------------------- */


// ============================================================================
// if frontend_call_loop is true, this routine gets called when
// the frontend is idle or once between every event
// ============================================================================

extern "C" INT frontend_loop() {

  return SUCCESS;
}
/* --------------------------------------------------------------------------- */

// ============================================================================
// Polling routine for events. Returns TRUE if event
// is available. If test equals TRUE, don't return. The test
// flag is used to time the polling
// Runs for the "LAM" Equipment...
// We keep for now in case midas expects a poll_event
// ============================================================================
extern "C" INT poll_event( INT source, INT count, BOOL test ) {

  return SUCCESS;

}
/* --------------------------------------------------------------------------- */


// ============================================================================
// ============================================================================
extern "C" INT interrupt_configure( INT cmd, INT source, PTYPE adr ) {

  return SUCCESS;
}
/* --------------------------------------------------------------------------- */


namespace {

  // ============================================================================
  // ============================================================================
  INT read_scaler_event( char *pevent, INT off ) 
  {

    DWORD *pdata, *mltm;
    float *rdata;
    DWORD *pdataOrig;
    DWORD time;
    int status;
    static DWORD old_scaler_array[ N_SCLR ];
    static DWORD old_mltm;

    // --------------------------------------------------------------------------- 

    bk_init32( pevent );

    bk_create( pevent, "MLTM", TID_DWORD, &mltm );
    *mltm = ss_millitime();
    bk_close( pevent, mltm + 1 );

    if ( runinfo.state == STATE_RUNNING ) 
      {
	bk_create( pevent, "SCLR", TID_DWORD, &pdata );
	bk_close( pevent, pdata + N_SCLR );
	bk_create( pevent, "RATE", TID_FLOAT, &rdata );
	bk_close( pevent, rdata + N_SCLR );

	// we need to read old values to get at rates
	DWORD *old_scaler = old_scaler_array;

	// read scaler bank 
	// Loop over scaler modules defined in sclr[] array */
	for ( int i = 0; i < n_sclr ; ++i ) 
	  {
	    // Loop over scaler channels in a modules as defined in sclr[]
	    for ( int chan = 0; chan < sclr[i].nchannels; ++chan ) 
	      {
		status = CAENVME_ReadCycle( VMEHndl, sclr[i].baseaddr + V560::read[chan], 
					    pdata, sclr[i].AddrMode, cvD32 );
		if ( status != cvSuccess )
		  cm_msg( MERROR, "FE_vme", "Failed to read Scaler: %d Channel %d with Error: %d",
			  i, chan, status );

		*rdata = (*pdata - *old_scaler)/( (float)( *mltm - old_mltm + 1.e-9) / 1000. );
		*old_scaler = *pdata;
		++pdata;
		++old_scaler;
		++rdata;
	      }
	  }
      } 
    else
      {
	for ( int i = 0; i < N_SCLR; ++i )
	  old_scaler_array[ i ] = 0;
      }

    old_mltm = *mltm; 

    return bk_size( pevent );

  }
  /* --------------------------------------------------------------------------- */

}; 
