/**
 * STATEMENT: Write a menu driven program in C++ to create an array of N integers
 * sorted in ascending order and to search for a given value in the array
 * using Binary Search algorithm.
 */

#include <iostream>
#include <math.h>
using namespace std;

class BinarySearch {
  private:
    int *arr, N;

  public:
    void initialize() {
      cout << "Enter size of array: ";
      cin >> N;

      arr = new int(N);

      cout << "Enter sorted array only." << endl;

      for (int i = 0; i < N; i++) {
        cout << "Enter " << i << "th element: ";
        cin >> arr[i];
      }

      cout << "Array: ";
      for (int i = 0; i < N; i++) cout << arr[i] << " ";
      cout << endl;
    }

    void searchElem() {
      int elem;

      cout << "Enter element to be searched: ";
      cin >> elem;

      int foundAt = search(0, N - 1, elem);
      if (foundAt == -1) cout << "Not found." << endl;
      else cout << "Fount at index: " << foundAt << endl;
    }

  private:
    int search(int from, int to, int what) {
      int middle = floor((from + to) / 2);

      if (arr[middle] == what) return middle;
      else if (from == to) return -1;
      else if (arr[middle] > what) return search(from, middle, what);
      else if (arr[middle] < what) return search(middle + 1, to, what);
      else return -1;
    }
};

int main() {
  BinarySearch B;
  int choice = 1;

  while (choice == 1 || choice == 2) {
    if (choice == 1) B.initialize();
    else if (choice == 2) B.searchElem();

    cout << "1 - Enter New Array" << endl;
    cout << "2 - Search Element" << endl;
    cout << "3 - Quit" << endl;

    cout << "Enter option: ";
    cin >> choice;
  }

  return 0;
}
