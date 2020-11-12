// Program to find whether a number is prime

#include <stdio.h>

int main() {
  int n, i;
  _Bool isPrime = 1; // Flag

  printf("Number?: ");
  scanf("%d", &n);

  if (n == 1) {
    printf("FYI, 1 is neither prime nor composite.");
    return 0;
  }

  if (n%2 == 0) isPrime = 0;
  i = 3;

  while(isPrime && i < n/2) {
    if (n%i == 0) isPrime = 0;
    i += 2;
  }

  if (isPrime) printf("Number is Prime. \n");
  else printf("Number is Composite. \n");
  return 0;
}