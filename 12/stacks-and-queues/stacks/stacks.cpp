// Converted from stack.txt

/**
 * STACKS: (abstract data type)
 * Take a stack of books
 * Limit on the number of books is the ceiling
 * push - Add a book to the top
 * Can push until it hits the ceiling
 *
 * pop - Take away the topmost book.
 */

#include <iostream>
#include "../../util/COLORS!.hpp"
using namespace std;

#define size 10
class Stack {
  int arr[size], top;

  public:
    Stack() {
      top = -1;
    }

    Stack push(int x) {
      if (top == size - 1) cout << RED_FLASH << "Stack is full." << NC << endl;
      else arr[++top] = x;

      cout << GREEN_NO_FLASH << "Pushed " << ORANGE_NO_FLASH << x << NC << endl;

      return *this;
    }

    Stack pop() {
      if (top == -1) cout << RED_FLASH << "Stack is empty." << NC << endl;
      else cout << "Popped " << RED_NO_FLASH << arr[top--] << NC << endl; // Not actually deleted but will be overwritten by the next push

      return *this;
    }

    Stack display() {
      if (top == -1) cout << RED_FLASH << "Stack is empty." << NC << endl;
      for(int i = top; i >= 0; i--) cout << ORANGE_NO_FLASH << arr[i] << NC << endl;

      return *this;
    }
};

int main() {
  Stack s;
  int ele, choice;

  while (true) {
    cout << "Enter " <<
    ORANGE_UNDER << 1 << NC
    << " to push, " <<
    ORANGE_UNDER << 2 << NC
    << " to pop and "
    << ORANGE_UNDER << 3 << NC
    << " to display: " << ORANGE_NO_FLASH;

    cin >> choice;
    cout << NC;

    switch(choice) {
      case 1:
        cout << "Enter element: " << ORANGE_NO_FLASH;
        cin >> ele;
        cout << NC;

        s.push(ele);
        break;

      case 2:
        s.pop();
        break;

      case 3:
        s.display();
        break;

      default:
        return 0;
    }
  }
}

