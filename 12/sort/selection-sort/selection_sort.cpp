#include <iostream>
#include "selection_sort.hpp"

using namespace std;

int main() {
  float a[5];
  int i;

  cout << "Enter the array(length 5): ";
  for (i = 0; i < 5; i++) cin >> a[i];

  float* b = selection_sort(5, a);

  cout << "Sorted Array: ";
  for (i = 0; i < 5; i++) cout << b[i] << " ";

  printf("\n");

  return 0;
}
