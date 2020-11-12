#include <stdio.h>

void main() {
  int n, i, k = 0, sum = 0;

  printf("Enter the value of n: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    sum += k;
    k += 2;
  }

  printf("Sum is %d \n", sum);
}