// total no of odd nos and even nos in a matrix
#include <stdio.h>

char GREEN_NO_FLASH[] = "\033[0;32m";
char RED_NO_FLASH[] = "\033[1;31m";
char NC[] = "\033[0m";

void main() {
  int a[5][5], i, j, even, odd;

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      int input;
      scanf("%d", &a[j][i]);
    }
    printf("\n");
  }
  printf("\n");

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      if (a[j][i]%2 == 0) printf("%s%d%s ", GREEN_NO_FLASH, a[j][i], NC);
      else printf("%s%d%s", RED_NO_FLASH, a[j][i], NC);
    }
    printf("\n");
  }
}