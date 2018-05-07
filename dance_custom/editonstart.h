/********************************************************************\

  Name:         editonstart.h
  Created by:   A. Couture

  Contents:     This file contains the structure needed for edit on
                start in order to make sure it is properly set.  

  Created on:   28 August 2015

\********************************************************************/

#define EXP_EDIT_DEFINED

typedef struct {
  char      comment[80];
  BOOL      calibration_run;
  BOOL      write_data;
  BOOL      write_auto_elog;
  char      sample[32];
  char      filter[32];
} EXP_EDIT;

#define EXP_EDIT_STR(_name) const char *_name[] = {\
"[.]",\
"Comment = LINK : [35] /Experiment/Run Parameters/Comment",\
"Calibration Run = LINK : [43] /Elog/Elog Parameters/Calibration Run",\
"Logger Active = LINK : [19] /Logger/Write data",\
"Write Auto Elog = LINK : [33] /Elog/Elog Parameters/Write Elog",\
"Sample = LINK : [34] /Elog/Elog Parameters/Sample",\
"Filter = LINK : [34] /Elog/Elog Parameters/Filter",\
"",\
NULL }

