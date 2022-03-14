#include <unistd.h>
#include <stdio.h>
#include "../constants.h"
#include "seg.h"

Seg user() {
	char *username = getlogin();
	char hostname[MAX_LENGTH];
	gethostname(hostname, MAX_LENGTH);
	static Seg user;
	user.color = BLUE;
	sprintf(user.value, "%s@%s", username, hostname);
	return user;
}
