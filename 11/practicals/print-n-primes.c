// Prongram to print first n primes

#include <stdio.h>

void main() {
  int n, i, p = 1, j;
  _Bool isPrime;

  printf("How Many?: ");
  scanf("%d", &n);

  printf("2 ");

  i = 3;

  while(p < n) {
    isPrime = 1;
    for (j = 2; j < i/2; j++) {
      if (i%j == 0) {
        isPrime = 0;
        break;
      }
    }

    if (isPrime) {
      printf("%d ", i);
      p++;
    }
    i++;
  }

  printf("\n");
}