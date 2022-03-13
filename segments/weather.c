#include <stdio.h>
#include <stdlib.h>
#include "../constants.h"

static int min(int a, int b) {
    return a > b ? b : a;
}

static int bitbs(char c) {
	return (c >> 1 & c & 64);
}

char *weather() {
	FILE *weatherfile = fopen("/tmp/weather", "r");

	fseek(weatherfile, 0, SEEK_END);
	int length = (int) ftell(weatherfile);
	rewind(weatherfile);

	char *content = malloc(length + 1);	
	fread(content, length, 1, weatherfile);
	content[length] = '\0';

	wchar_t adam_driver[length];
	wchar_t *temp;
	mbstowcs(adam_driver, content, length);
	adam_driver[MAX_LENGTH] = L'\0';
	while (*temp != L'\0') {
		switch(*temp) {
			case 0x2600:
				*temp = 0xe30d;
			break;
			case 0x2601:
				*temp = 0xe32e;
			break;
			case 0x26c5:
				*temp = 0xe302;
			break;
			case 0x26c8:
				*temp = 0xe31c;
			break;
			case 0x2728:
				*temp = 0xe370;
			break;
			case 0x2744:
				*temp = 0xe36f;
			break;
			case 0x1f311:
				*temp = 0xe3d5;
			break;
			case 0x1f312:
				*temp = 0xe3d8;
			break;
			case 0x1f313:
				*temp = 0xe3dc;
			break;
			case 0x1f314:
				*temp = 0xe3e0;
			break;
			case 0x1f315:
				*temp = 0xe3e3;
			break;
			case 0x1f316:
				*temp = 0xe3ca;
			break;
			case 0x1f317:
				*temp = 0xe3ce;
			break;
			case 0x1f318:
				*temp = 0xe3d1;
			break;
			case 0x1f326:
				*temp = 0xe35f;
			break;
			case 0x1f327:
				*temp = 0xe316;
			break;
			case 0x1f328:
				*temp = 0xe318;
			break;
			case 0x1f329:
				*temp = 0xfa92;
			break;
			case 0x1f32b:
				*temp = 0xe31e;
			break;
		}
	}
	wcstombs(content, adam_driver, MAX_LENGTH);
	char *temp2 = content + MAX_LENGTH - 1;
	while(bitbs(*temp2))
		temp2--;
	*temp2 = '\0';
	fclose(weatherfile);
	return content;
}
