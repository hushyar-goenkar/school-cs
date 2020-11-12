/**
 * BINARY SEARCH: Same as a dictionary. Take a sorted array as the input.
 * Start from the midpoint of the array, if the mid value is more than the element to be searched, consider the lower half
 * Otherwise, consider the upper half of the array.
 * Recursively do the same for the other half
 */

#include <iostream>
#include <math.h>
#include "../util/COLORS!.hpp"
#include "../sort/selection-sort/selection_sort.hpp"

using namespace std;

#define size 20

// Board format
class BinarySearch {
  float arr[size];

  public:
    BinarySearch() {
      for (int i = 0; i < size; i++) {
        cout << "Enter " << i << "th element: " << ORANGE_NO_UNDER;
        cin >> arr[i];
        cout << NC;
      }

      float* sorted = selection_sort(20, arr);

      for (int i = 0; i < size; i++) arr[i] = sorted[i];

      cout << "Final Sorted Array: " << ORANGE_NO_UNDER;
      for (int i = 0; i < size; i++) cout << arr[i]<< " ";
      cout << NC << endl;

      float elem;
      cout << "Enter the element to be searched: " << ORANGE_NO_UNDER;
      cin >> elem;
      cout << NC;

      cout << "Found at: " << ORANGE_UNDER << search(0, size - 1, elem) << NC << endl;
    }

  private:
    int search(int from, int to, float what) {
      int middle = floor((from + to) / 2);

      if (arr[middle] == what) return middle;
      else if (from == to) return -1;
      else if (arr[middle] > what) return search(from, middle, what);
      else if (arr[middle] < what) return search(middle + 1, to, what);
      else return -1;
    }
};

int main() {
  BinarySearch b;

  return 0;
}
