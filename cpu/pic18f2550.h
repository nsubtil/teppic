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

// macros to access registers
#define RD(a) FL_MEMRD(a)
#define WR(a, val) FL_MEMWR(a, val)

#define HW_RD(a) FL_HW_MEMRD(a)
#define HW_WR(a, val) FL_HW_MEMWR(a, val)

// macros to set ALU status bits: carry, digit carry, zero, overflow, negative
#define N  (1 << 4)
#define OV (1 << 3)
#define Z  (1 << 2)
#define DC (1 << 1)
#define C  (1 << 0)

#define SET(bit) HW_WR(STATUS, RD(STATUS) | bit)
#define CLR(bit) HW_WR(STATUS, RD(STATUS) & ~(bit))

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

#define P(f) \
 public:      \
     static void _##f(PIC18F2550 *pic, pic16_insn i)       \
     {                                                     \
        pic->f(i);                                         \
     };                                                    \
 private: \
    void f(pic16_insn i);

    P( ADDLW);
    P( ADDWF);
    P(ADDWFC);
    P( ANDLW);
    P( ANDWF);
    P(    BC);
    P(   BCF);
    P(    BN);
    P(   BNC);
    P(   BNN);
    P(  BNOV);
    P(   BNZ);
    P(   BRA);
    P(   BSF);
    P( BTFSC);
    P( BTFSS);
    P(   BTG);
    P(   BOV);
    P(    BZ);
    P(  CALL);
    P(  CLRF);
    P(CLRWDT);
    P(  COMF);
    P(CPFSEQ);
    P(CPFSGT);
    P(CPFSLT);
    P(   DAW);
    P(  DECF);
    P(DECFSZ);
    P(DCFSNZ);
    P(  GOTO);
    P(  INCF);
    P(INCFSZ);
    P(INFSNZ);
    P( IORLW);
    P( IORWF);
    P(  LFSR);
    P(  MOVF);
    P( MOVFF);
    P( MOVLB);
    P( MOVLW);
    P( MOVWF);
    P( MULLW);
    P( MULWF);
    P(  NEGF);
    P(   NOP);
    P(   POP);
    P(  PUSH);
    P( RCALL);
    P( RESET);
    P(RETFIE);
    P( RETLW);
    P(RETURN);
    P(  RLCF);
    P( RLNCF);
    P(  RRCF);
    P( RRNCF);
    P(  SETF);
    P( SLEEP);
    P(SUBFWB);
    P( SUBLW);
    P( SUBWF);
    P(SUBWFB);
    P( SWAPF);
    P( TBLRD);
    P( TBLWT);
    P(TSTFSZ);
    P( XORLW);
    P( XORWF);

#undef P

};

#endif
