#include <stdio.h>
#include <stdbool.h>
#include "seg.h"

const char *COLOR_STRINGS[] = {
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

static const Color PERCENT_COLORS[] = {
	RED,
	PEACH,
	YELLOW,
	GREEN,
	TEAL,
	BLUE,
	SKY,
	MAUVE
};

Color percent_to_color(int percent, bool high_is_bad) {
	if (percent < 0 || percent > 100) return WHITE;
	if (high_is_bad) percent = 100 - percent;
	return PERCENT_COLORS[percent * 2 / 25 - !(percent % 25) + !percent];
}
