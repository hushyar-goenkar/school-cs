/**
 * STATEMENT: Write a C++ program to transpose a m x n matrix of integers,
 * where m != n and output the original input matrix and its transpose.
 */

#include <iostream>
using namespace std;

class Transpose {
  public:
    Transpose() {
      int m, n;

      cout << "Enter m: ";
      cin >> m;

      cout << "Enter n: ";
      cin >> n;

      float mat[m][n], transpose[n][m];

      for (int i = 0; i < m; i++) {
        cout << "Enter row " << i + 1 << ": ";
        for (int j = 0; j < n; j++) cin >> mat[i][j];
      }

      cout << "Input Matrix:" << endl;
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          transpose[j][i] = mat[i][j];
          cout << mat[i][j] << " ";
        }
        cout << endl;
      }

      cout << "Transpose:" << endl;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << transpose[i][j] << " ";
        }
        cout << endl;
      }
    }
};

int main() {
  Transpose T;

  return 0;
}
