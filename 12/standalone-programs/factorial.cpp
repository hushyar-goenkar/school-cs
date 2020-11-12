#include <iostream>
using namespace std;

long int fact(long int n) {
  if (n == 1) return 1;
  else return fact(n - 1) * n;
}

int main() {
  long int n;

  cout << "n?: ";
  cin >> n;

  cout << fact(n) << endl;

  return 0;
}