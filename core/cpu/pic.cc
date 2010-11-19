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

#include <stdio.h>

#include "cpu/pic.h"

PIC::PIC()
{
    clk = 0;
}

void PIC::debug_pic16_insn(pic16_decoded_insn *decode, pic16_insn insn)
{
    printf("%04x: %s\t", PC, decode->insn_name);

    switch(decode->type)
    {
    case PIC16_insn_daf:
        printf("%02x (a=%d d=%d)", insn.daf.f, insn.daf.a, insn.daf.d);
        break;

    case PIC16_insn_af:
        printf("%02x (a=%d)", insn.af.f, insn.af.a);
        break;

    case PIC16_insn_ef:
        printf("%04x", insn.ef.f);
        break;

    case PIC16_insn_baf:
        printf("%02x (b=%d a=%d)", insn.baf.f, insn.baf.b, insn.baf.a);
        break;

    case PIC16_insn_n:
        printf("%02x", insn.n.n);
        break;

    case PIC16_insn_en:
        printf("%04x", insn.en.n);
        break;

    case PIC16_insn_sk:
        printf("%02x (s=%d)", insn.sk.k, insn.sk.s);
        break;

    case PIC16_insn_k:
        printf("%02x", insn.k.k);
        break;

    case PIC16_insn_ek:
        printf("%04x", insn.ek.k);
        break;

    case PIC16_insn_fk:
        printf("%04x (f=%d)", insn.fk.k, insn.fk.f);
        break;

    case PIC16_insn_s:
        printf("(s=%d)", insn.s.s);
        break;

    case PIC16_insn_nn:
        printf("(n=%d)", insn.nn.n);
        break;

    case PIC16_insn_o:
        break;

    case PIC16_insn_ox:
        printf("%04x", insn.ox.x);
        break;

    default:
        assert(!"unexpected");
    }

    printf("\n");
}

pic16_decoded_insn *PIC::decode(pic16_insn insn)
{
    pic16_decoded_insn *decoded;

    decoded = decode_table;
    while(decoded->type != PIC16_insn_NULL)
    {
        if ((insn.o.o & decoded->opcode_mask) == decoded->opcode)
        {
            return decoded;
        }

        decoded++;
    }

    return NULL;
}

void PIC::step(void)
{
    pic16_insn insn;
    pic16_decoded_insn *decoded;

    // fetch next instruction
    insn = fetch();

    // decode loop
    decoded = decode(insn);
    if (decoded)
    {
        debug_pic16_insn(decoded, insn);
        dispatch(decoded, insn);

        if (!(decoded->flags & PIC16I_NO_CLK_UPDATE))
        {
            clock_step(decoded->clocks);
        } 
    } else {
        printf("%04x: illegal instruction (%04x)\n", PC, insn.o.o);
        exit(1);
    }
}

void PIC::clock_step(int n)
{
    clk += n;
}
