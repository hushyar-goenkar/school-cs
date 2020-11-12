// Generates a reversed sierpinski triangle from a pascals triangle
// Algo Copyright Harsh Khandeparkar
#include <stdio.h>

char RED_FLASH[] = "\033[1;31;5m";
char GREEN_NO_UNDER[] = "\033[0;32m";
char NC[] = "\033[0m";

float fact(float x) {
  float i, prod = 1;
  for (i = 1; i <= x; i++) prod *= i;

  return prod;
}

float C(float n, float r) {
  return fact(n) / (fact(n - r) * fact(r));
}

void main() {
  float n, i, j, k;

  printf("size(n)?: ");
  scanf("%f", &n);

  for (i = n; i >= 0; i--) {
    for (j = 0; j <= i; j++) {
      int val = C(i, j);
      if ( val%2 != 0) /*printf(" ")*/ printf("%s*%s", GREEN_NO_UNDER, NC);
      else  /*printf(" ")*/ printf("%s*%s", RED_FLASH, NC);
      printf(" ");
    }
    printf("\n");
    for (k = 0; k < n - i + 1; k++) printf(" ");
  }
  printf("\n");
}