// Converted from programs_using_classes.docx

/** Define a class ‘‘Library’’ in C++ with the following specifications :
 * Private :
 * • code — type integer
 * • name — character array of size 20
 * • game_name — character array of size 20
 * • mtype — type character (P for permanent member and T for temporary member)
 * • fees — type float
 * Public :
 * • A parameterised constructor to assign the values for data members code, name, game_name and mtype.
 * • Calculate()-to calculate fees according to the following criteria.
 * Fees for different games.
 * Game-name     Fees for Permanent Member
 * Cricket         1000
 * Tennis          2000
 * Badminton  3000
 * If the member is temporary then the fees is double of permanent  member.
 * • Display()-to display all the data members on the screen.
 * Write a function main() to call necessary functions
 */

#include <iostream>
#include <string.h>
#include "../../util/COLORS!.hpp"

using namespace std;

#define numGames 3
const char gameNames[numGames][20] = {
  "cricket",
  "tennis",
  "badminton"
};

const int feesPerGame[numGames] = {
  1000,
  2000,
  3000
};

class Library {
  private:
    int code;
    char name[20];
    char gameName[20]; // One of gameNames array
    char mType; // Member type: P - permanent or T - temporary
    float fees;

  public:
    Library(int code_input, char name_input[20], char gameName_input[20], char mtype_input) {
      code = code_input;
      strcpy(name, name_input);
      strcpy(gameName, gameName_input);
      mType = mtype_input;
    }

    Library calculate() {
      for (int i = 0; i < numGames; i++) {
        if (strcmp(gameNames[i], gameName) == 0) { // Check game name against the defined games
          fees = feesPerGame[i];

          if (mType == 'T') fees *= 2; // Double fees for temporary members
          return *this;
        }
      }
      // If the code didn't return and reached this point, it means that the game was not found.
      cout << "Game Name Invalid";
      throw "Game Name Invalid";
      return *this;
    }

    Library display() {
      cout << "Code: " << ORANGE_NO_FLASH << code << NC << endl;
      cout << "Member Name: " << ORANGE_NO_FLASH << name << NC << endl;
      cout << "Game Name: " << ORANGE_NO_FLASH << gameName << NC << endl;
      cout << "Member Type: " << ORANGE_NO_FLASH << mType << NC << endl;
      cout << "Fees: " << ORANGE_NO_FLASH << "₹" << fees << NC << endl;

      return *this;
    }

};

int main() {
  int code;
  char name[20];
  char gameName[20];
  char mType;

  cout << "Enter The Code: " << ORANGE_NO_FLASH;
  cin >> code;
  cout << NC;

  cout << "Enter The Name: " << ORANGE_NO_FLASH;
  cin >> name;
  cout << NC;

  cout << "Enter Member Type(P or T): " << ORANGE_NO_FLASH;
  cin >> mType;
  cout << NC;

  cout << "Game Names: \n";
  for (int i = 0; i < numGames; i++) cout << GREEN_NO_FLASH << gameNames[i] << ORANGE_NO_FLASH << "(₹" << feesPerGame[i] * (mType == 'P' ? 1 : 2) << ")" << NC << " ";
  cout << endl;

  bool isDeptValid = false;
  while(!isDeptValid) {
    cout << "Type the game name(case sensitive): " << ORANGE_NO_FLASH;
    cin >> gameName;
    cout << NC;

    for (int i = 0; i < numGames; i++) if (strcmp(gameNames[i], gameName) == 0) {
      isDeptValid = true;
      break;
    }
  }

  Library l(code, name, gameName, mType);
  l.calculate().display();

  return 0;
}
