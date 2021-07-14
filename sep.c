#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>

int getWidth(int len) {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w.ws_col / len;
}

void printSep(const char *symbol, int len) {
	for (int i = 0; i < getWidth(len); i++) {
		printf(symbol);
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	int len;
	if (argc > 1) {
		printSep(argv[1], strlen(argv[1]));
	}
	else {
		printSep("-", 1);
	}
	return 0;
}
