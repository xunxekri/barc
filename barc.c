#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <NetworkManager.h>
#include "constants.h"
#include "segments/seg.h"
#include "segments/user.h"
#include "segments/datetime.h"
#include "segments/weather.h"
#include "segments/memory.h"
#include "segments/cpusage.h"
#include "segments/network.h"

int main(int argc, char **argv) {
	NMClient *client = nm_client_new(NULL, NULL);
	Seg u = user();
	Seg d = datetime();
	Seg w = weather();
	Seg m = memory();
	Seg c = cpusage();
	Seg n = network(client);
	printf("%s\n%s\n%s\n%s\n%s\n%s\n", u.value, d.value, w.value, m.value, c.value, n.value);
	return 0;
}
