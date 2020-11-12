#include "bubble_sort.hpp" // Explanation in the header file.
#include <iostream>

using namespace std;

int main() {
  int a[5], i;

  cout << "Enter the array(length 5): ";
  for (i = 0; i < 5; i++) cin >> a[i];

  int* b = bubble_sort(5, a);

  cout << "Sorted Array: ";
  for (i = 0; i < 5; i++) cout << b[i] << " ";

  cout << endl;
  return 0;
}
