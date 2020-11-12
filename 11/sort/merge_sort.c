#include <stdio.h>
#include "merge_sort.h" // Explanation in header file

void main() {
  int a[7] = {2, 5, 1, 34, 41 ,1 , 12},
    b[7],
    i;

  merge_sort(a, 0, 7, b);

  for(i = 0; i < 7; i++) {
    printf("%d ", b[i]);
  }
}