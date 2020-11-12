#include <iostream>
#include "insertion_sort.hpp"

using namespace std;

int main() {
  int a[5], i;

  cout << "Enter the array(length 5): ";
  for (i = 0; i < 5; i++) cin >> a[i];

  int* b = insertion_sort(5, a);

  cout << "Sorted Array: ";
  for (i = 0; i < 5; i++) cout << b[i] << " ";

  printf("\n");

  return 0;
}
