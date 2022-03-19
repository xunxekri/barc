#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../constants.h"
#include "seg.h"

static int is_utf8_header_char(char c) {
	return c >> 1 & c & 64;
}

static void update_weather(char *buf, size_t length, size_t buf_length) {
	FILE *weatherfile = fopen("/tmp/weather", "r");

	if (weatherfile == NULL) {
		sprintf(buf, "No weather data.");
		return;
	}

 	char content[length+1];
	if (fread(content, 1, length, weatherfile) != length) {
		sprintf(buf, "No weather data.");
		fclose(weatherfile);
		return;
	} else {
		content[length] = '\0';
		fclose(weatherfile);
	}

	// get required length of wchar buffer
	size_t wlength = mbstowcs(NULL, content, 0);

	wchar_t adam_driver[wlength+1];
	wchar_t *whatever = adam_driver;
	wchar_t ben_swolo[wlength+1];
	wchar_t *temp = ben_swolo;
	mbstowcs(adam_driver, content, wlength + 1);
	while (*whatever != L'\0') {
		switch(*whatever) {
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
			case L'\n':
			case 0xb0:
			case L'+': //plus sign
				temp--; //skip
			break;
			default:
				*temp = *whatever;
		}
		temp++;
		whatever++;
	}
	*temp = L'\0';

	wcstombs(content, ben_swolo, length + 1);
	strncpy(buf, content, buf_length - 1);
	char *temp2 = buf + buf_length - 1;

	//characters are at most 2 bytes, so if the last byte is a utf 8 header char, truncate at that point
	if(is_utf8_header_char(*temp2))
		temp2--;

	*temp2 = '\0';
}

Seg weather() {
	static time_t last_modified = 0;
	static Seg weather_seg;

	struct stat file_stat;
	if (stat("/tmp/weather", &file_stat) != 0) {
		sprintf(weather_seg.value, "No weather data.");
	} else if (file_stat.st_mtime > last_modified) {
		last_modified = file_stat.st_mtime;
		update_weather(weather_seg.value, file_stat.st_size, MAX_LENGTH);
	}

	return weather_seg;
}
