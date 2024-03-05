#include <stdio.h>

int main() {
    int c;

	printf("Get ready!\n");
    while ((c = getchar()) != '\n')
        printf("%d ", c);
}