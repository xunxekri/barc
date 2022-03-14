#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "segments/seg.h"
#include "segments/user.h"
#include "segments/datetime.h"
#include "segments/weather.h"
#include "segments/memory.h"
#include "segments/cpusage.h"

int main(int argc, char **argv) {
	Seg u = user();
	Seg d = datetime();
	Seg w = weather();
	Seg m = memory();
	Seg c = cpusage();
	printf("%s %s %s %s %s\n", u.value, d.value, w.value, m.value, c.value);
	return 0;
}
