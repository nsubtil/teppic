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
#include <stdio.h>

#include "cpu/pic18f2550.h"
#include "mem/m18fx550.h"

#define CLASS PIC18F2550
static pic16_decoded_insn pic18f2550_decode_table[] = {
    PIC16I   ( ADDLW,    k,  0x0F00),
    PIC16I   ( ADDWF,  daf,  0x2400),
    PIC16I   (ADDWFC,  daf,  0x2000),
    PIC16I   ( ANDLW,    k,  0x0B00),
    PIC16I   ( ANDWF,  daf,  0x1400),
    PIC16IFC (    BC,    n,  0xE200, 2, PIC16I_NO_PC_UPDATE | PIC16I_NO_CLK_UPDATE),
    PIC16I   (   BCF,  baf,  0x9000),
    PIC16IFC (    BN,    n,  0xE600, 2, PIC16I_NO_PC_UPDATE | PIC16I_NO_CLK_UPDATE),
    PIC16IFC (   BNC,    n,  0xE300, 2, PIC16I_NO_PC_UPDATE | PIC16I_NO_CLK_UPDATE),
    PIC16IFC (   BNN,    n,  0xE700, 2, PIC16I_NO_PC_UPDATE | PIC16I_NO_CLK_UPDATE),
    PIC16IFC (  BNOV,    n,  0xE500, 2, PIC16I_NO_PC_UPDATE | PIC16I_NO_CLK_UPDATE),
    PIC16IFC (   BNZ,    n,  0xE100, 2, PIC16I_NO_PC_UPDATE | PIC16I_NO_CLK_UPDATE),
    PIC16IFC (   BRA,   en,  0xD000, 2, PIC16I_NO_PC_UPDATE),
    PIC16I   (   BSF,  baf,  0x8000),
    PIC16IFC ( BTFSC,  baf,  0xB000, 2, PIC16I_NO_PC_UPDATE | PIC16I_NO_CLK_UPDATE),
    PIC16IFC ( BTFSS,  baf,  0xA000, 2, PIC16I_NO_PC_UPDATE | PIC16I_NO_CLK_UPDATE),
    PIC16I   (   BTG,  baf,  0x7000),
    PIC16IFC (   BOV,    n,  0xE400, 2, PIC16I_NO_PC_UPDATE | PIC16I_NO_CLK_UPDATE),
    PIC16IFC (    BZ,    n,  0xE000, 2, PIC16I_NO_PC_UPDATE | PIC16I_NO_CLK_UPDATE),
    PIC16IFC (  CALL,   sk,  0xEC00, 2, PIC16I_NO_PC_UPDATE | PIC16I_NO_CLK_UPDATE | PIC16I_TWO_WORD_INSN),
    PIC16I   (  CLRF,   af,  0x6A00),
    PIC16I   (CLRWDT,    o,  0x0004),
    PIC16I   (  COMF,  daf,  0x1C00),
    PIC16IFC (CPFSEQ,   af,  0x6200, 2, PIC16I_NO_PC_UPDATE | PIC16I_NO_CLK_UPDATE),
    PIC16IFC (CPFSGT,   af,  0x6400, 2, PIC16I_NO_PC_UPDATE | PIC16I_NO_CLK_UPDATE),
    PIC16IFC (CPFSLT,   af,  0x6000, 2, PIC16I_NO_PC_UPDATE | PIC16I_NO_CLK_UPDATE),
    PIC16I   (   DAW,    o,  0x0007),
    PIC16I   (  DECF,  daf,  0x0400),
    PIC16IFC (DECFSZ,  daf,  0x2C00, 2, PIC16I_NO_PC_UPDATE | PIC16I_NO_CLK_UPDATE),
    PIC16IFC (DCFSNZ,  daf,  0x4C00, 2, PIC16I_NO_PC_UPDATE | PIC16I_NO_CLK_UPDATE),
    PIC16IFC (  GOTO,    k,  0xEF00, 2, PIC16I_NO_PC_UPDATE | PIC16I_TWO_WORD_INSN),
    PIC16I   (  INCF,  daf,  0x2800),
    PIC16IFC (INCFSZ,  daf,  0x3C00, 2, PIC16I_NO_PC_UPDATE | PIC16I_NO_CLK_UPDATE),
    PIC16IFC (INFSNZ,  daf,  0x4800, 2, PIC16I_NO_PC_UPDATE | PIC16I_NO_CLK_UPDATE),
    PIC16I   ( IORLW,    k,  0x0900),
    PIC16I   ( IORWF,  daf,  0x1000),
    PIC16IFC (  LFSR,   fk,  0xEE00, 2, PIC16I_TWO_WORD_INSN),
    PIC16I   (  MOVF,  daf,  0x5000),
    PIC16IFC ( MOVFF,   ef,  0xC000, 2, PIC16I_TWO_WORD_INSN),
    PIC16I   ( MOVLB,    k,  0x0100),
    PIC16I   ( MOVLW,    k,  0x0E00),
    PIC16I   ( MOVWF,   af,  0x6E00),
    PIC16I   ( MULLW,    k,  0x0D00),
    PIC16I   ( MULWF,   af,  0x0200),
    PIC16I   (  NEGF,   af,  0x6C00),
    PIC16IFC (   NOP,    o,  0x0000, 1, PIC16I_TWO_WORD_INSN),
    PIC16I   (   POP,    o,  0x0006),
    PIC16I   (  PUSH,    o,  0x0005),
    PIC16IFC ( RCALL,   en,  0xD800, 2, PIC16I_NO_PC_UPDATE),
    PIC16I   ( RESET,    o,  0x00FF),
    PIC16IFC (RETFIE,    s,  0x0010, 2, PIC16I_NO_PC_UPDATE),
    PIC16IFC ( RETLW,    k,  0x0C00, 2, PIC16I_NO_PC_UPDATE),
    PIC16IFC (RETURN,    s,  0x0012, 2, PIC16I_NO_PC_UPDATE),
    PIC16I   (  RLCF,  daf,  0x3400),
    PIC16I   ( RLNCF,  daf,  0x4400),
    PIC16I   (  RRCF,  daf,  0x3000),
    PIC16I   ( RRNCF,  daf,  0x4000),
    PIC16I   (  SETF,   af,  0x6800),
    PIC16I   ( SLEEP,    o,  0x0003),
    PIC16I   (SUBFWB,  daf,  0x5400),
    PIC16I   ( SUBLW,    k,  0x0800),
    PIC16I   ( SUBWF,  daf,  0x5C00),
    PIC16I   (SUBWFB,  daf,  0x5800),
    PIC16I   ( SWAPF,  daf,  0x3800),
    PIC16IFC ( TBLRD,   nn,  0x0008, 2, 0),
    PIC16IFC ( TBLWT,   nn,  0x000C, 2, 0),
    PIC16IFC (TSTFSZ,   af,  0x6600, 2, PIC16I_NO_PC_UPDATE | PIC16I_NO_CLK_UPDATE),
    PIC16I   ( XORLW,    k,  0x0A00),
    PIC16I   ( XORWF,  daf,  0x1800),

    PIC16I_END
};
#undef CLASS

PIC18F2550::PIC18F2550()
{
    mmc = new M18FX550();
    PIC::decode_table = pic18f2550_decode_table;
}

void PIC18F2550::poweron_reset(void)
{
    WS = 0;
    BSRS = 0;
    STATUSS = 0;

    PC = 0;
    WDT = 0;

    mmc->poweron_reset();
}

void PIC18F2550::soft_reset(void)
{
    assert(!"unimplemented");
}

void PIC18F2550::wakeup_reset(void)
{
    assert(!"unimplemented");
}

void PIC18F2550::dispatch(pic16_decoded_insn *decode, pic16_insn insn)
{
    (decode->exec)(this, insn);

    if (!(decode->flags & PIC16I_NO_PC_UPDATE))
    {
        if (decode->flags & PIC16I_TWO_WORD_INSN)
        {
            PC = PC + 4;
        } else {
            PC = PC + 2;
        }
    }

    REGWR(PCL, (PC & 0xff));
}

void PIC18F2550::callstack_push(u32 dword)
{
    u32 addr;
    addr = REGRD(STKPTR);
    addr++;

    mmc->stack_wd(addr, dword);

    REGWR(TOSL, (dword & 0x0000ff));
    REGWR(TOSH, (dword & 0x00ff00) >> 8);
    REGWR(TOSU, (dword & 0xff0000) >> 16);
    REGWR(STKPTR, addr);
}

u32 PIC18F2550::callstack_pop(void)
{
    u32 addr, val;
    addr = REGRD(STKPTR);

    if (addr & (1 << 6)) // STKFUL
    {
        return 0;
    }

    val = mmc->stack_rd(addr);
    REGWR(STKPTR, addr - 1);

    return val;
}

void PIC18F2550::ADDLW(pic16_insn i)
{
    u32 res;

    res = alu_add8(REGRD(WREG), i.k.k);
    alu_set_flags(res, ST(N) | ST(OV) | ST(C) | ST(DC) | ST(Z));
    REGWR(WREG, RES8(res));
}

void PIC18F2550::ADDWF(pic16_insn i)
{
    u32 addr, res;
    u8 f;

    addr = FLAT(i.daf.f, i.daf.a);
    f = FL_MEMRD(addr);
    res = alu_add8(REGRD(WREG), f);
    alu_set_flags(res, ST(N) | ST(OV) | ST(C) | ST(DC) | ST(Z));

    if (i.daf.d == 0)
    {
        REGWR(WREG, RES8(res));
    } else {
        FL_MEMWR(addr, RES8(res));
    }
}

void PIC18F2550::ADDWFC(pic16_insn i)
{
    u32 addr, res;
    u8 f;

    addr = FLAT(i.daf.f, i.daf.a);
    f = FL_MEMRD(addr);

    res = alu_add8(REGRD(WREG), f);
    alu_set_flags(res, ST(N) | ST(OV) | ST(C) | ST(DC) | ST(Z));

    if (REGRD(STATUS) & ST(C))
    {
        u32 res2;

        res2 = alu_add8(RES8(res), 1);
        alu_set_flags(res2, ST(N) | ST(Z));

        if (CF8(res2))
        {
            SET(C);
        }

        if (OF8(res2))
        {
            SET(OV);
        }

        if (DF8(res2))
        {
            SET(DC);
        }

        res = res2;
    }

    if (i.daf.d == 0)
    {
        REGWR(WREG, RES8(res));
    } else {
        FL_MEMWR(i.daf.f, RES8(res));
    }
}

void PIC18F2550::ANDLW(pic16_insn i)
{
    u8 res;

    res = REGRD(WREG) & i.k.k;

    SET_N(res);
    SET_Z(res);
}

void PIC18F2550::ANDWF(pic16_insn i)
{
    u32 addr;
    u8 res;

    addr = FLAT(i.daf.f, i.daf.a);
    res = REGRD(WREG) & FL_MEMRD(addr);

    SET_N(res);
    SET_Z(res);

    if (i.daf.d == 0)
    {
        REGWR(WREG, res);
    } else {
        FL_MEMWR(addr, res);
    }
}

void PIC18F2550::BC(pic16_insn i)
{
    u32 addpc, clocks;

    if (REGRD(STATUS) & ST(C))
    {
        // sign-extend i.n.n into addpc
        if (ISNEG8(i.n.n))
        {
            addpc = i.n.n | 0xffffff00;
        } else {
            addpc = i.n.n;
        }

        addpc = 2 + 2 * addpc;
        clocks = 2;
    } else {
        addpc = 2;
        clocks = 1;
    }

    PC = PC + addpc;
    clock_step(clocks);
}

void PIC18F2550::BCF(pic16_insn i)
{
    u32 addr;
    u8 val;

    addr = FLAT(i.baf.f, i.baf.a);
    val = FL_MEMRD(addr);
    val &= ~(1 << i.baf.b);
    FL_MEMWR(addr, val);
}

void PIC18F2550::BN(pic16_insn i)
{
    u32 addpc, clocks;

    if (REGRD(STATUS) & ST(N))
    {
        // sign-extend i.n.n into addpc
        if (ISNEG8(i.n.n))
        {
            addpc = i.n.n | 0xffffff00;
        } else {
            addpc = i.n.n;
        }

        addpc = 2 + 2 * addpc;
        clocks = 2;
    } else {
        addpc = 2;
        clocks = 1;
    }

    PC = PC + addpc;
    clock_step(clocks);
}

void PIC18F2550::BNC(pic16_insn i)
{
    u32 addpc, clocks;

    if (!(REGRD(STATUS) & ST(C)))
    {
        // sign-extend i.n.n into addpc
        if (ISNEG8(i.n.n))
        {
            addpc = i.n.n | 0xffffff00;
        } else {
            addpc = i.n.n;
        }

        addpc = 2 + 2 * addpc;
        clocks = 2;
    } else {
        addpc = 2;
        clocks = 1;
    }

    PC = PC + addpc;
    clock_step(clocks);
}

void PIC18F2550::BNN(pic16_insn i)
{
    u32 addpc, clocks;

    if (!(REGRD(STATUS) & ST(N)))
    {
        if (ISNEG8(i.n.n))
        {
            addpc = i.n.n | 0xffffff00;
        } else {
            addpc = i.n.n;
        }

        addpc = 2 + 2 * addpc;
        clocks = 2;
    } else {
        addpc = 2;
        clocks = 1;
    }

    PC = PC + addpc;
    clock_step(clocks); 
}

void PIC18F2550::BNOV(pic16_insn i)
{
    u32 addpc, clocks;

    if (!(REGRD(STATUS) & ST(OV)))
    {
        if (ISNEG8(i.n.n))
        {
            addpc = i.n.n | 0xffffff00;
        } else {
            addpc = i.n.n;
        }

        addpc = 2 + 2 * addpc;
        clocks = 2;
    } else {
        addpc = 2;
        clocks = 1;
    }

    PC = PC + addpc;
    clock_step(clocks); 
}

void PIC18F2550::BNZ(pic16_insn i)
{
    u32 addpc, clocks;

    if (!(REGRD(STATUS) & ST(Z)))
    {
        if (ISNEG8(i.n.n))
        {
            addpc = i.n.n | 0xffffff00;
        } else {
            addpc = i.n.n;
        }

        addpc = 2 + 2 * addpc;
        clocks = 2;
    } else {
        addpc = 2;
        clocks = 1;
    }

    PC = PC + addpc;
    clock_step(clocks);
}

void PIC18F2550::BRA(pic16_insn i)
{
    int addpc;

    if (i.en.n & (1 << 10))
    {
        addpc = i.en.n | 0xfffff800;
    } else {
        addpc = i.en.n;
    }

    PC = PC + 2 + 2 * addpc;
}

void PIC18F2550::BSF(pic16_insn i)
{
    u32 addr;
    u8 val;
    
    addr = FLAT(i.baf.f, i.baf.a);
    val = FL_MEMRD(addr);
    val |= 1 << i.baf.b;
    FL_MEMWR(addr, val);
}

void PIC18F2550::BTFSC(pic16_insn i)
{
    u32 addr, addpc, clocks;
    u8 val;
    
    addr = FLAT(i.baf.f, i.baf.a);
    val = FL_MEMRD(addr);
    if (val & (1 << i.baf.b))
    {
        // bit set, execute
        addpc = 2;
        clocks = 1;
    } else {
        // bit clear, skip

        // see if next instruction is a two-word instruction
        pic16_insn nexti;
        pic16_decoded_insn *decoded;

        nexti = fetch(PC + 2);
        decoded = decode(nexti);

        if (decoded &&
            (decoded->flags & PIC16I_TWO_WORD_INSN))
        {
            addpc = 6;
            clocks = 3;
        } else {
            addpc = 4;
            clocks = 2;
        }
    }

    PC = PC + addpc;
    clock_step(clocks);
}

void PIC18F2550::BTFSS(pic16_insn i)
{
    u32 addr, addpc, clocks;
    u8 val;
    
    addr = FLAT(i.baf.f, i.baf.a);
    val = FL_MEMRD(addr);
    if (!(val & (1 << i.baf.b)))
    {
        // bit clear, execute
        addpc = 2;
        clocks = 1;
    } else {
        // bit set, skip

        // see if next instruction is a two-word instruction
        pic16_insn nexti;
        pic16_decoded_insn *decoded;

        nexti = fetch(PC + 2);
        decoded = decode(nexti);

        if (decoded && 
            (decoded->flags & PIC16I_TWO_WORD_INSN))
        {
            addpc = 6;
            clocks = 3;
        } else {
            addpc = 4;
            clocks = 2;
        }
    }

    PC = PC + addpc;
    clock_step(clocks);
}

void PIC18F2550::BTG(pic16_insn i)
{
    u32 addr;
    u8 val;

    addr = FLAT(i.baf.f, i.baf.a);
    val = FL_MEMRD(addr);
    val = val & ~(1 << i.baf.b) |
        ~(val & (1 << i.baf.b)) & (1 << i.baf.b);

    FL_MEMWR(addr, val);
}

void PIC18F2550::BOV(pic16_insn i)
{
    u32 addpc, clocks;

    if (REGRD(STATUS) & ST(OV))
    {
        if (ISNEG8(i.n.n))
        {
            addpc = i.n.n | 0xffff0000;
        } else {
            addpc = i.n.n;
        }

        addpc = 2 + 2 * addpc;
        clocks = 2;
    } else {
        addpc = 2;
        clocks = 1;
    }

    PC = PC + addpc;
    clock_step(clocks);
}

void PIC18F2550::BZ(pic16_insn i)
{
    u32 addpc, clocks;

    if (REGRD(STATUS) & ST(Z))
    {
        if (ISNEG8(i.n.n))
        {
            addpc = i.n.n | 0xffff0000;
        } else {
            addpc = i.n.n;
        }

        addpc = 2 + 2 * addpc;
        clocks = 2;
    } else {
        addpc = 2;
        clocks = 1;
    }

    PC = PC + addpc;
    clock_step(clocks);
}

void PIC18F2550::CALL(pic16_insn i)
{
    u32 dest;
    pic16_insn i2;

    i2 = fetch(PC + 2);
    assert(i2.ek.o == 0xF);

    dest = (i2.ek.k << 8) | i.sk.k;
    dest <<= 1;

    // push ret addr
    callstack_push(PC + 4);
    
    if (i.sk.s)
    {
        WS = REGRD(WREG);
        STATUSS = REGRD(STATUS);
        BSRS = REGRD(BSR);
    }

    PC = dest;
    clock_step(2);
}

void PIC18F2550::CLRF(pic16_insn i)
{
    u32 addr;

    addr = FLAT(i.af.f, i.af.a);
    FL_MEMWR(addr, 0);
    SET(Z);
}

void PIC18F2550::CLRWDT(pic16_insn i)
{
    WDT = 0;

    REGWR(RCON, REGRD(RCON) |
       (1 << 2) | // PD
       (1 << 3)); // TO
}

void PIC18F2550::COMF(pic16_insn i)
{
    u32 addr;
    u8 val;

    addr = FLAT(i.daf.f, i.daf.a);
    val = FL_MEMRD(addr);
    val = ~val;

    SET_N(val);
    SET_Z(val);

    if (i.daf.d == 0)
    {
        REGWR(WREG, val);
    } else {
        FL_MEMWR(addr, val);
    }
}

void PIC18F2550::CPFSEQ(pic16_insn i)
{
    u32 addr, addpc, clocks;
    u8 val;

    addr = FLAT(i.af.f, i.af.a);
    val = FL_MEMRD(addr);

    if (val == REGRD(WREG))
    {
        // skip next instruction

        pic16_insn nexti;
        pic16_decoded_insn *decoded;

        nexti = fetch(PC + 2);
        decoded = decode(nexti);

        if (decoded &&
            (decoded->flags & PIC16I_TWO_WORD_INSN))
        {
            addpc = 6;
            clocks = 3;
        } else {
            addpc = 4;
            clocks = 2;
        }
    } else {
        addpc = 2;
        clocks = 1;
    }

    PC += addpc;
    clock_step(clocks);
}

void PIC18F2550::CPFSGT(pic16_insn i)
{
    u32 addr, addpc, clocks;
    u8 val;

    addr = FLAT(i.af.f, i.af.a);
    val = FL_MEMRD(addr);

    if (val > REGRD(WREG))
    {
        // skip next instruction

        pic16_insn nexti;
        pic16_decoded_insn *decoded;

        nexti = fetch(PC + 2);
        decoded = decode(nexti);

        if (decoded &&
            (decoded->flags & PIC16I_TWO_WORD_INSN))
        {
            addpc = 6;
            clocks = 3;
        } else {
            addpc = 4;
            clocks = 2;
        }
    } else {
        addpc = 2;
        clocks = 1;
    }

    PC += addpc;
    clock_step(clocks);
}

void PIC18F2550::CPFSLT(pic16_insn i)
{
    u32 addr, addpc, clocks;
    u8 val;

    addr = FLAT(i.af.f, i.af.a);
    val = FL_MEMRD(addr);

    if (val < REGRD(WREG))
    {
        // skip next instruction

        pic16_insn nexti;
        pic16_decoded_insn *decoded;

        nexti = fetch(PC + 2);
        decoded = decode(nexti);

        if (decoded &&
            (decoded->flags & PIC16I_TWO_WORD_INSN))
        {
            addpc = 6;
            clocks = 3;
        } else {
            addpc = 4;
            clocks = 2;
        }
    } else {
        addpc = 2;
        clocks = 1;
    }

    PC += addpc;
    clock_step(clocks);
}

void PIC18F2550::DAW(pic16_insn /* i */)
{
    u8 wl, wh, dc;

    wl = REGRD(WREG) & 0xf;
    wh = (REGRD(WREG) & 0xf0) >> 4;
    dc = (REGRD(STATUS) & ST(DC) ? 1 : 0);

    if (wl > 9 || dc)
    {
        wl += 6;
    }

    if (wh + dc > 9 || (REGRD(STATUS) & ST(C)))
    {
        wh += 6 + dc;
    } else {
        wh += dc;
    }

    REGWR(WREG, (wh << 4) | wl);
}

void PIC18F2550::DECF(pic16_insn i)
{
    u32 addr, res;
    u8 val;

    addr = FLAT(i.daf.f, i.daf.a);
    val = FL_MEMRD(addr);
    res = alu_add8(val, TWOC(1));
    alu_set_flags(res, ST(C) | ST(DC) | ST(N) | ST(OV) | ST(Z));

    if (i.daf.d == 0)
    {
        REGWR(WREG, RES8(res));
    } else {
        FL_MEMWR(addr, RES8(res));
    }
}

void PIC18F2550::DECFSZ(pic16_insn i)
{
    u32 addr, addpc, clocks;
    u8 val, res;

    addr = FLAT(i.daf.f, i.daf.a);

    val = FL_MEMRD(addr);
    res = (val - 1) & 0xff;

    if (res == 0)
    {
        pic16_decoded_insn *decoded = fetch_and_decode(PC + 2);
        if (decoded &&
            (decoded->flags & PIC16I_TWO_WORD_INSN))
        {
            addpc = 6;
            clocks = 3;
        } else {
            addpc = 4;
            clocks = 2;
        }
    } else {
        addpc = 2;
        clocks = 1;
    }

    if (i.daf.d == 0)
    {
        REGWR(WREG, res);
    } else {
        FL_MEMWR(addr, res);
    }

    PC += addpc;
    clock_step(clocks);
}

void PIC18F2550::DCFSNZ(pic16_insn i)
{
    u32 addr, addpc, clocks;
    u8 val, res;

    addr = FLAT(i.daf.f, i.daf.a);

    val = FL_MEMRD(addr);
    res = (val - 1) & 0xff;

    if (res == 0)
    {
        addpc = 2;
        clocks = 1;
    } else {
        pic16_decoded_insn *decoded = fetch_and_decode(PC + 2);
        if (decoded &&
            (decoded->flags & PIC16I_TWO_WORD_INSN))
        {
            addpc = 6;
            clocks = 3;
        } else {
            addpc = 4;
            clocks = 2;
        }
    }

    if (i.daf.d == 0)
    {
        REGWR(WREG, res);
    } else {
        FL_MEMWR(addr, res);
    }

    PC += addpc;
    clock_step(clocks);
}

void PIC18F2550::GOTO(pic16_insn i)
{
    pic16_insn i2;

    i2 = fetch(PC + 2);
    assert(i2.ek.o == 0xf);

    PC = (i.k.k << 1) | (i2.ek.k << 8);
}

void PIC18F2550::INCF(pic16_insn i)
{
    u32 addr, res;
    u8 val;

    addr = FLAT(i.daf.f, i.daf.a);
    val = FL_MEMRD(addr);

    res = alu_add8(val, 1);
    alu_set_flags(res, ST(C) | ST(DC) | ST(N) | ST(OV) | ST(Z));

    if (i.daf.d == 0)
    {
        REGWR(WREG, res);
    } else {
        FL_MEMWR(addr, res);
    }
}

void PIC18F2550::INCFSZ(pic16_insn i)
{
    u32 addr, addpc, clocks;
    u8 val, res;

    addr = FLAT(i.daf.f, i.daf.a);

    val = FL_MEMRD(addr);
    res = (val + 1) & 0xff;

    if (res == 0)
    {
        pic16_decoded_insn *decoded = fetch_and_decode(PC + 2);
        if (decoded &&
            (decoded->flags & PIC16I_TWO_WORD_INSN))
        {
            addpc = 6;
            clocks = 3;
        } else {
            addpc = 4;
            clocks = 2;
        }
    } else {
        addpc = 2;
        clocks = 1;
    }

    if (i.daf.d == 0)
    {
        REGWR(WREG, res);
    } else {
        FL_MEMWR(addr, res);
    }

    PC += addpc;
    clock_step(clocks);
}

void PIC18F2550::INFSNZ(pic16_insn i)
{
    u32 addr, addpc, clocks;
    u8 val, res;

    addr = FLAT(i.daf.f, i.daf.a);

    val = FL_MEMRD(addr);
    res = (val + 1) & 0xff;

    if (res == 0)
    {
        pic16_decoded_insn *decoded = fetch_and_decode(PC + 2);
        if (decoded &&
            (decoded->flags & PIC16I_TWO_WORD_INSN))
        {
            addpc = 6;
            clocks = 3;
        } else {
            addpc = 4;
            clocks = 2;
        }
    } else {
        pic16_decoded_insn *decoded = fetch_and_decode(PC + 2);
        if (decoded &&
            (decoded->flags & PIC16I_TWO_WORD_INSN))
        {
            addpc = 6;
            clocks = 3;
        } else {
            addpc = 4;
            clocks = 2;
        }
    }

    if (i.daf.d == 0)
    {
        REGWR(WREG, res);
    } else {
        FL_MEMWR(addr, res);
    }

    PC += addpc;
    clock_step(clocks);
}

void PIC18F2550::IORLW(pic16_insn i)
{
    u32 res;

    res = REGRD(WREG) | i.k.k;
    SET_Z(res);
    SET_N(res);

    REGWR(WREG, res);
}

void PIC18F2550::IORWF(pic16_insn i)
{
    u32 addr;
    u8 val, res;

    addr = FLAT(i.daf.f, i.daf.a);
    val = FL_MEMRD(addr);

    res = val | REGRD(WREG);
    SET_Z(res);
    SET_N(res);

    if (i.daf.d == 0)
    {
        REGWR(WREG, res);
    } else {
        FL_MEMWR(addr, res);
    }
}

void PIC18F2550::LFSR(pic16_insn i)
{
    pic16_insn i2;
    i2 = fetch(PC + 2);

    assert(i2.k.o == 0xF0);
    
    switch(i.fk.f)
    {
    case 0:
        REGWR(FSR0L, i2.k.k);
        REGWR(FSR0H, i.k.k);
        break;

    case 1:
        REGWR(FSR1L, i2.k.k);
        REGWR(FSR1H, i.k.k);
        break;

    case 2:
        REGWR(FSR2L, i2.k.k);
        REGWR(FSR2H, i.k.k);
        break;

    case 3:
        assert(!"illegal LFSR encoding");
        break;
    }
}

void PIC18F2550::MOVF(pic16_insn i)
{
    u32 addr;
    u8 val;

    addr = FLAT(i.daf.f, i.daf.a);
    val = FL_MEMRD(addr);

    SET_Z(val);
    SET_N(val);

    if (i.daf.d == 0)
    {
        REGWR(WREG, val);
    } else {
        FL_MEMWR(addr, val);
    }
}

void PIC18F2550::MOVFF(pic16_insn i)
{
    pic16_insn i2;
    u8 val;

    i2 = fetch(PC + 2);
    assert(i2.ef.o == 0xF);

    val = FL_MEMRD(i.ef.f);
    FL_MEMWR(i2.ef.f, val);
}

void PIC18F2550::MOVLB(pic16_insn i)
{
    REGWR(BSR, i.k.k);
}

void PIC18F2550::MOVLW(pic16_insn i)
{
    REGWR(WREG, i.k.k);
}

void PIC18F2550::MOVWF(pic16_insn i)
{
    MEMWR(i.af.f, i.af.a, REGRD(WREG));
}

void PIC18F2550::MULLW(pic16_insn i)
{
    u16 res;

    res = REGRD(WREG) * i.k.k;

    REGWR(PRODL, res & 0xff);
    REGWR(PRODH, (res & 0xff00) >> 8);
}

void PIC18F2550::MULWF(pic16_insn i)
{
    u32 addr;
    u8 val;
    u16 res;

    addr = FLAT(i.af.f, i.af.a);
    val = FL_MEMRD(addr);

    res = val * REGRD(WREG);

    REGWR(PRODL, res & 0xff);
    REGWR(PRODH, (res & 0xff00) >> 8);
}

void PIC18F2550::NEGF(pic16_insn i)
{
    u32 addr;
    u8 val;
    u8 res;

    addr = FLAT(i.af.f, i.af.a);
    val = FL_MEMRD(addr);

    // XXX: this might be incorrect, since we'll be computing C, DC and OV based on the +1 operation
    res = alu_add8(~val, 1);
    alu_set_flags(res, ST(N) | ST(OV) | ST(C) | ST(DC) | ST(Z));

    FL_MEMWR(addr, val);
}

void PIC18F2550::NOP(pic16_insn i)
{
}

void PIC18F2550::POP(pic16_insn i)
{
    callstack_pop();
}

void PIC18F2550::PUSH(pic16_insn i)
{
    callstack_push(PC + 2);
}

void PIC18F2550::RCALL(pic16_insn i)
{
    int addpc;

    if (i.en.n & (1 << 10))
    {
        addpc = i.en.n | 0xfffff800;
    } else {
        addpc = i.en.n;
    }

    callstack_push(PC + 2);
    PC = PC + 2 + 2 * addpc;
}

void PIC18F2550::RESET(pic16_insn i)
{
    soft_reset();
}

// XXX: this is incomplete, needs to set interrupt enable bits
void PIC18F2550::RETFIE(pic16_insn i)
{
    if (i.s.s)
    {
        REGWR(WREG, WS);
        REGWR(STATUS, STATUSS);
        REGWR(BSR, BSRS);
    }

    PC = callstack_pop();
}

void PIC18F2550::RETLW(pic16_insn i)
{
    REGWR(WREG, i.k.k);
    PC = callstack_pop();
}

void PIC18F2550::RETURN(pic16_insn i)
{
    u32 dest;

    dest = callstack_pop();
    
    if (i.s.s)
    {
        REGWR(WREG, WS);
        REGWR(STATUS, STATUSS);
        REGWR(BSR, BSRS);
    }

    PC = dest;
}

void PIC18F2550::RLCF(pic16_insn i)
{
    u32 addr;
    u8 val;
    u16 res;

    addr = FLAT(i.daf.f, i.daf.a);
    val = FL_MEMRD(addr);

    res = val << 1;
    res |= (REGRD(STATUS) & ST(C)) ? 1 : 0;
    val = res & 0xFF;

    if ((res & 0x0100))
    {
        SET(C);
    } else {
        CLR(C);
    }

    SET_N(val);
    SET_Z(val);

    if (i.daf.d == 0)
    {
        REGWR(WREG, val);
    } else {
        FL_MEMWR(addr, val);
    }
}

void PIC18F2550::RLNCF(pic16_insn i)
{
    u32 addr;
    u8 val;
    u16 res;

    addr = FLAT(i.daf.f, i.daf.a);
    val = FL_MEMRD(addr);

    res = val << 1;
    val = (res & 0xFF) | ((res & 0x0100) >> 8);

    SET_N(val);
    SET_Z(val);

    if (i.daf.d == 0)
    {
        REGWR(WREG, val);
    } else {
        FL_MEMWR(addr, val);
    }
}

void PIC18F2550::RRCF(pic16_insn i)
{
    u32 addr;
    u8 val;
    u16 res;

    addr = FLAT(i.daf.f, i.daf.a);
    val = FL_MEMRD(addr);

    res = ((val & 1) << 8) | (val >> 1) | ((REGRD(STATUS) & ST(C)) ? 1 << 7 : 0);
    val = res & 0xFF;

    if ((res & 0x0100))
    {
        SET(C);
    } else {
        CLR(C);
    }

    SET_N(val);
    SET_Z(val);

    if (i.daf.d == 0)
    {
        REGWR(WREG, val);
    } else {
        FL_MEMWR(addr, val);
    }
}

void PIC18F2550::RRNCF(pic16_insn i)
{
    u32 addr;
    u8 val;
    u16 res;

    addr = FLAT(i.daf.f, i.daf.a);
    val = FL_MEMRD(addr);

    res = ((val & 1) << 7) | (val >> 1);
    val = res & 0xff;

    SET_N(val);
    SET_Z(val);

    if (i.daf.d == 0)
    {
        REGWR(WREG, val);
    } else {
        FL_MEMWR(addr, val);
    }
}

void PIC18F2550::SETF(pic16_insn i)
{
    u32 addr;

    addr = FLAT(i.daf.f, i.daf.a);
    FL_MEMWR(addr, 0xFF);
}

void PIC18F2550::SLEEP(pic16_insn i)
{
    assert(!"unimplemented");
}

void PIC18F2550::SUBFWB(pic16_insn i)
{
    u32 addr, res;
    u8 val;

    addr = FLAT(i.daf.f, i.daf.a);
    val = FL_MEMRD(addr);
    
    res = alu_sub8(val, REGRD(WREG));
    alu_set_flags(res, ST(N) | ST(OV) | ST(C) | ST(DC) | ST(Z));

    if (!(REGRD(STATUS) & ST(C)))
    {
        u32 res2;

        res2 = alu_sub8(RES8(res), 1);
        alu_set_flags(res2, ST(N) | ST(Z));

        if (CF8(res2))
        {
            SET(C);
        }

        if (OF8(res2))
        {
            SET(OV);
        }

        if (DF8(res2))
        {
            SET(DC);
        }

        res = res2;
    }

    if (i.daf.d == 0)
    {
        REGWR(WREG, RES8(res));
    } else {
        FL_MEMWR(addr, RES8(res));
    }
}

void PIC18F2550::SUBLW(pic16_insn i)
{
    u32 res;

    res = alu_sub8(i.k.k, REGRD(WREG));
    alu_set_flags(res, ST(N) | ST(OV) | ST(C) | ST(DC) | ST(Z));
    REGWR(WREG, RES8(res));
}

void PIC18F2550::SUBWF(pic16_insn i)
{
    u32 addr, res;
    u8 val;

    addr = FLAT(i.daf.f, i.daf.a);
    val = FL_MEMRD(addr);
    res = alu_sub8(val, REGRD(WREG));
    alu_set_flags(res, ST(N) | ST(OV) | ST(C) | ST(DC) | ST(Z));
    
    if (i.daf.d == 0)
    {
        REGWR(WREG, RES8(res));
    } else {
        FL_MEMWR(addr, RES8(res));
    }
}

void PIC18F2550::SUBWFB(pic16_insn i)
{
    u32 addr, res;
    u8 val;
    
    addr = FLAT(i.daf.f, i.daf.a);
    val = FL_MEMRD(addr);
    
    res = alu_sub8(val, REGRD(WREG));
    alu_set_flags(res, ST(N) | ST(OV) | ST(C) | ST(DC) | ST(Z));
    
    if (!(REGRD(STATUS) & ST(C)))
    {
        u32 res2;
        
        res2 = alu_sub8(RES8(res), 1);
        alu_set_flags(res2, ST(N) | ST(Z));
        
        if (CF8(res2))
        {
            SET(C);
        }
        
        if (OF8(res2))
        {
            SET(OV);
        }
        
        if (DF8(res2))
        {
            SET(DC);
        }
        
        res = res2;
    }
    
    if (i.daf.d == 0)
    {
        REGWR(WREG, RES8(res));
    } else {
        FL_MEMWR(addr, RES8(res));
    }
}

void PIC18F2550::SWAPF(pic16_insn i)
{
    u32 addr;
    u8 val;

    addr = FLAT(i.daf.f, i.daf.a);
    val = FL_MEMRD(addr);

    val = ((val & 0x0F) << 4) | ((val & 0xF0) >> 4);

    if (i.daf.d == 0)
    {
        REGWR(WREG, val);
    } else {
        FL_MEMWR(addr, val);
    }
}

void PIC18F2550::TBLRD(pic16_insn i)
{
    u32 addr;
    u8 val;

#define TBLADDR() ((REGRD(TBLPTRU) << 16) | (REGRD(TBLPTRH) << 8) | (REGRD(TBLPTRL)))

    switch(i.nn.n)
    {
    case 0: // *
        addr = TBLADDR();
        val = mmc->code_rb(addr);

        break;

    case 1: // *+
        addr = TBLADDR();
        val = mmc->code_rb(addr);
        addr++;

        break;

    case 2: // *-
        addr = TBLADDR();
        val = mmc->code_rb(addr);
        addr--;

        break;

    case 3: // +*
        addr = TBLADDR();
        addr++;
        val = mmc->code_rb(addr);

        break;
    }

    REGWR(TBLPTRL, addr & 0xFF);
    REGWR(TBLPTRH, (addr >> 8) & 0xFF);
    REGWR(TBLPTRU, (addr >> 16) & 0xFF);
    REGWR(TABLAT, val);
}

void PIC18F2550::TBLWT(pic16_insn i)
{
    u32 addr;

    addr = TBLADDR();

    if (i.nn.n == 3) // +*
    {
        addr++;
    }

    mmc->code_wb(addr, REGRD(TABLAT));
    
    switch(i.nn.n)
    {
    case 1: // *+
        addr++;
        break;

    case 2: // *-
        addr--;
        break;
    }

    REGWR(TBLPTRL, addr & 0xFF);
    REGWR(TBLPTRH, (addr >> 8) & 0xFF);
    REGWR(TBLPTRU, (addr >> 16) & 0xFF);   
}

void PIC18F2550::TSTFSZ(pic16_insn i)
{
    u32 addpc, clocks;
    u8 val;

    val = MEMRD(i.af.f, i.af.a);

    if (val == 0)
    {
        // skip

        // see if next instruction is a two-word instruction
        pic16_insn nexti;
        pic16_decoded_insn *decoded;

        nexti = fetch(PC + 2);
        decoded = decode(nexti);

        if (decoded &&
            (decoded->flags & PIC16I_TWO_WORD_INSN))
        {
            addpc = 6;
            clocks = 3;
        } else {
            addpc = 4;
            clocks = 2;
        }
    } else {
        addpc = 2;
        clocks = 1;
    }

    PC += addpc;
    clock_step(clocks);
}

void PIC18F2550::XORLW(pic16_insn i)
{
    u8 val;

    val = REGRD(WREG) ^ i.k.k;
    SET_N(val);
    SET_Z(val);
}

void PIC18F2550::XORWF(pic16_insn i)
{
    u32 addr;
    u8 val;

    addr = FLAT(i.daf.f, i.daf.a);
    val = FL_MEMRD(addr);

    val = REGRD(WREG) ^ val;

    if (i.daf.d == 0)
    {
        REGWR(WREG, val);
    } else {
        FL_MEMWR(addr, val);
    }
}
