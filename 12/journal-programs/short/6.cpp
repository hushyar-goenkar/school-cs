/**
 * STATEMENT: Write a C++ program to create an array of maximum size
 * 10 and storing integer values. Input N(N<=10) numbers into the array.
 * Process the array to find out the largest and the smallest numbers from
 * the array as well as all the values in the array.
 */

#include <iostream>
using namespace std;

class ArrayMinMax {
  public:
    ArrayMinMax() {
      int arr[10], N, min, max;

      cout << "Enter N(<=10): ";
      cin >> N;

      cout << "Enter N values: ";
      for (int i = 0; i < N; i++) cin >> arr[i];

      min = arr[0];
      max = arr[0];

      for (int i = 0; i < N; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
      }

      cout << "Array: ";
      for (int i = 0; i < N; i++) cout << arr[i] << " ";
      cout << endl;

      cout << "Min: " << min << endl;
      cout << "Max: " << max << endl;
    }
};

int main() {
  ArrayMinMax A;

  return 0;
}
