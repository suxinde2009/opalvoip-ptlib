/*
 * $Id: timeint.h,v 1.1 1995/01/23 18:43:27 craigs Exp $
 *
 * Portable Windows Library
 *
 * Operating System Classes Interface Declarations
 *
 * Copyright 1993 Equivalence
 *
 * $Log: timeint.h,v $
 * Revision 1.1  1995/01/23 18:43:27  craigs
 * Initial revision
 *
 * Revision 1.1  1994/04/12  08:31:05  robertj
 * Initial revision
 *
 */

#ifndef _PTIMEINTERVAL

#pragma interface

///////////////////////////////////////////////////////////////////////////////
// PTimeInterval

#include <time.h>

#include "../../common/timeint.h"
  public:
    PTimeInterval & PTimeInterval::operator =(const PTimeInterval & timeInterval);
};

#define PMaxTimeInterval PTimeInterval((long)0x7fffffff)

#endif
