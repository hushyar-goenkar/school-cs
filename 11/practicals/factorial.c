// n! = n(n-1)(n-2)(n-3)...3x2x1
#include <stdio.h>

void main() {
  int n, fact = 1;
  char green[] = "\033[0;32;4m";
  char NC[] = "\033[0m";

  printf("Enter The Number: ");
  scanf("%d", &n);

  for (n; n > 0; n--) {
    fact *= n;
  }
  printf("Factorial is: %s%d%s \n", green, fact, NC);
}