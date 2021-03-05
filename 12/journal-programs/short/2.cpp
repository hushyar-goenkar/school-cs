/**
 * STATEMENT: Write a C++ program to calculate sin(x) by summing the terms of the sine series
 * given below. N is the number of terms to be summed and x is a real number specifying
 * an angle in radian. Also check the result of your calculations with that of the standard
 * library function sin()
 * sin(x) = x -x^3/3! + x^5/5! - x^7/7! + ... up to N terms
 */

#include <iostream>
#include <math.h>
using namespace std;

class Sin {
  public:
    Sin() {
      float angle;
      int terms;

      cout << "Enter Angle in Radians: ";
      cin >> angle;

      cout << "Enter Number of Terms: ";
      cin >> terms;

      long double sine = 0;

      for (int i = 0; i < terms; i++) {
        sine += (pow(angle, 2*i + 1) * pow(-1, i) ) / factorial(2*i + 1);
      }

      cout << "Computed Sine: " << sine << endl;
      cout << "Standar Library Sine: " << sin(angle) << endl;
    }
  private:
    long int factorial(long int n) {
      if (n == 0) return 1;
      else if (n == 1) return 1;
      else return factorial(n - 1) * n;
    }
};

int main() {
  Sin sin;

  return 0;
}
