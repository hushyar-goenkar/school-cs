/**
 * STATEMENT: Write a menu driven progra in C++ to create an array
 * of N numbers and to sort the array in ascending order using using
 * Selection Sort technique. Output the array before and after sorting.
 */

#include <iostream>
using namespace std;

class SelectionSort {
  private:
    int *arr, N;

  public:
    void sort() {
      int i, j, max;

      for (i = N - 1; i >= 0; i--) {
        max = 0;
        for (j = 0; j <= i; j++) {
          if (arr[j] > arr[max]) max = j;
        }
        j = arr[i]; // j used as a temporary variable
        arr[i] = arr[max];
        arr[max] = j;
      }
    }

    void display() {
      cout << "Array: ";
      for (int i = 0; i < N; i++) cout << arr[i] << " ";
      cout << endl;
    }

    void initialize() {
      cout << "Enter size of array: ";
      cin >> N;

      arr = new int(N);

      for (int i = 0; i < N; i++) {
        cout << "Enter " << i << "th element: ";
        cin >> arr[i];
      }
    }
};

int main() {
  SelectionSort S;
  int choice = 1;

  while (choice == 1 || choice == 2 || choice == 3) {
    if (choice == 1) {
      S.initialize();
      S.display();
    }
    else if (choice == 2) {
      S.sort();
      S.display();
    }
    else if (choice == 3) S.display();

    cout << "1 - Enter New Array" << endl;
    cout << "2 - Sort" << endl;
    cout << "3 - Display" << endl;
    cout << "4 - Quit" << endl;

    cout << "Enter option: ";
    cin >> choice;
  }

  return 0;
}
