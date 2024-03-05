#include <stdio.h>

/* count tabs, new lines, and spaces in input */
int main() {
	int c, nl, tb, sp;

	nl = 0;
	tb = 0;
	sp = 0;
	while ((c = getchar()) != EOF)
		if (c == 10)
			++nl;
		else if (c == 9)
			++tb;
		else if (c == 32)
			++sp;
	printf("NL:%d TB:%d SP:%d\n", nl, tb, sp);
}
