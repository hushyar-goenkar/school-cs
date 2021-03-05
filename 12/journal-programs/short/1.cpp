/**
 * STATEMENT: Write a C++ program to reverse a given positive integer M,
 * of arbitrary length(i.e. any number of digits) and output M as well as its reverse.
 */

#include <iostream>
using namespace std;

class ReverseNumber {
  public:
    ReverseNumber() {
      int no, rev = 0, original;

      cout << "Enter Number: ";
      cin >> no;
      original = no;

      while (no > 0) {
        rev *= 10;
        rev += no % 10;
        no /= 10;
      }

      cout << "Original Number: " << original << endl;
      cout << "Reversed Number: " << rev << endl;
    }
};

int main() {
  ReverseNumber N;

  return 0;
}
