#include <stdio.h>

void main() {
  int i, n, last = 1, last2 = 0, new = 1;

  printf("How many numbers?: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("%d \n", new);
    new = last + last2;

    last2 = last;
    last = new;

  }
}