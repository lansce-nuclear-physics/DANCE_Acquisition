//*********************************//
//*    Christopher J. Prokop      *//
//*    cprokop@lanl.gov           *//
//*    functions.h                *// 
//*    Last Edit: 03/06/18        *//  
//*********************************//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//Fucntions
#define Sleep(x) usleep((x)*1000)

int SaveRegImage(char datapath[256],int handle,int runnum, int start);

#endif
