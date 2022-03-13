#include <unistd.h>
#include <stdio.h>
#include "../constants.h"

char *user() {
	char *username = getlogin();
	static char hostname[MAX_LENGTH];
	gethostname(hostname, MAX_LENGTH);
	static char ret[MAX_LENGTH * 2 + 1];
	sprintf(ret, "%s@%s", username, hostname);
	return ret;
}
