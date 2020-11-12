/** 2 1 3 4 7 ....
 * Just like Fibonacci but starts with 2, 1 instead of 1, 1
 */
#include <stdio.h>

void main() {
  int i, n, last = 1, last2 = 2, new;

  printf("Kitne nos chahiye(>=2)?: ");
  scanf("%d", &n);

  printf("\n2\n1\n");

  for (i = 0; i < n - 2; i++) {
    new = last + last2;

    last2 = last;
    last = new;

    printf("%d \n", new);
  }
}