#include <stdio.h>
#include <stdlib.h>
#include "segments/constants.h"
#include "segments/user.h"
#include "segments/datetime.h"

int main(int argc, char **argv) {
	char *u = user();
	char *d = datetime();
	printf("%s %s\n", u, d);
	return 0;
}
