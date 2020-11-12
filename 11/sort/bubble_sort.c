#include "bubble_sort.h" // Explanation in the header file.
#include <stdio.h>

void main() {
  int a[5], i;

  printf("Enter the array(length 5): ");
  for (i = 0; i < 5; i++) scanf("%d", &a[i]);

  printf("\n");

  int* b = bubble_sort(5, a);

  printf("Sorted Array: \n");
  for (i = 0; i < 5; i++) printf("%d ", b[i]);
  
  printf("\n");
}