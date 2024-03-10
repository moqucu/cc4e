#include <stdio.h>

#define THRESHOLD 35
#define MAXLINE 70 /* maximum input line size */

/* get line into s, return length */
int get_line(char charArray[], int charArraySize);

/* print lines over 35 characters */
int main()
{
	int len;
    char line[MAXLINE]; /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > THRESHOLD)
        	printf("%s", line);
}

int get_line(char charArray[], int charArraySize)
{
    int character, i, lineLength;
    
    i = 0;
    lineLength = 0;
    
    while ((character = getchar()) != EOF)
    {
    	/* reservere the last index for \0 */
    	if (i < charArraySize - 2)
    	{
    		charArray[i] = character;
    		++i;
    	}
    	++lineLength;
    	if (character == '\n')
    		break;
    }
    
    if (i > 0 && charArray[i - 1] != '\n')
    {
    	charArray[i] = '\n';
    	++i;
    }
    charArray[i] = '\0';
    
    return(lineLength);
}
