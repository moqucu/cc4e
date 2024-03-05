#include <stdio.h>

/* a program to replace each tab by the three-character sequence >, backspace, -, which prints as >, and each backspace by the similar sequence < */
int main() {
	int c;

	while ((c = getchar()) != EOF) {
		if (c == 8)
			putchar('<');
		else if (c == 9)
			putchar('>');
		else
			putchar(c);
	}
}
