// BUBBLE SORT
// Multiple Iterations
// Each iteration, Compare two consecutive locations at a time
// Bigger Number of the two is pushed ahead.

// Example:
// NOTE: ~ = last compare
//       _ = current compare
/**
 * [8, 3, 5, 3, 6]
 * I1: [~3, _8, 5, 3, 6] -> [3, ~5, _8, 3, 6] -> [3, 5, ~3, _8, 6] -> [3, 5, 3, ~6, 8]
 * I2: [~3, _5, 3, 6, 8] -> [3, ~3, _5, 6, 8] -> [3, 3, ~5, _6, 8] -> [3, 3, 5, ~6, 8]
 * This example required 2 iterations but max possible iterations is no of elements in the array - 1. Therefore, always iterate
 * those many times
 * Every iteration/pass, the biggest element bubbles to the end of the array
 *
 * Time complexity:
 * Worst case - O(n^2)
 */


int* bubble_sort(int n, int a[]) {
  int i, temp, j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n - 1; j++) {
      if (a[j] > a[j+1]) {
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }

  return a;
}
