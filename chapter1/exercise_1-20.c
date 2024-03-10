#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

/* get line into s, return length */
int get_line(char charArray[], int charArraySize);

/* replaces tabs in the input with the proper number of blanks */
int detab(char sourceArray[], char targetArray[], int charArraySize , int spacesPerTab);

/* replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing */
int entab(char sourceArray[], char targetArray[], int charArraySize , int spacesPerTab);

/* print lines over 35 characters */
int main()
{
	int len;
    char line[MAXLINE]; /* current input line */
    char entabbedLine[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0)
    {
    	entab(line, entabbedLine, MAXLINE, 4);
    	printf("%s", entabbedLine);
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

int detab(char sourceArray[], char targetArray[], int charArraySize , int spacesPerTab)
{
	int oldIndex;
	int detabs = 0;
	int newIndex = 0;
	int i;
	
	for (oldIndex = 0; oldIndex < charArraySize; ++oldIndex)
	{
		if (sourceArray[oldIndex] == '\t')
		{
			for (i = 0; i < 4; ++i)
			{
				targetArray[newIndex] = ' ';
				++newIndex;
			}
			++detabs;
		}
		else
		{
			targetArray[newIndex] = sourceArray[oldIndex];
			++newIndex;
		}
		
		if (sourceArray[oldIndex] == '\0')
		{
			break;
		}
	}
	
	return(detabs);
}

int entab(char sourceArray[], char targetArray[], int charArraySize, int spacesPerTab)
{
	int oldIndex;
	int entabs = 0;
	int newIndex = 0;
	int i;
	int consecutiveSpaceCounter = 0;
	
	for (oldIndex = 0; oldIndex < charArraySize; ++oldIndex)
	{
		if (sourceArray[oldIndex] == ' ')
		{
			
			for (i = 0; i < 4 && oldIndex + i < charArraySize && sourceArray[oldIndex + i] != '\0'; ++i)
			{
				if (sourceArray[oldIndex + i] == ' ')
				{
					++consecutiveSpaceCounter;
				}
			}
			if (consecutiveSpaceCounter == 4)
			{
				targetArray[newIndex] = '\t';
				++newIndex;
				oldIndex = oldIndex + 3;
				++entabs;
			}
			else
			{
				targetArray[newIndex] = sourceArray[oldIndex];
				++newIndex;
			}
			consecutiveSpaceCounter = 0;
		}
		else
		{
			targetArray[newIndex] = sourceArray[oldIndex];
			++newIndex;
		}
		
		if (sourceArray[oldIndex] == '\0')
		{
			break;
		}
	}
	
	return(entabs);
}

