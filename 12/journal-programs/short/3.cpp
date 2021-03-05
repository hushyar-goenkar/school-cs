/**
 * STATEMENT: Write a C++ program to generate the first N terms of the Fibonacci series
 * 0, 1, 1, 2, 3, 5...
 */

#include <iostream>
using namespace std;

class Fibonacci {
  public:
    Fibonacci() {
      int n; // Number of fibonacci terms to display
      int lastFibTerm = 1; // The last term in this sequence (considering the term before 0 to be 1)
      int fibSum = 0; // The current sum of all terms ie the new term in the sequence (The sum of first 1 term is 0)

      cout << "Enter The Number of Terms: ";
      cin >> n;

      for (int i = 0; i < n; i++) {
        cout << fibSum << " "; // Print the sum ie the current term
        fibSum += lastFibTerm; // Add the last term to the sum of the current digit to get the next term

        lastFibTerm = fibSum - lastFibTerm; // The last fibsum is the new last term
      }
      cout << endl;
    }
};

int main() {
  Fibonacci F;

  return 0;
}
