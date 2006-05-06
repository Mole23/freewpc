/*
 * Copyright 2006 by Brian Dominy <brian@oddchange.com>
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
#include <rtsol.h>

U8 rtsol_lower_jet;

void slingshot_rtt (void)
{
	extern U8 *sol_state;

	rt_solenoid_update ((char *)&sol_state + (SOL_LOWER_JET / 8),
		1 << (SOL_LOWER_JET % 8),
		RTSOL_ACTIVE_HIGH,
		&switch_bits[0][0] + (SW_BOTTOM_JET / 8),
		1 << (SW_BOTTOM_JET % 8),
		RTSW_ACTIVE_HIGH,
		&rtsol_lower_jet,
		8,
		8);
}


DECLARE_SWITCH_DRIVER (sw_left_sling)
{
	.flags = SW_PLAYFIELD,
	.sound = SND_SLINGSHOT,
};


DECLARE_SWITCH_DRIVER (sw_right_sling)
{
	.flags = SW_PLAYFIELD,
	.sound = SND_SLINGSHOT,
};

