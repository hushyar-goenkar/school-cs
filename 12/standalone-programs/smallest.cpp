/**
* Take 3 nos and find the smallest usiing if-else
*/

#include <iostream>

int main() {
  int a, b, c;

  std::cout << "Three numbers: ";
  std::cin >> a >> b >> c;

  if (a <= b) {
    if (c <= a) std::cout << c;
    else std::cout << a;
  }
  else {
    if (c <= b) std::cout << c;
    else std::cout << b;
  }

  std::cout << '\n';

  return 0;
}