#include <iostream>
#include "merge_sort.hpp" // Explanation in header file
using namespace std;

int main() {
  int a[5], i;
  int b[5];

  cout << "Enter the array(length 5): ";
  for (i = 0; i < 5; i++) cin >> a[i];

  merge_sort(a, 0, 5, b);

  cout << "Sorted Array: ";
  for (i = 0; i < 5; i++) cout << b[i] << " ";

  printf("\n");

  return 0;
}
