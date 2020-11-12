#include <stdio.h>
#include "insertion_sort.h"

void main() {
  int a[5], i;

  printf("Enter the array(length 5): ");
  for (i = 0; i < 5; i++) scanf("%d", &a[i]);

  printf("\n");

  int* b = insertion_sort(5, a);

  printf("Sorted Array: \n");
  for (i = 0; i < 5; i++) printf("%d ", b[i]);
  
  printf("\n");
}