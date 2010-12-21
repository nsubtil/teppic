/*
  Copyright (C) 2010, Nuno Subtil

  This file is part of Teppic.

  Teppic is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Teppic is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with Teppic.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __PIC_REGISTERS_H
#define __PIC_REGISTERS_H

#include "types.h"

#ifndef NULL
#define NULL 0
#endif

typedef struct PICRegisterBitRec
{
    const char *name;
    u32 bit;
} PICRegisterBit;

typedef struct PICRegisterAliasRec
{
    const char *name;
    u32 addr;
} PICRegisterAlias;

typedef struct PICRegisterRec
{
    const char *name;
    u32 addr;
    u32 len;

    u32 readMask;
    u32 writeMask;

    PICRegisterBit *bits;
    PICRegisterAlias *aliases;
} PICRegister;

class PICRegisterFile
{
private:
    PICRegister *registers;
    int register_count;

public:
    PICRegisterFile(PICRegister *register_list);

    int num_registers(void);
    const PICRegister *get_register(int idx);
};

#endif
