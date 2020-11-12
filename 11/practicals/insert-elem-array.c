// Insert a given element at a given position in an Array

#include <stdio.h>

void main() {
  int a[10], elem, i, j;

  printf("Enter the array: \n");

  for (i = 0; i < 5; i++) {
    scanf("%d", &a[i]);
  }

  printf("Which Location?: ");
  scanf("%d", &i);

  printf("Which Element?: ");
  scanf("%d", &elem);

  for (j = 5; j > i; j--) a[j] = a[j - 1];
  a[i] = elem;

  printf("New Array: \n");

  printf("[");
  for (i = 0; i < 6; i++) printf("%d, ", a[i]);
  printf("]");

  printf("\n");
}