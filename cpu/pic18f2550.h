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

#ifndef __PIC18F2550_H
#define __PIC18F2550_H

#include "cpu/pic.h"
#include "cpu/pic18f2550_registers.h"

#define LOW8(a) ((a) & 0xFF)

// memory space conversions
#define AB_TO_FL(addr) (mmc->access_bank_to_flat(addr))
#define BSR_TO_FL(addr) (mmc->bsr_to_flat(addr))

// macros to access memory (flat address space)
#define FL_MEMRD(addr) mmc->data_sw_rb(addr)
#define FL_MEMWR(addr, data) mmc->data_sw_wb(addr, LOW8(data))
#define FL_HW_MEMRD(addr) mmc->data_hw_rb(addr)
#define FL_HW_MEMWR(addr, data) mmc->data_hw_wb(addr, LOW8(data))

// access bank memory
#define AB_MEMRD(addr) FL_MEMRD(AB_TO_FL(addr))
#define AB_MEMWR(addr, data) FL_MEMWR(AB_TO_FL(addr), LOW8(data))

#define BSR_MEMRD(addr) FL_MEMRD(BSR_TO_FL(addr))
#define BSR_MEMWR(addr, data) FL_MEMWR(BSR_TO_FL(addr), LOW8(data))

// compute flat address for a given 8 bit offset + access bit
#define FLAT(addr, a) ((a) == 0 ? AB_TO_FL(addr) : BSR_TO_FL(addr))
// BSR/AB memory read
#define MEMRD(addr, a) FL_MEMRD(FLAT(addr, a))
// BSR/AB memory write
#define MEMWR(addr, a, val) FL_MEMWR(FLAT(addr, a), val)

// macros to access registers
#define REGRD(a) FL_MEMRD(a)
#define REGWR(a, val) FL_MEMWR(a, val)

#define HW_RD(a) FL_HW_MEMRD(a)
#define HW_WR(a, val) FL_HW_MEMWR(a, val)

// macros to set ALU status bits: carry, digit carry, zero, overflow, negative
#define SET(bit) HW_WR(STATUS, REGRD(STATUS) | (1 << bit))
#define CLR(bit) HW_WR(STATUS, REGRD(STATUS) & ~(1 << bit))

#define SET_Z(a) if (a == 0) { SET(Z); } else { CLR(Z); }
#define SET_N(a) if (ISNEG8(a)) { SET(N); } else { CLR(N); }

class PIC18F2550 : public PIC
{
 public:

    // shadow registers
    u8 WS, STATUSS, BSRS;
    // watchdog timer
    u32 WDT;

    PIC18F2550();

    void poweron_reset(void);
    void soft_reset(void);
    void wakeup_reset(void);

    inline pic16_insn fetch(u32 addr)
    {
        pic16_insn i;
        i.o.o = mmc->code_rw(addr);        
        return i;
    };

    inline pic16_insn fetch(void)
    {
        return fetch(PC);
    };

    inline pic16_decoded_insn *fetch_and_decode(u32 addr)
    {
        pic16_insn i;

        i = fetch(addr);
        return decode(i);
    };

    void dispatch(pic16_decoded_insn *decode, pic16_insn insn);

    inline void alu_set_flags(u32 res, u32 mask)
    {
        if (mask & N)
        {
            if (ISNEG8(RES8(res)))
            {
                SET(N);
            } else {
                CLR(N);
            }
        }

        if (mask & OV)
        {
            if (OF8(res))
            {
                SET(OV);
            } else {
                CLR(OV);
            }
        }

        if (mask & Z)
        {
            if(RES8(res) == 0)
            {
                SET(Z);
            } else {
                CLR(Z);
            }
        }

        if (mask & DC)
        {
            if(DF8(res))
            {
                SET(DC);
            } else {
                CLR(DC);
            }
        }

        if (mask & C)
        {
            if (CF8(res))
            {
                SET(C);
            } else {
                CLR(C);
            }
        }
    };

 private:
    void callstack_push(u32 dword);
    u32 callstack_pop(void);

#define _P(f) \
 public:      \
     static void _##f(PIC18F2550 *pic, pic16_insn i)       \
     {                                                     \
        pic->f(i);                                         \
     };                                                    \
 private: \
    void f(pic16_insn i);

    _P( ADDLW);
    _P( ADDWF);
    _P(ADDWFC);
    _P( ANDLW);
    _P( ANDWF);
    _P(    BC);
    _P(   BCF);
    _P(    BN);
    _P(   BNC);
    _P(   BNN);
    _P(  BNOV);
    _P(   BNZ);
    _P(   BRA);
    _P(   BSF);
    _P( BTFSC);
    _P( BTFSS);
    _P(   BTG);
    _P(   BOV);
    _P(    BZ);
    _P(  CALL);
    _P(  CLRF);
    _P(CLRWDT);
    _P(  COMF);
    _P(CPFSEQ);
    _P(CPFSGT);
    _P(CPFSLT);
    _P(   DAW);
    _P(  DECF);
    _P(DECFSZ);
    _P(DCFSNZ);
    _P(  GOTO);
    _P(  INCF);
    _P(INCFSZ);
    _P(INFSNZ);
    _P( IORLW);
    _P( IORWF);
    _P(  LFSR);
    _P(  MOVF);
    _P( MOVFF);
    _P( MOVLB);
    _P( MOVLW);
    _P( MOVWF);
    _P( MULLW);
    _P( MULWF);
    _P(  NEGF);
    _P(   NOP);
    _P(   POP);
    _P(  PUSH);
    _P( RCALL);
    _P( RESET);
    _P(RETFIE);
    _P( RETLW);
    _P(RETURN);
    _P(  RLCF);
    _P( RLNCF);
    _P(  RRCF);
    _P( RRNCF);
    _P(  SETF);
    _P( SLEEP);
    _P(SUBFWB);
    _P( SUBLW);
    _P( SUBWF);
    _P(SUBWFB);
    _P( SWAPF);
    _P( TBLRD);
    _P( TBLWT);
    _P(TSTFSZ);
    _P( XORLW);
    _P( XORWF);

#undef _P

};

#endif
