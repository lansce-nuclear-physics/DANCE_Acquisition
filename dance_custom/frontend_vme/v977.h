#ifndef __V977_LANL__
#define __V977_LANL__

//
// v977.h
//
// Description:
//   This header contains information for the CAEN v977 i/o register
//   At this point, it is all const variable declarations, but could
//   for more later. The documentation of the address map can be 
//   found in the v977 manual.
//
//  Author:
//    A. Couture
//
//  Revision History
//  Initial write
//    8 May 2013

namespace V977 {
  const unsigned int channels = 16;
  const uint32_t iset = 0x0000;
  const uint32_t imask = 0x0002;
  const uint32_t iread = 0x0004;
  const uint32_t singleh_read = 0x0006;
  const uint32_t multih_read = 0x0008;
  const uint32_t oset = 0x000A;
  const uint32_t omask = 0x000C;
  const uint32_t interrupt_mask = 0x000E;
  const uint32_t clear = 0x0010;
  const uint32_t singleh_readclear = 0x0016;
  const uint32_t multih_readclear = 0x0018;
  const uint32_t test = 0x001A;
  const uint32_t interrupt_level = 0x0020;
  const uint32_t interrupt_vector = 0x0022;
  const uint32_t serial = 0x0024;
  const uint32_t firmware = 0x0026;
  const uint32_t control = 0x0028;
  const uint32_t dummy = 0x002A;
  const uint32_t soft_reset = 0x002E;
}

#endif
