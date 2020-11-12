// Converted from arrays_classes.docx
/**
 * Write a program to create an array of objects for class account with member variable accno, name, balance. Write functions deposit, withdraw and display.
 */

#include <iostream>
#include <string.h>

using namespace std;

class Account {
  int accno;
  float balance;
  char name[];

  public:
    Account(int accNumber, float initBalance, char accName[]) { // Parameterized
      accno = accNumber;
      balance = initBalance;
      strcpy(name, accName);
    }

    Account() { // Overloaded Default Constructor
      cout << "Acc No?: ";
      cin >> accno;

      cout << "Initial Balance?: ";
      cin >> balance;

      cout << "Name?: ";
      cin >> name;
    }

    Account deposit(float amnt) {
      balance += amnt;
      return *this;
    }

    Account withdraw(float amnt) {
      balance -= amnt;
      return *this;
    }

    Account display() {
      cout << "Acc No: " << accno << endl;
      cout << "Balance: " << balance << endl;
      cout << "Name: " << name << endl;

      return *this;
    }
};

int main() {
  char name[30];
  int accno;
  float initBalance;

  cout << "Name?: ";
  cin >> name;

  cout << "Acc No?: ";
  cin >> accno;

  cout << "Initial Balance?: ";
  cin >> initBalance;

  Account A(accno, initBalance, name);

  cout << "Initial Details: \n";
  A.display().withdraw(500).deposit(2.501);

  cout << "\nFinal Details: \n";
  A.display();

  Account A[50]; // Make 50 accounts using default constructor

  return 0;
}
