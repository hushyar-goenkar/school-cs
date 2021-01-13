// Converted from linked-list.cpp
#include <iostream>
#include "./circular-linked-list.hpp"
using namespace std;

int main() {
  CircularLinkedList L;
  int choice = 0;

  while (true) {
    cout << endl << "Options: " << endl;
    cout << ORANGE_UNDER << "0" << NC << ": Exit." << endl;
    cout << ORANGE_UNDER << "1" << NC << ": Insert after." << endl;
    cout << ORANGE_UNDER << "2" << NC << ": Insert before." << endl;
    cout << ORANGE_UNDER << "3" << NC << ": Delete given element." << endl;
    cout << ORANGE_UNDER << "4" << NC << ": Delete before." << endl;
    cout << ORANGE_UNDER << "5" << NC << ": Delete after." << endl << endl;

    L.display();
    cout << "Enter your option: ";
    cin >> choice;

    switch (choice) {
      case 0:
        return 0;
        break;
      case 1:
        L.insertAfter();
        break;
      case 2:
        L.insertBefore();
        break;
      case 3:
        L.deleteElement();
        break;
      case 4:
        L.deleteBefore();
        break;
      case 5:
        L.deleteAfter();
        break;

      default:
        cout << "Ty. Now enter again." << endl;
        break;
    }
  }
  return 0;
}
