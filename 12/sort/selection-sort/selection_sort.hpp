/**
 * Selection Sort
 * Select the largest elem in the array and swap it with the last elem in the array at every pass
 * In the next pass, n - 1 elements can be checked and swap the biggest elem with the
 * 2nd last elem in the array
 * continue
 * n - 1 passes in the worst case
 *
 * You can also put the smallest element at the first position
 *
 * Time complexity:
 * Worst case - O(n^2)
 */

float* selection_sort(int n, float a[]) {
  int i, j, max;

  for (i = n - 1; i >= 0; i--) {
    max = 0;
    for (j = 0; j <= i; j++) {
      if (a[j] > a[max]) max = j;
    }
    j = a[i]; // j used as a temporary variable
    a[i] = a[max];
    a[max] = j;
  }

  return a;
}
