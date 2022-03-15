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

Color percent_to_color(int percent) {
	if (percent < 0 || percent > 100) return WHITE;
	else if (percent >= 88) return MAUVE;
	else if (percent >= 76) return SKY;
	else if (percent >= 63) return BLUE;
	else if (percent >= 51) return TEAL;
	else if (percent >= 38) return GREEN;
	else if (percent >= 26) return YELLOW;
	else if (percent >= 13) return PEACH;
	else return RED;
}
