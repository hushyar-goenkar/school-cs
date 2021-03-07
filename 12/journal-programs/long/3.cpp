/**
 * STATEMENT: Write a C++ program to input two matrices having integer
 * elements  - M1 of order mxn and M2 of order nxp and obtain the
 * product matrix P. Output all the three matrices M1, M2, and P.
 */

#include <iostream>
using namespace std;

class MatrixMultiplication {
  private:
    int m, n, p;
    int **M1;
    int **M2;
    int **P;

    void getMatrices() {
      cout << "Enter matrix M1(" << m << "x" << n << ")" << endl;
      for (int i = 0; i < m; i++) {
        cout << "Enter row " << i + 1 << ": ";
        for (int j = 0; j < n; j++) cin >> M1[i][j];
      }

      cout << "Enter matrix M2(" << n << "x" << p << ")" << endl;
      for (int i = 0; i < n; i++) {
        cout << "Enter row " << i + 1 << ": ";
        for (int j = 0; j < p; j++) cin >> M2[i][j];
      }
    }

    void multiplyMatrices() {
      int sum;

      for (int i = 0; i < p; i ++) { // Columns of 2nd matrix
        for (int j = 0; j < m; j++) { // Rows of 1st matrix
          sum = 0;
          for (int k = 0; k < n; k++) { // Dot Product
            sum += M1[j][k] * M2[k][i];
          }

          P[j][i] = sum;
        }
      }
    }

    void printMatrices() {
      cout << endl << "Matrix M1: " << endl;
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cout << M1[i][j] << " ";
        cout << endl;
      }

      cout << endl << "Matrix M2: " << endl;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) cout << M2[i][j] << " ";
        cout << endl;
      }

      cout << endl << "Matrix P(M1xM2): " << endl;
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) cout << P[i][j] << " ";
        cout << endl;
      }
    }

  public:
    MatrixMultiplication() {
      cout << "Enter m: ";
      cin >> m;

      cout << "Enter n: ";
      cin >> n;

      cout << "Enter p: ";
      cin >> p;

      M1 = new int*[m];
      M2 = new int*[n];
      P = new int*[m];

      for(int j = 0; j < m; j++) M1[j] = new int[n];
      for(int j = 0; j < n; j++) M2[j] = new int[p];
      for(int j = 0; j < m; j++) P[j] = new int[p];

      getMatrices();
      multiplyMatrices();
      printMatrices();
    }
};

int main() {
  MatrixMultiplication M;

  return 0;
}
