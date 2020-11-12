// Converted from basics.pdf

/**
 * WAP to display Fibonacci series till n terms. Execute all the programs on the compiler and check.
 */

#include <iostream>
using namespace std;

int main() {
  int n; // Number of fibonacci terms to display; n to be entered by the user
  int lastFibTerm = 0; // The last term in this sequence (considering the term before 1 to be 0)
  int fibSum = 1; // The current sum of all terms ie the new term in the sequence (The sum of first 1 term is 1)

  cout << "How many terms? (even if you enter a -ve number or fraction, my program won't break ᕦ(ò_óˇ)ᕤ): ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    cout << fibSum << " "; // Print the sum ie the current term
    fibSum += lastFibTerm; // Add the last term to the sum of the current digit to get the next term

    lastFibTerm = fibSum - lastFibTerm; // The last fibsum is the new last term
  }
  cout << endl;

  return 0;
}
