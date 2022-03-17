#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <errno.h>
#include <unistd.h>

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

enum Bar {TOP, BOTTOM};

static FILE *startbar(enum Bar bar) {
	int pipefd[2];
	if (pipe(pipefd) == -1) {
		perror("Failed to open pipe for bar.");
		return NULL;
	}

	pid_t pid = vfork();
	if (pid == -1) {
		perror("Failed to fork process for bar.");
		return NULL;
	} else if (pid) {
		// parent process
		close(pipefd[0]); // don't need to read from child
		return fdopen(pipefd[1], "w");
	} else {
		// child process
		close(pipefd[1]); // don't need to write to parent
		dup2(pipefd[0], STDIN_FILENO); // replace stdin with pipe

		if (bar == TOP)
			execlp("lemonbar", "lemonbar", "-a", "20", "-g", "+0+60", "-f", "CaskaydiaCove Nerd Font:size=15", "-B", "#161320", NULL);
		else if (bar == BOTTOM)
			execlp("lemonbar", "lemonbar", "-f", "CaskaydiaCove Nerd Font:size=15", "-B", "#161320", "-b", "-a", "20", NULL);
	}
}

int main(int argc, char **argv) {
	setlocale(LC_ALL, "en_US.UTF-8");

	NMClient *client = nm_client_new(NULL, NULL);
	if (client == NULL) {
		// This is unrecoverable
		fprintf(stderr, "Failed to create nm client.\n");
		return 1;
	}

	FILE *meminfo = fopen("/proc/meminfo", "r");
	setbuf(meminfo, NULL);
	FILE *topbar = startbar(TOP);
	//FILE *bottombar = startbar(BOTTOM);
	setlinebuf(topbar);
	//setlinebuf(bottombar);

	Seg u = user(); //not liable to change users while running
	while (1) {
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
