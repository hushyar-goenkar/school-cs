// Finding the approximate values of sin and cos
// using their McLaurin series

// sin(x) = x - x^3/3! + x^5/5! - ....
// cos(x) = 1 - x^2/2! + x^4/4! - ....

// These series are only accurate when x is near 0 as the
// derivatives of the polynomial approximation are matched to that of sin(x) and cos(x)
// only near x = 0
// To make the series accurate for any value of x, infinite terms need to be written

// This version writes only 4 terms (good enough) and 
// Maps the input angles to [-pi, +pi]

#include <stdio.h>
#include <math.h>
float pi = 3.1415926;

float sine(float x) {
  return x - pow(x, 3) / 6.0 + pow(x, 5) / 120.0 - pow(x, 7) / 5040.0;
}

float cosine(float x) {
  return 1 - pow(x, 2) / 2.0 + pow(x, 4) / 24.0 - pow(x, 6) / 720.0;
}

float sinCosSelect(float x, int selection) {
  if (selection == 0) return sine(x);
  else return cosine(x);
}
 
void main() {
  float x, y_reduced, y_raw;
  int selection; // Selection: cos = 1, sin = 0

  printf("sin (0) or cos (1)?: ");
  scanf("%d", &selection);

  printf("\nEnter the angle(in radians): ");
  scanf("%f", &x);

  y_raw = sinCosSelect(x, selection);

  while (x > pi || x < -pi) {
    if (x > pi) x -= 2.0*pi;
    if (x < -pi) x += 2.0*pi;
  }

  printf("Reduced angle: %f\n", x);

  y_reduced = sinCosSelect(x, selection);

  printf("\nAnswer without reducing the angle to [-pi, +pi]: %f\n", y_raw);
  printf("Answer after reducing the angle to [-pi, +pi]: %f\n", y_reduced);
}
