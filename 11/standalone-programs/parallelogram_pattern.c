/**
 * A vertical parallelogram pattern
 * Algo Copyright Harsh Khandeparkar
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void main() {
  int n , i, j, k;

  printf("No of lines?: ");
  scanf("%d", &n);

  for (i = 1; i <= 2*n - 1; i++) {
    for (j = 0; j < abs(n - i); j++) printf(" ");
    for (k = 0; k < n; k++) printf("*");
    for (j = 0; j < 2*(n - 1 - abs(n-i)); j++) printf(" ");
    for (k = 0; k < n; k++) printf("*");
    printf("\n");
  }
}