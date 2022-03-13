#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "segments/user.h"
#include "segments/datetime.h"
#include "segments/weather.h"

int main(int argc, char **argv) {
	char *u = user();
	char *d = datetime();
	char *w = weather();
	printf("%s %s %s\n", u, d, w);
	return 0;
}
