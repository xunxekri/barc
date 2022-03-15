#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
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
	setlocale(LC_ALL, "en_US.UTF-8");
	NMClient *client = nm_client_new(NULL, NULL);
	FILE *meminfo = fopen("/proc/meminfo", "r");
	setbuf(meminfo, NULL);
	FILE *topbar = popen("lemonbar -a 20 -g +0+60 -f \"CaskaydiaCove Nerd Font:size=15\" -B \"#161320\"", "w");
    //FILE *bottombar = popen("lemonbar -f \"CaskaydiaCove Nerd Font:size=15\" -B \"#161320\" -b -a 20", "w");
    setlinebuf(topbar);
    //setlinebuf(bottombar);

	while (1) {
		Seg u = user();
		Seg d = datetime();
		Seg w = weather();
		Seg m = memory(meminfo);
		Seg c = cpusage();
		Seg n = network(client);
		fprintf(topbar, "%s %s %s %s %s %s\n", u.value, d.value, w.value, m.value, c.value, n.value);
		usleep(100000);
	}

	// Dead code, but will run if an exit condition for the loop is created.
	//fclose(bottombar);
	fclose(topbar);
	fclose(meminfo);
	g_object_unref(client);

	return 0;
}
