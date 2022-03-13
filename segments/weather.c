#include <stdio.h>
#include "../constants.h"

char *weather() {
	FILE *weatherfile = fopen("/tmp/weather", "r");

	fseek(weatherfile, 0, SEEK_END);
	int length = (int) ftell(weatherfile);
	rewind(weatherfile);

	static char content[MAX_LENGTH];	
	fread(content, length, 1, weatherfile);
	content[length - 1] = '\0';

	fclose(weatherfile);
	return content;
}
