// COLORSSSSSS!!!!
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./COLORS!.h"

void printRandomStar() {
  int color = random();

  switch(color%6) {
    case 0:
      printf("%s*%s", GREEN_FLASH, NC);
    case 1:
      printf("%s*%s", RED_FLASH, NC);
    case 2:
      printf("%s*%s", ORANGE_FLASH, NC);
    case 3:
      printf("%s*%s", GREEN_NO_FLASH, NC);
    case 4:
      printf("%s*%s", RED_NO_FLASH, NC);
    case 5:
      printf("%s*%s", ORANGE_NO_FLASH, NC);
  }
}

void main() {
  int i, j, n = 50;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; i++) {
      printRandomStar();
    }
    printf("\n");
  }
}