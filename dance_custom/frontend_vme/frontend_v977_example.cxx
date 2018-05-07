/********************************************************************
  
  This is most of an example of how to write a frontend using the v977
  I/O register.  It was taken from the old DANCE (acqiris-based) code
  and all of the non-v977 parts were cut out.  So it may not be perfect
  but the concepts work.  Take special note of hor oreg_belief is used
  to preserve knowledge of the output register.

*********************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <iostream>
#include "unistd.h"

#include "midas.h"
#include "mcstd.h"
//#include "experim.h"
//#include "camlib.h"
#include "eventid.h"
//#include "camac_modules.h"
#include "vme_modules.h"

#include "CAENVMEtypes.h"
#include "CAENVMElib.h"
#include "v977.h"

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

//#define MAX_EVENT_SIZE (128*1024)

/* The frontend name */
const char	*frontend_name		= "FE_vme";

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
HNDLE	 hDB
RUNINFO  runinfo;
int	 status;
INT	 eventCounter = 0;

// -----------------------------------------------------
// Annonymous Namespace declarations for frontend_vme   
// -----------------------------------------------------

namespace {
  // VME specific stuff
  CVBoardTypes VMEBoard = cvV2718;
  short Link = 0;
  short Device = 0;
  INT VMEHndl;
  uint16_t oreg_belief =0x0000;

  // Midas-like things
  INT read_vme( char *pevent, INT off );
  int Count;
};

 /* ----------------- *
  * Setup ODB entries *
  * ----------------- */

 /* -------------- *
  * Equipment list *
  * -------------- */
EQUIPMENT equipment[] = {

  { "LAM",                      // equipment name
    { VME_EVENTID, 0,           // event ID, trigger mask
      "VME",                    // event buffer  --Used to be CAMAC--should there be changes elsewhere?
      EQ_POLLED,                // equipment type
      0,                        // event source
      "MIDAS",                  // format
      TRUE,                     // enabled
      RO_RUNNING,               // read only when running, omit RO_ODB
      50,                       // polling interval in ms
      0,                        // stop run after this event limit
      0,                        // number of subevents
      0,                        // history logging
      "", "", "",
    },
    read_vme,                   // readout routine
  },
  { "" }
};


// ============================================================================ 
// ============================================================================ 
extern "C" INT frontend_init(){

  HNDLE	hKey;
  int size;
  int data;

  int iMdl, iSpicket;

  RUNINFO_STR (runinfo_str);
  EXP_EDIT_STR (editdefined_str);

/* --------------------------------------------------------------------------- */

 // Get handle to ODB for this experiment //
    if ( cm_get_experiment_database( &hDB, NULL ) != CM_SUCCESS ) {
	cm_msg( MERROR, "frontend_init",
	      " Failed to get ODB handle for experiment, EXITING " );
	sleep(2);
	return 0;
    }

 // Set start/stop priorities for this frontend //
    cm_set_transition_sequence(TR_STOP,  250);

    /*
     * start questions to set run time parameters
     */

    db_create_record( hDB, 0,
                      "/Experiment/Edit On Start", strcomb(editdefined_str));

 // Create runinfo if needed, and map to it //
    status = db_create_record( hDB, 0, "/Runinfo", strcomb(runinfo_str));
    if ( status != DB_SUCCESS && status != DB_OPEN_RECORD ) {
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
                         MODE_READ, NULL, NULL ) != DB_SUCCESS ) {
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
 
    // Initialize V977 I/O register(s)
    uint16_t d16=0x0000;
    uint32_t d32=0x0000;

    for ( int i=0; i < n_ioreg; ++i)
    {
      // First we reset the module to defaults
      if (CAENVME_WriteCycle( VMEHndl, ioreg[i].baseaddr + V977::soft_reset,
                             &d16, ioreg[i].AddrMode, cvD16 )
           != cvSuccess)
      {
        cm_msg( MERROR, "FE_vme", "Failed to reset ioreg %d with address %x",
                i, ioreg[i].baseaddr);
        return 0;
      }

      // Now we set the control register to operate in the appropriate
      // mode, ie, io register, gate mask disabled, all outputs masked
      d16 = ( 0x0000 | 0x0002 | 0x0004 );
      if (CAENVME_WriteCycle( VMEHndl, ioreg[i].baseaddr + V977::control,
                             &d16, ioreg[i].AddrMode, cvD16 )
           != cvSuccess)
      {
        cm_msg( MERROR, "FE_vme", "Failed to set control register on ioreg %d with address %x",
                i, ioreg[i].baseaddr);
        return 0;
      }

      // Now we mask the individual inputs so that we only 
      // listen for inputs on the low bits, ie, channels 0-7
      // for channels 8-15, the input can be set via an iset
      d16 = 0xFF00;
      if (CAENVME_WriteCycle( VMEHndl, ioreg[i].baseaddr + V977::imask,
                             &d16, ioreg[i].AddrMode, cvD16 )
           != cvSuccess)
      {
        cm_msg( MERROR, "FE_vme", "Failed to set imask on ioreg %d with address %x",
                i, ioreg[i].baseaddr);
        return 0;
      }


      // Now we mask the individual outputs so that all channels can only be 
      // changed via an oset.
      d16 = 0xFFFF;
      if (CAENVME_WriteCycle( VMEHndl, ioreg[i].baseaddr + V977::omask,
                             &d16, ioreg[i].AddrMode, cvD16 )
           != cvSuccess)
      {
        cm_msg( MERROR, "FE_vme", "Failed to set omask on ioreg %d with address %x",
                i, ioreg[i].baseaddr);
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

  uint16_t bit[] = { 0x0001, 0x0002, 0x0004, 0x0008,
                     0x0010, 0x0020, 0x0040, 0x0080,
                     0x0100, 0x0200, 0x0400, 0x0800,
                     0x1000, 0x2000, 0x4000, 0x8000 };
  int i, size;
  int data;
  uint16_t d16;

  int status;
/* --------------------------------------------------------------------------- */

  cm_msg( MINFO, "begin_of_run", " Start of Run %i ", run_number );

  // Now we deal with the I/O Register

  // First we clear all of the inputs with a read & clear
  if ( CAENVME_ReadCycle( VMEHndl, ioreg[0].baseaddr +V977::singleh_readclear,
                          &d16, ioreg[0].AddrMode, cvD16 )
       != cvSuccess )
  {
    cm_msg( MERROR, "FE_vme", "Failed to read and clear inputs on ioreg %d with address %x",
            0, ioreg[0].baseaddr);
    return 0;

  }

  // Now we clear the outputs
  d16 = 0x0000;
  if ( CAENVME_WriteCycle( VMEHndl, ioreg[0].baseaddr + V977::clear,
                           &d16, ioreg[0].AddrMode, cvD16 )
       != cvSuccess )
  {
    cm_msg( MERROR, "FE_vme", "Failed to clear outputs on ioreg %d with address %x",
            0, ioreg[0].baseaddr);
    return 0;
  }
  else
  {
    // we start with a clean oreg_belief as we just cleared it
    oreg_belief = 0x0000;
  }
  // Get desired run mode from ODB   
  // Output is on bit 8 of OUTREG    
  size = sizeof(cMode);
  status = db_get_data( hDB, cModeKey, &cMode, &size, TID_BOOL );
  size = sizeof(sMode);
  status = db_get_data( hDB, sModeKey, &sMode, &size, TID_BOOL );
  if ( ( cMode && sMode ) || ( !cMode && !sMode ) ) 
  {
    cm_msg( MERROR, "begin_of_run",
            " Invalid Run Mode options... Defaulting to Continuous Mode " );
    cMode = TRUE;
    sMode = FALSE;
  }

  // Set Mode bit in OUTREG (bit 11)
  if ( cMode ) 
  {
    // This should ensure d16 has bit[11] true (continuous mode)
    oreg_belief |= bit[ 11 ];
  } 
  else 
  {
    // This should ensure d16 has bit[11] false
    oreg_belief = oreg_belief & ( ~ bit[11] ) ;
  }

  // Get desired looking time from ODB  
  // Values identify one unit on a     
  // P/S 794 Quad G/D Generator        
  // Output is on bits 9 - 12 of OUTREG
  size = sizeof(looking_time);
  status = db_get_data( hDB, lTimeKey, &looking_time, &size, TID_SHORT );
  if ( cMode ) 
  {
    if ( looking_time < 1 || looking_time > 1 ) 
    {
      cm_msg( MERROR, "begin_of_run",
              " Invalid Looking Time Option (%i) For Continuous Mode... Defaulting To Option 1 ",
              looking_time );
      looking_time = 1;
    }
  }
  if ( sMode ) 
  {
    // valid looking times are 
    // 1 (100 us)
    // 2 (2 ms)
    // 3 (14 ms)
    if ( looking_time < 1 || looking_time > 3 ) 
    {
      cm_msg( MERROR, "begin_of_run",
              " Invalid Looking Time Option (%i) For Sequential Mode... Defaulting To Option 3 ",
              looking_time );
      looking_time = 3;
    }
  }
  // Clear all LT bits d16 (bits 12-15)
  oreg_belief = oreg_belief & ( ~( bit[12] | bit[13] | bit[14] | bit[15]) );
    
  // Set desired LT bit in d16
  oreg_belief |= bit[ 12 + ( looking_time - 1 ) ];
  
  // I am unclear on the operation here.  The cable is connected to bit 2 on the 
  // camac output register, but from above, it appears that the bit is _only_
  // set if the delay is > 0.  So the code below will set the bit if uncommented.
  // From pieces later in the code (poll_event and read_vme), 
  // it seems this is needed.  So we enable it for now.
  oreg_belief |= bit[10];

  // Now we write the present output pattern to the register
  if ( CAENVME_WriteCycle( VMEHndl, ioreg[0].baseaddr + V977::oset,
                           &oreg_belief, ioreg[0].AddrMode, cvD16 )
       != cvSuccess )
  {
    cm_msg( MERROR, "FE_vme", "Failed to set output register on ioreg %d with address %x and data value %04x",
            0, ioreg[0].baseaddr, oreg_belief);
    return 0;
  }


  resume_run( run_number, error );

  eventCounter = 0;

  // Start of Run, set bit 8 in OUTREG (used to be bit 0)
  // This is the Run in Progress bit.
  oreg_belief |= bit[ 8 ];

  // Now we write the full output pattern to the register
  if ( CAENVME_WriteCycle( VMEHndl, ioreg[0].baseaddr + V977::oset,
                           &oreg_belief, ioreg[0].AddrMode, cvD16 )
       != cvSuccess )
  {
    cm_msg( MERROR, "FE_vme", "Failed to set output register on ioreg %d with address %x and data value %04x",
            0, ioreg[0].baseaddr, oreg_belief);
    return 0;
  }


  cm_msg( MINFO, "begin_of_run", " Run %i started ", run_number );

  return SUCCESS;

}
/* --------------------------------------------------------------------------- */


// ============================================================================
// ============================================================================
extern "C" INT resume_run( INT run_number, char *error )
{
  short	alive[16], nalive, armed[16], narmed;
  short	spill, allow, reset_trigger, force_rearm;
  int		size, i;
  uint16_t bit[] = { 0x0001, 0x0002, 0x0004, 0x0008,
                     0x0010, 0x0020, 0x0040, 0x0080,
                     0x0100, 0x0200, 0x0400, 0x0800,
                     0x1000, 0x2000, 0x4000, 0x8000 };
  uint16_t d16;
/* --------------------------------------------------------------------------- */

  // Wait for all digitizers to arm 
      // Set Computer Busy bit to true (bit[9])
      oreg_belief |= bit[9];
      if ( CAENVME_WriteCycle( VMEHndl, ioreg[0].baseaddr + V977::oset,
                              &oreg_belief, ioreg[0].AddrMode, cvD16 )
           != cvSuccess )
      {
        cm_msg( MERROR, "FE_vme", "Failed to set input pattern on ioreg %d with address %x to %04x",
                0, ioreg[0].baseaddr, oreg_belief );
        return 0;
      }
      return SUCCESS;

  cm_msg( MERROR, "resume_of_run",
          " Failed to arm all digitizers at begin of run. " );

  return 0;
}
/* --------------------------------------------------------------------------- */


// ============================================================================
// ============================================================================
extern "C" INT end_of_run( INT run_number, char *error ) {

  int   size;
  uint16_t bit[] = { 0x0001, 0x0002, 0x0004, 0x0008,
                     0x0010, 0x0020, 0x0040, 0x0080,
                     0x0100, 0x0200, 0x0400, 0x0800,
                     0x1000, 0x2000, 0x4000, 0x8000 };
  uint16_t d16 = 0x0000;


  // We do a read/clear:  This clears any hits in the input register

  if ( CAENVME_ReadCycle( VMEHndl, ioreg[0].baseaddr + V977::singleh_readclear,
                          &d16, ioreg[0].AddrMode, cvD16 )
       != cvSuccess )
  {
    cm_msg( MERROR, "FE_vme", "Failed to read present input status on ioreg %d with address %x",
            0, ioreg[0].baseaddr);
    return 0;
  }
  
  // End of Run--clear Run in Progress bit (8) in OUTPUT Register
  // Clear Run in Progress bit (bit[8])
  oreg_belief = oreg_belief & ( ~( bit[8] ) );

  // Now write everything back to the input pattern.  
  if ( CAENVME_WriteCycle( VMEHndl, ioreg[0].baseaddr + V977::oset,
                           &oreg_belief, ioreg[0].AddrMode, cvD16 )
       != cvSuccess )
  {
    cm_msg( MERROR, "FE_vme", "Failed to set input pattern on ioreg %d with address %x to %04x",
            0, ioreg[0].baseaddr, oreg_belief );
    return 0;
  }

    pause_run( run_number, error );

    return SUCCESS;
}
/* --------------------------------------------------------------------------- */


// ============================================================================
// ============================================================================
extern "C" INT pause_run( INT run_number, char *error ) {

  short  spill, allow, reset_trigger, force_rearm;
  int  size;
  uint16_t bit[] = { 0x0001, 0x0002, 0x0004, 0x0008,
                     0x0010, 0x0020, 0x0040, 0x0080,
                     0x0100, 0x0200, 0x0400, 0x0800,
                     0x1000, 0x2000, 0x4000, 0x8000 };
  uint16_t d16;

  // Clear any hits in input register
  if ( CAENVME_ReadCycle( VMEHndl, ioreg[0].baseaddr + V977::singleh_readclear,
                          &d16, ioreg[0].AddrMode, cvD16 )
       != cvSuccess )
  {
    cm_msg( MERROR, "FE_vme", "Failed to read present input status on ioreg %d with address %x",
            0, ioreg[0].baseaddr);
    return 0;
  }

  // Pause of Run--clear CPU Busy bit (9) in OUTPUT Register
  // Clear the CPU Busy bit (bit[9])
  oreg_belief = oreg_belief & ( ~( bit[9] ) );

  if ( CAENVME_WriteCycle( VMEHndl, ioreg[0].baseaddr + V977::oset,
                           &oreg_belief, ioreg[0].AddrMode, cvD16 )
       != cvSuccess )
  {
    cm_msg( MERROR, "FE_vme", "Failed to set input pattern on ioreg %d with address %x to %04x",
            0, ioreg[0].baseaddr, oreg_belief );
    return 0;
  }

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
// ============================================================================
extern "C" INT poll_event( INT source, INT count, BOOL test ) {

  DWORD lam;
  uint16_t bit[] = { 0x0001, 0x0002, 0x0004, 0x0008,
                     0x0010, 0x0020, 0x0040, 0x0080,
                     0x0100, 0x0200, 0x0400, 0x0800,
                     0x1000, 0x2000, 0x4000, 0x8000 };

  uint16_t d16 = 0x0000;
  short reset_trigger;
  int i, size;

// ---------------------------------------------------------------------------

  // Keep checking LAM pattern until we get the End_of_Beam
  // Gate (INREG input 2) then inhibit the triggers and set
  // ODB variable for Acq frontends to read out the digitizers

  // cm_msg( MERROR, "poll_event", "In Poll Event looking for End Of Spill, Count =%d", count );

  Count = count/10;  // not sure what this scaling should be...
  // cm_msg( MERROR, "poll_event", "!test, d16 = %04x, count = %d", d16, count );

  for ( i = 0; i < count; ++i ) 
  {
    // End of beam gate is at INREG bit[1] //
    if ( CAENVME_ReadCycle( VMEHndl, ioreg[0].baseaddr + V977::singleh_readclear,
                            &d16, ioreg[0].AddrMode, cvD16 )
         != cvSuccess )
    {
      cm_msg( MERROR, "FE_vme", "Failed to read present input status on ioreg %d with address %x",
              0, ioreg[0].baseaddr);
      return 0;
    }

    // cm_msg( MERROR, "poll_event", "!test, d16 = %04x, count = %d", d16, count );

    if ( ( !test ) && ( d16 & bit[1] ) ) 
    {
      // cm_msg( MERROR, "poll_event", "!test, d16 = %04x, count = %d", d16, count );
      // cm_msg( MERROR, "poll_event", "!test, satisfied IF d16 = %04x", d16 );
      // Reached end of looking time, clear CPU Busy OUTREG (bit[9])
      // - inhibit digitizer triggers //
        
        
      // Clear CPU busy bit (bit[9])
      oreg_belief = oreg_belief & ( ~(bit[9]) );

      // Now we write the pattern back to the high bits in the IO register
      if ( CAENVME_WriteCycle( VMEHndl, ioreg[0].baseaddr + V977::oset,
                               &oreg_belief, ioreg[0].AddrMode, cvD16 )
           != cvSuccess )
      {
        cm_msg( MERROR, "FE_vme", "Failed to set output pattern on ioreg %d with address %x to %04x",
                0, ioreg[0].baseaddr, oreg_belief );
        return 0;
      }

      return SUCCESS;
    }
  }

  // If we get here then something has gone wrong. //
  // But why is not finding an event bad?
  // cm_msg(MERROR, "poll_event", " Failed to catch LAM from INREG. " );

  // This needs to be recoded with an explicit timer

  // Check for reset flag //

  for ( i = 0; i < Count; ++i ) 
  {
    size = sizeof(reset_trigger);
    status = db_get_data( hDB, resetKey, &reset_trigger, &size, TID_SHORT );
    if ( reset_trigger ) 
    {
      cm_msg( MERROR, "poll_event",
		  " ODB flag \"reset_trigger\" set, setting ODB flag \"force_rearm\" " );
      status = ResetTrigger();
      return 0;
    }
  }


  return 0;

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
  INT read_vme( char *pevent, INT off ) 
    {

    short alive[16], nalive, armed[16], narmed;
    short spill, allow, reset_trigger;
    uint16_t bit[] = { 0x0001, 0x0002, 0x0004, 0x0008,
                       0x0010, 0x0020, 0x0040, 0x0080,
                       0x0100, 0x0200, 0x0400, 0x0800,
                       0x1000, 0x2000, 0x4000, 0x8000 };
    int size;
    int count = 2000;
    int i, j, digit_check;
    uint16_t d16;

  /* --------------------------------------------------------------------------- */

    eventCounter++;

    // should only be here if got a hit from poll_event, which already 
    // cleared the input register, but we're paranoid, so we make sure...
    if ( CAENVME_ReadCycle( VMEHndl, ioreg[0].baseaddr + V977::singleh_readclear,
                            &d16, ioreg[0].AddrMode, cvD16 )
         != cvSuccess )
    {
      cm_msg( MERROR, "read_vme", "Failed to read and clear present input status on ioreg %d with address %x",
              0, ioreg[0].baseaddr);
      return 0;
    }


        // Now we write the output pattern back the IO register
        if ( CAENVME_WriteCycle( VMEHndl, ioreg[0].baseaddr + V977::oset,
                                 &oreg_belief, ioreg[0].AddrMode, cvD16 )
             != cvSuccess )
        {
          cm_msg( MERROR, "read_vme", "Failed to set output pattern on ioreg %d with address %x to %04x",
                  0, ioreg[0].baseaddr, oreg_belief );
          return 0;
        }


        // So I think this T0 inhibit business is important--but not sure where else it is 
        // managed.
        // it seems to send an edge, so I will do that.
        // Clear T0 inhibit 
        oreg_belief = oreg_belief & ( ~( bit[10] ) );
        
        // Now we write the output pattern back the IO register
        if ( CAENVME_WriteCycle( VMEHndl, ioreg[0].baseaddr + V977::oset,
                                 &oreg_belief, ioreg[0].AddrMode, cvD16 )
             != cvSuccess )
        {
          cm_msg( MERROR, "read_vme", "Failed to set output pattern on ioreg %d with address %x to %04x",
                  0, ioreg[0].baseaddr, oreg_belief );
          return 0;
        }

        oreg_belief |= bit[10];
        // Now we write the output pattern back the IO register
        if ( CAENVME_WriteCycle( VMEHndl, ioreg[0].baseaddr + V977::oset,
                                 &oreg_belief, ioreg[0].AddrMode, cvD16 )
             != cvSuccess )
        {
          cm_msg( MERROR, "read_vme", "Failed to set output pattern on ioreg %d with address %x to %04x",
                  0, ioreg[0].baseaddr, oreg_belief );
          return 0;
        }

        digit_check = 1;
        break;
      }
    }

    return 0;

  }
  // --------------------------------------------------------------------------- 

