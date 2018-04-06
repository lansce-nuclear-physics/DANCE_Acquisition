//*********************************//
//*    Christopher J. Prokop      *//
//*    cprokop@lanl.gov           *//
//*    program_digitizer.h        *// 
//*    Last Edit: 04/06/18        *//  
//*********************************//

#ifndef PROGRAM_DIGITIZER_H
#define PROGRAM_DIGITIZER_H

#include "global.h"

int get_board_information(int *handle,int eye, HNDLE hDB, HNDLE *activeBoards, int ModType[], int ModCode[], int AMC_MajRev[],  int AMC_MinRev[], int NChannels[], int SerialNumber[] );

int program_general_board_registers(int *handle,int eye, HNDLE hDB, HNDLE *activeBoards,int *Modtype, int *ModCode, int *AMC_MajRev, int *NChannels);

int program_trigger_validation_registers(int *handle,int eye, HNDLE hDB, HNDLE *activeBoards, int *ModType, int *ModCode, int *AMC_MajRev, int *NChannels);

int program_channel_registers(int *handle,int eye, HNDLE hDB, HNDLE *activeBoards,int *Modtype, int *ModCode, int *AMC_MajRev, int *NChannels);

int program_group_registers(int *handle,int eye, HNDLE hDB, HNDLE *activeBoards,int *Modtype, int *ModCode, int *AMC_MajRev, int *NChannels);

#endif

