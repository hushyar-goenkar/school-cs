#include <iostream>
using namespace std;

long int fact(long int n) {
  if (n == 0) return 1;
  else if (n == 1) return 1;
  else return fact(n - 1) * n;
}