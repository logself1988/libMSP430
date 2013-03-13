/*
 * FuncletCode.h
 *
 * Copyright (C) 2007 - 2011 Texas Instruments Incorporated - http://www.ti.com/ 
 * 
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                                                                                                                                                                                                                                                                                                         
 */

#ifndef FUNCLET_CODE_H
#define FUNCLET_CODE_H

#include <inttypes.h>
/** 
\struct FuncletCode.

\brief	Non POD data holding struct which can be initialized at once through ctor.

\note	See FuncletCode.

 */
class FuncletCode
{
public:
	enum Type { NONE, ERASE, WRITE, BSLUNLOCK};

	FuncletCode(const uint16_t* code = 0, size_t size = 0, size_t maxPayload = 0)
		: code_(code), codeSize_(size-2), maxPayload_(maxPayload) {}

	const uint16_t *code() const { return &code_[1]; }
	size_t codeSize() const { return codeSize_; }
	uint16_t programStartOffset() const { return code_ ? code_[0] : 0; }
	size_t maxPayloadSize() const { return maxPayload_; }

	bool operator==(const FuncletCode& b) const
	{
		return  (codeSize_ == b.codeSize_) && 
				(maxPayload_ == b.maxPayload_) &&
				(memcmp(code_, b.code_, codeSize_+2) == 0);
	}

private:
	const uint16_t *code_;
	size_t codeSize_;
	size_t maxPayload_;
};




const uint16_t eraseFuncletCodeDCO[] = {
	0x0000, 
	0x400a, 0x40b2, 0x5a80, 0x0120, 0x4bc2, 0x0056, 0x4cc2, 0x0057, 
	0x503a, 0x005c, 0x40ba, 0xbeef, 0x0000, 0x3c02, 0x0000, 0x0000, 
	0x403b, 0xdead, 0xea2b, 0x23fc, 0x403b, 0x000a, 0x4982, 0x0128, 
	0x450c, 0x40bc, 0xdead, 0x0000, 0x403c, 0x227a, 0x831c, 0x23fe, 
	0x40b2, 0xa500, 0x0128, 0x831b, 0x23f1, 0x40f2, 0x0087, 0x0057, 
	0x3c05, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3fff, 0x4303
};

const uint16_t writeFuncletCodeDCO[] = {
	0x0000,
	0x400a, 0x40b2, 0x5a80, 0x0120, 0x4bc2, 0x0056, 0x4cc2, 0x0057, 
	0x503a, 0x005c, 0x40ba, 0xbeef, 0x0000, 0x3c02, 0x0000, 0x0000, 
	0x403b, 0xdead, 0xea2b, 0x23fc, 0x4a0b, 0x532b, 0x450c, 0x40b2, 
	0xa540, 0x0128, 0x4bac, 0x0000, 0xb392, 0x012c, 0x23fd, 0x40b2, 
	0xa500, 0x0128, 0x40b2, 0xa500, 0x012c, 0x532b, 0x532c, 0x8316, 
	0x23ee, 0x40f2, 0x0087, 0x0057, 0x3c01, 0x0000, 0x3fff, 0x4303
};

const uint16_t eraseFuncletCodeFLL[] = {
	0x0000, 
	0x400A, 0x40B2, 0x5A80, 0x0120, 0x503A, 0x005C, 0x40BA, 0xBEEF, 
	0x0000, 0x3C06, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 
	0x403B, 0xDEAD, 0xEA2B, 0x23FC, 0x403B, 0x000A, 0x4982, 0x0128, 
	0x450C, 0x40BC, 0xDEAD, 0x0000, 0x403C, 0x227A, 0x831C, 0x23FE, 
	0x40B2, 0xA500, 0x0128, 0x831B, 0x23F1, 0x3C08, 0xFFFF, 0xFFFF,
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x3FFF, 0x4303
};

const uint16_t writeFuncletCodeFLL[] = {
	0x0000,
	0x400A, 0x40B2, 0x5A80, 0x0120, 0x503A, 0x005C, 0x40BA, 0xBEEF, 
	0x0000, 0x3C06, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 
	0x403B, 0xDEAD, 0xEA2B, 0x23FC, 0x4A0B, 0x532B, 0x450C, 0x9BAC, 
	0x0000, 0x240E, 0x40B2, 0xA540, 0x0128, 0x4BAC, 0x0000, 0xB392, 
	0x012C, 0x23FD, 0x40B2, 0xA500, 0x0128, 0x40B2, 0xA500, 0x012C,
	0x532B, 0x532C, 0x8316, 0x23EB, 0x3C01, 0xFFFF, 0x3FFF, 0x4303
};

const uint16_t eraseFuncletCodeXDCO[] = {
	0x0000,
	0x1800, 0x404a, 0x40b2, 0x5a80, 0x0120, 0x4bc2, 0x0056, 0x4cc2, 
	0x0057, 0x1840, 0x503a, 0x0066, 0x1840, 0x40ba, 0xbeef, 0x0000, 
	0x3c00, 0x403b, 0xdead, 0x1840, 0xea1b, 0x0000, 0x23fa, 0x1840, 
	0x403b, 0x000a, 0x1840, 0x4982, 0x0128, 0x1800, 0x454c, 0x1840, 
	0x40bc, 0xdead, 0x0000, 0x1840, 0x403c, 0x227a, 0x832c, 0x23fe, 
	0x1840, 0x40b2, 0xa500, 0x0128, 0x832b, 0x23ec, 0x40f2, 0x0087, 
	0x0057, 0x3c02, 0x0000, 0x0000, 0x3fff, 0x4303
};

const uint16_t writeFuncletCodeXDCO[] = {
	0x0000,
	0x1800, 0x404a, 0x40b2, 0x5a80, 0x0120, 0x4bc2, 0x0056, 0x4cc2, 
	0x0057, 0x1840, 0x503a, 0x0066, 0x1840, 0x40ba, 0xbeef, 0x0000, 
	0x3c00, 0x403b, 0xdead, 0x1840, 0xea1b, 0x0000, 0x23fa, 0x1840, 
	0x4a0b, 0x1840, 0x532b, 0x1800, 0x454c, 0x40b2, 0xa540, 0x0128, 
	0x4bac, 0x0000, 0xb392, 0x012c, 0x23fd, 0x40b2, 0xa500, 0x0128, 
	0x40b2, 0xa500, 0x012c, 0x03eb, 0x03ec, 0x8316, 0x23ee, 0x40f2, 
	0x0087, 0x0057, 0x3c01, 0x0000, 0x3fff, 0x4303
};

const uint16_t eraseFuncletCodeXFLL[] = {
	0x0000,
	0x1800, 0x404a, 0x40b2, 0x5a80, 0x0120, 0x1840, 0x503a, 0x0066, 
	0x1840, 0x40ba, 0xbeef, 0x0000, 0x3c04, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x403b, 0xdead, 0x1840, 0xea1b, 0x0000, 0x23fa, 0x1840, 
	0x403b, 0x000a, 0x1840, 0x4982, 0x0128, 0x1800, 0x454c, 0x1840, 
	0x40bc, 0xdead, 0x0000, 0x1840, 0x403c, 0x227a, 0x832c, 0x23fe, 
	0x1840, 0x40b2, 0xa500, 0x0128, 0x832b, 0x23ec, 0x3c05, 0x0000, 
	0x0000, 0x0000, 0x0000, 0x0000, 0x3fff, 0x4303
};

const uint16_t writeFuncletCodeXFLL[] = {
	0x0000,
	0x1800, 0x404A, 0x40B2, 0x5A80, 0x0120, 0x1840, 0x503A, 0x0066, 
	0x1840, 0x40BA,	0xBEEF, 0x0000, 0x3C04, 0xFFFF, 0xFFFF, 0xFFFF, 
	0xFFFF, 0x403B, 0xDEAD, 0x1840, 0xEA1B,	0x0000, 0x23FA, 0x1840, 
	0x4A0B, 0x1840, 0x532B, 0x1800, 0x454C, 0x1840, 0x9BAC,	0x0000, 
	0x240E, 0x40B2, 0xA540, 0x0128, 0x4BAC, 0x0000, 0xB392, 0x012C, 
	0x23FD, 0x40B2, 0xA500, 0x0128, 0x40B2, 0xA500, 0x012C, 0x03EB, 
	0x03EC, 0x8316, 0x23EA,	0x3C00, 0x3FFF, 0x4303
};

const uint16_t eraseFuncletCodeXv2[] = 
{
	0x000E,
	0x000E, 0x00CA, 0xA508, 0xA500, 0xA500, 0xDEAD, 0x000B, 0x40B2,
	0x5A80, 0x015C, 0x4213, 0xFFFE, 0x4290, 0x0140, 0xFFEA, 0x4290, 
	0x0144, 0xFFE6, 0x180F, 0x4AC0, 0xFFE2, 0x40B2, 0x00D0, 0x0186, 
	0x40B2, 0xABAD, 0x018E, 0x40B2, 0xBABE, 0x018C, 0xB3A2, 0x0186, 
	0x27FD, 0x90B2, 0xBEEF, 0x0188, 0x23F9, 0x90B2, 0xDEAD, 0x018A,
	0x23F5, 0xB392, 0x0144, 0x23FD, 0x4882, 0x0144, 0x4290, 0x0144, 
	0xFFA4, 0x98C0,	0xFFA0, 0x2405, 0x480A, 0xD03A, 0x0040, 0x4A82, 
	0x0144, 0x1800, 0x454A, 0x4982,	0x0140, 0x40BA, 0xDEAD, 0x0000, 
	0xB392, 0x0144, 0x23FD, 0x1F80, 0x405A, 0xFF80,	0xE0B0, 0x3300, 
	0xFF76, 0xE0B0, 0x3300, 0xFF72, 0x4092, 0xFF6C, 0x0140, 0x4092,
	0xFF68, 0x0144, 0x4290, 0x0144, 0xFF5C, 0x90D0, 0xFF5C, 0xFF56, 
	0x2406, 0xD0B0,	0x0040, 0xFF52, 0x4092, 0xFF4E, 0x0144, 0x40B2, 
	0xCAFE, 0x018E, 0x40B2, 0xBABE,	0x018C, 0x3FFF
};

const uint16_t writeFuncletCodeXv2WordMode[] = 
{
	0x0012,
	0x0012, 0x011e, 0xa508, 0xa500, 0xa500, 0xdead, 0x000b, 0xdead, 
	0x000b, 0x40b2, 0x5a80, 0x015c, 0x40b2, 0xabad, 0x018e, 0x40b2, 
	0xbabe, 0x018c, 0x4290, 0x0140, 0xffde, 0x4290, 0x0144, 0xffda, 
	0x180f, 0x4ac0, 0xffd6, 0x180f, 0x4bc0, 0xffd4, 0xb392, 0x0144, 
	0x23fd, 0x4882, 0x0144, 0x4290, 0x0144, 0xffba, 0x98c0, 0xffb6, 
	0x2405, 0x480a, 0xd03a, 0x0040, 0x4a82, 0x0144, 0x1800, 0x454a, 
	0x1800, 0x464b, 0x40b2, 0x00d0, 0x0186, 0xb392, 0x0186, 0x27fd, 
	0x421d, 0x0188, 0xc392, 0x0186, 0xb392, 0x0144, 0x23fd, 0x40b2, 
	0xa500, 0x0140, 0x40b2, 0xa540, 0x0140, 0x4d8a, 0x0000, 0x1800, 
	0x536a, 0x1800, 0x835b, 0x2417, 0xb3a2, 0x0186, 0x27fd, 0x421e, 
	0x018a, 0xc3a2, 0x0186, 0xb392, 0x0144, 0x23fd, 0x40b2, 0xa500, 
	0x0140, 0x40b2, 0xa540, 0x0140, 0x4e8a, 0x0000, 0x1800, 0x536a, 
	0x1800, 0x835b, 0x23d2, 0xb392, 0x0144, 0x23fd, 0xc3a2, 0x0186, 
	0xc392, 0x0186, 0x1f80, 0x405a, 0xff32, 0x1f80, 0x405b, 0xff30, 
	0xe0b0, 0x3300, 0xff22, 0xe0b0, 0x3300, 0xff1e, 0x4092, 0xff18, 
	0x0140, 0x4092, 0xff14, 0x0144, 0x4290, 0x0144, 0xff08, 0x90d0, 
	0xff08, 0xff02, 0x2406, 0xd0b0, 0x0040, 0xfefe, 0x4092, 0xfefa, 
	0x0144, 0x40b2, 0xcafe, 0x018e, 0x40b2, 0xbabe, 0x018c, 0x3fff
};

const uint16_t writeFuncletCodeXv2[] = 
{
	0x0012,
	0x0012, 0x00F2, 0xA508, 0xA500, 0xA500, 0xDEAD, 0x000B, 0xDEAD, 
	0x000B, 0x40B2,	0x5A80, 0x015C, 0x40B2, 0xABAD, 0x018E, 0x40B2, 
	0xBABE, 0x018C, 0x4290, 0x0140,	0xFFDE, 0x4290, 0x0144, 0xFFDA, 
	0x180F, 0x4AC0, 0xFFD6, 0x180F, 0x4BC0, 0xFFD4,	0xB392, 0x0144, 
	0x23FD, 0x4882, 0x0144, 0x4290, 0x0144, 0xFFBA, 0x98C0, 0xFFB6,
	0x2405, 0x480A, 0xD03A, 0x0040, 0x4A82, 0x0144, 0x1800, 0x454A, 
	0x1800, 0x464B,	0x40B2, 0x00D0, 0x0186, 0xB3A2, 0x0186, 0x27FD, 
	0x40B2, 0xA580, 0x0140, 0x429A,	0x0188, 0x0000, 0x1800, 0x536A, 
	0x1800, 0x835B, 0x429A, 0x018A, 0x0000, 0xC3A2,	0x0186, 0xC392, 
	0x0186, 0xB392, 0x0144, 0x23FD, 0x40B2, 0xA500, 0x0140, 0x1800,
	0x536A, 0x1800, 0x835B, 0x23E1, 0x1F80, 0x405A, 0xFF5E, 0x1F80, 
	0x405B, 0xFF5C,	0xE0B0, 0x3300, 0xFF4E, 0xE0B0, 0x3300, 0xFF4A, 
	0x4092, 0xFF44, 0x0140, 0x4092,	0xFF40, 0x0144, 0x4290, 0x0144, 
	0xFF34, 0x90D0, 0xFF34, 0xFF2E, 0x2406, 0xD0B0,	0x0040, 0xFF2A, 
	0x4092, 0xFF26, 0x0144, 0x40B2, 0xCAFE, 0x018E, 0x40B2, 0xBABE,
	0x018C, 0x3FFF
};

const uint16_t eraseFuncletCodeXv2FRAM[] = 
{
	0x0012,
	0x0012, 0x00BE, 0xDEAD, 0x000B, 0xDEAD, 0x000B, 0x0000, 0x0000, 0x0000, 0x40B2,
	0x5A80, 0x015C, 0x4292, 0x0162, 0x1C0C, 0x4292, 0x0164, 0x1C0E, 0x4292, 0x0166,
	0x1C10, 0x40B2, 0xA500, 0x0160, 0x40B2, 0x0006, 0x0162, 0x40B2, 0x0033, 0x0164,
	0x40B2, 0x0033, 0x0166, 0x180F, 0x4AC0, 0xFFBE, 0x180F, 0x4BC0, 0xFFBC, 0x40B2,
	0x00D0, 0x0186, 0x40B2, 0xABAD, 0x018E, 0x40B2, 0xBABE, 0x018C, 0xB3A2, 0x0186,
	0x27FD, 0x90B2, 0xBEEF, 0x0188, 0x23F9, 0x90B2, 0xDEAD, 0x018A, 0x23F5, 0x1800,
	0x454A, 0x1800, 0x464B, 0x43BA, 0x0000, 0x1800, 0x536A, 0x1800, 0x836B, 0x930B,
	0x23F8, 0x1F80, 0x405A, 0xFF72, 0x1F80, 0x405B, 0xFF70, 0x40B2, 0xA500, 0x0160,
	0x4292, 0x1C0C, 0x0162, 0x4292, 0x1C0E, 0x0164, 0x4292, 0x1C10, 0x0166, 0x40B2,
	0xCAFE, 0x018E, 0x40B2, 0xBABE, 0x018C, 0x3FFF
};

const uint16_t writeFuncletCodeXv2FRAM[] = 
{
	0x0018,
	0x0018, 0x00D4, 0x0000, 0xA500, 0xA500, 0xDEAD, 0x000B, 0xDEAD, 0x000B, 0x0000,
	0x0000, 0x0000, 0x40B2, 0x5A80, 0x015C, 0x4292, 0x0162, 0x1C12, 0x4292, 0x0164,
	0x1C14, 0x4292, 0x0166, 0x1C16, 0x40B2, 0xA500, 0x0160, 0x40B2, 0x0006, 0x0162,
	0x40B2, 0x0033, 0x0164, 0x40B2, 0x0033, 0x0166, 0x40B2, 0xABAD, 0x018E, 0x40B2,
	0xBABE, 0x018C, 0x180F, 0x4AC0, 0xFFB2, 0x180F, 0x4BC0, 0xFFB0, 0x1800, 0x454A,
	0x1800, 0x464B, 0x40B2, 0x00D0, 0x0186, 0xB3A2, 0x0186, 0x27FD, 0x429A, 0x0188,
	0x0000, 0xC392, 0x0186, 0x1800, 0x536A, 0x1800, 0x835B, 0x930B, 0x2001, 0x3C0C,
	0x429A, 0x018A, 0x0000, 0xC3A2, 0x0186, 0x1800, 0x536A, 0x1800, 0x835B, 0x930B,
	0x23E6, 0x3C00, 0x1F80, 0x405A, 0xFF62, 0x1F80, 0x405B, 0xFF60, 0x40B2, 0xA500,
	0x0160, 0x4292, 0x1C12, 0x0162, 0x4292, 0x1C14, 0x0164, 0x4292, 0x1C16, 0x0166,
	0x40B2, 0xCAFE, 0x018E, 0x40B2, 0xBABE, 0x018C, 0x3FFF
};

const uint16_t UnlockBslFuncletCodeXv2[] = 
{
	0x0018,
	0x0018, 0x008E, 0xDEAD, 0x000B, 0xDEAD, 0x000B, 0xDEAD, 0x000B, 0xDEAD, 0x000B,
	0xDEAD, 0x000B, 0x40B2, 0x5A80, 0x015C, 0x4180, 0xFFF4, 0x180F, 0x4BC0, 0xFFEA,
	0x180F, 0x4CC0, 0xFFD8, 0x180F, 0x4DC0, 0xFFD6, 0x40B2, 0x00D0, 0x0186, 0x40B2,
	0xABAD, 0x018E, 0x40B2, 0xBABE, 0x018C, 0xB3A2, 0x0186, 0x27FD, 0x90B2, 0xBEEF,
	0x0188, 0x23F9, 0x90B2, 0xDEAD, 0x018A, 0x23F5, 0x1800, 0x435C, 0x403D, 0xDEAD,
	0x403E, 0xBEEF, 0x13B0, 0x1002, 0x4011, 0xFFA6, 0x1F80, 0x405B, 0xFF9C, 0x1F80,
	0x405C, 0xFF8A, 0x1F80, 0x405D, 0xFF88, 0x40B2, 0xCAFE, 0x018E, 0x40B2, 0xBABE,
	0x018C, 0x3FFF,
};

#endif