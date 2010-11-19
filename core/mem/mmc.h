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

#ifndef __MMC_H
#define __MMC_H

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "types.h"

class MMC
{
 protected:
    u8 *code;
    u8 *data;
    u8 *eeprom;
    u32 *stack;

    u32 code_size;
    u32 data_size;
    u32 eeprom_size;
    u32 stack_size;

    void init(void);

 public:
    virtual void code_wb(u32 addr, u8 val);
    virtual u8 code_rb(u32 addr);
    virtual void code_ww(u32 addr, u16 val);
    virtual u16 code_rw(u32 addr);

    // software writes, can have side effects
    virtual void data_sw_wb(u32 addr, u8 val);
    virtual u8 data_sw_rb(u32 addr);
    // hw updates, no side effects
    virtual void data_hw_wb(u32 addr, u8 val);
    virtual u8 data_hw_rb(u32 addr);

    virtual void eeprom_wb(u32 addr, u8 val);
    virtual u8 eeprom_rb(u32 addr);

    virtual u32 stack_rd(u32 addr);
    virtual void stack_wd(u32 addr, u32 data);

    virtual u32 bsr_to_flat(u8 offset) = 0;
    virtual u32 access_bank_to_flat(u8 offset);

    virtual void poweron_reset(void) = 0;
    virtual void soft_reset(void) = 0;
    virtual void wakeup_reset(void) = 0;

    bool load_hex_file(const char *fname);
};

#endif
