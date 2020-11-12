// Armstrong NO - sum of cubes of digits is equal to the number
#include <stdio.h>
#include <math.h>

void main() {
  int n, armstrong = 0, temp;

  printf("Enter the number: ");
  scanf("%d", &n);

  temp = n;
  while(temp > 0) {
    armstrong += pow(temp % 10, 3);
    temp /= 10;
  }

  if (armstrong == n) printf("One small step for man, one giant leap for humanity \n");
  else printf("Not an armstrong no \n");
}