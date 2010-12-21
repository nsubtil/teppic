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

#include <assert.h>

#include "cpu/pic_registers.h"

PICRegisterFile::PICRegisterFile(PICRegister *r)
{
    registers = r;

    register_count = 0;
    while(registers[register_count].name != NULL)
    {
        register_count++;
    }
}

int PICRegisterFile::num_registers(void)
{
    return register_count;
}

const PICRegister *PICRegisterFile::get_register(int idx)
{
    assert(idx < register_count);
    return &registers[idx];
}
