#include <stdio.h>

/* raise x to n-th power; n > 0 */
int lower(int c);

int main()
{
	int ch;
    while ((ch = getchar()) != EOF)
    	putchar(lower(ch));
	printf("\n");
}

int lower(int c)
{
	int cl = c;
	if (cl >= 'A' && cl <= 'Z')
		cl = cl + 32;
    
    return (cl);
}