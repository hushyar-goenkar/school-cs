/**
 * STATEMENT: Write a menu driven program in C++ to push and pop a value
 * in a linked queue storing floating point numbers. Display the contents
 * of the queue after each operation.
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

    LinkedList insertEnd() {
      Node *newNode = new Node,
      *t;

      cout << "Enter the data: ";
      cin >> newNode->data;

      newNode->next = NULL;

      if(start == NULL) start = newNode;
      else {
        t = start;

        while(t->next != NULL) t = t->next;

        t->next = newNode;
      }

      return *this;
    }

    LinkedList deleteBeginning() {
      if (start == NULL) cout << "Empty." << endl;
      else {
        Node *temp;

        temp = start;
        start = start->next;

        delete temp;
      }

      return *this;
    }
};

class Queue {
  private:
    LinkedList queue;

  public:
    void add() {
      queue.insertEnd();
    }

    void remove() {
      queue.deleteBeginning();
    }

    void display() {
      queue.display();
    }
};

int main() {
  Queue Q;
  int choice = 1;

  while (true) {
    cout << "1 - Add" << endl;
    cout << "2 - Remove" << endl;
    cout << "3 - Display" << endl;
    cout << "4 - Quit" << endl;

    cout << "Enter option: ";
    cin >> choice;

    if (choice == 1) {
      Q.add();
      Q.display();
    }
    else if (choice == 2) {
      Q.remove();
      Q.display();
    }
    else if (choice == 3) Q.display();
    else if (choice == 4) return 0;
  }
}
