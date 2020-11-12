/*
* Armstrong Number: Sum of cubes of digits = Number itself
* Find armstrong numbers
*/

#include <iostream>
#include <math.h>
using namespace std;

bool isArmstrong(long int n) {
  long int temp = n;
  long int cubeSum = 0;

  while (temp > 0) {
    cubeSum += pow(temp % 10, 3);
    temp /= 10;
  }

  if (cubeSum == n) return true;
  else return false;
}

int main() {
  cout << "Press CTRL+C to stop.\n";

  for (long int i = 1; i < 1000; i++) {
    if (isArmstrong(i)) cout << i << " ";
  }
}