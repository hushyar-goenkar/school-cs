/**
 * Generates an array which is the sum of two arrays
*/ 
#include <stdio.h>

void main() {
  int a[5], b[5], c[5], i;

  printf("Array A:\n");
  printf("[");
  for (i = 0; i < 5; i++) {
    scanf("%d", &a[i]);
    if (i != 4) printf(", ");
  }
  printf("]\n");

  printf("Array B:\n");
  printf("[");
  for (i = 0; i < 5; i++) {
    scanf("%d", &b[i]);
    if (i != 4) printf(", ");
  }
  printf("]\n");

  for (i = 0; i < 5; i++) c[i] = a[i] + b[i];

  printf("Array C:\n");
  printf("[");
  for (i = 0; i < 5; i++) {
    printf("%d", c[i]);
    if (i != 4) printf(", ");
  }
  printf("]\n");
}