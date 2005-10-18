
#include <freewpc.h>

#define DECLARE_PAGED	_Pragma ("section (\"font\")")

DECLARE_PAGED
const uint8_t font_5x5_alpha_cap[][5] = {
	{ 4, 10, 31, 17, 17 },
	{ 7, 9, 7, 9, 7 },
	{ 14, 1, 1, 1, 14 },
	{ 7, 9, 17, 9, 7 },
	{ 31, 1, 31, 1, 31 },

	{ 31, 1, 31, 1, 1 },
	{ 14, 1, 25, 9, 15 },
	{ 17, 17, 31, 17, 17 },
	{ 31, 4, 4, 4, 31 },
	{ 15, 4, 4, 5, 2 },

	{ 17, 9, 7, 9, 17 },
	{ 1, 1, 1, 1, 31 },
	{ 17, 27, 21, 17, 17 },
	{ 17, 19, 21, 25, 17 },
	{ 14, 17, 17, 17, 14 },
	
	{ 15, 17, 15, 1, 1 },
	{ 14, 17, 21, 25, 30 },
	{ 15, 17, 15, 9, 17 },
	{ 14, 1, 14, 16, 14 },
	{ 31, 4, 4, 4, 4 },

	{ 17, 17, 17, 17, 14 },
	{ 17, 17, 10, 10, 4 },
	{ 17, 17, 21, 21, 14 },
	{ 17, 10, 4, 10, 17 },
	{ 17, 10, 4, 4, 4 },
	{ 31, 8, 4, 2, 31 },
};


const uint8_t font_5x5_digit[][5] = {
	{ 14, 17, 17, 17, 14 },
	{ 4, 6, 4, 4, 14 },
	{ 14, 16, 14, 1, 31 },
	{ 14, 16, 14, 16, 14 },
	{ 5, 5, 31, 4, 4 },
	{ 31, 1, 15, 16, 15 },
	{ 14, 1, 15, 17, 14 },
	{ 31, 8, 4, 2, 1 },
	{ 14, 17, 14, 17, 14 },
	{ 14, 17, 30, 16, 14 },
};


const font_t font_5x5 = {
	.width = 5, 
	.spacing = 3,
	.height = 5, 
	.chars = (uint8_t **)font_5x5_alpha_cap, 
	.digits = (uint8_t **)font_5x5_digit
};


