#include <stdio.h>

/* raise x to n-th power; n > 0 */
int power(int x, int n);

int main() /* test power function */
{
    int i;

    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2,i), power(-3,i));
}

int power(int x, int n) /* raise x to n-th power; n > 0 */
{
    int i,p;

    for (p = 1; n > 0; --n)
        p = p * x;
    return (p);
}