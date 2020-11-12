// From model-paper.pdf

#include <iostream>
using namespace std;

/**
 * Given two arrays of integers of sizes M and N respectively. Write a function named
 * MIX() which will produce a third array named C such that the resulting sequence is
 * followed
 * 1) All even numbers of A from left to right are copied into C from left to right.
 * 2) All odd numbers of A from left to right are copied into C from right to left.
 * 3) All even numbers of B from left to right are copied into C from left to right
 * 4) All odd numbers of B from left to right are copied into C from right to left
 * A , B and C are passed as arguments to MIX()
 * Eg:-If A ={ 3, 2 ,1 , 7, 6, 3} and B = { 9, 3, 5, 6, 2, 8, 10}
 * The resultant array C should be { 2, 6 , 6, 2, 8 , 10, 5, 3, 9 , 3, 7 , 1, 3}
 */


/**
 * @param a First array
 * @param m Size of first array
 * @param b Second array
 * @param n Size of second array
 * @param c Final array
 */
int* mix(int a[], int m, int b[], int n, int c[]) {
  /**
   * IMPLEMENTATION:
   * A variable i which stores the first empty position in the array, from the left.
   * Two for loops, to iterate over each array.
   *
   * Iterate over first array a:
   * 1) If the jth element is even, add it to the beginning of the final array. Increment i.
   * 2) If the jth element is odd, add it to the end of the final array. DO NOT increment i.
   *
   * Iterate over second array b:
   * 1) If the jth element is even, add it to the ith position ie from the beginning. Increment i.
   * 2) If the jth element is odd, calculate the first empty position from the end of the array
   *    using i, j and "maths". DO NOT increment i.
   *
   * Done.
   *
   * COPYRIGHT: © Harsh K
   */

  int i = 0; // Position of the first empty element from the left of the array.

  for (int j = 0; j < m; j++) {
    if (a[j] % 2 == 0) c[i++] = a[j];
    else c[n + m - 1 - j + i] = a[j];
  }

  for (int j = 0; j < n; j++) {
    if (b[j] % 2 == 0) c[i++] = b[j];
    else c[n - 1 + i - j] = b[j];
  }

  return c;
}

int main() {
  int m = 6;
  int A[m] = {3, 2, 1, 7, 6, 3};

  int n = 7;
  int B[n] = {9, 3, 5, 6, 2, 8, 10};

  int C[m + n];

  int* d = mix(A, m, B, n, C);

  for (int i = 0; i < m + n; i++) {
    cout << d[i] << " ";
  }

  cout << endl;

  return 0;
}
