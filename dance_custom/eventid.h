#ifndef EVENTIDH
  #define EVENTIDH

  #define DIGIT_EVENTID  1
  #define SCALER_EVENTID   2
  #define HV_EVENTID  3
  //
  #define CAMAC_EVENTID 4
  // We define the VME_EVENTID the same as CAMAC.  
  // Not sure this is smart--fortunately, they don't go into the 
  // data stream at this time.
  #define VME_EVENTID 4

  #define NTP_EVENTID 5
  #define SMART_EVENTID 6
  #define ELOG_EVENTID 7

#endif
