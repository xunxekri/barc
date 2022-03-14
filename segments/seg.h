#ifndef BARC_SEG_H
#define BARC_SEG_H

#include "../constants.h"

typedef enum {
	FLAMINGO,
	MAUVE,
	PINK,
	MAROON,
	RED,
	PEACH,
	YELLOW,
	GREEN,
	TEAL,
	BLUE,
	SKY,
	BLACK_0,
	BLACK_1,
	BLACK_2,
	BLACK_3,
	BLACK_4,
	GRAY_0,
	GRAY_1,
	GRAY_2,
	WHITE,
	LAVENDER,
	ROSEWATER,
	TRANSPARENT
} Color;

typedef struct {
	Color color;
	char value[MAX_LENGTH];
} Seg;

static char *color_strings[] = {
	[FLAMINGO] = "F2CDCD",
	[MAUVE] = "DDB6F2",
	[PINK] = "F5C2E7",
	[MAROON] = "E8A2AF",
	[RED] = "F28FAD",
	[PEACH] = "F8BD96",
	[YELLOW] = "FAE3B0",
	[GREEN] = "ABE9B3",
	[TEAL] = "B5E8E0",
	[BLUE] = "96CDFB",
	[SKY] = "89DCEB",
	[BLACK_0] = "161320",
	[BLACK_1] = "1A1826",
	[BLACK_2] = "1E1E2E",
	[BLACK_3] = "302D41",
	[BLACK_4] = "575268",
	[GRAY_0] = "6E6C7E",
	[GRAY_1] = "988BA2",
	[GRAY_2] = "C3BAC6",
	[WHITE] = "D9E0EE",
	[LAVENDER] = "C9CBFF",
	[ROSEWATER] = "F5E0DC",
	[TRANSPARENT] = "00000000"
};
	
#endif
