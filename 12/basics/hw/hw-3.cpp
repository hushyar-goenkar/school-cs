// Converted from basics.pdf

/**
 * WAP to take from the user to take 3 nos and find the smallest no using if-else statement.
 */

#include <iostream>
using namespace std;

int main() {
  int a, b, c; // 3 input nos

  cout << "Enter the numbers (separated by spaces): ";
  cin >> a >> b >> c;

  if (a > b) {
    if (a > c) cout << "Largest no is: " << a << endl;
    else cout << "Largest no is: " << c << endl;
  }
  else {
    if (b > c) cout << "Largest no is: " << b << endl;
    else cout << "Largest no is: " << c << endl;
  }

  return 0;
}
