/**
 * Input: Array A
 * Create Array B such that odd first, even last
 **/
#include <stdio.h>
void main() {
  int a[5], b[5], i, k;

  printf("Array A:\n");
  printf("[");
  for (i = 0; i < 5; i++) {
    scanf("%d", &a[i]);
    if (i != 4) printf(", ");
  }
  printf("]\n");

  k = 0;
  for (i = 0; i < 5; i++) {
    if (a[i]%2 != 0) {
      b[k] = a[i];
      k++;
    }
  }

  for (i = 0; i < 5; i++) {
    if (a[i]%2 == 0) {
      b[k] = a[i];
      k++;
    }
  }

  printf("Array B:\n");
  printf("[");
  for (i = 0; i < 5; i++) {
    printf("%d", b[i]);
    if (i != 4) printf(", ");
  }
  printf("]\n");
}