#include <stdio.h>

void main() {
  int n, rev = 0;

  printf("Enter the number: ");
  scanf("%d", &n);

  do  {
    rev *= 10;
    rev += n % 10;
    n /= 10;
  }
  while (n > 0);

  printf("Reverse is: %d \n", rev);
}