// Converted from linked-list.cpp
#include <iostream>
#include "./linked-list.hpp"
using namespace std;

int main() {
  LinkedList L;
  int choice = 0;

  while (true) {
    cout << "Options: " << endl;
    cout << ORANGE_UNDER << "0" << NC << ": Exit." << endl;
    cout << ORANGE_UNDER << "1" << NC << ": Insert at end." << endl;
    cout << ORANGE_UNDER << "2" << NC << ": Insert at beginning." << endl;
    cout << ORANGE_UNDER << "3" << NC << ": Insert after." << endl;
    cout << ORANGE_UNDER << "4" << NC << ": Insert before." << endl;
    cout << ORANGE_UNDER << "5" << NC << ": Delete at beginning." << endl;
    cout << ORANGE_UNDER << "6" << NC << ": Delete at end." << endl;
    cout << ORANGE_UNDER << "7" << NC << ": Delete given element." << endl;
    cout << ORANGE_UNDER << "8" << NC << ": Delete before." << endl;
    cout << ORANGE_UNDER << "9" << NC << ": Delete after." << endl;
    cout << ORANGE_UNDER << "10" << NC << ": Reverse." << endl;

    L.display();
    cout << "Enter your option: ";
    cin >> choice;

    switch (choice) {
      case 0:
        return 0;
        break;

      case 1:
        L.insertEnd();
        break;
      case 2:
        L.insertBeginning();
        break;
      case 3:
        L.insertAfter();
        break;
      case 4:
        L.insertBefore();
        break;
      case 5:
        L.deleteBeginning();
        break;
      case 6:
        L.deleteEnd();
        break;
      case 7:
        L.deleteElement();
        break;
      case 8:
        L.deleteBefore();
        break;
      case 9:
        L.deleteAfter();
        break;
      case 10:
        L.reverse();
        break;

      default:
        cout << "Ty. Now enter again." << endl;
        break;
    }
  }
  return 0;
}
