// Converted from basics.pdf

/**
 * WAP to find the sum of all odd nos from 1 to n, where n is entered by the user.
 */

#include <iostream>
using namespace std;

int main() {
  int n; // Sum of odd nos from 1 to n; n to be entered by user
  int sum = 0;

  cout << "Enter the upper limit n (even if you enter an even number, my program won't break ᕦ(ò_óˇ)ᕤ): ";
  cin >> n;

  for (int i = 1; i <= n; i += 2) sum += i;

  cout << "The sum is: " << sum;
  return 0;
}
