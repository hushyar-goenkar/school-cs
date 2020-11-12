// Remove a given element (by value) from an array

#include <stdio.h>

void main() {
  int a[5], elem, i, loc;

  printf("Enter the array: \n");
  for (i = 0; i < 5; i++) scanf("%d", &a[i]);

  printf("Element?: ");
  scanf("%d", &elem);

  for (i = 0; i < 5; i++) {
    if (a[i] == elem) {
      loc = i;
      break;
    }
  }

  for (i = loc; i < 4; i++) {
    a[i] = a[i + 1];
  }

  a[4] = 0;
  printf("New Array: \n");

  printf("[");
  for (i = 0; i < 4; i++) printf("%d, ", a[i]);
  printf("] \n");
}