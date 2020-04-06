
////////////////////////////////////////////////////////////////////////
//                                                                    //
//   Software Name: DANCE Data Acquisition and Analysis Package       //
//     Subpackage: DANCE_Analysis                                     //
//   Identifying Number: C18105                                       // 
//                                                                    //
////////////////////////////////////////////////////////////////////////
//                                                                    //
//                                                                    //
// Copyright 2019.                                                    //
// Triad National Security, LLC. All rights reserved.                 //
//                                                                    //
//                                                                    //
//                                                                    //
// This program was produced under U.S. Government contract           //
// 89233218CNA000001 for Los Alamos National Laboratory               //
// (LANL), which is operated by Triad National Security, LLC          //
// for the U.S. Department of Energy/National Nuclear Security        //
// Administration. All rights in the program are reserved by          //
// Triad National Security, LLC, and the U.S. Department of           //
// Energy/National Nuclear Security Administration. The Government    //
// is granted for itself and others acting on its behalf a            //
// nonexclusive, paid-up, irrevocable worldwide license in this       //
// material to reproduce, prepare derivative works, distribute        //
// copies to the public, perform publicly and display publicly,       //
// and to permit others to do so.                                     //
//                                                                    //
// This is open source software; you can redistribute it and/or       //
// modify it under the terms of the GPLv2 License. If software        //
// is modified to produce derivative works, such modified             //
// software should be clearly marked, so as not to confuse it         //
// with the version available from LANL. Full text of the GPLv2       //
// License can be found in the License file of the repository         //
// (GPLv2.0_License.txt).                                             //
//                                                                    //
////////////////////////////////////////////////////////////////////////




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
  BOOL      write_data;
  BOOL      write_auto_elog;
  char      sample[32];
  char      filter[32];
} EXP_EDIT;

#define EXP_EDIT_STR(_name) const char *_name[] = {\
"[.]",\
"Comment = LINK : [35] /Experiment/Run Parameters/Comment",\
"Logger Active = LINK : [19] /Logger/Write data",\
"Write Auto Elog = LINK : [33] /Elog/Elog Parameters/Write Elog",\
"Sample = LINK : [34] /Elog/Elog Parameters/Sample",\
"Filter = LINK : [34] /Elog/Elog Parameters/Filter",\
"",\
NULL }

