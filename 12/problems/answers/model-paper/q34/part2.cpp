// From model-paper.pdf

#include <iostream>
#include <string.h>
#include "../../../../util/COLORS!.hpp"
using namespace std;

/**
 * Declare an abstract class named “account” which has the following members:
 *    i)    deposit: of type integer under private visibility label.
 *    ii)   display(): a function under public visibility label to display the
 *          data members deposit.
 *     iii) Define constructor to initialise data member deposit.
 * Declare a class named “person” which has the following members:
 *    i)   a: of type customer under private visibility label.
 *    ii)  b: of type account under private visibility label.
 *    iii) name: a character array of size 30, under private visibility label.
 *    iv)  Define a constructor to initialise the data member name.
 *    v)   display(): a function under protected visibility label to display the
 *         data member name.
 * Write a main program to create an object of class “person” to
 * initialize data members of all classes.
 * Also display the data members of all classes.
 */

class Account {
  private:
    int deposit;

  public:
    Account display() {

    }
};
