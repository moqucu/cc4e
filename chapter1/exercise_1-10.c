#include <stdio.h>

#define YES 1
#define NO  0

/* count lines, words, chars in input */
int main() {
    int c, nl, nw, nc, inword;

    inword = NO;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n' )
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t' ) {
            inword = NO;
			putchar('\n');        
        }
        else if ( inword == NO ) {
            inword = YES;
            ++nw;
            putchar(c);
        } else
        	putchar(c);
    }
    printf("\n%d %d %d\n", nl, nw, nc);
}
