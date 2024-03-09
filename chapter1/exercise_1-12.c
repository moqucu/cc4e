#include <stdio.h>

#define YES 1
#define NO  0

/* count lines, words, chars in input */
int main() {
    int c, inword, wordLength, i, j;

    inword = NO;
    
	int wordHistogram[50];
	for (i = 0; i < 50; ++i)
		wordHistogram[i] = 0;
		
	wordLength = 0;
    
    /* Repeat until the end of file */
    while ((c = getchar()) != EOF)
	{
    	if (inword == NO && (c >= 65 && c <= 90 || c >= 97 && c <= 122))
    	{
    		inword = YES;
    		putchar(c);
    		++wordLength;
    	} 
    	else if (inword == YES && (c >= 48 && c <= 57 || c >= 65 && c <= 90 || c >= 96 && c <= 122))
    	{
    		putchar(c);
    		++wordLength;
    	}
    	else
    	{
    		inword = NO;
    		putchar('\n');
    		++wordHistogram[wordLength];
    		wordLength = 0;
    	}
    }
    
	for (i = 1; i < 50; ++i)
	{
		printf("%d: ", i);
		for (j = 0; j < wordHistogram[i]; ++j)
			printf("+");
		printf("\n");		
	}
}