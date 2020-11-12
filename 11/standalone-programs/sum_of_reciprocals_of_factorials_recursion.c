// sum of (1/1!) + (1/2!) + (1/3!) ....
#include <stdio.h>
#include "factorial.h"

float factRecip(int no) {
  return 1.0 / factorial(no);
}

float sumRecips(float sum, int n) {
  if (n == 1) sum += factRecip(n);
  else sum += sumRecips(sum, n - 1) + factRecip(n);

  return sum;
}

void main() {
  int n;
  float sum = 0;

  printf("no of terms?: ");
  scanf("%d", &n);

  printf("%f\n", sumRecips(sum, n));
}