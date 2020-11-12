// Return the transpose of a (square) matrix and check whether it is
// symmetric or not. (Has to be square to check symmetricity)

#include <stdio.h>

void main() {
  int mat[5][5], transpose[5][5], i, j;
  _Bool isSymmetric = 1;

  printf("Enter The Matrix(5 x 5) \n");
  for (i = 0; i < 5; i++) {
    printf("Row %d: ", i);
    for (j = 0; j < 5; j++) scanf("%d", &mat[i][j]);
  }

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++){
      transpose[j][i] = mat[i][j];
    }
  }

  for (i = 0; i < 5; i++) {
    if(!isSymmetric) break;
    for (j = 0; j < 5; j++) {
      if (mat[i][j] != transpose[i][j]) isSymmetric = 0;
      if (!isSymmetric) break;
    }
  }

  printf("\nTranspose of the Matrix:");
  for (i = 0; i < 5; i++) {
    printf("\nRow %d: ", i);
    for (j = 0; j < 5; j++) printf("%d ", transpose[i][j]);
  }

  if (isSymmetric) printf("\n\nMatrix is symmetric.\n");
  else printf("\n\nMatrix is not symmetric.\n");
}