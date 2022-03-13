#include <time.h>
#include "../constants.h"

char *datetime() {
	time_t current_time = time(NULL);
	struct tm *time = localtime(&current_time);
	static char date[MAX_LENGTH];
	strftime(date, MAX_LENGTH, "%a %b %-d, %H:%M:%S", time);
	return date;
}
