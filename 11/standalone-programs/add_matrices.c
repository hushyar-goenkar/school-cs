// Add two matrices

#include <stdio.h>

void main() {
  int mat[5][5], i, j, temp;

  printf("Enter The 1st Matrix(5 x 5) \n");

  for (i = 0; i < 5; i++) {
    printf("Row %d: ", i);
    for (j = 0; j < 5; j++) scanf("%d", &mat[i][j]);
  }

  printf("\nEnter The 2nd Matrix(5 x 5)\n");
  for (i = 0; i < 5; i++) {
    printf("Row %d: ", i);
    for (j = 0; j < 5; j++) {
      scanf("%d", &temp);
      mat[i][j] += temp;
    }
  }

  printf("\nSum (5 x 5)");
  for (i = 0; i < 5; i++) {
    printf("\nRow %d: ", i);
    for (j = 0; j < 5; j++) printf("%d ", mat[i][j]);
  }
  printf("\n");
}