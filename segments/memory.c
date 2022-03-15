#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>

#include "../constants.h"
#include "seg.h"

Seg memory(FILE *meminfo) {
	double total, available;
	Seg mem;

	rewind(meminfo);
	if (fscanf(meminfo, "MemTotal: %lf kB\nMemFree: %*f kB\nMemAvailable: %lf kB", &total, &available) != 2) {
		sprintf(mem.value, "\ufb19NA%%%%");
		return mem;
	}

	double used = total - available;
	sprintf(mem.value, "\ufb19%.1f%%%%", used / total * 100);
	return mem;
}
