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

typedef struct PICRegisterBitRec
{
    char *name;
    u32 bit_start;
    u32 bit_end;
} PICRegisterBit;

typedef struct PICRegisterRec
{
    char *name;
    u32 addr;
    u32 len;

    u32 readMask;
    u32 writeMask;

    PICRegisterBit *bits;
    PICRegister *sub;
} PICRegister;

typedef struct PICRegisterFileRec
{
public:
    PICRegister *registers;
    u8 *changetable;
} PICRegisterFile;

#endif
