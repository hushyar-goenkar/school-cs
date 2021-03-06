/**
 * STATEMENT: Write a menu driven program in C++ to create and display a linked list having N nodes, where the data part consists of:
 * empcode - integer
 * empname - of maximum length 20 characters
 * basic_pay - float
 * allowance - float
 *
 * The output should be in a neat tabular form as shown below
 ************************************************************************************
 Sr No        Emp Code         Emp Name        Basic Pay       Allowance        Total
 1            101              ......................................................
 ************************************************************************************
 */

#include <iostream>
using namespace std;

struct Node {
  struct Node *next = NULL;

  int empcode;
  char empname[20];
  float basic_pay;
  float allowance;
};

class EmpData {
  private:
    Node *start;

  public:
    EmpData display() {
      Node *t = start;
      int srNo = 1;

      if (t == NULL) cout << "Empty." << endl;
      else {
        cout << "************************************************************************************" << endl;
        cout << "Sr No        Emp Code         Emp Name        Basic Pay       Allowance        Total" << endl;

        while (t != NULL) {
          cout << srNo << "            " << t->empcode << "               " << t->empname << "            " << t->basic_pay << "             " << t->allowance << "               " << t->allowance + t->basic_pay << endl;

          t = t->next;
          srNo++;
        }

        cout << "************************************************************************************" << endl;
      }

      return *this;
    }

    EmpData add() {
      Node *newNode = new Node,
      *t;

      cout << "Enter empcode: ";
      cin >> newNode->empcode;

      cout << "Enter empname: ";
      cin >> newNode->empname;

      cout << "Enter basic_pay: ";
      cin >> newNode->basic_pay;

      cout << "Enter allowance: ";
      cin >> newNode->allowance;

      newNode->next = NULL;

      if(start == NULL) start = newNode;
      else {
        t = start;

        while(t->next != NULL) t = t->next;

        t->next = newNode;
      }

      return *this;
    }

    EmpData() {
      start = NULL;
    }
};

int main() {
  EmpData E;

  int choice = 1;

  while (true) {
    cout << "1 - Insert Data" << endl;
    cout << "2 - Display" << endl;
    cout << "3 - Quit" << endl;

    cout << "Enter option: ";
    cin >> choice;

    if (choice == 1) {
      E.add();
      E.display();
    }
    else if (choice == 2) E.display();
    else if (choice == 3) return 0;
  }
}

