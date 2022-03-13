#include <stdio.h>
#include "../constants.h"

static int min(int a, int b) {
    return a > b ? b : a;
}

char *weather() {
	FILE *weatherfile = fopen("/tmp/weather", "r");

	fseek(weatherfile, 0, SEEK_END);
	int length = (int) ftell(weatherfile);
	rewind(weatherfile);

	static char content[MAX_LENGTH];	
	fread(content, min(MAX_LENGTH, length), 1, weatherfile);
	content[min(length + 1, MAX_LENGTH - 1)] = '\0';

	fclose(weatherfile);
	return content;
}
