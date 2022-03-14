#include <string.h>
#include <time.h>
#include "../constants.h"
#include "seg.h"

Seg datetime() {
	time_t current_time = time(NULL);
	struct tm *time = localtime(&current_time);
	static Seg dt;
	dt.color = PINK;
	strftime(dt.value, MAX_LENGTH, "%a %b %-d, %H:%M:%S", time);
	return dt;
}
