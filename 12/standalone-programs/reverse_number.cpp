/**
* Take a number
* Reverse it
* Print the reversed no
*/

#include <iostream>
using namespace std;

int main() {
  int no, rev = 0;

  cout << "Number?: ";
  cin >> no;

  while (no > 0) {
    rev *= 10;
    rev += no%10;
    no /= 10;
  }

  cout << "Reversed Number: " << rev << endl;

  return 0;
}