//*********************************//
//*    Christopher J. Prokop      *//
//*    cprokop@lanl.gov           *//
//*    program_digitizer.cpp      *// 
//*    Last Edit: 03/06/18        *//  
//*********************************//

//File includes
#include "global.h"
#include "program_digitizer.h"

//C/C++ includes
#include "sys/types.h"
#include <sstream>
#include <fstream>
#include "experim.h"
#include <string.h>

// CAEN includes
#include "CAENDigitizer.h"
#include "CAENDigitizerType.h"


//Board information that doesnt get used by the frontend
int ROC_MinRev[MAXNB];               //ROC Minor Revision
int ROC_MajRev[MAXNB];               //ROC Major Revision
int DigitizerCode[MAXNB];            //This says whether its a 725 or 730
int FormFactorCode[MAXNB];           //This says whether its a V1,VX1,DT5,or N6
std::stringstream DigType[MAXNB];    //Digitizer Type comments


//Board register storage
uint32_t Board_0x8000[MAXNB];
//uint32_t Board_0x800C[MAXNB];
uint32_t Board_0x8100[MAXNB];
uint32_t Board_0x810C[MAXNB];
uint32_t Board_0x8110[MAXNB];
uint32_t Board_0x8118[MAXNB];
uint32_t Board_0x811C[MAXNB];
uint32_t Board_0x8138[MAXNB];
uint32_t Board_0x8144[MAXNB];
uint32_t Board_0x8170[MAXNB];
uint32_t Board_0x817C[MAXNB];
uint32_t Board_0x81A0[MAXNB];
uint32_t Board_0xEF00[MAXNB];

//Trigger registers
uint32_t Board_0x8180[MAXNB];
uint32_t Board_0x8184[MAXNB];
uint32_t Board_0x8188[MAXNB];
uint32_t Board_0x818C[MAXNB];
uint32_t Board_0x8190[MAXNB];
uint32_t Board_0x8194[MAXNB];
uint32_t Board_0x8198[MAXNB];
uint32_t Board_0x819C[MAXNB];

uint32_t Board_0x8120[MAXNB];        //Channel validation mask

//Channel Registers
uint32_t Board_0x1n28[MAXNB][MAXNCH];  
uint32_t Board_0x1n60[MAXNB][MAXNCH];  
uint32_t Board_0x1n6C[MAXNB][MAXNCH];  
uint32_t Board_0x1n98[MAXNB][MAXNCH];  
uint32_t Board_0x1n38[MAXNB][MAXNCH];  
uint32_t Board_0x1n20[MAXNB][MAXNCH];  
uint32_t Board_0x1n34[MAXNB][MAXNCH];  
uint32_t Board_0x1nD4[MAXNB][MAXNCH];  
uint32_t Board_0x1n74[MAXNB][MAXNCH];  
uint32_t Board_0x1n70[MAXNB][MAXNCH];  
uint32_t Board_0x1n80[MAXNB][MAXNCH];  
uint32_t Board_0x1n84[MAXNB][MAXNCH];  
uint32_t Board_0x1n64[MAXNB][MAXNCH];  
uint32_t Board_0x1n78[MAXNB][MAXNCH];  
uint32_t Board_0x1n7C[MAXNB][MAXNCH];  
uint32_t Board_0x1n44[MAXNB][MAXNCH];  
uint32_t Board_0x1n3C[MAXNB][MAXNCH];  
uint32_t Board_0x1nD8[MAXNB][MAXNCH];  
uint32_t Board_0x1n54[MAXNB][MAXNCH];  
uint32_t Board_0x1n5C[MAXNB][MAXNCH];  
uint32_t Board_0x1n58[MAXNB][MAXNCH];  

//NOTE1: The mallocs must be done AFTER digitizer's configuration!
CAEN_DGTZ_DPP_AcqMode_t interpret_dppacq_mode(const char *acqmode) {
  if (strcmp(acqmode,"CAEN_DGTZ_DPP_ACQ_MODE_Mixed") == 0) {
    return CAEN_DGTZ_DPP_ACQ_MODE_Mixed;
  }    
  else if (strcmp(acqmode,"CAEN_DGTZ_DPP_ACQ_MODE_List") == 0) {
    return CAEN_DGTZ_DPP_ACQ_MODE_List;
  }
  else if {strcmp(acqmode,"CAEN_DGTZ_DPP_ACQ_MODE_Oscilloscope") == 0) {
    return CAEN_DGTZ_DPP_ACQ_MODE_Oscilloscope;
  }
  else {
    cm_msg(MERROR,"interpret_connection","Could not interpret dppacqmode type %s\n", acqmode);
    exit(1);
  }
}

int get_board_information(int *handle,int eye, HNDLE hDB, HNDLE *activeBoards, int ModType[], int ModCode[], int AMC_MajRev[], int AMC_MinRev[], int NChannels[], int SerialNumber[]) {

  //return value of reading and writing to boards
  CAEN_DGTZ_ErrorCode ret;
  
  //address of the register to read and write to
  uint32_t address;     
  //value from the register
  uint32_t register_value;   

  //Checks on registers complying with documentation
  bool failure = false;
    
  //ODB path
  char buf[100];
  
  //Size of ODB variable
  int size;

  //General handle to the current ODB location
  HNDLE genHdl;
  
  //Get the Serial Number 
  address = 0xF080;
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&register_value);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0xF080, retval: %i  Exiting",eye,ret);
    return -1;
  }
  SerialNumber[eye] = register_value & 0xFF;
  address = 0xF084;
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&register_value);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0xF084, retval: %i  Exiting",eye,ret);
    return -1;
  }
  SerialNumber[eye] += register_value & 0xFF;

  //Get the Number of Channels
  address = 0x8140;
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&register_value);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x8140, retval: %i  Exiting",eye,ret);
    return -1;
  }
  NChannels[eye] = (register_value >> 16) & 0xFF;
    
  //Get the ROC information
  address = 0x8124;
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&register_value);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x8124, retval: %i  Exiting",eye,ret);
    return -1;
  }
  ROC_MinRev[eye] = register_value & 0xFF;
  ROC_MajRev[eye] = (register_value >> 8) & 0xFF;
    
  //Get the AMC information (Technically this exists for each channel but we dont do different firmware for different channels)
  address = 0x108C;
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&register_value);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x108C, retval: %i  Exiting",eye,ret);
    return -1;
  }
  AMC_MinRev[eye] = register_value & 0xFF;
  AMC_MajRev[eye] = (register_value >> 8) & 0xFF;
    
  //Get the digitizer family code
  address = 0xF030;
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&register_value);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0xF030, retval: %i  Exiting",eye,ret);
    return -1;
  }
  DigitizerCode[eye] = register_value & 0xFF;
    
  //Get the form factor
  address = 0xF034;
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&register_value);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0xF034, retval: %i  Exiting",eye,ret);
    return -1;
  }
  FormFactorCode[eye] = register_value & 0xFF;

  //Write the Serial Number
  sprintf(buf,"Digitizer_Information/Serial_Number",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_set_data(hDB,genHdl,&SerialNumber[eye],sizeof(SerialNumber[eye]),1,TID_INT);
  // cm_msg(MINFO,"frontend_init","Board %i serial number %i",eye,SerialNumber[eye]);
    
  //Write the Number of Channels
  sprintf(buf,"Digitizer_Information/NChannels",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_set_data(hDB,genHdl,&NChannels[eye],sizeof(NChannels[eye]),1,TID_INT);
  //  cm_msg(MINFO,"frontend_init","Board %i NChannels %i",eye,NChannels[eye]);

  //Write the AMC Major Version
  sprintf(buf,"Digitizer_Information/AMC_Major_Version",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_set_data(hDB,genHdl,&AMC_MajRev[eye],sizeof(AMC_MajRev[eye]),1,TID_INT);
    
  //Write the AMC Minor Version
  sprintf(buf,"Digitizer_Information/AMC_Minor_Version",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_set_data(hDB,genHdl,&AMC_MinRev[eye],sizeof(AMC_MinRev[eye]),1,TID_INT);
  // cm_msg(MINFO,"frontend_init","Board %i AMC Version %i.%i",eye,AMC_MajRev[eye],AMC_MinRev[eye]);

  //Write the ROC Major Version
  sprintf(buf,"Digitizer_Information/ROC_Major_Version",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_set_data(hDB,genHdl,&ROC_MajRev[eye],sizeof(ROC_MajRev[eye]),1,TID_INT);
    
  //Write the ROC Minor Version
  sprintf(buf,"Digitizer_Information/ROC_Minor_Version",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_set_data(hDB,genHdl,&ROC_MinRev[eye],sizeof(ROC_MinRev[eye]),1,TID_INT);
  // cm_msg(MINFO,"frontend_init","Board %i ROC Version %i.%i",eye,ROC_MajRev[eye],ROC_MinRev[eye]);

  //Clear the stringstream
  DigType[eye].str("");
    
  //Insert the form factor
  switch(FormFactorCode[eye]) {
  case 0x00:
    DigType[eye] << "V1";
    ModCode[eye] = 0;  //VME
    break;
  case 0x01:
    DigType[eye] << "VX1";
    ModCode[eye] = 1;  //VME X64
    break;
  case 0x02:
    DigType[eye] << "DT5";
    ModCode[eye] = 2;  //Desktop
    break;
  case 0x03:
    DigType[eye] << "N6";
    ModCode[eye] = 3;  //NIM
    break;
  }

  //Add on the module type
  switch(DigitizerCode[eye]) {
  case 0xF0:
    DigType[eye] << "725";
    ModType[eye] = 725;
    break;
  case 0xF1:
    DigType[eye] << "725B";
    ModType[eye] = 725;
    break;
  case 0xF2:
    DigType[eye] << "725C";
    ModType[eye] = 725;
    break;
  case 0xF3:
    DigType[eye] << "725D";
    ModType[eye] = 725;
    break;
  case 0xC0:
    DigType[eye] << "730";
    ModType[eye] = 730;
    break;
  case 0xC1:
    DigType[eye] << "730B";
    ModType[eye] = 730;
    break;
  case 0xC2:
    DigType[eye] << "730C";
    ModType[eye] = 730;
    break;
  case 0xC3:
    DigType[eye] << "730D";
    ModType[eye] = 730;
    break;
  }
    
  //Write the digitizer type to the ODB
  char modtypebuf[32];
  sprintf(modtypebuf,"%s",DigType[eye].str().c_str());   
  sprintf(buf,"Digitizer_Information/Type",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_set_data(hDB,genHdl,&modtypebuf,sizeof(modtypebuf),1,TID_STRING);
  // cm_msg(MINFO,"frontend_init","Board %i is a %s \n",eye,DigType[eye].str().c_str());

  DigType[eye] <<" #"<<SerialNumber[eye]<<" with DPP-";
    
  if(AMC_MajRev[eye] == 136) {
    DigType[eye] << "PSD";
  }
  if(AMC_MajRev[eye] == 139) {
    DigType[eye] << "PHA";
  }
  DigType[eye] << " firmware "<<AMC_MajRev[eye]<<"."<<AMC_MinRev[eye];
      
  char modcommentbuf[64];
  sprintf(modcommentbuf,"%s",DigType[eye].str().c_str());   
  sprintf(buf,"Comment",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_set_data(hDB,genHdl,&modcommentbuf,sizeof(modcommentbuf),1,TID_STRING);
  cm_msg(MINFO,"frontend_init","Board %i is %s \n",eye,DigType[eye].str().c_str());
    
  /* END OF DIGITIZER INFORMATION */
}


int program_general_board_registers(int *handle,int eye, HNDLE hDB, HNDLE *activeBoards, int *ModType, int *ModCode, int *AMC_MajRev, int *NChannels) {


  cm_msg(MINFO,"frontend_init","Board %i Programming General Board Registers Started",eye);

  //  std::ofstream out;
  //  out.open("Diagnostics.txt");

  //return value of reading and writing to boards
  CAEN_DGTZ_ErrorCode ret;
  
  //address of the register to read and write to
  uint32_t address;     
  
  //Checks on registers complying with documentation
  bool failure = false;
    
  //ODB path
  char buf[100];
  
  //Size of ODB variable
  int size;

  //General handle to the current ODB location
  HNDLE genHdl;

  //Acquisition Mode
  size = sizeof(buf);
  db_find_key(hDB,activeBoards[eye],"AcqMode",&genHdl);
  db_get_data(hDB,genHdl,buf,&size,TID_STRING);
  CAEN_DGTZ_DPP_AcqMode_t dpp_acq_mode = interpret_dppacq_mode(buf);
  cm_msg(MINFO,"General_Board_Registers","Board %d Setting ACQMode %s",eye,buf);
  ret = CAEN_DGTZ_SetDPPAcquisitionMode(handle[eye], (CAEN_DGTZ_DPP_AcqMode_t)dpp_acq_mode, CAEN_DGTZ_DPP_SAVE_PARAM_EnergyAndTime);

  if(ret) {
    cm_msg( MERROR, "frontend_init", "Board %i. cannot set DPP Acq Mode.",eye);
    return -1;
  }
  
  // 0x8000
  DWORD ODB_0x8000 = 0;
  size = sizeof(ODB_0x8000);
  sprintf(buf,"General_Board_Registers/Register_0x8000",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_get_data(hDB,genHdl,&ODB_0x8000,&size,TID_DWORD);
  //cm_msg(MINFO,"frontend_init","Board %i 0x8000 %lu from ODB",eye,ODB_0x8000);
    
  // out<<ODB_0x8000<<"\n";
  //Check to see if its ok to write to digitizer
  failure = false;
  //PHA
  if(AMC_MajRev[eye] == 139) {
    for(int jay=0; jay < 32; jay++) {
      if(jay == 3 || jay == 5 || jay == 6 || jay == 7 || jay == 9 || jay == 10) {
	if( ((ODB_0x8000 >> jay)  & 0x1) != 0 ) {
	  cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x8000 not 0 in ODB.",eye,jay);
	  failure = true;
	}
      }
      if(jay == 4 || jay == 8 || jay == 18 || jay ==19) {
	if( ((ODB_0x8000 >> jay)  & 0x1) != 1 ) {
	  cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x8000 not 1 in ODB.",eye,jay);
	  failure = true;
	}
      }
    }
  } 
    
  //PSD
  if(AMC_MajRev[eye] == 136) {
    for(int jay=0; jay < 32; jay++) {
      if(jay == 1 || jay == 3 || jay == 5 || jay == 6 || jay == 7 || jay == 9 || 
	 jay == 10 || jay == 14 || jay == 15 || jay == 20 || jay == 21 || jay == 22 ||
	 jay == 29 || jay == 30) {
	if( ((ODB_0x8000 >> jay)  & 0x1) != 0 ) {
	  cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x8000 not 0 in ODB.",eye,jay);
	  failure = true;
	}
      }
      if(jay == 4 || jay == 8 || jay == 18 || jay ==19) {
	if( ((ODB_0x8000 >> jay)  & 0x1) != 1 ) {
	  cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x8000 not 1 in ODB.",eye,jay);
	  failure = true;
	}
      }
    }
  } 
    
  if(failure) {
    cm_msg( MERROR, "frontend_init", "Board %i. Problem with 0x8000 register value in ODB.  Exiting",eye);
    return -1;
  }

  address = 0x8000;
  ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x8000);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to write 0x8000, retval: %i  Exiting",eye,ret);
    return -1;
  }
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x8000[eye]);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x8000, retval: %i  Exiting",eye,ret);
    return -1;
  }    
  //cm_msg(MINFO,"frontend_init","Board %i 0x8000 %lu from digitizer",eye,Board_0x8000[eye]);

  //Make sure the settings we think we have are really on the board
  if(Board_0x8000[eye] != ODB_0x8000) {
    cm_msg( MERROR, "frontend_init", ",Board %i. ODB and Board 0x8000 do not match!... Exiting ",eye);
    return -1;
  }
    
  /*
  // 0x800C
  DWORD ODB_0x800C = 0;
  size = sizeof(ODB_0x800C);
  sprintf(buf,"General_Board_Registers/Register_0x800C",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_get_data(hDB,genHdl,&ODB_0x800C,&size,TID_DWORD);
  //  cm_msg(MINFO,"frontend_init","Board %i 0x800C %lu from ODB",eye,ODB_0x800C);
    
  
  //Check to see if its ok to write to digitizer
  failure = false;
  //PHA and PSD are the same
  if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
    for(int jay=4; jay < 32; jay++) {
      if( ((ODB_0x800C >> jay)  & 0x1) != 0 ) {
	cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x800C not 0 in ODB.",eye,jay);
	failure = true;
      }
    }
  } 
    
  if(failure) {
    cm_msg( MERROR, "frontend_init", "Board %i. Problem with 0x800C register value in ODB.  Exiting",eye);
    return -1;
  }

  address = 0x800C;
  ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x800C);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to write 0x800C, retval: %i  Exiting",eye,ret);
    return -1;
  }    
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x800C[eye]);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x800C, retval: %i  Exiting",eye,ret);
    return -1;
  }    
  // cm_msg(MINFO,"frontend_init","Board %i 0x800C %i from digitizer",eye,Board_0x800C[eye]);

  //Make sure the settings we think we have are really on the board
  if(Board_0x800C[eye] != ODB_0x800C) {
    cm_msg( MERROR, "frontend_init", ",Board %i. ODB and Board 0x800C do not match!... Exiting ",eye);
    return -1;
  }
*/
    

  // 0x8100
  DWORD ODB_0x8100 = 0;
  size = sizeof(ODB_0x8100);
  sprintf(buf,"General_Board_Registers/Register_0x8100",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_get_data(hDB,genHdl,&ODB_0x8100,&size,TID_DWORD);
  //  cm_msg(MINFO,"frontend_init","Board %i 0x8100 %lu from ODB",eye,ODB_0x8100);
    
  //Check to see if its ok to write to digitizer
  failure = false;
  //PHA
  if(AMC_MajRev[eye] == 139) {
    for(int jay=0; jay < 32; jay++) {
      if(jay == 3 || jay == 4 || jay == 5 || jay == 7 || jay == 10 || jay == 11 || jay >= 13 || 
	 ((ModType[eye] == 2 || ModType[eye] == 3) && jay == 6) || 
	 ((ModType[eye] == 0 || ModType[eye] == 1) && (jay == 8 || jay == 9 || jay == 12))) {
	if( ((ODB_0x8100 >> jay)  & 0x1) != 0 ) {
	  cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x8100 not 0 in ODB.",eye,jay);
	  failure = true;
	}
      }
    }
  } 
    
  //PSD
  if(AMC_MajRev[eye] == 136) {
    for(int jay=0; jay < 32; jay++) {
      if(jay == 4 || jay == 5 || jay == 7 || jay == 10 || jay >= 12 ||
	 ((ModType[eye] == 2 || ModType[eye] == 3) && jay == 6) || 
	 ((ModType[eye] == 0 || ModType[eye] == 1) && (jay == 8 || jay == 9 || jay == 12))) {
	if( ((ODB_0x8100 >> jay)  & 0x1) != 0 ) {
	  cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x8100 not 0 in ODB.",eye,jay);
	  failure = true;
	}
      }
    }
  } 
  if(failure) {
    cm_msg( MERROR, "frontend_init", "Board %i. Problem with 0x8100 register value in ODB.  Exiting",eye);
    return -1;
  }

  address = 0x8100;
  ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x8100);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to write 0x8100, retval: %i  Exiting",eye,ret);
    return -1;
  }
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x8100[eye]);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x8100, retval: %i  Exiting",eye,ret);
    return -1;
  }    
  // cm_msg(MINFO,"frontend_init","Board %i 0x8100 %lu from digitizer",eye,Board_0x8100[eye]);

  //Make sure the settings we think we have are really on the board
  if(Board_0x8100[eye] != ODB_0x8100) {
    cm_msg( MERROR, "frontend_init", ",Board %i. ODB and Board 0x8100 do not match!... Exiting ",eye);
    return -1;
  }



  // 0x810C
  DWORD ODB_0x810C = 0;
  size = sizeof(ODB_0x810C);
  sprintf(buf,"General_Board_Registers/Register_0x810C",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_get_data(hDB,genHdl,&ODB_0x810C,&size,TID_DWORD);
  // cm_msg(MINFO,"frontend_init","Board %i 0x810C %lu from ODB",eye,ODB_0x810C);
    
  //Check to see if its ok to write to digitizer
  failure = false;
  //PHA and PSD are the same
  if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
    for(int jay=0; jay < 32; jay++) {
      if((jay >= 8 && jay <= 19) || ((ModType[eye] == 2 || ModType[eye] == 3) && (jay >= 4 && jay<=7)) || 
	 jay == 27 || jay == 28) {
	if( ((ODB_0x810C >> jay)  & 0x1) != 0 ) {
	  cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x810C not 0 in ODB.",eye,jay);
	  failure = true;
	}
      }
    }
  } 
        
  if(failure) {
    cm_msg( MERROR, "frontend_init", "Board %i. Problem with 0x810C register value in ODB.  Exiting",eye);
    return -1;
  }

  address = 0x810C;
  ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x810C);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to write 0x810C, retval: %i  Exiting",eye,ret);
    return -1;
  }
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x810C[eye]);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x810C, retval: %i  Exiting",eye,ret);
    return -1;
  }    
  // cm_msg(MINFO,"frontend_init","Board %i 0x810C %lu from digitizer",eye,Board_0x810C[eye]);

  //Make sure the settings we think we have are really on the board
  if(Board_0x810C[eye] != ODB_0x810C) {
    cm_msg( MERROR, "frontend_init", ",Board %i. ODB and Board 0x810C do not match!... Exiting ",eye);
    return -1;
  }


  // 0x8110
  DWORD ODB_0x8110 = 0;
  size = sizeof(ODB_0x8110);
  sprintf(buf,"General_Board_Registers/Register_0x8110",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_get_data(hDB,genHdl,&ODB_0x8110,&size,TID_DWORD);
  // cm_msg(MINFO,"frontend_init","Board %i 0x8110 %lu from ODB",eye,ODB_0x8110);
    
  //Check to see if its ok to write to digitizer
  failure = false;
  //PHA and PSD are the same
  if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
    for(int jay=16; jay <= 28; jay++) {
      if( ((ODB_0x8110 >> jay)  & 0x1) != 0 ) {
	cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x8110 not 0 in ODB.",eye,jay);
	failure = true;
      }
    }
  } 
    
  if(failure) {
    cm_msg( MERROR, "frontend_init", "Board %i. Problem with 0x8110 register value in ODB.  Exiting",eye);
    return -1;
  }

  address = 0x8110;
  ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x8110);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to write 0x8110, retval: %i  Exiting",eye,ret);
    return -1;
  }
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x8110[eye]);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x8110, retval: %i  Exiting",eye,ret);
    return -1;
  }    
  //  cm_msg(MINFO,"frontend_init","Board %i 0x8110 %lu from digitizer",eye,Board_0x8110[eye]);

  //Make sure the settings we think we have are really on the board
  if(Board_0x8110[eye] != ODB_0x8110) {
    cm_msg( MERROR, "frontend_init", ",Board %i. ODB and Board 0x8110 do not match!... Exiting ",eye);
    return -1;
  }


    
  // 0x811C
  DWORD ODB_0x811C = 0;
  size = sizeof(ODB_0x811C);
  sprintf(buf,"General_Board_Registers/Register_0x811C",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_get_data(hDB,genHdl,&ODB_0x811C,&size,TID_DWORD);
  // cm_msg(MINFO,"frontend_init","Board %i 0x811C %lu from ODB",eye,ODB_0x811C);
    
  //Check to see if its ok to write to digitizer
  failure = false;
  //PHA and PSD are the same
  if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
    for(int jay=0; jay < 32; jay++) {
      if(jay == 12 || jay == 13 || jay >= 23) {
	if( ((ODB_0x811C >> jay)  & 0x1) != 0 ) {
	  cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x811C not 0 in ODB.",eye,jay);
	  failure = true;
	}
      }
    }
  } 
    
  if(failure) {
    cm_msg( MERROR, "frontend_init", "Board %i. Problem with 0x811C register value in ODB.  Exiting",eye);
    return -1;
  }

  address = 0x811C;
  ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x811C);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to write 0x811C, retval: %i  Exiting",eye,ret);
    return -1;
  }
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x811C[eye]);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x811C, retval: %i  Exiting",eye,ret);
    return -1;
  }    
  // cm_msg(MINFO,"frontend_init","Board %i 0x811C %lu from digitizer",eye,Board_0x811C[eye]);

  //Make sure the settings we think we have are really on the board
  if(Board_0x811C[eye] != ODB_0x811C) {
    cm_msg( MERROR, "frontend_init", ",Board %i. ODB and Board 0x811C do not match!... Exiting ",eye);
    return -1;
  }



  // 0x8138
  DWORD ODB_0x8138 = 0;
  size = sizeof(ODB_0x8138);
  sprintf(buf,"General_Board_Registers/Register_0x8138",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_get_data(hDB,genHdl,&ODB_0x8138,&size,TID_DWORD);
  //  cm_msg(MINFO,"frontend_init","Board %i 0x8138 %lu from ODB",eye,ODB_0x8138);
    
  //Check to see if its ok to write to digitizer
  failure = false;
  //PHA and PSD are the same
  if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
    for(int jay=12; jay < 32; jay++) {
      if( ((ODB_0x8138 >> jay)  & 0x1) != 0 ) {
	cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x8138 not 0 in ODB.",eye,jay);
	failure = true;
      }
    }
  } 
    
  if(failure) {
    cm_msg( MERROR, "frontend_init", "Board %i. Problem with 0x8138 register value in ODB.  Exiting",eye);
    return -1;
  }

  address = 0x8138;
  ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x8138);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to write 0x8138, retval: %i  Exiting",eye,ret);
    return -1;
  }
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x8138[eye]);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x8138, retval: %i  Exiting",eye,ret);
    return -1;
  }    
  //  cm_msg(MINFO,"frontend_init","Board %i 0x8138 %lu from digitizer",eye,Board_0x8138[eye]);

  //Make sure the settings we think we have are really on the board
  if(Board_0x8138[eye] != ODB_0x8138) {
    cm_msg( MERROR, "frontend_init", ",Board %i. ODB and Board 0x8138 do not match!... Exiting ",eye);
    return -1;
  }


  // 0x8144
  DWORD ODB_0x8144 = 0;
  size = sizeof(ODB_0x8144);
  sprintf(buf,"General_Board_Registers/Register_0x8144",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_get_data(hDB,genHdl,&ODB_0x8144,&size,TID_DWORD);
  // cm_msg(MINFO,"frontend_init","Board %i 0x8144 %lu from ODB",eye,ODB_0x8144);
    
  //Check to see if its ok to write to digitizer
  failure = false;
  //PHA and PSD are the same
  if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
    for(int jay=3; jay < 32; jay++) {
      if( ((ODB_0x8144 >> jay)  & 0x1) != 0 ) {
	cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x8144 not 0 in ODB.",eye,jay);
	failure = true;
      }
    }
  } 
    
  if(failure) {
    cm_msg( MERROR, "frontend_init", "Board %i. Problem with 0x8144 register value in ODB.  Exiting",eye);
    return -1;
  }

  address = 0x8144;
  ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x8144);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to write 0x8144, retval: %i  Exiting",eye,ret);
    return -1;
  }
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x8144[eye]);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x8144, retval: %i  Exiting",eye,ret);
    return -1;
  }    
  //  cm_msg(MINFO,"frontend_init","Board %i 0x8144 %lu from digitizer",eye,Board_0x8144[eye]);

  //Make sure the settings we think we have are really on the board
  if(Board_0x8144[eye] != ODB_0x8144) {
    cm_msg( MERROR, "frontend_init", ",Board %i. ODB and Board 0x8144 do not match!... Exiting ",eye);
    return -1;
  }


  // 0x8170
  DWORD ODB_0x8170 = 0;
  size = sizeof(ODB_0x8170);
  sprintf(buf,"General_Board_Registers/Register_0x8170",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_get_data(hDB,genHdl,&ODB_0x8170,&size,TID_DWORD);
  // cm_msg(MINFO,"frontend_init","Board %i 0x8170 %lu from ODB",eye,ODB_0x8170);
    
  //Check to see if its ok to write to digitizer
  failure = false;
  //PHA is the only restriction
  if(AMC_MajRev[eye] == 139 ) {
    for(int jay=8; jay < 32; jay++) {
      if( ((ODB_0x8170 >> jay)  & 0x1) != 0 ) {
	cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x8170 not 0 in ODB.",eye,jay);
	failure = true;
      }
    }
  } 
    
  if(failure) {
    cm_msg( MERROR, "frontend_init", "Board %i. Problem with 0x8170 register value in ODB.  Exiting",eye);
    return -1;
  }

  address = 0x8170;
  ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x8170);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to write 0x8170, retval: %i  Exiting",eye,ret);
    return -1;
  }
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x8170[eye]);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x8170, retval: %i  Exiting",eye,ret);
    return -1;
  }    
  //  cm_msg(MINFO,"frontend_init","Board %i 0x8170 %lu from digitizer",eye,Board_0x8170[eye]);

  //Make sure the settings we think we have are really on the board
  if(Board_0x8170[eye] != ODB_0x8170) {
    cm_msg( MERROR, "frontend_init", ",Board %i. ODB and Board 0x8170 do not match!... Exiting ",eye);
    return -1;
  }

  // 0x817C
  DWORD ODB_0x817C = 0;
  size = sizeof(ODB_0x817C);
  sprintf(buf,"General_Board_Registers/Register_0x817C",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_get_data(hDB,genHdl,&ODB_0x817C,&size,TID_DWORD);
  // cm_msg(MINFO,"frontend_init","Board %i 0x817C %lu from ODB",eye,ODB_0x817C);
    
  //Check to see if its ok to write to digitizer
  failure = false;
  //PHA and PSD are the same
  if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
    for(int jay=1; jay < 32; jay++) {
      if( ((ODB_0x817C >> jay)  & 0x1) != 0 ) {
	cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x817C not 0 in ODB.",eye,jay);
	failure = true;
      }
    }
  } 
    
  if(failure) {
    cm_msg( MERROR, "frontend_init", "Board %i. Problem with 0x817C register value in ODB.  Exiting",eye);
    return -1;
  }

  address = 0x817C;
  ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x817C);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to write 0x817C, retval: %i  Exiting",eye,ret);
    return -1;
  }
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x817C[eye]);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x817C, retval: %i  Exiting",eye,ret);
    return -1;
  }    
  //  cm_msg(MINFO,"frontend_init","Board %i 0x817C %lu from digitizer",eye,Board_0x817C[eye]);

  //Make sure the settings we think we have are really on the board
  if(Board_0x817C[eye] != ODB_0x817C) {
    cm_msg( MERROR, "frontend_init", ",Board %i. ODB and Board 0x817C do not match!... Exiting ",eye);
    return -1;
  }



  // 0x81A0
  DWORD ODB_0x81A0 = 0;
  size = sizeof(ODB_0x81A0);
  sprintf(buf,"General_Board_Registers/Register_0x81A0",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_get_data(hDB,genHdl,&ODB_0x81A0,&size,TID_DWORD);
  //  cm_msg(MINFO,"frontend_init","Board %i 0x81A0 %lu from ODB",eye,ODB_0x81A0);
    
  //Check to see if its ok to write to digitizer
  failure = false;
  //PHA and PSD are the same
  if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
    for(int jay=17; jay < 32; jay++) {
      if( ((ODB_0x81A0 >> jay)  & 0x1) != 0 ) {
	cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x81A0 not 0 in ODB.",eye,jay);
	failure = true;
      }
    }
  } 
    
  if(failure) {
    cm_msg( MERROR, "frontend_init", "Board %i. Problem with 0x81A0 register value in ODB.  Exiting",eye);
    return -1;
  }

  address = 0x81A0;
  ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x81A0);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to write 0x81A0, retval: %i  Exiting",eye,ret);
    return -1;
  }
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x81A0[eye]);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x81A0, retval: %i  Exiting",eye,ret);
    return -1;
  }    
  //  cm_msg(MINFO,"frontend_init","Board %i 0x81A0 %lu from digitizer",eye,Board_0x81A0[eye]);

  //Make sure the settings we think we have are really on the board
  if(Board_0x81A0[eye] != ODB_0x81A0) {
    cm_msg( MERROR, "frontend_init", ",Board %i. ODB and Board 0x81A0 do not match!... Exiting ",eye);
    return -1;
  }


  // 0xEF00
  DWORD ODB_0xEF00 = 0;
  size = sizeof(ODB_0xEF00);
  sprintf(buf,"General_Board_Registers/Register_0xEF00",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_get_data(hDB,genHdl,&ODB_0xEF00,&size,TID_DWORD);
  //  cm_msg(MINFO,"frontend_init","Board %i 0xEF00 %lu from ODB",eye,ODB_0xEF00);
    
  //Check to see if its ok to write to digitizer
  failure = false;
  //PHA and PSD are the same
  if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
    for(int jay=9; jay < 32; jay++) {
      if( ((ODB_0xEF00 >> jay)  & 0x1) != 0 ) {
	cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0xEF00 not 0 in ODB.",eye,jay);
	failure = true;
      }
    }
  } 
    
  if(failure) {
    cm_msg( MERROR, "frontend_init", "Board %i. Problem with 0xEF00 register value in ODB.  Exiting",eye);
    return -1;
  }

  address = 0xEF00;
  ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0xEF00);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to write 0xEF00, retval: %i  Exiting",eye,ret);
    return -1;
  }
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0xEF00[eye]);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0xEF00, retval: %i  Exiting",eye,ret);
    return -1;
  }    
  //  cm_msg(MINFO,"frontend_init","Board %i 0xEF00 %lu from digitizer",eye,Board_0xEF00[eye]);

  //Make sure the settings we think we have are really on the board
  if(Board_0xEF00[eye] != ODB_0xEF00) {
    cm_msg( MERROR, "frontend_init", ",Board %i. ODB and Board 0xEF00 do not match!... Exiting ",eye);
    return -1;
  }

  //out.close();
  
  cm_msg(MINFO,"frontend_init","Board %i Programming General Board Registers Complete",eye);

  //if all is good return 0 errors
  return 0;
}


int program_trigger_validation_registers(int *handle,int eye, HNDLE hDB, HNDLE *activeBoards, int *ModType, int *ModCode, int *AMC_MajRev, int *NChannels) {

  cm_msg(MINFO,"frontend_init","Board %i Programming Trigger Validation Registers Started",eye);

  //return value of reading and writing to boards
  CAEN_DGTZ_ErrorCode ret;
  
  //address of the register to read and write to
  uint32_t address;     
  
  //Checks on registers complying with documentation
  bool failure = false;
    
  //ODB path
  char buf[100];
  
  //Size of ODB variable
  int size;

  //General handle to the current ODB location
  HNDLE genHdl;

  // 0x8180
  DWORD ODB_0x8180 = 0;
  size = sizeof(ODB_0x8180);
  sprintf(buf,"Trigger_Validation_Registers/Register_0x8180",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_get_data(hDB,genHdl,&ODB_0x8180,&size,TID_DWORD);
  //  cm_msg(MINFO,"frontend_init","Board %i 0x8180 %lu from ODB",eye,ODB_0x8180);
    
  //Check to see if its ok to write to digitizer
  failure = false;
  //PHA and PSD are the same
  if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
    for(int jay=13; jay <= 27; jay++) {
      if( ((ODB_0x8180 >> jay)  & 0x1) != 0 ) {
	cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x8180 not 0 in ODB.",eye,jay);
	failure = true;
      }
    }
  } 
    
  if(failure) {
    cm_msg( MERROR, "frontend_init", "Board %i. Problem with 0x8180 register value in ODB.  Exiting",eye);
    return -1;
  }

  address = 0x8180;
  ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x8180);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to write 0x8180, retval: %i  Exiting",eye,ret);
    return -1;
  }
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x8180[eye]);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x8180, retval: %i  Exiting",eye,ret);
    return -1;
  }    
  // cm_msg(MINFO,"frontend_init","Board %i 0x8180 %lu from digitizer",eye,Board_0x8180[eye]);

  //Make sure the settings we think we have are really on the board
  if(Board_0x8180[eye] != ODB_0x8180) {
    cm_msg( MERROR, "frontend_init", ",Board %i. ODB and Board 0x8180 do not match!... Exiting ",eye);
    return -1;
  }


  // 0x8184
  DWORD ODB_0x8184 = 0;
  size = sizeof(ODB_0x8184);
  sprintf(buf,"Trigger_Validation_Registers/Register_0x8184",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_get_data(hDB,genHdl,&ODB_0x8184,&size,TID_DWORD);
  // cm_msg(MINFO,"frontend_init","Board %i 0x8184 %lu from ODB",eye,ODB_0x8184);
    
  //Check to see if its ok to write to digitizer
  failure = false;
  //PHA and PSD are the same
  if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
    for(int jay=13; jay <= 27; jay++) {
      if( ((ODB_0x8184 >> jay)  & 0x1) != 0 ) {
	cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x8184 not 0 in ODB.",eye,jay);
	failure = true;
      }
    }
  } 
    
  if(failure) {
    cm_msg( MERROR, "frontend_init", "Board %i. Problem with 0x8184 register value in ODB.  Exiting",eye);
    return -1;
  }

  address = 0x8184;
  ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x8184);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to write 0x8184, retval: %i  Exiting",eye,ret);
    return -1;
  }
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x8184[eye]);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x8184, retval: %i  Exiting",eye,ret);
    return -1;
  }    
  // cm_msg(MINFO,"frontend_init","Board %i 0x8184 %lu from digitizer",eye,Board_0x8184[eye]);

  //Make sure the settings we think we have are really on the board
  if(Board_0x8184[eye] != ODB_0x8184) {
    cm_msg( MERROR, "frontend_init", ",Board %i. ODB and Board 0x8184 do not match!... Exiting ",eye);
    return -1;
  }


  // 0x8188
  DWORD ODB_0x8188 = 0;
  size = sizeof(ODB_0x8188);
  sprintf(buf,"Trigger_Validation_Registers/Register_0x8188",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_get_data(hDB,genHdl,&ODB_0x8188,&size,TID_DWORD);
  // cm_msg(MINFO,"frontend_init","Board %i 0x8188 %lu from ODB",eye,ODB_0x8188);
    
  //Check to see if its ok to write to digitizer
  failure = false;
  //PHA and PSD are the same
  if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
    for(int jay=13; jay <= 27; jay++) {
      if( ((ODB_0x8188 >> jay)  & 0x1) != 0 ) {
	cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x8188 not 0 in ODB.",eye,jay);
	failure = true;
      }
    }
  } 
    
  if(failure) {
    cm_msg( MERROR, "frontend_init", "Board %i. Problem with 0x8188 register value in ODB.  Exiting",eye);
    return -1;
  }

  address = 0x8188;
  ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x8188);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to write 0x8188, retval: %i  Exiting",eye,ret);
    return -1;
  }
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x8188[eye]);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x8188, retval: %i  Exiting",eye,ret);
    return -1;
  }    
  // cm_msg(MINFO,"frontend_init","Board %i 0x8188 %lu from digitizer",eye,Board_0x8188[eye]);

  //Make sure the settings we think we have are really on the board
  if(Board_0x8188[eye] != ODB_0x8188) {
    cm_msg( MERROR, "frontend_init", ",Board %i. ODB and Board 0x8188 do not match!... Exiting ",eye);
    return -1;
  }


  // 0x818C
  DWORD ODB_0x818C = 0;
  size = sizeof(ODB_0x818C);
  sprintf(buf,"Trigger_Validation_Registers/Register_0x818C",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_get_data(hDB,genHdl,&ODB_0x818C,&size,TID_DWORD);
  //cm_msg(MINFO,"frontend_init","Board %i 0x818C %lu from ODB",eye,ODB_0x818C);
    
  //Check to see if its ok to write to digitizer
  failure = false;
  //PHA and PSD are the same
  if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
    for(int jay=13; jay <= 27; jay++) {
      if( ((ODB_0x818C >> jay)  & 0x1) != 0 ) {
	cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x818C not 0 in ODB.",eye,jay);
	failure = true;
      }
    }
  } 
    
  if(failure) {
    cm_msg( MERROR, "frontend_init", "Board %i. Problem with 0x818C register value in ODB.  Exiting",eye);
    return -1;
  }

  address = 0x818C;
  ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x818C);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to write 0x818C, retval: %i  Exiting",eye,ret);
    return -1;
  }
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x818C[eye]);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x818C, retval: %i  Exiting",eye,ret);
    return -1;
  }    
  // cm_msg(MINFO,"frontend_init","Board %i 0x818C %lu from digitizer",eye,Board_0x818C[eye]);

  //Make sure the settings we think we have are really on the board
  if(Board_0x818C[eye] != ODB_0x818C) {
    cm_msg( MERROR, "frontend_init", ",Board %i. ODB and Board 0x818C do not match!... Exiting ",eye);
    return -1;
  }

  // 0x8190
  DWORD ODB_0x8190 = 0;
  size = sizeof(ODB_0x8190);
  sprintf(buf,"Trigger_Validation_Registers/Register_0x8190",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_get_data(hDB,genHdl,&ODB_0x8190,&size,TID_DWORD);
  // cm_msg(MINFO,"frontend_init","Board %i 0x8190 %lu from ODB",eye,ODB_0x8190);
    
  //Check to see if its ok to write to digitizer
  failure = false;
  //PHA and PSD are the same
  if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
    for(int jay=13; jay <= 27; jay++) {
      if( ((ODB_0x8190 >> jay)  & 0x1) != 0 ) {
	cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x8190 not 0 in ODB.",eye,jay);
	failure = true;
      }
    }
  } 
    
  if(failure) {
    cm_msg( MERROR, "frontend_init", "Board %i. Problem with 0x8190 register value in ODB.  Exiting",eye);
    return -1;
  }

  address = 0x8190;
  ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x8190);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to write 0x8190, retval: %i  Exiting",eye,ret);
    return -1;
  }
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x8190[eye]);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x8190, retval: %i  Exiting",eye,ret);
    return -1;
  }    
  // cm_msg(MINFO,"frontend_init","Board %i 0x8190 %lu from digitizer",eye,Board_0x8190[eye]);

  //Make sure the settings we think we have are really on the board
  if(Board_0x8190[eye] != ODB_0x8190) {
    cm_msg( MERROR, "frontend_init", ",Board %i. ODB and Board 0x8190 do not match!... Exiting ",eye);
    return -1;
  }


  // 0x8194
  DWORD ODB_0x8194 = 0;
  size = sizeof(ODB_0x8194);
  sprintf(buf,"Trigger_Validation_Registers/Register_0x8194",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_get_data(hDB,genHdl,&ODB_0x8194,&size,TID_DWORD);
  // cm_msg(MINFO,"frontend_init","Board %i 0x8194 %lu from ODB",eye,ODB_0x8194);
    
  //Check to see if its ok to write to digitizer
  failure = false;
  //PHA and PSD are the same
  if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
    for(int jay=13; jay <= 27; jay++) {
      if( ((ODB_0x8194 >> jay)  & 0x1) != 0 ) {
	cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x8194 not 0 in ODB.",eye,jay);
	failure = true;
      }
    }
  } 
    
  if(failure) {
    cm_msg( MERROR, "frontend_init", "Board %i. Problem with 0x8194 register value in ODB.  Exiting",eye);
    return -1;
  }

  address = 0x8194;
  ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x8194);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to write 0x8194, retval: %i  Exiting",eye,ret);
    return -1;
  }
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x8194[eye]);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x8194, retval: %i  Exiting",eye,ret);
    return -1;
  }    
  // cm_msg(MINFO,"frontend_init","Board %i 0x8194 %lu from digitizer",eye,Board_0x8194[eye]);

  //Make sure the settings we think we have are really on the board
  if(Board_0x8194[eye] != ODB_0x8194) {
    cm_msg( MERROR, "frontend_init", ",Board %i. ODB and Board 0x8194 do not match!, retval: %i  Exiting",eye,ret);
    return -1;
  }


  // 0x8198
  DWORD ODB_0x8198 = 0;
  size = sizeof(ODB_0x8198);
  sprintf(buf,"Trigger_Validation_Registers/Register_0x8198",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_get_data(hDB,genHdl,&ODB_0x8198,&size,TID_DWORD);
  // cm_msg(MINFO,"frontend_init","Board %i 0x8198 %lu from ODB",eye,ODB_0x8198);
    
  //Check to see if its ok to write to digitizer
  failure = false;
  //PHA and PSD are the same
  if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
    for(int jay=13; jay <= 27; jay++) {
      if( ((ODB_0x8198 >> jay)  & 0x1) != 0 ) {
	cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x8198 not 0 in ODB.",eye,jay);
	failure = true;
      }
    }
  } 
    
  if(failure) {
    cm_msg( MERROR, "frontend_init", "Board %i. Problem with 0x8198 register value in ODB.  Exiting",eye);
    return -1;
  }

  address = 0x8198;
  ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x8198);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to write 0x8198, retval: %i  Exiting",eye,ret);
    return -1;
  }
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x8198[eye]);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x8198, retval: %i  Exiting",eye,ret);
    return -1;
  }    
  // cm_msg(MINFO,"frontend_init","Board %i 0x8198 %lu from digitizer",eye,Board_0x8198[eye]);

  //Make sure the settings we think we have are really on the board
  if(Board_0x8198[eye] != ODB_0x8198) {
    cm_msg( MERROR, "frontend_init", ",Board %i. ODB and Board 0x8198 do not match!... Exiting ",eye);
    return -1;
  }


  // 0x819C
  DWORD ODB_0x819C = 0;
  size = sizeof(ODB_0x819C);
  sprintf(buf,"Trigger_Validation_Registers/Register_0x819C",eye);
  db_find_key(hDB, activeBoards[eye],buf, &genHdl);
  db_get_data(hDB,genHdl,&ODB_0x819C,&size,TID_DWORD);
  // cm_msg(MINFO,"frontend_init","Board %i 0x819C %lu from ODB",eye,ODB_0x819C);
    
  //Check to see if its ok to write to digitizer
  failure = false;
  //PHA and PSD are the same
  if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
    for(int jay=13; jay <= 27; jay++) {
      if( ((ODB_0x819C >> jay)  & 0x1) != 0 ) {
	cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x819C not 0 in ODB.",eye,jay);
	failure = true;
      }
    }
  } 
    
  if(failure) {
    cm_msg( MERROR, "frontend_init", "Board %i. Problem with 0x819C register value in ODB.  Exiting",eye);
    return -1;
  }

  address = 0x819C;
  ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x819C);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to write 0x819C, retval: %i  Exiting",eye,ret);
    return -1;
  }
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x819C[eye]);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x819C, retval: %i  Exiting",eye,ret);
    return -1;
  }    
  // cm_msg(MINFO,"frontend_init","Board %i 0x819C %lu from digitizer",eye,Board_0x819C[eye]);

  //Make sure the settings we think we have are really on the board
  if(Board_0x819C[eye] != ODB_0x819C) {
    cm_msg( MERROR, "frontend_init", ",Board %i. ODB and Board 0x819C do not match!... Exiting ",eye);
    return -1;
  }
    
  cm_msg(MINFO,"frontend_init","Board %i Programming Trigger Validation Registers Complete",eye);

  return 0;
}




int program_channel_registers(int *handle,int eye, HNDLE hDB, HNDLE *activeBoards, int *ModType, int *ModCode, int *AMC_MajRev, int *NChannels) {

  cm_msg(MINFO,"frontend_init","Board %i Programming Channel Registers Started",eye);

  //return value of reading and writing to boards
  CAEN_DGTZ_ErrorCode ret;
  
  //address of the register to read and write to
  uint32_t address;     
  
  //Checks on registers complying with documentation
  bool failure = false;
    
  //ODB path
  char buf[100];
  
  //Size of ODB variable
  int size;

  //General handle to the current ODB location
  HNDLE genHdl;

  /* Begin Channel Specific stuff */

  uint32_t ODB_0x8120 = 0;
    
  for(int jay=0; jay<NChannels[eye]; jay++) {
    // for(int jay=0; jay<1; jay++) {

    HNDLE genHdlbase;
    char buf[64];
    sprintf(buf,"Channel_%i",jay);
    db_find_key(hDB,activeBoards[eye],buf,&genHdlbase);
      
    // Figure out if the channel is enabled
    BOOL enabled;
    size = sizeof(enabled);
    db_find_key(hDB,genHdlbase,"Enabled",&genHdl);
    db_get_data(hDB,genHdl,&enabled,&size,TID_BOOL);
      
    if (enabled) {
      //Add to the channel enable register for this board
      ODB_0x8120 += (0x1 << jay);
      //  cm_msg(MINFO,"frontend_init","Board %i, Channel %i Enabled",eye,jay);

      char buf64[64];


	
      uint32_t ODB_0x1n60 = 0;   //PSD: Trigger Threshold                   , PHA: Trapezoidal Rise Time 
      uint32_t ODB_0x1n6C = 0;   //PSD: DOESN'T EXIST                       , PHA: Trigger Threshold
      uint32_t ODB_0x1n70 = 0;   //PSD: Shaped Trigger Width                , PHA: 
      uint32_t ODB_0x1n54 = 0;   //PSD: Short Gate
      uint32_t ODB_0x1n58 = 0;   //PSD: Long Gate
      uint32_t ODB_0x1n5C = 0;   //PSD: Gate Offset
      uint32_t ODB_0x1n80 = 0;   //PSD: Control 1
      uint32_t ODB_0x1n84 = 0;   //PSD: Control 2
      uint32_t ODB_0x1n3C = 0;   //PSD: CFD Control
      uint32_t ODB_0x1n44 = 0;   //PSD: Charge Zero Suppression Threshold
      uint32_t ODB_0x1n78 = 0;   //PSD: PSD Threshold
      uint32_t ODB_0x1n7C = 0;   //PSD: PUR-GAP Threshold
      uint32_t ODB_0x1n64 = 0;   //PSD: Fixed Baseline                      , PHA: Peaking Time
      uint32_t ODB_0x1nD8 = 0;   //PSD: Baseline Freeze                     , PHA: DOESN'T EXIST

      uint32_t ODB_0x1n28 = 0;   //PSD/PHA ADC Range
      uint32_t ODB_0x1n98 = 0;   //PSD/PHA DC Offset
      uint32_t ODB_0x1n38 = 0;   //PSD/PHA Waveform PreTrigger
      uint32_t ODB_0x1n20 = 0;   //PSD/PHA Waveform Length
      // uint32_t ODB_0x1n34 = 0;   //PSD/PHA NEvents per Aggregate
      uint32_t ODB_0x1n74 = 0;   //PSD/PHA Trigger Hold-Off Width
      uint32_t ODB_0x1nD4 = 0;   //PSD/PHA Veto Width and Veto Width Multiplier

	
      /* DO ALL THE COMMON THINGS FIRST */

      //0x1n80 Pulse polarity (PSD,PHA bit 16)
      size = sizeof(buf64);
      db_find_key(hDB,genHdlbase,"PulsePolarity",&genHdl);
      db_get_data(hDB,genHdl,buf64,&size,TID_STRING);
	
      int polarity_bit=0;
      if(strcmp(buf64,"Negative") == 0) {
	polarity_bit=1;
      }
      else if(strcmp(buf64,"Positive") == 0) {
	polarity_bit=1;
      }
      else {
      	cm_msg(MINFO,"frontend_init","Board %i, Channel %i. Can't understand polarity. Negative or Positive",eye,jay);
	return -1;
      }
      //  cm_msg(MINFO,"frontend_init","Board %i, Channel %i, Polarity: %s, %i",eye,jay,buf64,polarity_bit);
	
      //Add in the polarity bit
      ODB_0x1n80 += (polarity_bit << 16);
	
	
      float adcrange;
      size = sizeof(adcrange);
      db_find_key(hDB,genHdlbase,"ADC_Range", &genHdl);
      db_get_data(hDB,genHdl,&adcrange,&size,TID_FLOAT);
	
      if(adcrange == 2.0) {
	ODB_0x1n28 = 0;
      }
      else if(adcrange == 0.5) {
	ODB_0x1n28 = 1;
      }
      else {
	cm_msg(MINFO,"frontend_init","Board %i, Channel %i. Can't understand ADC Range. 2.0 or 0.5",eye,jay);
	return -1;
      }
      //   cm_msg(MINFO,"frontend_init","Board %i, Channel %i, ADC Range: %1.1f, %i",eye,jay,adcrange,ODB_0x1n28);
	
      WORD dcoffset;
      size = sizeof(dcoffset);
      db_find_key(hDB,genHdlbase,"DC_Offset", &genHdl);
      db_get_data(hDB,genHdl,&dcoffset,&size,TID_WORD);
      ODB_0x1n98 = dcoffset;
      //   cm_msg(MINFO,"frontend_init","Board %i, Channel %i, DC Offset: %i, %i",eye,jay,dcoffset,ODB_0x1n98);

      WORD wfpretrig;
      size = sizeof(wfpretrig);
      db_find_key(hDB,genHdlbase,"Waveform_Pre-Trigger_Length", &genHdl);
      db_get_data(hDB,genHdl,&wfpretrig,&size,TID_WORD);
      if(wfpretrig % 4 !=0) {
	cm_msg(MINFO,"frontend_init","Board %i, Channel %i. Waveform Length is not divisible by 4",eye,jay);
	return -1; 
      }
      ODB_0x1n38 = (int)wfpretrig/4.0;
      // cm_msg(MINFO,"frontend_init","Board %i, Channel %i, Waveorm Pre-Trigger Length: %i, %i",eye,jay,wfpretrig,ODB_0x1n38);

      WORD wflength;
      size = sizeof(wflength);
      db_find_key(hDB,genHdlbase,"Waveform_Record_Length", &genHdl);
      db_get_data(hDB,genHdl,&wflength,&size,TID_WORD);
      if(wflength % 8 !=0) {
	cm_msg(MINFO,"frontend_init","Board %i, Channel %i. Waveform Length is not divisible by 8",eye,jay);
	return -1;
      }	
      ODB_0x1n20 = (int)wflength/8.0;
      // cm_msg(MINFO,"frontend_init","Board %i, Channel %i, Waveform_Record_Length: %i, %i",eye,jay,wflength,ODB_0x1n20);
	
      /*
      WORD nevtsperagg;
      size = sizeof(nevtsperagg);
      db_find_key(hDB,genHdlbase,"NEvents_per_Aggregate", &genHdl);
      db_get_data(hDB,genHdl,&nevtsperagg,&size,TID_WORD);
      ODB_0x1n34 = (int)nevtsperagg;
      // cm_msg(MINFO,"frontend_init","Board %i, Channel %i, NEvents per Aggregate: %i, %i",eye,jay,nevtsperagg,ODB_0x1n34);
      */

      WORD vetowidth;
      size = sizeof(vetowidth);
      db_find_key(hDB,genHdlbase,"Veto_Width", &genHdl);
      db_get_data(hDB,genHdl,&vetowidth,&size,TID_WORD);
      if(vetowidth >= 32768) {
	cm_msg(MINFO,"frontend_init","Board %i, Channel %i. Veto Width is >= 32768 ",eye,jay);
	return -1;
      }
      ODB_0x1nD4 += vetowidth;
      //  cm_msg(MINFO,"frontend_init","Board %i, Channel %i, Veto Width: %i, %i",eye,jay,vetowidth,ODB_0x1nD4);
      WORD vetowidthmult;
      size = sizeof(vetowidthmult);
      db_find_key(hDB,genHdlbase,"Veto_Width_Multiplier", &genHdl);
      db_get_data(hDB,genHdl,&vetowidthmult,&size,TID_WORD);
      if(vetowidthmult >= 4) {
	cm_msg(MINFO,"frontend_init","Board %i, Channel %i. Veto Width Multiplier is >= 4 ",eye,jay);
	return -1;
      }
      ODB_0x1nD4 += (vetowidthmult << 16);
      // cm_msg(MINFO,"frontend_init","Board %i, Channel %i, Veto Width Multiplier: %i, %i",eye,jay,vetowidthmult,ODB_0x1nD4);
	
      WORD trigholdoff;
      size = sizeof(trigholdoff);
      db_find_key(hDB,genHdlbase,"Trigger_Hold-Off_Width", &genHdl);
      db_get_data(hDB,genHdl,&trigholdoff,&size,TID_WORD);
      ODB_0x1n74 = (int)trigholdoff;
      //  cm_msg(MINFO,"frontend_init","Board %i, Channel %i, Trigger Hold-Off Width: %i, %i",eye,jay,trigholdoff,ODB_0x1n74);








      if(AMC_MajRev[eye] == 139) {
	//Trigger Threshold
	WORD trigthreshold;
	size = sizeof(trigthreshold);
	db_find_key(hDB,genHdlbase,"Trigger_Threshold", &genHdl);
	db_get_data(hDB,genHdl,&trigthreshold,&size,TID_WORD);
	ODB_0x1n6C = trigthreshold;
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, Trigger Threshold: %i, %i",eye,jay,trigthreshold,ODB_0x1n6C);
	  
	//Shaped Trigger Width
	WORD shapedtrigwidth;
	size = sizeof(shapedtrigwidth);
	db_find_key(hDB,genHdlbase,"Shaped_Trigger_Width", &genHdl);
	db_get_data(hDB,genHdl,&shapedtrigwidth,&size,TID_WORD);
	ODB_0x1n84 = shapedtrigwidth;
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, Shaped Trigger Width: %i, %i",eye,jay,shapedtrigwidth,ODB_0x1n84);




	  


      }  //End of AMC MajRev 139
	 
	


      if(AMC_MajRev[eye] == 136) {
	//Trigger Threshold
	WORD trigthreshold;
	size = sizeof(trigthreshold);
	db_find_key(hDB,genHdlbase,"Trigger_Threshold", &genHdl);
	db_get_data(hDB,genHdl,&trigthreshold,&size,TID_WORD);
	ODB_0x1n60 = trigthreshold;
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, Trigger Threshold: %i, %i",eye,jay,trigthreshold,ODB_0x1n60);

	//Shaped Trigger Width
	WORD shapedtrigwidth;
	size = sizeof(shapedtrigwidth);
	db_find_key(hDB,genHdlbase,"Shaped_Trigger_Width", &genHdl);
	db_get_data(hDB,genHdl,&shapedtrigwidth,&size,TID_WORD);
	ODB_0x1n70 = shapedtrigwidth;
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, Shaped Trigger Width: %i, %i",eye,jay,shapedtrigwidth,ODB_0x1n70);


	/* PSD specific stuff */
	  
	//Short Gate
	WORD shortgate;
	size = sizeof(shortgate);
	db_find_key(hDB,genHdlbase,"DPP_PSD_Params/Short_Gate", &genHdl);
	db_get_data(hDB,genHdl,&shortgate,&size,TID_WORD);
	ODB_0x1n54 = shortgate;
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, Short Gate: %i, %i",eye,jay,shortgate,ODB_0x1n54);
	  
	//Long Gate
	WORD longgate;
	size = sizeof(longgate);
	db_find_key(hDB,genHdlbase,"DPP_PSD_Params/Long_Gate", &genHdl);
	db_get_data(hDB,genHdl,&longgate,&size,TID_WORD);
	ODB_0x1n58 = longgate;
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, Long Gate: %i, %i",eye,jay,longgate,ODB_0x1n58);

	//Gate Offset
	WORD gateoffset;
	size = sizeof(gateoffset);
	db_find_key(hDB,genHdlbase,"DPP_PSD_Params/Gate_Offset", &genHdl);
	db_get_data(hDB,genHdl,&gateoffset,&size,TID_WORD);
	ODB_0x1n5C = gateoffset;
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, Gate Offset: %i, %i",eye,jay,gateoffset,ODB_0x1n5C);
	  
	//Control register 1
	DWORD reg_0x1n80;
	size = sizeof(reg_0x1n80);
	db_find_key(hDB,genHdlbase,"DPP_PSD_Params/Register_0x1n80", &genHdl);
	db_get_data(hDB,genHdl,&reg_0x1n80,&size,TID_DWORD);
	for(int kay=0; kay<32; kay++) {
	  if(kay != 16) {
	    ODB_0x1n80 += (((reg_0x1n80 >> kay) & 0x1) << kay);  //+= is to not overwrite the polarity bit
	  }
	}
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, Register 0x1n80: %i, %i",eye,jay,reg_0x1n80,ODB_0x1n80);
      
	//Control register 2
	DWORD reg_0x1n84;
	size = sizeof(reg_0x1n84);
	db_find_key(hDB,genHdlbase,"DPP_PSD_Params/Register_0x1n84", &genHdl);
	db_get_data(hDB,genHdl,&reg_0x1n84,&size,TID_DWORD);
	ODB_0x1n84 = reg_0x1n84;
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, Register 0x1n84: %i, %i",eye,jay,reg_0x1n84,ODB_0x1n84);

	//CFD Control
	DWORD reg_0x1n3C;
	size = sizeof(reg_0x1n3C);
	db_find_key(hDB,genHdlbase,"DPP_PSD_Params/Register_0x1n3C", &genHdl);
	db_get_data(hDB,genHdl,&reg_0x1n3C,&size,TID_DWORD);
	ODB_0x1n3C = reg_0x1n3C;
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, Register 0x1n3C: %i, %i",eye,jay,reg_0x1n3C,ODB_0x1n3C);

	//Charge Zero Suppression Threshold
	WORD czst;
	size = sizeof(czst);
	db_find_key(hDB,genHdlbase,"DPP_PSD_Params/Charge_Zero_Suppression", &genHdl);
	db_get_data(hDB,genHdl,&czst,&size,TID_WORD);
	ODB_0x1n44 = czst;
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, Charge Zero Suppression Threshold: %i, %i",eye,jay,czst,ODB_0x1n44);

	//PSD Threshold
	WORD psdt;
	size = sizeof(psdt);
	db_find_key(hDB,genHdlbase,"DPP_PSD_Params/PSD_Threshold", &genHdl);
	db_get_data(hDB,genHdl,&psdt,&size,TID_WORD);
	ODB_0x1n78 = psdt;
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, PSD Threshold: %i, %i",eye,jay,psdt,ODB_0x1n78);

	//PUR-GAP Threshold
	WORD purgapt;
	size = sizeof(purgapt);
	db_find_key(hDB,genHdlbase,"DPP_PSD_Params/PUR-GAP_Threshold", &genHdl);
	db_get_data(hDB,genHdl,&purgapt,&size,TID_WORD);
	ODB_0x1n7C = purgapt;
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, PUR-GAP Threshold: %i, %i",eye,jay,purgapt,ODB_0x1n7C);
	  
	//Fixed Baseline
	WORD fixedbase;
	size = sizeof(fixedbase);
	db_find_key(hDB,genHdlbase,"DPP_PSD_Params/Fixed_Baseline", &genHdl);
	db_get_data(hDB,genHdl,&fixedbase,&size,TID_WORD);
	ODB_0x1n64 = fixedbase;
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, Fixed Baseline: %i, %i",eye,jay,fixedbase,ODB_0x1n64);

	//Baseline Freeze
	WORD basefreeze;
	size = sizeof(basefreeze);
	db_find_key(hDB,genHdlbase,"DPP_PSD_Params/Baseline_Freeze", &genHdl);
	db_get_data(hDB,genHdl,&basefreeze,&size,TID_WORD);
	ODB_0x1nD8 = basefreeze;
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, Baseline Freeze: %i, %i",eye,jay,basefreeze,ODB_0x1nD8);

      } //End o AMC MajRev 136

	
	




	

      failure = false;

      //Write 0x1n28	
      //PHA and PSD are the same
      if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
	for(int kay = 1; kay < 32; kay++) {
	  if( ((ODB_0x1n28 >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n28 not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }
	}
      }
	
      if(failure) {
	cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Problem with 0x1n28.  Exiting",eye,jay);
	return -1;
      }
	
      address =  0x1028 + (jay << 8);
      ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x1n28);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to write 0x1n28, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x1n28[eye][jay]);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to read 0x1n28, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      //   cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n28 %i from ODB",eye,jay,ODB_0x1n28);
      //   cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n28 %i from digitizer",eye,jay,Board_0x1n28[eye][jay]);
	
      if(ODB_0x1n28 != Board_0x1n28[eye][jay]) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. 0x1n28 ODB and Board do not match... Exiting ",eye,jay);
	return -1;
      }

	
      //Write 0x1n60	
      //PHA
      if(AMC_MajRev[eye] == 139 ) {
	for(int kay = 12; kay < 32; kay++) {
	  if( ((ODB_0x1n60 >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n60 not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }
	}	  
      }
      //PSD
      if(AMC_MajRev[eye] == 136) {
	for(int kay = 14; kay < 32; kay++) {
	  if( ((ODB_0x1n60 >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n60 not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }
	}
      }
	
      if(failure) {
	cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Problem with 0x1n60.  Exiting",eye,jay);
	return -1;
      }
	
      address =  0x1060 + (jay << 8);
      ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x1n60);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to write 0x1n60, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x1n60[eye][jay]);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to read 0x1n60, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      //   cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n60 %i from ODB",eye,jay,ODB_0x1n60);
      //  cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n60 %i from digitizer",eye,jay,Board_0x1n60[eye][jay]);
	
      if(ODB_0x1n60 != Board_0x1n60[eye][jay]) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. 0x1n60 ODB and Board do not match... Exiting ",eye,jay);
	return -1;
      }
	

      //Write 0x1n98	
      //PHA and PSD are the same
      if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
	for(int kay = 16; kay < 32; kay++) {
	  if( ((ODB_0x1n98 >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n98 not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }
	}
      }
	
      if(failure) {
	cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Problem with 0x1n98.  Exiting",eye,jay);
	return -1;
      }
	
      address =  0x1098 + (jay << 8);
      ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x1n98);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to write 0x1n98, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    

      // sleep(1000);
      ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x1n98[eye][jay]);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to read 0x1n98, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      //  cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n98 %i from ODB",eye,jay,ODB_0x1n98);
      //   cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n98 %i from digitizer",eye,jay,Board_0x1n98[eye][jay]);
	
      if(ODB_0x1n98 != Board_0x1n98[eye][jay]) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. 0x1n98 ODB and Board do not match... Exiting ",eye,jay);
      	return -1;
      }

      //Write 0x1n38	
      //PHA and PSD are the same
      if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
	for(int kay = 9; kay < 32; kay++) {
	  if( ((ODB_0x1n38 >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n38 not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }
	}
      }
	
      if(failure) {
	cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Problem with 0x1n38.  Exiting",eye,jay);
	return -1;
      }
	
      address =  0x1038 + (jay << 8);
      ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x1n38);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to write 0x1n38, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x1n38[eye][jay]);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to read 0x1n38, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      // cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n38 %i from ODB",eye,jay,ODB_0x1n38);
      // cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n38 %i from digitizer",eye,jay,Board_0x1n38[eye][jay]);
	
      if(ODB_0x1n38 != Board_0x1n38[eye][jay]) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. 0x1n38 ODB and Board do not match... Exiting ",eye,jay);
	return -1;
      }

      //Write 0x1n20	
      //PHA and PSD are the same
      if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
	for(int kay = 14; kay < 32; kay++) {
	  if( ((ODB_0x1n20 >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n20 not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }
	}
      }
	
      if(failure) {
	cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Problem with 0x1n20.  Exiting",eye,jay);
	return -1;
      }
	
      address =  0x1020 + (jay << 8);
      ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x1n20);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to write 0x1n20, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x1n20[eye][jay]);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to read 0x1n20, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      // cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n20 %i from ODB",eye,jay,ODB_0x1n20);
      // cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n20 %i from digitizer",eye,jay,Board_0x1n20[eye][jay]);
	
      if(ODB_0x1n20 != Board_0x1n20[eye][jay]) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. 0x1n20 ODB and Board do not match... Exiting ",eye,jay);
	return -1;
      }


      /*
      //Write 0x1n34	
      //PHA and PSD are the same
      if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
	for(int kay = 10; kay < 32; kay++) {
	  if( ((ODB_0x1n34 >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n34 not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }
	}
      }
	
      if(failure) {
	cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Problem with 0x1n34.  Exiting",eye,jay);
	return -1;
      }
	
      address =  0x1034 + (jay << 8);
      ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x1n34);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to write 0x1n34, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x1n34[eye][jay]);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to read 0x1n34, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      //    cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n34 %i from ODB",eye,jay,ODB_0x1n34);
      //     cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n34 %i from digitizer",eye,jay,Board_0x1n34[eye][jay]);
	
      if(ODB_0x1n34 != Board_0x1n34[eye][jay]) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. 0x1n34 ODB and Board do not match... Exiting ",eye,jay);
	return -1;
      }
      */

      //Write 0x1nD4	
      //PHA and PSD are the same
      if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
	for(int kay = 18; kay < 32; kay++) {
	  if( ((ODB_0x1nD4 >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1nD4 not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }
	}
      }
	
      if(failure) {
	cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Problem with 0x1nD4.  Exiting",eye,jay);
	return -1;
      }
	
      address =  0x10D4 + (jay << 8);
      ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x1nD4);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to write 0x1nD4, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x1nD4[eye][jay]);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to read 0x1nD4, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      //  cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1nD4 %i from ODB",eye,jay,ODB_0x1nD4);
      //  cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1nD4 %i from digitizer",eye,jay,Board_0x1nD4[eye][jay]);
	
      if(ODB_0x1nD4 != Board_0x1nD4[eye][jay]) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. 0x1nD4 ODB and Board do not match... Exiting ",eye,jay);
	return -1;
      }

	



      //Write 0x1n64	
      //PHA
      if(AMC_MajRev[eye] == 139 ) {
	for(int kay = 11; kay < 32; kay++) {
	  if( ((ODB_0x1n64 >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n64 not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }
	}	  
      }
      //PSD
      if(AMC_MajRev[eye] == 136) {
	for(int kay = 14; kay < 32; kay++) {
	  if( ((ODB_0x1n64 >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n64 not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }
	}
      }
      if(failure) {
	cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Problem with 0x1n64.  Exiting",eye,jay);
	return -1;
      }
	
      address =  0x1064 + (jay << 8);
      ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x1n64);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to write 0x1n64, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x1n64[eye][jay]);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to read 0x1n64, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      // cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n64 %i from ODB",eye,jay,ODB_0x1n64);
      // cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n64 %i from digitizer",eye,jay,Board_0x1n64[eye][jay]);
	
      if(ODB_0x1n64 != Board_0x1n64[eye][jay]) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. 0x1n64 ODB and Board do not match... Exiting ",eye,jay);
	return -1;
      }


      //Write 0x1n70	
      //PHA
      if(AMC_MajRev[eye] == 139 ) {
	for(int kay = 10; kay < 32; kay++) {
	  if( ((ODB_0x1n70 >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n70 not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }
	}	  
      }
      //PSD
      if(AMC_MajRev[eye] == 136) {
	for(int kay = 10; kay < 32; kay++) {
	  if( ((ODB_0x1n70 >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n70 not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }
	}
      }
	
      if(failure) {
	cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Problem with 0x1n70.  Exiting",eye,jay);
	return -1;
      }
	
      address =  0x1070 + (jay << 8);
      ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x1n70);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to write 0x1n70, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x1n70[eye][jay]);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to read 0x1n70, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      //  cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n70 %i from ODB",eye,jay,ODB_0x1n70);
      // cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n70 %i from digitizer",eye,jay,Board_0x1n70[eye][jay]);
	
      if(ODB_0x1n70 != Board_0x1n70[eye][jay]) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. 0x1n70 ODB and Board do not match... Exiting ",eye,jay);
	return -1;
      }

       
      //Write 0x1n74	
      //PHA
      if(AMC_MajRev[eye] == 139 ) {
	for(int kay = 10; kay < 32; kay++) {
	  if( ((ODB_0x1n74 >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n74 not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }
	}	  
      }
      //PSD
      if(AMC_MajRev[eye] == 136) {
	for(int kay = 16; kay < 32; kay++) {
	  if( ((ODB_0x1n74 >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n74 not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }
	}
      }
	
      if(failure) {
	cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Problem with 0x1n74.  Exiting",eye,jay);
	return -1;
      }
	
      address =  0x1074 + (jay << 8);
      ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x1n74);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to write 0x1n74, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x1n74[eye][jay]);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to read 0x1n74, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      // cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n74 %i from ODB",eye,jay,ODB_0x1n74);
      // cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n74 %i from digitizer",eye,jay,Board_0x1n74[eye][jay]);
	
      if(ODB_0x1n74 != Board_0x1n74[eye][jay]) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. 0x1n74 ODB and Board do not match... Exiting ",eye,jay);
	return -1;
      }
	
      
      //Write 0x1n80	
      //PHA
      if(AMC_MajRev[eye] == 139 ) {
	for(int kay = 0; kay < 32; kay++) {
	  if(kay == 6 || kay == 7 || kay == 14 || kay == 15 || kay == 23 || kay >= 28) {
	    if( ((ODB_0x1n80 >> kay)  & 0x1) != 0 ) {
	      cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n80 not 0 in ODB.",eye,jay,kay);
	      failure = true;
	    }
	  }	  
	}
      }
      //PSD
      if(AMC_MajRev[eye] == 136) {
	for(int kay = 0; kay < 32; kay++) {
	  if(kay == 3 || (kay >= 11 && kay <= 15) || kay == 23) {
	    if( ((ODB_0x1n80 >> kay)  & 0x1) != 0 ) {
	      cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n80 not 0 in ODB.",eye,jay,kay);
	      failure = true;
	    }
	  }
	}
      }
      if(failure) {
	cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Problem with 0x1n80.  Exiting",eye,jay);
	return -1;
      }

      address =  0x1080 + (jay << 8);
      ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x1n80);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to write 0x1n80, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x1n80[eye][jay]);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to read 0x1n80, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      // cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n80 %i from ODB",eye,jay,ODB_0x1n80);
      // cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n80 %i from digitizer",eye,jay,Board_0x1n80[eye][jay]);
	
      if(ODB_0x1n80 != Board_0x1n80[eye][jay]) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. 0x1n80 ODB and Board do not match... Exiting ",eye,jay);
	return -1;
      }
       

      //Write 0x1n84	
      //PHA
      if(AMC_MajRev[eye] == 139 ) {
	for(int kay = 10; kay < 32; kay++) {
	  if( ((ODB_0x1n84 >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n84 not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }	  
	}
      }
      //PSD
      if(AMC_MajRev[eye] == 136) {
	for(int kay = 0; kay < 32; kay++) {
	  if(kay == 3 || (kay >= 19 && kay <= 23) || kay >= 25) {
	    if( ((ODB_0x1n84 >> kay)  & 0x1) != 0 ) {
	      cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n84 not 0 in ODB.",eye,jay,kay);
	      failure = true;
	    }
	  }
	}
      }
      if(failure) {
	cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Problem with 0x1n84.  Exiting",eye,jay);
	return -1;
      }

      address =  0x1084 + (jay << 8);
      ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x1n84);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to write 0x1n84, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x1n84[eye][jay]);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to read 0x1n84, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      // cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n84 %i from ODB",eye,jay,ODB_0x1n84);
      // cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n84 %i from digitizer",eye,jay,Board_0x1n84[eye][jay]);
	
      if(ODB_0x1n84 != Board_0x1n84[eye][jay]) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. 0x1n84 ODB and Board do not match... Exiting ",eye,jay);
	return -1;
      }

      //Write 0x1n78	
      //PHA and PSD are the same
      if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
	for(int kay = 10; kay < 32; kay++) {
	  if( ((ODB_0x1n78 >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n78 not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }	  
	}
      }
	
      if(failure) {
	cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Problem with 0x1n78.  Exiting",eye,jay);
	return -1;
      }

      address =  0x1078 + (jay << 8);
      ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x1n78);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to write 0x1n78, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x1n78[eye][jay]);
      if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to read 0x1n78, retval: %i  Exiting",eye,jay,ret);
	return -1;
      }    
      // cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n78 %i from ODB",eye,jay,ODB_0x1n78);
      // cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n78 %i from digitizer",eye,jay,Board_0x1n78[eye][jay]);
	
      if(ODB_0x1n78 != Board_0x1n78[eye][jay]) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. 0x1n78 ODB and Board do not match... Exiting ",eye,jay);
	return -1;
      }


	
      //PHA ONLY!!
      if(AMC_MajRev[eye] == 139 ) {
	//Write 0x1n6C	
	for(int kay = 14; kay < 32; kay++) {
	  if( ((ODB_0x1n6C >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n6C not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }
	}	  
	  
	if(failure) {
	  cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Problem with 0x1n6C.  Exiting",eye,jay);
	  return -1;
	}
	  
	address =  0x106C + (jay << 8);
	ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x1n6C);
	if(ret) {
	  cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to write 0x1n6C, retval: %i  Exiting",eye,jay,ret);
	  return -1;
	}    
	ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x1n6C[eye][jay]);
	if(ret) {
	  cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to read 0x1n6C, retval: %i  Exiting",eye,jay,ret);
	  return -1;
	}    
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n6C %i from ODB",eye,jay,ODB_0x1n6C);
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n6C %i from digitizer",eye,jay,Board_0x1n6C[eye][jay]);
	  
	if(ODB_0x1n6C != Board_0x1n6C[eye][jay]) {
	  cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. 0x1n6C ODB and Board do not match... Exiting ",eye,jay);
	  return -1;
	}	  
      }


      //PSD ONLY!
      if(AMC_MajRev[eye] == 136) {
	//Write 0x1n3C	
	for(int kay = 12; kay < 32; kay++) {
	  if( ((ODB_0x1n3C >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n3C not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }
	}
	  
	if(failure) {
	  cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Problem with 0x1n3C.  Exiting",eye,jay);
	  return -1;
	}
	  
	address =  0x103C + (jay << 8);
	ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x1n3C);
	if(ret) {
	  cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to write 0x1n3C, retval: %i  Exiting",eye,jay,ret);
	  return -1;
	}    
	ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x1n3C[eye][jay]);
	if(ret) {
	  cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to read 0x1n3C, retval: %i  Exiting",eye,jay,ret);
	  return -1;
	}    
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n3C %i from ODB",eye,jay,ODB_0x1n3C);
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n3C %i from digitizer",eye,jay,Board_0x1n3C[eye][jay]);
	  
	if(ODB_0x1n3C != Board_0x1n3C[eye][jay]) {
	  cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. 0x1n3C ODB and Board do not match... Exiting ",eye,jay);
	  return -1;
	}

	//Write 0x1n44	
	for(int kay = 16; kay < 32; kay++) {
	  if( ((ODB_0x1n44 >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n44 not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }
	}
	  
	if(failure) {
	  cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Problem with 0x1n44.  Exiting",eye,jay);
	  return -1;
	}
	  
	address =  0x1044 + (jay << 8);
	ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x1n44);
	if(ret) {
	  cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to write 0x1n44, retval: %i  Exiting",eye,jay,ret);
	  return -1;
	}    
	ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x1n44[eye][jay]);
	if(ret) {
	  cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to read 0x1n44, retval: %i  Exiting",eye,jay,ret);
	  return -1;
	}    
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n44 %i from ODB",eye,jay,ODB_0x1n44);
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n44 %i from digitizer",eye,jay,Board_0x1n44[eye][jay]);
	  
	if(ODB_0x1n44 != Board_0x1n44[eye][jay]) {
	  cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. 0x1n44 ODB and Board do not match... Exiting ",eye,jay);
	  return -1;
	}

	//Write 0x1n54	
	for(int kay = 12; kay < 32; kay++) {
	  if( ((ODB_0x1n54 >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n54 not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }
	}
	  
	if(failure) {
	  cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Problem with 0x1n54.  Exiting",eye,jay);
	  return -1;
	}
	  
	address =  0x1054 + (jay << 8);
	ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x1n54);
	if(ret) {
	  cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to write 0x1n54, retval: %i  Exiting",eye,jay,ret);
	  return -1;
	}    
	ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x1n54[eye][jay]);
	if(ret) {
	  cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to read 0x1n54, retval: %i  Exiting",eye,jay,ret);
	  return -1;
	}    
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n54 %i from ODB",eye,jay,ODB_0x1n54);
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n54 %i from digitizer",eye,jay,Board_0x1n54[eye][jay]);
	  
	if(ODB_0x1n54 != Board_0x1n54[eye][jay]) {
	  cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. 0x1n54 ODB and Board do not match... Exiting ",eye,jay);
	  return -1;
	}

	//Write 0x1n58	
	for(int kay = 16; kay < 32; kay++) {
	  if( ((ODB_0x1n58 >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n58 not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }
	}
	  
	if(failure) {
	  cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Problem with 0x1n58.  Exiting",eye,jay);
	  return -1;
	}
	  
	address =  0x1058 + (jay << 8);
	ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x1n58);
	if(ret) {
	  cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to write 0x1n58, retval: %i  Exiting",eye,jay,ret);
	  return -1;
	}    
	ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x1n58[eye][jay]);
	if(ret) {
	  cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to read 0x1n58, retval: %i  Exiting",eye,jay,ret);
	  return -1;
	}    
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n58 %i from ODB",eye,jay,ODB_0x1n58);
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n58 %i from digitizer",eye,jay,Board_0x1n58[eye][jay]);
	  
	if(ODB_0x1n58 != Board_0x1n58[eye][jay]) {
	  cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. 0x1n58 ODB and Board do not match... Exiting ",eye,jay);
	  return -1;
	}


	//Write 0x1n5C	
	for(int kay = 8; kay < 32; kay++) {
	  if( ((ODB_0x1n5C >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n5C not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }
	}
	  
	if(failure) {
	  cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Problem with 0x1n5C.  Exiting",eye,jay);
	  return -1;
	}
	  
	address =  0x105C + (jay << 8);
	ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x1n5C);
	if(ret) {
	  cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to write 0x1n5C, retval: %i  Exiting",eye,jay,ret);
	  return -1;
	}    
	ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x1n5C[eye][jay]);
	if(ret) {
	  cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to read 0x1n5C, retval: %i  Exiting",eye,jay,ret);
	  return -1;
	}    
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n5C %i from ODB",eye,jay,ODB_0x1n5C);
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n5C %i from digitizer",eye,jay,Board_0x1n5C[eye][jay]);
	  
	if(ODB_0x1n5C != Board_0x1n5C[eye][jay]) {
	  cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. 0x1n5C ODB and Board do not match... Exiting ",eye,jay);
	  return -1;
	}


	/*
	//Write 0x1n7C	
	for(int kay = 12; kay < 32; kay++) {
	if( ((ODB_0x1n7C >> kay)  & 0x1) != 0 ) {
	cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1n7C not 0 in ODB.",eye,jay,kay);
	failure = true;
	}
	}
	  
	if(failure) {
	cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Problem with 0x1n7C.  Exiting",eye,jay);
	return -1;
	}
	  
	address =  0x107C + (jay << 8);
	ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x1n7C);
	if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to write 0x1n7C, retval: %i  Exiting",eye,jay,ret);
	return -1;
	}    
	ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x1n7C[eye][jay]);
	if(ret) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to read 0x1n7C, retval: %i  Exiting",eye,jay,ret);
	return -1;
	}    
	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n7C %i from ODB",eye,jay,ODB_0x1n7C);
	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1n7C %i from digitizer",eye,jay,Board_0x1n7C[eye][jay]);
	  
	if(ODB_0x1n7C != Board_0x1n7C[eye][jay]) {
	cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. 0x1n7C ODB and Board do not match... Exiting ",eye,jay);
	return -1;
	}
	*/
	 

	//Write 0x1nD8	
	for(int kay = 10; kay < 32; kay++) {
	  if( ((ODB_0x1nD8 >> kay)  & 0x1) != 0 ) {
	    cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Bit %i of 0x1nD8 not 0 in ODB.",eye,jay,kay);
	    failure = true;
	  }
	}
	  
	if(failure) {
	  cm_msg( MERROR, "frontend_init", "Board %i, Channel %i. Problem with 0x1nD8.  Exiting",eye,jay);
	  return -1;
	}
	  
	address =  0x10D8 + (jay << 8);
	ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x1nD8);
	if(ret) {
	  cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to write 0x1nD8, retval: %i  Exiting",eye,jay,ret);
	  return -1;
	}    
	ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x1nD8[eye][jay]);
	if(ret) {
	  cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. Failure to read 0x1nD8, retval: %i  Exiting",eye,jay,ret);
	  return -1;
	}    
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1nD8 %i from ODB",eye,jay,ODB_0x1nD8);
	//	cm_msg(MINFO,"frontend_init","Board %i, Channel %i, 0x1nD8 %i from digitizer",eye,jay,Board_0x1nD8[eye][jay]);
	  
	if(ODB_0x1nD8 != Board_0x1nD8[eye][jay]) {
	  cm_msg( MERROR, "frontend_init", ",Board %i, Channel %i. 0x1nD8 ODB and Board do not match... Exiting ",eye,jay);
	  return -1;
	}

	  


      } //End of PSD Only
    }
  }

    
  //Write the channel enable register
  //Check to see if its ok to write to digitizer
  failure = false;
  //PHA and PSD are the same
  if(AMC_MajRev[eye] == 139 || AMC_MajRev[eye] == 136) {
    for(int jay=8; jay < 32; jay++) {
      if((ModCode[eye] == 2 || ModCode[eye] == 3) && jay >= 8) {
	if( ((ODB_0x8120 >> jay)  & 0x1) != 0 ) {
	  cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x8120 not 0 in ODB.",eye,jay);
	  failure = true;
	}
      }
      if((ModCode[eye] == 0 || ModCode[eye] == 1) && jay >= 16) {
	if( ((ODB_0x8120 >> jay)  & 0x1) != 0 ) {
	  cm_msg( MERROR, "frontend_init", "Board %i. Bit %i of 0x8120 not 0 in ODB.",eye,jay);
	  failure = true;
	}
      }
    }
  } 
    
  if(failure) {
    cm_msg( MERROR, "frontend_init", "Board %i. Problem with 0x8120 register value in ODB.  Exiting",eye);
    return -1;
  }
    
  address = 0x8120;
  ret = CAEN_DGTZ_WriteRegister(handle[eye],address,ODB_0x8120);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to write 0x8120... Exiting ",eye);
    return -1;
  }    
  ret = CAEN_DGTZ_ReadRegister(handle[eye],address,&Board_0x8120[eye]);
  if(ret) {
    cm_msg( MERROR, "frontend_init", ",Board %i. Failure to read 0x8120... Exiting ",eye);
    return -1;
  }    
  // cm_msg(MINFO,"frontend_init","Board %i 0x8120 %i from ODB",eye,ODB_0x8120);
  // cm_msg(MINFO,"frontend_init","Board %i 0x8120 %i from digitizer",eye,Board_0x8120[eye]);

  if(ODB_0x8120 != Board_0x8120[eye]) {
    cm_msg( MERROR, "frontend_init", ",Board %i, 0x8120 ODB and Board do not match... Exiting ",eye);
    return -1;
  }
    
  cm_msg(MINFO,"frontend_init","Board %i Programming Channel Registers Complete",eye);

  return 0;
}
