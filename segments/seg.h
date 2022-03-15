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

extern const char *COLOR_STRINGS[];

Color percent_to_color(int percent);

#endif
