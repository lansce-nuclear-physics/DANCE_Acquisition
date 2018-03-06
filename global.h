//*********************************//
//*    Christopher J. Prokop      *//
//*    cprokop@lanl.gov           *//
//*    global.h                   *// 
//*    Last Edit: 03/06/18        *//  
//*********************************//

#ifndef GLOBAL_H
#define GLOBAL_H

//MIDAS includes
#include "/opt64/midas/pro/include/midas.h"
#include "/opt64/midas/pro/include/mcstd.h"

// The following define must be set to the actual number of connected boards
// This number needs to correspond to the value in the 
#define MAXNB   14

//MaxNChannels for the digitizers (this probably shouldnt change much)
#define MAXNCH 16

//Number of bits of the digitizer
#define MAXNBITS 14

#endif
