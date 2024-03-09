#include <stdio.h>

#define YES 1
#define NO  0

/* count lines, words, chars in input */
int main() {
    int c, inword;

    inword = NO;
    
    /* Repeat until the end of file */
    while ((c = getchar()) != EOF) {
    	if (inword == NO && (c >= 65 && c <= 90 || c >= 97 && c <= 122)) {
    		inword = YES;
    		putchar(c);
    	} 
    	else if (inword == YES && (c >= 48 && c <= 57 || c >= 65 && c <= 90 || c >= 96 && c <= 122)) {
    		putchar(c);
    	}
    	else {
    		inword = NO;
    		putchar('\n');
    	}
    }
}
