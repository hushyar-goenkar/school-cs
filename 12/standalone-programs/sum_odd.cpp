/**
* Take n
* Find sum of odd numbers from 1 to n
*/

#include <iostream>
using namespace std;

int main() {
  int n, sum = 0;

  cout << "Enter n: ";
  cin >> n;

  if (n%2 == 0) n -= 1;

  for (; n > 0; n-=2) {
    sum += n;
  }

  cout << "Sum: " << sum << endl;
}
