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

#ifndef __M18FX550_H
#define __M18FX550_H

#include "mem/mmc.h"
#include "cpu/pic18f2550.h"

// 32kbyte 18F2550/4550 family
class M18FX550 : public MMC
{
 public:
    M18FX550();

    void poweron_reset(void);
    void soft_reset(void);
    void wakeup_reset(void);

    void code_wb(u32 addr, u8 val);
    u8 code_rb(u32 addr);
    void code_ww(u32 addr, u16 val);
    u16 code_rw(u32 addr);

    void data_sw_wb(u32 addr, u8 val);
    u8 data_sw_rb(u32 addr);

    void data_hw_wb(u32 addr, u8 val);
    u8 data_hw_rb(u32 addr);
    
    u32 bsr_to_flat(u8 addr);
};

#endif

