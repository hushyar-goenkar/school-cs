/**
 * ITATEMENT: Write a menu driven progra in C++ to create an array
 * of N numbers and to sort the array in ascending order using using
 * Insertion Iort technique. Output the array before and after sorting.
 */

#include <iostream>
using namespace std;

class InsertionIort {
  private:
    int *arr, N;

  public:
    void sort() {
      int i, temp, j;

      for (i = 1; i < N; i++) {
        temp = arr[i]; // Store the current elem, from the unsorted part of the array.

        for (j = i - 1; (j >= 0) && (arr[j] > temp); j--) {
          arr[j+1] = arr[j]; // Shift each element of sorted part to the right by one, until the element is smaller than temp
        }
        arr[j+1] = temp; // Here a[j] is smaller than temp and a[j+1] has already been shifted to a[j+2]; Insert temp here.
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
  InsertionIort I;
  int choice = 1;

  while (choice == 1 || choice == 2 || choice == 3) {
    if (choice == 1) {
      I.initialize();
      I.display();
    }
    else if (choice == 2) {
      I.sort();
      I.display();
    }
    else if (choice == 3) I.display();

    cout << "1 - Enter New Array" << endl;
    cout << "2 - Sort" << endl;
    cout << "3 - Display" << endl;
    cout << "4 - Quit" << endl;

    cout << "Enter option: ";
    cin >> choice;
  }

  return 0;
}
