//*********************************//
//*    Christopher J. Prokop      *//
//*    cprokop@lanl.gov           *//
//*    functions.cpp              *// 
//*    Last Edit: 03/06/18        *//  
//*********************************//

//File includes
#include "functions.h"

//C/C++ includes
#include <fstream>

// CAEN includes
#include "CAENDigitizer.h"
#include "CAENDigitizerType.h"


//This function saves the register image
int SaveRegImage(char datapath[256], int handle, int runnum, int start) {
  FILE *regs;
  char fname[100];
  int ret;
  uint32_t addr, reg, ch;
  if(start) {
    sprintf(fname, "%s/register_images/run%06d.%02d.start.txt",datapath,runnum,handle);
  }
  else {
    sprintf(fname, "%s/register_images/run%06d.%02d.end.txt",datapath,runnum,handle);
  }
  regs=fopen(fname, "w");
  if (regs==NULL)
    return -1;
  
  fprintf(regs, "[COMMON REGS]\n");
  for(addr=0x8000; addr <= 0x8200; addr += 4) {
    ret = CAEN_DGTZ_ReadRegister(handle, addr, &reg);
    if (ret==0) {
      fprintf(regs, "%04X : %08X\n", addr, reg);
    } else {
      fprintf(regs, "%04X : --------\n", addr);
      Sleep(1);
    }
  }
  for(addr=0xEF00; addr <= 0xEF34; addr += 4) {
    ret = CAEN_DGTZ_ReadRegister(handle, addr, &reg);
    if (ret==0) {
      fprintf(regs, "%04X : %08X\n", addr, reg);
    } else {
      fprintf(regs, "%04X : --------\n", addr);
      Sleep(1);
    }
  }
  for(addr=0xF000; addr <= 0xF088; addr += 4) {
    ret = CAEN_DGTZ_ReadRegister(handle, addr, &reg);
    if (ret==0) {
      fprintf(regs, "%04X : %08X\n", addr, reg);
    } else {
      fprintf(regs, "%04X : --------\n", addr);
      Sleep(1);
    }
  }
  
  for(ch=0; ch<16; ch++) {
    fprintf(regs, "[CHANNEL %d]\n", ch);
    for(addr=0x1000+(ch<<8); addr <= (0x10FF+(ch<<8)); addr += 4) {
      if (addr != 0x1090+(ch<<8)) {
	ret = CAEN_DGTZ_ReadRegister(handle, addr, &reg);
	if (ret==0) {
	  fprintf(regs, "%04X : %08X\n", addr, reg);
	} else {
	  fprintf(regs, "%04X : --------\n", addr);
	  Sleep(1);
	}
      }
    }
  }
  
  fclose(regs);
  return 0;
}
