#include <stdio.h>

/* a program to copy its input to its output, replacing each string of one or more blanks by a single blank */
int main() {
	int c, isWhiteSpace;

	isWhiteSpace = 0;
	while                     ((c = getchar()) != EOF)
		if (c != 32) {
			putchar(c);
			isWhiteSpace = 0;
		}
		else if (c == 32 && isWhiteSpace == 0) {
			putchar(c);
			isWhiteSpace = 1;
		}
}
