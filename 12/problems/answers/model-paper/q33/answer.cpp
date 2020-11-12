// From model-paper.pdf
#include <iostream>
#include <string.h>
#include "../../../../util/COLORS!.hpp"
using namespace std;

/**
 * Define a class “Library” in c++ with the following specifications:
 * Data Members:
 *    code – type integer
 *    name – character array of size 20
 *    game_name – character array of size 20
 *    mtype – single character(P for Permanent T for Temporary)
 *    fees - type float
 * Member Functions:-
 *    A Parameterised constructor to assign the values for data
 *    members code, name, game_name and mtype.
 *    calculate() - to calculate fees according to the following criteria.
 *
 *      game_name   fees for permanent member
 *      Cricket     1000
 *      Tennis      2000
 *      Badminton   3000
 *      If the member is temporary, then fees are double of permanent member.
 *
 *    displayData()- To display all data members on the screen.
 *
 * Write a main function to create an object of class library, assign values to object
 * and display values on the screen.
 */

class Library {
  int code;
  char name[20];
  char game_name[20];
  char mtype;
  float fees;

  public:
    /**
     * @param c Code
     * @param n name
     * @param gn Game name ("cricket" | "badminton" | "tennis")
     * @param mt Member type ("P" | "T")
     */
    Library(int c, const char n[20], const char gn[20], char mt) {
      code = c;
      strcpy(name, n);
      strcpy(game_name, gn);
      mtype = mt;
    }

    Library calculate() {
      if (strcmp(game_name, "cricket") == 0) fees = 1000;
      else if (strcmp(game_name, "tennis") == 0) fees = 2000;
      else if (strcmp(game_name, "badminton") == 0) fees = 3000;
      else fees = 10000; // Their mistake

      if (mtype != 'P') fees *= 2;

      return *this;
    }

    Library displayData() {
      cout << "Code: " << ORANGE_UNDER << code << NC << endl;
      cout << "Name: " << ORANGE_UNDER << name << NC << endl;
      cout << "Game Name: " << ORANGE_UNDER << game_name << NC << endl;
      cout << "Member Type: " << ORANGE_UNDER << mtype << NC << endl;
      cout << "Fees: " << GREEN_UNDER << "₹" << fees << NC << endl;

      return *this;
    }
};

int main() {
  Library L1(1729, "Gully Cricketer", "cricket", 'P');
  L1.calculate().displayData();

  cout << endl;

  Library L2(87539319, "Ati Shano", "atishanepana", 'T');
  L2.calculate().displayData();

  return 0;
}
