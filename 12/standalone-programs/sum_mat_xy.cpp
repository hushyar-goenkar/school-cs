/**
 * Take an nxn square matrix
 * But only assign n - 1 elems in each row/col
 * The last elem is the sum of elems in that row/col
 * the (n,n) element is assigned 0
 * 
 * This is derivative of Sairaj's code zo have sarko kelo. Tane burso, wrong stylicho, error bharillo, code barayllo.
 * Have fix kelo.
 */

#include <iostream>
using namespace std;

#define m 5

class SumMate {
  int a[m][m];
  public:

    SumMate() {
      a[m - 1][m - 1] = 0; // The last elem has no use, it doesn't represent the sum of any row/col
      cout << "Matrix size " << m - 1 << "x" << m - 1 << endl;

      for (int i = 0; i < m - 1; i++) {
        cout << "Enter row " << i + 1 << ": ";
        for (int j = 0; j < m - 1; j++) {
          cin >> a[i][j];
        }
      }
    }

  /**
   * @param axis 'x' or 'y': The axis to sum.
   */
    void sumMate(char axis) {
      int sum;

      for (int i = 0; i < m - 1; i++) {
        sum = 0; // To find the next sum
        for (int j = 0; j < m - 1; j++) {
          if (axis == 'x') sum += a[i][j];
          else sum += a[j][i];
        }
        if (axis == 'x') a[i][m - 1] = sum; // Assign the last elem, the sum of the row
        else a[m - 1][i] = sum;
      }
    }

    void sum() {
      this->sumMate('x');
      this->sumMate('y');
    }

    void finalDisplay() {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
          cout << a[i][j] << "  ";
        }
        cout << endl;
      }
    }
};

int main() {
  SumMate S;
  S.sum();
  S.finalDisplay();
  return 0;
}
