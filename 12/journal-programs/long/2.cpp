/**
 * STATEMENT: Write a C++ program to input two arrays A and B
 * of integers, both sorted in ascending order. Merge A and B to obtain a
 * third array C, such that C is also in ascending order. Output
 * all arrays A, B, and C.
 */

#include <iostream>
using namespace std;

class SortedMerge {
  private:
    int A[5], B[5], C[10];

  public:
    SortedMerge() {
      cout << "Enter array A(size 5): ";
      for (int  i = 0; i < 5; i++) cin >> A[i];

      cout << "Enter array B(size 5): ";
      for (int  i = 0; i < 5; i++) cin >> B[i];

      int iA = 0, iB = 0;

      for (int i = 0; i < 10; i++) {
        if (iA < 5 && iB < 5) {
          if (A[iA] < B[iB]) C[i] = A[iA++];
          else C[i] = B[iB++];
        }
        else if (iA < 5) C[i] = A[iA++];
        else if (iB < 5) C[i] = B[iB++];
      }

      cout << "Array A: ";
      for (int i = 0; i < 5; i++) cout << A[i] << " ";
      cout << endl;

      cout << "Array B: ";
      for (int i = 0; i < 5; i++) cout << B[i] << " ";
      cout << endl;

      cout << "Array C: ";
      for (int i = 0; i < 10; i++) cout << C[i] << " ";
      cout << endl;
    }
};

int main() {
  SortedMerge M;

  return 0;
}
