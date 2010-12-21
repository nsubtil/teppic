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

#ifndef __PIC_H
#define __PIC_H

#include "mem/mmc.h"
#include "cpu/pic_registers.h"

typedef enum {
    PIC16_insn_daf,
    PIC16_insn_af,
    PIC16_insn_ef,
    PIC16_insn_baf,
    PIC16_insn_n,
    PIC16_insn_en,
    PIC16_insn_sk,
    PIC16_insn_k,
    PIC16_insn_ek,
    PIC16_insn_fk,
    PIC16_insn_s,
    PIC16_insn_nn,
    PIC16_insn_o,
    PIC16_insn_ox,
    PIC16_insn_NULL
} PIC16_insn_type;

#define PIC16_OPCODE_MASK_daf   0xFC00
#define PIC16_OPCODE_MASK_af    0xFE00
#define PIC16_OPCODE_MASK_ef    0xF000
#define PIC16_OPCODE_MASK_baf   0xF000
#define PIC16_OPCODE_MASK_n     0xFF00
#define PIC16_OPCODE_MASK_en    0xF800
#define PIC16_OPCODE_MASK_sk    0xFE00
#define PIC16_OPCODE_MASK_k     0xFF00
#define PIC16_OPCODE_MASK_ek    0xFC00
#define PIC16_OPCODE_MASK_fk    0xFFC0
#define PIC16_OPCODE_MASK_s     0xFFFE
#define PIC16_OPCODE_MASK_nn    0xFFFC
#define PIC16_OPCODE_MASK_o     0xFFFF
#define PIC16_OPCODE_MASK_ox    0xF000
#define PIC16_OPCODE_MASK_NULL  0x0000

// oooo ooda ffff ffff
typedef struct pic16_insn_daf_rec
{
    // destination register
    unsigned int f : 8;
    // access bit
    unsigned int a : 1;
    // direction bit
    unsigned int d : 1;
    // opcode
    unsigned int o : 6;
} __attribute__((__packed__)) pic16_insn_daf;

// oooo oooa ffff ffff
typedef struct pic16_insn_af_rec
{
    // destination register
    unsigned int f : 8;
    // access bit
    unsigned int a : 1;
    // opcode
    unsigned int o : 7;
} __attribute__((__packed__)) pic16_insn_af;

// oooo ffff ffff ffff
typedef struct pic16_insn_ef_rec
{
    // source/dest f
    unsigned int f : 12;
    // opcode
    unsigned int o : 4;
} __attribute__((__packed__)) pic16_insn_ef;

// oooo bbba ffff ffff
typedef struct pic16_insn_baf_rec
{
    // source/dest f
    unsigned int f : 8;
    // access bit
    unsigned int a : 1;
    // bit selector
    unsigned int b : 3;
    // opcode
    unsigned int o : 4;
} __attribute__((__packed__)) pic16_insn_baf;

// oooo oooo nnnn nnnn
typedef struct pic16_insn_n_rec
{
    // destination address
    unsigned int n : 8;
    // opcode
    unsigned int o : 8;
} __attribute__((__packed__)) pic16_insn_n;

// oooo onnn nnnn nnnn
typedef struct pic16_insn_en_rec
{
    // destination address
    unsigned int n : 11;
    // opcode
    unsigned int o : 5;
} __attribute__((__packed__)) pic16_insn_en;

// oooo ooos kkkk kkkk
typedef struct pic16_insn_sk_rec
{
    unsigned int k : 8;
    unsigned int s : 1;
    unsigned int o : 7;
} __attribute__((__packed__)) pic16_insn_sk;

// oooo oooo kkkk kkkk
typedef struct pic16_insn_k_rec
{
    unsigned int k : 8;
    unsigned int o : 8;
} __attribute__((__packed__)) pic16_insn_k;

// oooo kkkk kkkk kkkk
typedef struct pic16_insn_ek_rec
{
    unsigned int k : 12;
    unsigned int o : 4;
} __attribute__((__packed__)) pic16_insn_ek;

// oooo oooo ooff kkkk
typedef struct pic16_insn_fk_rec
{
    unsigned int k : 4;
    unsigned int f : 2;
    unsigned int o : 10;
} __attribute__((__packed__)) pic16_insn_fk;

// oooo oooo oooo ooos
typedef struct pic16_insn_s_rec
{
    unsigned int s : 1;
    unsigned int o : 15;
} __attribute__((__packed__)) pic16_insn_s;

// oooo oooo oooo oonn
typedef struct pic16_insn_nn_rec
{
    unsigned int n : 2;
    unsigned int o : 14;
} __attribute__((__packed__)) pic16_insn_nn;

// oooo oooo oooo oooo
typedef struct pic16_insn_o_rec
{
    unsigned int o : 16;
} __attribute__((__packed__)) pic16_insn_o;

// oooo xxxx xxxx xxxx
typedef struct pic16_insn_ox_rec
{
    unsigned int x : 12;
    unsigned int o : 4;
} __attribute__((__packed__)) pic16_insn_ox;

typedef struct pic16_insn_hilo_rec
{
    unsigned int lo : 8;
    unsigned int hi : 8;
} __attribute__((__packed__)) pic16_insn_hilo;

typedef union
{
    pic16_insn_daf  daf;
    pic16_insn_af   af;
    pic16_insn_ef   ef;
    pic16_insn_baf  baf;
    pic16_insn_n    n;
    pic16_insn_en   en;
    pic16_insn_sk   sk;
    pic16_insn_k    k;
    pic16_insn_ek   ek;
    pic16_insn_fk   fk;
    pic16_insn_s    s;
    pic16_insn_nn   nn;
    pic16_insn_o    o;
    pic16_insn_ox   ox;
    pic16_insn_hilo hilo;
} pic16_insn;

class PIC;

typedef void (*pic16_insn_func_t)(PIC *, pic16_insn);

#define PIC16I_NO_PC_UPDATE       0x00000001
#define PIC16I_NO_CLK_UPDATE      0x00000002
#define PIC16I_TWO_WORD_INSN      0x00000004

typedef struct pic16_decoded_insn_rec
{
    // instruction type
    PIC16_insn_type type;
    // mask for opcode extraction
    u16 opcode_mask;
    // opcode
    u16 opcode;

    // exec func for instruction
    pic16_insn_func_t exec;

    // clock cycles required
    u32 clocks;
    // instruction flags
    u32 flags;

    // name of instruction (for debug)
    const char *insn_name;
} pic16_decoded_insn;

#define PIC16IFC(_name, _type, _opcode, _clocks, _flags)                \
    { PIC16_insn_##_type, PIC16_OPCODE_MASK_##_type, _opcode, (pic16_insn_func_t) CLASS::_##_name, _clocks, _flags, #_name }

#define PIC16I(_name, _type, _opcode) PIC16IFC(_name, _type, _opcode, 1, 0)

#define PIC16I_END \
    { PIC16_insn_NULL, 0, 0, NULL, 0, 0, NULL }


// check is f an 8-bit integer is negative
#define ISNEG8(a) ((a) & (1 << 7))
// compute the 2's complement of a
#define TWOC(a) (~(a) + 1)

class PIC
{
 public:
    PICRegisterFile *registers;

    pic16_decoded_insn *decode_table;
    MMC *mmc;
   
    // program counter
    u32 PC;
    // chip clock
    u64 clk;

    PIC();

    void debug_pic16_insn(pic16_decoded_insn *decode, pic16_insn i);

    // decode an instruction
    pic16_decoded_insn *decode(pic16_insn i);

    // step through next instruction
    void step(void);
    // move the clock forward N cycles
    void clock_step(int n);

    // reset functions
    virtual void poweron_reset(void) = 0;
    virtual void soft_reset(void) = 0;
    virtual void wakeup_reset(void) = 0;

    // fetch the next instruction
    virtual pic16_insn fetch(void) = 0;
    // dispatch an instruction for execution
    virtual void dispatch(pic16_decoded_insn *decode, pic16_insn i) = 0;


    // the following is based on Mihocka, D., Troeger, J., "A Proposal for
    // Hardware-Assisted Arithmetic Overflow Detection for Array and
    // Bitfield Operations"
    // (checked in as docs/LazyOverflowDetect_Final.pdf)

    // simulate an alu 8-bit summation
    // returns a 32-bit word with the result in the low byte, flag vector in the second byte, carry-out vector in the third
    inline u32 alu_add8(u8 a, u8 b)
    {
        u8 s;
        u8 cv;
        u8 fv;

        s = a + b;
        cv = ((a & b) | ((a | b) & ~s));
        fv = (cv >> 6) | (cv & 0x8);

        return (s) | (cv << 8) | (fv << 16);
    };

    inline u32 alu_sub8(u8 a, u8 b)
    {
        return alu_add8(a, TWOC(b));
    };

    // extract the result of the sum
#define RES8(res) ((res) & 0xFF)
    // extract 8-bit carry flag from alu_add8
#define CF8(res) ((res) & 0x20000)
    // extract 8-bit overflow flag from alu_add8
#define OF8(res) (((res) + 0x10000) & 0x20000)
    // extract 4-bit overflow flag (digit carry) from alu_add8
#define DF8(res) (((res) & 0x800))
};

#endif
