#ifndef VME_MODULES
  #define VME_MODULES

  #include <cstdint>
  #include "CAENVMElib.h"
  #include "v560.h"

  typedef struct {
    uint32_t baseaddr ;	    // Base Address
    CVAddressModifier AddrMode;    // Addressing Mode
    const int nchannels;     // Number of channels
  } vmeLoc;

  //Definitions for Scaler module V560
  static const vmeLoc sclr[] = {
    //base addr   Addr mode     Channels  
    { 0x00100000, cvA32_U_DATA, V560::channels }, // Ungated scaler	
    { 0x00200000, cvA32_U_DATA, V560::channels }  // Live gated scaler
  };

  #define n_sclr (sizeof(sclr)/sizeof(sclr[0]))
  #define N_SCLR (n_sclr * 16+3)

#endif
