#include <stdio.h>
#include <math.h>

void main() {
  int n, i;
  float reciprocal, sum = 0;

  printf("Enter the value of n: ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    reciprocal = (1.0 / (2*i - 1));
    sum += pow(reciprocal, 2);
  }

  printf("The sum is %f \n", sum);
}