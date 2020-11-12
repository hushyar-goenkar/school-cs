// Converted from dynamic_mem.docx

#include <iostream>
#include <string.h>

using namespace std;

#define m 3
#define n 3

// Non Dynamic
class Matrix {
  private:
    int a[m + 1][n + 1];

  public:
    Matrix() {
      cout << "Enter " << n << "x" << m << "matrix:" << endl;
      for (int i = 0; i < n; i++) {
        cout << "Row " << i << ": ";
        for (int j = 0; j < m; j++)  cin >> a[i][j];
      }
    }

    Matrix add() {
      for(int i = 0; i < m; i++) {
        a[i][m] = 0;

        for(int j = 0; j < n; j++) {
          a[i][m] += a[i][j];
        }
      }
      for(int i = 0; i < m; i++) {
        a[m][i] = 0;

        for(int j = 0; j < n; j++) {
          a[m][i] += a[j][i];
        }
      }

      return *this;
    }

    Matrix display() {
      for (int i = 0; i < m + 1; i++) {
        cout << "| ";

        for (int j = 0; j < n; j++) cout << a[i][j] << " ";

        cout << "|" << endl;
      }

      return *this;
    }
};

int main() {
  Matrix M;

  M.add().display();

  return 0;
}
