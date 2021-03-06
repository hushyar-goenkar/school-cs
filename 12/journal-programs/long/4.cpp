/**
 * STATEMENT: Write a menu driven progra in C++ to create an array
 * of N numbers and to sort the array in ascending order using using
 * Bubble Sort technique. Output the array before and after sorting.
 */

#include <iostream>
using namespace std;

class BubbleSort {
  private:
    int *arr, N;

  public:
    void sort() {
      int i, temp, j;

      for (i = 0; i < N; i++) {
        for (j = 0; j < N - 1; j++) {
          if (arr[j] > arr[j+1]) {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
          }
        }
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
  BubbleSort B;
  int choice = 1;

  while (choice == 1 || choice == 2 || choice == 3) {
    if (choice == 1) {
      B.initialize();
      B.display();
    }
    else if (choice == 2) {
      B.sort();
      B.display();
    }
    else if (choice == 3) B.display();

    cout << "1 - Enter New Array" << endl;
    cout << "2 - Sort" << endl;
    cout << "3 - Display" << endl;
    cout << "4 - Quit" << endl;

    cout << "Enter option: ";
    cin >> choice;
  }

  return 0;
}
