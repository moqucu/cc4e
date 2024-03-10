#include <stdio.h>

#define MAXLINE 70 /* maximum input line size */

/* get line into s, return length */
int get_line(char charArray[], int charArraySize);

/* copy s1 to s2; assume s2 big enough */
void copy(char s1[], char s2[]);


int main() /* find longest line */
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char save[MAXLINE]; /* longest line, saved */

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max)
        {
            max = len;
            copy(line, save);
        }
    
    /* there was a line */
    if (max > 0)
    {
		printf("Max line length = %d\n", max);
        printf("%s", save);
    }
}

int get_line(char charArray[], int charArraySize)
{
    int character, i, lineLength;
    
    i = 0;
    lineLength = 0;
    
    while ((character = getchar()) != EOF)
    {
    	/* reservere the last index for \0 */
    	if (i < charArraySize - 1)
    	{
    		charArray[i] = character;
    		++i;
    	}
    	++lineLength;
    	if (character == '\n')
    		break;
    }
    
    charArray[i] = '\0';
    return(lineLength);
}

void copy(char s1[], char s2[])
{
    int i;

    i = 0;
    while ((s2[i] = s1[i]) != '\0')
        ++i;
}