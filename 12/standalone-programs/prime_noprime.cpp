/*
* Take a number
* Check whether it is prime or not
*/

#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int n;
  bool isPrime = true;
  
  cout << "n?: ";
  cin >> n;

  if (n == 1) {
    cout << "FYI, 1 is neither a prime nor a composite number. \n";
    return 0;
  }

  for (int i = 2; i <= sqrt(n) && isPrime; i++) {
    if (n % i == 0) isPrime = false;
  }

  if (isPrime) cout << "Prime";
  else cout << "Composite";

  cout << '\n';

  return 0;
}