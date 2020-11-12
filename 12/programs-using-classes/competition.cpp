// Converted from programs_using_classes.docx

/**
 * Define a class competition with complete function definitions in C++ with following specification.
 * Private Members:
 * • Event_No of type integer
 * • Description of type string, size[30]
 * • Score of type integer
 * • Qualified of type character
 * Public Members:
 * A constructor functions to assign initial values Event_no as 101 description as “ state level”, score as 50 and qualified as ‘N’
 * • Input( ) To take input for Event_No, description and score.
 * • Award ( ) To award qualified as ‘y’ if score is more than the cut off score passed as argument to the function else ‘N’
 * • Show( ) To display all the details
 * Write a function main ( ) accepting the input for cutoffscore and call the necessary functions.
 */

#include <iostream>
#include <string.h>
#include "../util/COLORS!.hpp"

using namespace std;

class Competition {
  private:
    int eventNo; // Event Number
    string description;
    int score;
    char qualified; // Whether qualified Y or N

  public:
    Competition(int e = 40, string d = "state level", int s = 50) {
      eventNo = e;
      description = d;
      score = s;
      qualified = 'N';
    }

    Competition input() {
      cout << "Enter Event No: " << ORANGE_NO_FLASH;
      cin >> eventNo;
      cout << NC;

      cout << "Enter Description: " << ORANGE_NO_FLASH;
      cin >> description;
      cout << NC;

      cout << "Enter Score: " << ORANGE_NO_FLASH;
      cin >> score;
      cout << NC;

      return *this;
    }

    Competition award(int cutoff) {
      if(score > cutoff) qualified = 'Y';
      else qualified = 'N';

      return *this;
    }

    Competition show() {
      cout << "Event No: " << ORANGE_NO_FLASH << eventNo << NC << endl;
      cout << "Description: " << ORANGE_NO_FLASH << description << NC << endl;
      cout << "Score: " << ORANGE_NO_FLASH << score << NC << endl;
      cout << "Qualified: " << ORANGE_NO_FLASH << qualified << NC << endl;

      return *this;
    }

};

int main() {
  Competition c;
  c.input();

  int cs; // Cutoff Score

  cout << "Enter Cutoff Score: " << ORANGE_NO_FLASH;
  cin >> cs;
  cout << NC;

  c.award(cs).show();

  return 0;
}
