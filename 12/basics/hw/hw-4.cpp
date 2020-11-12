// Converted from basics.pdf

/**
 * WAP to find the reverse of a given no.
 */

#include <iostream>
using namespace std;

int main() {
  int number;
  int reverse = 0; // Initialized to 0 to add one digit at a time

  cout << "Enter the number: ";
  cin >> number;

  while (number > 0) {
    reverse *= 10; // Multiply by 10 to make way for the new digit
    reverse += number % 10; // Modulo base 10 give the last digit

    number /= 10; // Remove the last digit, for datatype int, this will truncate the decimal place
  }

  cout << "Reverse is: " << reverse;
  return 0;
}
