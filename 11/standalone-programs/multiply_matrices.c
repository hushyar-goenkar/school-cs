// Multiply Two Matrices

#include <stdio.h>

void main() {
  int mat1[4][3], mat2[3][2], final[4][2], i, j, k, sum;

  printf("Enter The 1st Matrix(4 x 3) \n");
  for (i = 0; i < 4; i++) {
    printf("Row %d: ", i);
    for (j = 0; j < 3; j++) scanf("%d", &mat1[i][j]);
  }

  printf("\nEnter The 2nd Matrix(3 x 2)\n");
  for (i = 0; i < 3; i++) {
    printf("Row %d: ", i);
    for (j = 0; j < 2; j++) scanf("%d", &mat2[i][j]);
  }

  for (i = 0; i < 2; i ++) { // Columns of 2nd matrix
    for (j = 0; j < 4; j++) { // Rows of 1st matrix
      sum = 0;
      for (k = 0; k < 3; k++) { // Dot Product
        sum += mat1[j][k] * mat2[k][i];
      }

      final[j][i] = sum;
    }
  }

  printf("\nFinal Matrix:");
  for (i = 0; i < 4; i++) {
    printf("\nRow %d: ", i);
    for (j = 0; j < 2; j++) printf("%d ", final[i][j]);
  }
  
  printf("\n");
}