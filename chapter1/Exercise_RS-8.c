#include <stdio.h>
#include <stdlib.h>

int main() {
  	char buffer[1000];
  	int aGuessedNumber;
  	while(fgets(buffer, 1000, stdin) != NULL) {
      aGuessedNumber = atoi(buffer);
      if (aGuessedNumber == 42) {
        printf("Nice work!\n");
        break;
      }
      else if (aGuessedNumber < 42)
        printf("Too low - guess again\n");
      else
        printf("Too high - guess again\n");
    }
}
