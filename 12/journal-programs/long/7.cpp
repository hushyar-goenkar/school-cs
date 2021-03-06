/**
 * STATEMENT: Write a menu driven program in C++ to push and pop a value
 * in a linked stack storing floating point numbers. Display the contents
 * of the stack after each operation.
 */

#include <iostream>
using namespace std;

struct Node {
  struct Node *next = NULL;
  float data;
};

class LinkedList {
  Node *start;

  public:
    LinkedList() {
      start = NULL;
    }

    LinkedList display() {
      Node *t = start;

      if (t == NULL) cout << "Empty." << endl;
      else {
        cout << "Current: ";
        cout << t->data;

        while (t->next != NULL) {
          t = t->next;
          cout << " " << t->data;
        }

        cout << endl;
      }

      return *this;
    }

    LinkedList insertBeginning() {
      Node *newNode = new Node;

      cout << "Enter the data: ";
      cin >> newNode->data;

      newNode->next = start;
      start = newNode;

      return *this;
    }

    LinkedList deleteBeginning() {
      if (start == NULL) cout << "Empty." << endl;
      else {
        Node *temp;

        temp = start;
        start = start->next;

        cout << "Deleted " << temp->data << "." << endl;
        delete temp;
      }

      return *this;
    }
};

class Stack {
  private:
    LinkedList stack;

  public:
    void push() {
      stack.insertBeginning();
    }

    void pop() {
      stack.deleteBeginning();
    }

    void display() {
      stack.display();
    }
};

int main() {
  Stack S;
  int choice = 1;

  while (choice == 1 || choice == 2 || choice == 3 || choice == 4) {
    cout << "1 - Push" << endl;
    cout << "2 - Pop" << endl;
    cout << "3 - Display" << endl;
    cout << "4 - Quit" << endl;

    cout << "Enter option: ";
    cin >> choice;

    if (choice == 1) {
      S.push();
      S.display();
    }
    else if (choice == 2) {
      S.pop();
      S.display();
    }
    else if (choice == 3) S.display();
    else if (choice == 4) return 0;
  }
}
