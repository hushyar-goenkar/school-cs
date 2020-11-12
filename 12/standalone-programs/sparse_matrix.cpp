/**
 * Sparse Matrix - Matrix with majority of elem 0
 */

#include <iostream>
using namespace std;

#define n 3
#define m 3

class Matrix {
  int mat[n][m];

  public:
    Matrix() {
      for (int i = 0; i < n; i ++) {
        cout << "Enter row " << i + 1 << " elems: ";
        for (int j = 0; j < m; j++) {
          cin >> mat[i][j];
        }
      }
    }

    bool isSparse() {
      int zeroCount = 0;

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (mat[i][j] == 0) zeroCount++;
          if (zeroCount > (n*m / 2)) return true;
        }
      }

      return false;
    }
};

int main () {
  Matrix m1;

  if (m1.isSparse()) cout << "Sparse";
  else cout << "Dense";
}