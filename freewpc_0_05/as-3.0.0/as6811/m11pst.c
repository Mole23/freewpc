/* m11pst.c */

/*
 * (C) Copyright 1989-2000
 * All Rights Reserved
 *
 * Alan R. Baldwin
 * 721 Berkeley St.
 * Kent, Ohio  44240
 */

#include <stdio.h>
#include <setjmp.h>
#include "asxxxx.h"
#include "m6811.h"

struct	mne	mne[] = {

	/* machine */

    {	NULL,	".setdp",	S_SDP,		0,	0	},

	/* system */

    {	NULL,	"CON",		S_ATYP,		0,	A_CON	},
    {	NULL,	"OVR",		S_ATYP,		0,	A_OVR	},
    {	NULL,	"REL",		S_ATYP,		0,	A_REL	},
    {	NULL,	"ABS",		S_ATYP,		0,	A_ABS|A_OVR	},
    {	NULL,	"NOPAG",	S_ATYP,		0,	A_NOPAG	},
    {	NULL,	"PAG",		S_ATYP,		0,	A_PAG	},

    {	NULL,	".byte",	S_DATA,		0,	1	},
    {	NULL,	".db",		S_DATA,		0,	1	},
    {	NULL,	".word",	S_DATA,		0,	2	},
    {	NULL,	".dw",		S_DATA,		0,	2	},
    {	NULL,	".ascii",	S_ASCII,	0,	0	},
    {	NULL,	".asciz",	S_ASCIZ,	0,	0	},
    {	NULL,	".blkb",	S_BLK,		0,	1	},
    {	NULL,	".ds",		S_BLK,		0,	1	},
    {	NULL,	".blkw",	S_BLK,		0,	2	},
    {	NULL,	".page",	S_PAGE,		0,	0	},
    {	NULL,	".title",	S_TITLE,	0,	0	},
    {	NULL,	".sbttl",	S_SBTL,		0,	0	},
    {	NULL,	".globl",	S_GLOBL,	0,	0	},
    {	NULL,	".area",	S_DAREA,	0,	0	},
    {	NULL,	".even",	S_EVEN,		0,	0	},
    {	NULL,	".odd",		S_ODD,		0,	0	},
    {	NULL,	".if",		S_IF,		0,	0	},
    {	NULL,	".else",	S_ELSE,		0,	0	},
    {	NULL,	".endif",	S_ENDIF,	0,	0	},
    {	NULL,	".include",	S_INCL,		0,	0	},
    {	NULL,	".radix",	S_RADIX,	0,	0	},
    {	NULL,	".org",		S_ORG,		0,	0	},
    {	NULL,	".module",	S_MODUL,	0,	0	},
    {	NULL,	".ascis",	S_ASCIS,	0,	0	},
    {	NULL,	".assume",	S_ERROR,	0,	0	},
    {	NULL,	".error",	S_ERROR,	0,	1	},

	/* 6811 */

    {	NULL,	"bra",		S_BRA,		0,	0x20	},
    {	NULL,	"brn",		S_BRA,		0,	0x21	},
    {	NULL,	"bhi",		S_BRA,		0,	0x22	},
    {	NULL,	"bls",		S_BRA,		0,	0x23	},
    {	NULL,	"bcc",		S_BRA,		0,	0x24	},
    {	NULL,	"bhs",		S_BRA,		0,	0x24	},
    {	NULL,	"bcs",		S_BRA,		0,	0x25	},
    {	NULL,	"blo",		S_BRA,		0,	0x25	},
    {	NULL,	"bne",		S_BRA,		0,	0x26	},
    {	NULL,	"beq",		S_BRA,		0,	0x27	},
    {	NULL,	"bvc",		S_BRA,		0,	0x28	},
    {	NULL,	"bvs",		S_BRA,		0,	0x29	},
    {	NULL,	"bpl",		S_BRA,		0,	0x2A	},
    {	NULL,	"bmi",		S_BRA,		0,	0x2B	},
    {	NULL,	"bge",		S_BRA,		0,	0x2C	},
    {	NULL,	"blt",		S_BRA,		0,	0x2D	},
    {	NULL,	"bgt",		S_BRA,		0,	0x2E	},
    {	NULL,	"ble",		S_BRA,		0,	0x2F	},
    {	NULL,	"bsr",		S_BRA,		0,	0x8D	},

    {	NULL,	"neg",		S_TYP1,		0,	0x40	},
    {	NULL,	"com",		S_TYP1,		0,	0x43	},
    {	NULL,	"lsr",		S_TYP1,		0,	0x44	},
    {	NULL,	"ror",		S_TYP1,		0,	0x46	},
    {	NULL,	"asr",		S_TYP1,		0,	0x47	},
    {	NULL,	"asl",		S_TYP1,		0,	0x48	},
    {	NULL,	"lsl",		S_TYP1,		0,	0x48	},
    {	NULL,	"rol",		S_TYP1,		0,	0x49	},
    {	NULL,	"dec",		S_TYP1,		0,	0x4A	},
    {	NULL,	"inc",		S_TYP1,		0,	0x4C	},
    {	NULL,	"tst",		S_TYP1,		0,	0x4D	},
    {	NULL,	"clr",		S_TYP1,		0,	0x4F	},

    {	NULL,	"sub",		S_TYP2,		0,	0x80	},
    {	NULL,	"cmp",		S_TYP2,		0,	0x81	},
    {	NULL,	"sbc",		S_TYP2,		0,	0x82	},
    {	NULL,	"and",		S_TYP2,		0,	0x84	},
    {	NULL,	"bit",		S_TYP2,		0,	0x85	},
    {	NULL,	"lda",		S_TYP2,		0,	0x86	},
    {	NULL,	"sta",		S_TYP2,		0,	0x87	},
    {	NULL,	"eor",		S_TYP2,		0,	0x88	},
    {	NULL,	"adc",		S_TYP2,		0,	0x89	},
    {	NULL,	"ora",		S_TYP2,		0,	0x8A	},
    {	NULL,	"add",		S_TYP2,		0,	0x8B	},

    {	NULL,	"suba",		S_TYP3,		0,	0x80	},
    {	NULL,	"subb",		S_TYP3,		0,	0xC0	},
    {	NULL,	"cmpa",		S_TYP3,		0,	0x81	},
    {	NULL,	"cmpb",		S_TYP3,		0,	0xC1	},
    {	NULL,	"sbca",		S_TYP3,		0,	0x82	},
    {	NULL,	"sbcb",		S_TYP3,		0,	0xC2	},
    {	NULL,	"subd",		S_TYP3,		0,	0x83	},
    {	NULL,	"addd",		S_TYP3,		0,	0xC3	},
    {	NULL,	"anda",		S_TYP3,		0,	0x84	},
    {	NULL,	"andb",		S_TYP3,		0,	0xC4	},
    {	NULL,	"bita",		S_TYP3,		0,	0x85	},
    {	NULL,	"bitb",		S_TYP3,		0,	0xC5	},
    {	NULL,	"ldaa",		S_TYP3,		0,	0x86	},
    {	NULL,	"ldab",		S_TYP3,		0,	0xC6	},
    {	NULL,	"staa",		S_TYP3,		0,	0x87	},
    {	NULL,	"stab",		S_TYP3,		0,	0xC7	},
    {	NULL,	"eora",		S_TYP3,		0,	0x88	},
    {	NULL,	"eorb",		S_TYP3,		0,	0xC8	},
    {	NULL,	"adca",		S_TYP3,		0,	0x89	},
    {	NULL,	"adcb",		S_TYP3,		0,	0xC9	},
    {	NULL,	"oraa",		S_TYP3,		0,	0x8A	},
    {	NULL,	"orab",		S_TYP3,		0,	0xCA	},
    {	NULL,	"adda",		S_TYP3,		0,	0x8B	},
    {	NULL,	"addb",		S_TYP3,		0,	0xCB	},

    {	NULL,	"jsr",		S_TYP4,		0,	0x8D	},
    {	NULL,	"lds",		S_TYP4,		0,	0x8E	},
    {	NULL,	"sts",		S_TYP4,		0,	0x8F	},
    {	NULL,	"ldd",		S_TYP4,		0,	0xCC	},
    {	NULL,	"std",		S_TYP4,		0,	0xCD	},

    {	NULL,	"jmp",		S_TYP5,		0,	0x6E	},

    {	NULL,	"cpd",		S_PG3,		0,	0x83	},
    {	NULL,	"cmpd",		S_PG3,		0,	0x83	},
    {	NULL,	"cpx",		S_TYP6,		0,	0x8C	},
    {	NULL,	"cmpx",		S_TYP6,		0,	0x8C	},
    {	NULL,	"cpy",		S_PG2,		0,	0x8C	},
    {	NULL,	"cmpy",		S_PG2,		0,	0x8C	},
    {	NULL,	"ldx",		S_TYP6,		0,	0xCE	},
    {	NULL,	"ldy",		S_PG2,		0,	0xCE	},
    {	NULL,	"stx",		S_TYP6,		0,	0xCF	},
    {	NULL,	"sty",		S_PG2,		0,	0xCF	},

    {	NULL,	"brset",	S_BTB,		0,	0x12	},
    {	NULL,	"brclr",	S_BTB,		0,	0x13	},
    {	NULL,	"bset",		S_STCLR,	0,	0x14	},
    {	NULL,	"bclr",		S_STCLR,	0,	0x15	},

    {	NULL,	"aba",		S_INH,		0,	0x1B	},
    {	NULL,	"abx",		S_INH,		0,	0x3A	},
    {	NULL,	"aby",		S_INH2,		0,	0x3A	},
    {	NULL,	"asla",		S_INH,		0,	0x48	},
    {	NULL,	"aslb",		S_INH,		0,	0x58	},
    {	NULL,	"asld",		S_INH,		0,	0x05	},
    {	NULL,	"asra",		S_INH,		0,	0x47	},
    {	NULL,	"asrb",		S_INH,		0,	0x57	},
    {	NULL,	"cba",		S_INH,		0,	0x11	},
    {	NULL,	"clc",		S_INH,		0,	0x0C	},
    {	NULL,	"cli",		S_INH,		0,	0x0E	},
    {	NULL,	"clra",		S_INH,		0,	0x4F	},
    {	NULL,	"clrb",		S_INH,		0,	0x5F	},
    {	NULL,	"clv",		S_INH,		0,	0x0A	},
    {	NULL,	"coma",		S_INH,		0,	0x43	},
    {	NULL,	"comb",		S_INH,		0,	0x53	},
    {	NULL,	"daa",		S_INH,		0,	0x19	},
    {	NULL,	"deca",		S_INH,		0,	0x4A	},
    {	NULL,	"decb",		S_INH,		0,	0x5A	},
    {	NULL,	"des",		S_INH,		0,	0x34	},
    {	NULL,	"dex",		S_INH,		0,	0x09	},
    {	NULL,	"dey",		S_INH2,		0,	0x09	},
    {	NULL,	"idiv",		S_INH,		0,	0x02	},
    {	NULL,	"fdiv",		S_INH,		0,	0x03	},
    {	NULL,	"inca",		S_INH,		0,	0x4C	},
    {	NULL,	"incb",		S_INH,		0,	0x5C	},
    {	NULL,	"ins",		S_INH,		0,	0x31	},
    {	NULL,	"inx",		S_INH,		0,	0x08	},
    {	NULL,	"iny",		S_INH2,		0,	0x08	},
    {	NULL,	"lsla",		S_INH,		0,	0x48	},
    {	NULL,	"lslb",		S_INH,		0,	0x58	},
    {	NULL,	"lsld",		S_INH,		0,	0x05	},
    {	NULL,	"lsra",		S_INH,		0,	0x44	},
    {	NULL,	"lsrb",		S_INH,		0,	0x54	},
    {	NULL,	"lsrd",		S_INH,		0,	0x04	},
    {	NULL,	"mul",		S_INH,		0,	0x3D	},
    {	NULL,	"nega",		S_INH,		0,	0x40	},
    {	NULL,	"negb",		S_INH,		0,	0x50	},
    {	NULL,	"nop",		S_INH,		0,	0x01	},
    {	NULL,	"psha",		S_INH,		0,	0x36	},
    {	NULL,	"pshb",		S_INH,		0,	0x37	},
    {	NULL,	"pshx",		S_INH,		0,	0x3C	},
    {	NULL,	"pshy",		S_INH2,		0,	0x3C	},
    {	NULL,	"pula",		S_INH,		0,	0x32	},
    {	NULL,	"pulb",		S_INH,		0,	0x33	},
    {	NULL,	"pulx",		S_INH,		0,	0x38	},
    {	NULL,	"puly",		S_INH2,		0,	0x38	},
    {	NULL,	"rola",		S_INH,		0,	0x49	},
    {	NULL,	"rolb",		S_INH,		0,	0x59	},
    {	NULL,	"rora",		S_INH,		0,	0x46	},
    {	NULL,	"rorb",		S_INH,		0,	0x56	},
    {	NULL,	"rti",		S_INH,		0,	0x3B	},
    {	NULL,	"rts",		S_INH,		0,	0x39	},
    {	NULL,	"sba",		S_INH,		0,	0x10	},
    {	NULL,	"sec",		S_INH,		0,	0x0D	},
    {	NULL,	"sei",		S_INH,		0,	0x0F	},
    {	NULL,	"sev",		S_INH,		0,	0x0B	},
    {	NULL,	"stop",		S_INH,		0,	0xCF	},
    {	NULL,	"swi",		S_INH,		0,	0x3F	},
    {	NULL,	"tab",		S_INH,		0,	0x16	},
    {	NULL,	"tap",		S_INH,		0,	0x06	},
    {	NULL,	"tba",		S_INH,		0,	0x17	},
    {	NULL,	"tpa",		S_INH,		0,	0x07	},
    {	NULL,	"tsta",		S_INH,		0,	0x4D	},
    {	NULL,	"tstb",		S_INH,		0,	0x5D	},
    {	NULL,	"tsx",		S_INH,		0,	0x30	},
    {	NULL,	"tsy",		S_INH2,		0,	0x30	},
    {	NULL,	"txs",		S_INH,		0,	0x35	},
    {	NULL,	"tys",		S_INH2,		0,	0x35	},
    {	NULL,	"wai",		S_INH,		0,	0x3E	},
    {	NULL,	"xgdx",		S_INH,		0,	0x8F	},
    {	NULL,	"xgdy",		S_INH2,		0,	0x8F	},

    {	NULL,	"pul",		S_PUL,		0,	0x32	},
    {	NULL,	"psh",		S_PUL,		S_END,	0x36	}
};
