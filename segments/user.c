#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../constants.h"
#include "seg.h"

Seg user() {
	char *username = getenv("LOGNAME");
	char hostname[MAX_LENGTH];
	gethostname(hostname, MAX_LENGTH);
	Seg user;
	user.color = BLUE;
	sprintf(user.value, "%s@%s", username, hostname);
	return user;
}
