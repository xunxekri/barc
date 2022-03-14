#include <stdio.h>
#include <unistd.h>
#include "../constants.h"
#include "seg.h"

Seg memory() {
	double total_pages = (double) sysconf( _SC_PHYS_PAGES);
	double used_pages = total_pages - (double) sysconf( _SC_AVPHYS_PAGES);
	static Seg mem;
	sprintf(mem.value, "\ufb19%.1f%%%%",  (used_pages / total_pages) * 100.);
	return mem;
}
