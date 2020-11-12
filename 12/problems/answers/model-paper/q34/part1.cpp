// From model-paper.pdf
#include <iostream>
#include <string.h>
#include "../../../../util/COLORS!.hpp"
using namespace std;

/**
 * Declare an abstract class named “customer “which has the following members:
 *    i)   cno: of type integer under private visibility label.
 *    ii)  display(): a function under protected visibility label to display data
 *         member “cno”.
 *    iii) Define a constructor to initialise the data member “cno”.
 * Derive a class named “account” from class “customer” under public mode which has
 * the following members:
 *    i)   deposit: of type integer under private visibility label.
 *    ii)  intr: of type float under private visibility label.
 *    iii) display (): a function under protected visibility label to display the
 *         data members intr and deposit.
 *    iv)  Define constructor to initialise data member deposit and set intr
 *         with computed value as deposit*0.05*3.
 * Derive a class named “person” from class “account” under public mode. It has the
 * following members:
 *    i)   name: a character array of size 30 under private visibility label.
 *    ii)  display(): a function under protected visibility label to display the
 *         data member name.
 *    iii) Define a constructor to initialise the data member name.
 * Write a main program to create an object of class “person” to initialise
 * data members of all classes.
 * Use the same object to display the data members of all classes.
 */

class Customer {
  private:
    int cno;

  protected:
    Customer display() {
      cout << "C No: " << ORANGE_UNDER << cno << NC << endl;

      return *this;
    }

  public:
    /**
     * @param cn C No
     */
    Customer(int cn) {
      cno = cn;
    }
};

class Account: public Customer {
  private:
    int deposit;
    float intr;

  protected:
    Account display() {
      Customer::display();
      cout << "Deposit: " << ORANGE_UNDER << "₹" << deposit << NC << endl;
      cout << "Interest: " << ORANGE_UNDER << "₹" << intr << NC << endl;

      return *this;
    }

  public:
    /**
     * @param cno C No.
     * @param dep Deposit
     */
    Account(int cno, int dep): Customer(cno) {
      deposit = dep;
      intr = deposit * 0.05 * 3;
    }
};

class Person: public Account {
  private:
    char name[30];

  protected:
    Person display() {
      cout << "Name: " << GREEN_UNDER << name << NC << endl;
      Account::display();

      return *this;
    }

  public:
    /**
     * @param cno C No.
     * @param dep Deposit
     * @param n Names
     */
    Person(int cno, int dep, const char n[30]): Account(cno, dep) {
      strcpy(name, n);

      this->display();
    }
};

int main() {
  Person P(1729, 10000, "Mr. X");

  return 0;
}
