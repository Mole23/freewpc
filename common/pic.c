/*
 * Copyright 2007, 2008 by Brian Dominy <brian@oddchange.com>
 *
 * This file is part of FreeWPC.
 *
 * FreeWPC is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * FreeWPC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with FreeWPC; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <freewpc.h>

#define pic_debug(rest...)

#ifdef CONFIG_NATIVE
#define POS_CONVERT(pos) (3-(pos))
#else
#define POS_CONVERT(pos) pos
#endif

#define PICMAP(byte, reg, pos) [byte] = (U8 *)&pic_serial_encoded.reg + POS_CONVERT (pos)


struct pic_serial_encoded
{
	U32 reg1;
	U32 reg2;
	U32 reg3;
	U32 reg4;
	U8 check10;
	U8 check2;
} pic_serial_encoded;


U8 *pic_serial_map[] =
{
	PICMAP(3, reg3, 1),
	PICMAP(14, reg3, 2),
	PICMAP(6, reg3, 3),

	PICMAP(1, reg1, 1),
	PICMAP(11, reg1, 2),
	PICMAP(9, reg1, 3),

	PICMAP(7, reg2, 0),
	PICMAP(12, reg2, 1),
	PICMAP(0, reg2, 2),
	PICMAP(8, reg2, 3),

	PICMAP(2, check2, 0),
	PICMAP(10, check10, 0),

	PICMAP(15, reg4, 2),
	PICMAP(4, reg4, 3),

	[5] = NULL,
	[13] = NULL,
};


struct pic_strip_info
{
	/* Up to 5 digits can be stored per register;
	 * these are ordered from 10000's to 1's.
	 * If a particular digit is to be ignored,
	 * it is set to -1, otherwise the value here
	 * indicates which serial number digit is
	 * present here. */
	S8 place[5];
} pic_strip_info[] = {
	{ -1, -1, 1, 7, 4 },
	{ 2, 15, 0, 8, 6 },
	{ -1, 16, 3, 5, 14 },
	{ 13, 12, 11, 10, 9 },
};


/** A lookup table to aid in division by powers of ten. */
static const U16 place_value[] = {
	10000U,
	1000U,
	100U,
	10U,
	1U
};

/** The decoded PIC serial number.  The 17-digit serial number
 * is stored here in textual format, i.e. each byte is between
 * '0' and '9'.  The last byte is kept as a '\0' to allow
 * the whole thing to be printed. */
U8 pic_serial_number[18];

/** True if the PIC could not be read or some error occurred during
 * reading, so that the PIC data should not be trusted. */
bool pic_invalid;


#if 0
/** A generic division algorithm based on repeated subtraction.
 * It is not the most efficient, but it works.  The 6809 compiler
 * support for long division is sketchy at this point. */
#ifndef CONFIG_NATIVE
static __attribute__((noinline)) void udiv32 (U32 reg, U16 divisor, U32 *quotientp, U32 *remainderp)
{
	register U32 quotient = 0;
	register U32 guess;

	while (reg >= divisor)
	{
		/* Make a guess for the quotient, taking care to
		 * err on the low side always.
		 *
		 * It is always safe to guess 1, although that will be the slowest.
		 */
		if ((divisor < 5) && (reg > 320))
		{
			guess = 64;
			quotient += guess;
			reg -= divisor * guess;
		}
		else
		{
			guess = 1;
			quotient += guess;
			reg -= divisor * guess;
		}

	}
	if (*remainderp)
		*remainderp = reg;
	if (*quotientp)
		*quotientp = quotient;
}
#endif /* !CONFIG_NATIVE */
#endif /* 0 */


void pic_decode32 (U32 *reg, const U32 offset, const U16 divisor, const bool negate)
{
	pic_debug ("reg.start = %w\n", *reg);
	pic_debug ("offset = %w\n", offset);
	pic_debug ("divisor = %ld\n", divisor);
	if (negate)
	{
		*reg = offset -*reg;
		pic_debug ("reg.after_negate = %w\n", *reg);
	}
	else
	{
		*reg -= offset;
		pic_debug ("reg.after_subtract = %w\n", *reg);
	}

#ifdef CONFIG_NATIVE
	if (*reg % divisor)
		dbprintf ("error: there is a remainder\n");
	*reg /= divisor;
#else
	udiv32 (*reg, divisor, reg, NULL);
#endif
	pic_debug ("reg.after_divide = %w\n", *reg);
}


/** Strip the individual digits of a decoded PIC register,
 * and store them separately into the decoded serial number
 * array according to the mapping defined in INFO. */
void pic_strip_digits (U32 reg, struct pic_strip_info *info)
{
	U8 place;
	U8 digit;

	if (reg > 100000ULL)
	{
		dbprintf ("error: strip reg is too large\n");
		while (reg > 100000ULL)
			reg -= 100000ULL;
	}

	for (place = 0 ; place < 5 ; place++)
	{
		digit = 0;
		while (reg >= place_value[place])
		{
			reg -= place_value[place];
			digit++;
		}

		if (info->place[place] != -1)
		{
			pic_debug ("Digit %d is %d (place was %ld)\n", info->place[place], digit, place_value[place]);
			pic_serial_number[info->place[place]] = digit + '0';
		}
	}
}


/** Return the game number as stored in the PIC. */
U16 pic_read_game_number (void)
{
	U16 game_number;

	game_number = 100UL * (pic_serial_number[0] - '0')
		+ 10UL * (pic_serial_number[1] - '0')
		+ (pic_serial_number[2] - '0');

	return game_number;
}


/** Verify that the PIC game number is correct.
 * A normal WPC ROM would complain badly if this is not true; we only give
 * a warning. */
void pic_verify (void)
{
	U16 pic_game_number = pic_read_game_number ();
	U16 expected_game_number = MACHINE_NUMBER;

	if (pic_game_number != expected_game_number)
	{
		dbprintf ("warning: expected game number %ld, found %ld\n",
			expected_game_number, pic_game_number);
	}

	/* Mark the PIC data as valid. */
	pic_invalid = FALSE;
}


/**
 * Initialize the PIC security device.
 */
void pic_init (void)
{
	U8 i;
	U8 val;
	U8 *ereg;
	U16 rval;

	dbprintf ("Initialize the PIC...\n");
	pic_invalid = TRUE;

	/* Reset the PIC. */
	wpc_write_pic (WPC_PIC_RESET);

	/* Zero the serial number registers */
	memset (&pic_serial_number, '0', sizeof (pic_serial_number));

	/* Zero the encoding registers.  Because most of these are
	 * 32-bit numbers, but sometimes only 16 or 24 bits will be
	 * set below, we ensure the uppermost bytes are zero here. */
	memset (&pic_serial_encoded, 0, sizeof (pic_serial_encoded));

	/* Read each of the PIC serial registers, and store the
	 * value returned into the appropriate encoding register,
	 * using the serial map to guide us. */
	for (i=0; i < 16; i++)
	{
		/* Read a single PIC register, and store it in the
		 * correct slot. */
		wpc_write_pic (WPC_PIC_SERIAL (i));
		val = wpc_read_pic ();
		ereg = pic_serial_map[i];
		if (ereg)
			*ereg = val;
	}

	/* Each encoding register holds one or more PIC digits,
	 * multiplied by some magic value, offset by some magic value...
	 * The next step is to strip out the magic values, leaving only
	 * the digits.
	 *
	 * If any division yields a remainder, the data is invalid.
	 *
	 * The check registers are not modified in any way, but serve
	 * as an adjustment on reg2 and reg3.
	 */

	/* reg1 = digits x 1BCD + 1F3F0
	 * reg2 = digits x 107F + 71E259
	 * reg3 = digits x 245 + 3D74
	 * reg4 = 99999 - digits
	 */
	pic_decode32 (&pic_serial_encoded.reg1, 0x1F3F0ULL, 0x1BCD, FALSE);
	pic_serial_encoded.reg1 -= (5 * pic_serial_encoded.check10);
	pic_strip_digits (pic_serial_encoded.reg1, &pic_strip_info[0]);
	
	pic_decode32 (&pic_serial_encoded.reg2, 0x71E259ULL, 0x107F, FALSE);
	pic_serial_encoded.reg2 -= (2 * pic_serial_encoded.check10 + pic_serial_encoded.check2);
	pic_strip_digits (pic_serial_encoded.reg2, &pic_strip_info[1]);

	pic_decode32 (&pic_serial_encoded.reg3, 0x3D74ULL, 0x245, FALSE);
	pic_serial_encoded.reg3 -= pic_serial_encoded.check2;
	pic_strip_digits (pic_serial_encoded.reg3, &pic_strip_info[2]);
	
	pic_decode32 (&pic_serial_encoded.reg4, 99999UL, 1, TRUE);
	pic_strip_digits (pic_serial_encoded.reg4, &pic_strip_info[3]);

	pic_verify ();
}


/** Render the serial number read from the PIC for display. */
void pic_render_serial_number (void)
{
	sprintf ("%3s %6s %5s", pic_serial_number, pic_serial_number+3, pic_serial_number+9);
}
