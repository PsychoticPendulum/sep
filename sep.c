// |-------------------------------------------------------------------------|
// |  ____                 _     _      ____                        _        |
// | |  _ \ ___ _   _  ___| |__ (_) ___|  _ \ ___ _ __   __ _ _   _(_)_ __   |
// | | |_) / __| | | |/ __| '_ \| |/ __| |_) / _ \ '_ \ / _` | | | | | '_ \  |
// | |  __/\__ \ |_| | (__| | | | | (__|  __/  __/ | | | (_| | |_| | | | | | |
// | |_|   |___/\__, |\___|_| |_|_|\___|_|   \___|_| |_|\__, |\__,_|_|_| |_| |
// |           |___/                                   |___/                 |
// |-------------------------------------------------------------------------| 

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>

int getWidth(int len) {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w.ws_col / len;
}

void printSep(int len, int lines, const char *symbol) {
	for (int i = 0; i < getWidth(len) * lines; i++) {
		printf(symbol);
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	int option;
	char *symbol = "+";
	int lines = 1;

	while ((option = getopt(argc, argv, "l:s:")) != -1) {
		switch (option) {
			case 'l':
				lines = atoi(optarg);
				break;
			case 's':
				symbol = optarg;
				break;
		}
	}
	
	printSep(strlen(symbol), lines, symbol);
	return 0;
}

