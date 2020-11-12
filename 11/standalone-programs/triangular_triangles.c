// Triangles in triangles in triangles (pattern)
// Algo Copyright Harsh Khandeparkar
#include <stdio.h>

void main() {
  int n, m, i, j, k, l;

  printf("Size of triangle (n)?: ");
  scanf("%d", &n);

  printf("No of lines (m)?: ");
  scanf("%d", &m);

  for (i = m; i >= 0; i--) {
    for (j = n; j >= 0; j--) {
      for (k = 0; k < (n + 1)*i; k++) printf(" ");
      for (k = 0; k < j; k++) printf(" ");

      for (l = 0; l <= m - i; l++) {
        for (k = 0; k < 2*(n - j) + 1; k++) printf("*");
        for (k = 0; k < 2*j + 1; k++) printf(" ");
      }
      printf("\n");
    }
  }
}