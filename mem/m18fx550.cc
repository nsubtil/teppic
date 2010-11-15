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

#include "mem/m18fx550.h"

M18FX550::M18FX550()
{
    code_size = 32768;
    // address space is 4096 bytes long, but half of it is unimplemented
    data_size = 4096;
    eeprom_size = 256;
    stack_size = 31;
    
    MMC::init();
}

void M18FX550::poweron_reset(void)
{
    memset(data, 0, data_size);
    memset(stack, 0, stack_size * 4);

    data[INTCON2] = 0xFF;
    data[INTCON3] = 0xC0;
    data[  FSR0L] = 0xEE;
    data[   WREG] = 0xEE;
    data[  FSR1L] = 0xEE;
    data[  FSR2L] = 0xEE;
    data[  TMR0L] = 0xEE;
    data[  T0CON] = 0xFF;
    // XXX: bit 3 of OSCCON depends on the fuse config
    data[ OSCCON] = 0x40;
    data[HLVDCON] = 0x05;
    // XXX: bit 6 of RCON depends on fuse config SBOREN (brown-out enable)
    data[   RCON] = 0x1C;
    data[    PR2] = 0xFF;
    // XXX: ADCON1 depends on fuse config
    data[BAUDCON] = 0x40;
    data[  CMCON] = 0x07;
    data[  TXSTA] = 0x02;
    data[   IPR2] = 0xFF;
    data[   IPR1] = 0xFF;
    //    data[  TRISE] = 0x0F;
    //    data[  TRISD] = 0xFF;
    data[  TRISC] = 0xFF;
    data[  TRISB] = 0xFF;
    data[  TRISA] = 0xFF;
}

void M18FX550::soft_reset(void)
{
    assert(!"unimplemented");
}

void M18FX550::wakeup_reset(void)
{
    assert(!"unimplemented");
}

void M18FX550::code_wb(u32 addr, u8 val)
{
    if (addr < code_size)
    {
        code[addr] = val;
    } else if (addr < 0x200000)
    {
        assert(!"writing code NOP area");
    } else if (addr >= 0x300000 && addr <= 0x30000E) {
        // fuse write
    } else {
        assert(!"code write out of bounds");
    }
}

u8 M18FX550::code_rb(u32 addr)
{
    if (addr < code_size)
    {
        return code[addr];
    } else if (addr < 0x200000) {
        // NOP area
        return 0x0;
    } else if (addr >= 0x300000 && addr <= 0x30000E) {
        // fuse read
        return code[addr];
    } else {
        assert(!"code read out of bounds");
        return 0x0;
    }
}

void M18FX550::code_ww(u32 addr, u16 val)
{
    if (addr < code_size - 1)
    {
        *(u16 *)(&code[addr]) = val;
    } else if (addr < code_size) {
        // boundary condition: first byte is within code area, second byte is not
        assert(!"code write spills over into NOP area");
    } else if (addr < 0x200000) {
        assert(!"writing code NOP area");
    } else {
        assert(!"code write out of bounds");
    }
}

u16 M18FX550::code_rw(u32 addr)
{
    if (addr < code_size - 1)
    {
        return *(u16 *)(&code[addr]);
    } else if (addr < code_size) {
        // read spills over into NOP area
        return (u16)code[addr];
    } else if (addr < 0x200000) {
        // NOP area
        return 0x0;
    } else {
        assert(!"code read out of bounds");
        return 0x0;
    }
}

void M18FX550::data_hw_wb(u32 addr, u8 val)
{
    if (addr < 0x7ff ||
        (addr >= 0xf00 && addr <= 0xfff))
    {
        data[addr] = val;
    } else if (addr >= 0x800 && addr <= 0xeff) {
        // unused (bsr bank 8 to 14)
    } else {
        assert(!"data write out of bounds");
    }
}

u8 M18FX550::data_hw_rb(u32 addr)
{
    if (addr < 0x7ff ||
        (addr >= 0xf00 && addr <= 0xfff))
    {
        return data[addr];
    } else if (addr >= 0x800 && addr <= 0xeff) {
        // unused, read as 0
        return 0x0;
    } else {
        assert(!"data read out of bounds");
    }
}

void M18FX550::data_sw_wb(u32 addr, u8 val)
{
    data_hw_wb(addr, val);
}

u8 M18FX550::data_sw_rb(u32 addr)
{
    return data_hw_rb(addr);
}

u32 M18FX550::bsr_to_flat(u8 addr)
{
    return addr + 
        ((data_hw_rb((u32) BSR) & 0x0f) << 4);
}
