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

#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace std;

#include "types.h"
#include "mem/mmc.h"

struct hex_line
{
    u8 byte_count;
    u16 address;
    u8 record_type;
    u8 data[256];;
    u8 cksum;
};

static bool valid_digit(char d)
{
    if (!((d >= '0' && d <= '9') || (d >= 'a' && d <= 'f') || (d >= 'A' && d <= 'F')))
    {
        return false;
    }

    return true;
}

static u8 conv_digit(char *s)
{
    if (*s >= '0' && *s <= '9')
    {
        return *s - '0';
    } else {
        return *s - 'a' + 0xa;
    }
}

static u8 conv_u8(char *s)
{
    u8 ret;

    ret = conv_digit(s) << 4 |
        conv_digit(s+1);

    return ret;
}

static u16 conv_u16(char *s)
{
    u16 ret;

    ret = conv_digit(s) << 12 |
        conv_digit(s+1) << 8 |
        conv_digit(s+2) << 4 |
        conv_digit(s+3);

    return ret;
}

static bool parse_hex_line(char *line, int len, struct hex_line *out)
{
    int c;
    u8 cksum;

    if (line[0] != ':')
    {
        return false;
    }

    for(c = 1; c < len; c++)
    {
        if (line[c] == 0)
        {
            break;
        }

        if (!valid_digit(line[c]))
        {
            return false;
        }

        line[c] = tolower(line[c]);
    }

    line++;

    cksum = 0;

    out->byte_count = conv_u8(line);
    cksum = (cksum + out->byte_count) & 0xff;
    line += 2;
    out->address = conv_u16(line);
    cksum = (cksum + ((out->address >> 8) & 0xff)) & 0xff;
    cksum = (cksum + (out->address & 0xff)) & 0xff;
    line += 4;
    out->record_type = conv_u8(line);
    cksum = (cksum + out->record_type) & 0xff;
    line += 2;

    memset(out->data, 0, 256);
    for(c = 0; c < out->byte_count; c++)
    {
        out->data[c] = conv_u8(line);
        cksum = (cksum + out->data[c]) & 0xff;
        line += 2;
    }
#if 0
    // make dwords more friendly
    for(c = 0; c < out->byte_count; c += 2)
    {
        u8 tmp;

        tmp = out->data[c];
        out->data[c] = out->data[c+1];
        out->data[c+1] = tmp;
    }
#endif
    cksum = cksum ^ 0xff + 1;
    out->cksum = conv_u8(line);

#if 0
    if(cksum != out->cksum)
    {
        printf("warning: invalid cksum\n");
    }
#endif

    return true;
}

bool MMC::load_hex_file(const char *fname)
{
    u32 base_addr = 0;

    int i = 1, c;
    ifstream in;

    in.open(fname);

    if (in.is_open() == false)
    {
        printf("error opening %s\n", fname);
        return false;
    }

    while(in.good())
    {
        char line[256];
        struct hex_line h;

        memset(line, 0, 256);
        in.getline(line, 256);

        if(parse_hex_line(line, strlen(line), &h) == false)
        {
            printf("error in line %d\n", i);
            return false;
        }

        switch(h.record_type)
        {
        case 0:
            // code
            for(c = 0; c < h.byte_count; c++)
            {
                //                printf("%06x: %02x\n", base_addr + h.address + c, h.data[c]);
                code_wb(base_addr + h.address + c, h.data[c]);
            }

            break;

        case 1:
            // EOF
            return true;

            //        case 2:
            // extended segment address record
            //            base_address = h.data[0] << 12 + h.data[1] << 8 + h.data[2] << 4 + h.data[3];

        case 4:
            // extended linear address record
            base_addr = (h.data[0] << 8 | h.data[1]) << 16;
            break;

        default:
            assert(!"unimplmented");
            return false;
        }
    }

    return false;
}

u32 MMC::access_bank_to_flat(u8 offset)
{
    if (offset <= 0x5f)
    {
        return offset;
    }

    return offset + 0xf00;
}


void MMC::init(void)
{
    code = (u8 *) malloc(code_size);
    assert(code);
    memset(code, 0, code_size);

    data = (u8 *) malloc(data_size);
    assert(data);
    memset(data, 0, data_size);

    eeprom = (u8 *) malloc(eeprom_size);
    assert(eeprom);
    memset(eeprom, 0, eeprom_size);

    stack = (u32 *) malloc(stack_size * 4);
    assert(stack);
    memset(stack, 0, stack_size);
}

void MMC::code_wb(u32 addr, u8 val)
{
    assert(addr < code_size);
    code[addr] = val;
}

u8 MMC::code_rb(u32 addr)
{
    assert(addr < code_size);
    return code[addr];
}

void MMC::code_ww(u32 addr, u16 val)
{
    assert(addr < code_size - 1);
    *(u16 *)(&code[addr]) = val;
}


u16 MMC::code_rw(u32 addr)
{
    assert(addr < code_size - 1);
    return *(u16 *)(&code[addr]);
}

void MMC::data_hw_wb(u32 addr, u8 val)
{
    assert(addr < data_size);
    data[addr] = val;
}

u8 MMC::data_hw_rb(u32 addr)
{
    assert(addr < data_size);
    return data[addr];
}

void MMC::data_sw_wb(u32 addr, u8 val)
{
    data_hw_wb(addr, val);
}

u8 MMC::data_sw_rb(u32 addr)
{
    return data_hw_rb(addr);
}

void MMC::eeprom_wb(u32 addr, u8 val)
{
    assert(addr < eeprom_size);
    eeprom[addr] = val;
}

u8 MMC::eeprom_rb(u32 addr)
{
    assert(addr < eeprom_size);
    return eeprom[addr];
}

u32 MMC::stack_rd(u32 addr)
{
    assert((addr - 1) < stack_size);
    return stack[addr - 1];
}

void MMC::stack_wd(u32 addr, u32 data)
{
    assert((addr - 1) < stack_size);
    stack[addr - 1] = data;
}
