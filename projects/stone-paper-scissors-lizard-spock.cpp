// By Harsh Khandeparkar

#include <iostream>
#include <string.h>
#include <cstdlib>
#include "../12/util/COLORS!.hpp"
using namespace std;

#define MULTI_LINE_STRING(a) #a

const char *RULES = MULTI_LINE_STRING(\n
Scissors cuts paper.\n
Paper covers rock.\n
Rock crushes lizard.\n
Lizard poisons Spock.\n
Spock smashes scissors.\n
Scissors decapitates lizard.\n
Lizard eats paper.\n
Paper disproves Spock.\n
Spock vaporizes rock.\n
Rock crushes scissors.\n
\n
- Sheldon Cooper \n
);

enum PLAYS: int {
  ROCK,
  PAPER,
  SCISSORS,
  LIZARD,
  SPOCK
};

const char nameMap[5][15] = {
  "Rock",
  "Paper",
  "Scissors",
  "Lizard",
  "Spock"
};

const int killers[5][2] = {
  { PAPER, SPOCK },
  { SCISSORS, LIZARD },
  { ROCK, SPOCK },
  { ROCK, SCISSORS },
  { LIZARD, PAPER }
};

class Game {
  int playerPlayed;

  public:
    Game startGame() {
      askPlayer().calculateResult();
      return *this;
    }

    Game askPlayer() {
      cout << endl;
      cout << "ROCK: " << ORANGE_UNDER << ROCK << NC << endl;
      cout << "PAPER: " << ORANGE_UNDER << PAPER << NC << endl;
      cout << "SCISSORS: " << ORANGE_UNDER << SCISSORS << NC << endl;
      cout << "LIZARD: " << ORANGE_UNDER << LIZARD << NC << endl;
      cout << "SPOCK: " << ORANGE_UNDER << SPOCK << NC << endl;

      cout << endl << "Enter your option: " << ORANGE_NO_UNDER;
      cin >> playerPlayed;
      cout << NC;

      return *this;
    }

    Game calculateResult() {
      srand(time(0));
      int computerPlayed = rand() % 5;

      cout << "Computer played " << ORANGE_NO_UNDER << nameMap[computerPlayed] << NC << '.' << endl;

      if (
        killers[computerPlayed][0] == playerPlayed ||
        killers[computerPlayed][1] == playerPlayed
      ) cout << GREEN_UNDER << "YOU WON! 🎉" << NC << endl;
      else if(
        killers[playerPlayed][0] == computerPlayed ||
        killers[playerPlayed][1] == computerPlayed
      ) cout << "You lost :(" << endl;
      else cout << "TIE." << endl;

      return *this;
    }
};

int main() {
  int choice;
  Game g;

  while (true) {
    cout << "Options: " << endl;
    cout << ORANGE_UNDER << 0 << NC << ": Exit." << endl;
    cout << ORANGE_UNDER << 1 << NC << ": Display rules." << endl;
    cout << ORANGE_UNDER << 2 << NC << ": Start game." << endl;

    cout << "Enter your choice: " << ORANGE_NO_UNDER;
    cin >> choice;
    cout << NC;

    switch(choice) {
      case 0:
        return 0;
      case 1:
        cout << GREEN_NO_UNDER << RULES << NC << endl;
        break;
      case 2:
        g.startGame();
        return 0;
      default:
        break;
    }
  }

  return 0;
}
