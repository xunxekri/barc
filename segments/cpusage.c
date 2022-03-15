#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../constants.h"
#include "seg.h"

Seg cpusage() {
	double cores = (double) sysconf(_SC_NPROCESSORS_ONLN);
	double avgs[3];
	getloadavg(avgs, 3);
	double cpul = (avgs[0] / cores) * 100;
	Seg cpu;
	cpu.color = BLUE;
	sprintf(cpu.value, "\ufb19%.1f%%%%", cpul);
	return cpu;
}
