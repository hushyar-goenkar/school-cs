#include <stdio.h>
#include <math.h>

int main() {
  float a, b, c, discriminant, root1, root2, complex, real;

  printf("Enter the coefficients a, b, c of ax^2 + bx + c = 0 in that order: ");
  scanf("%f%f%f", &a, &b, &c);

  discriminant = b*b - 4*a*c;

  if (discriminant == 0) {
    root1 = -b / (2*a);
    printf("The equation has two equal roots: %f", root1);
  }

  if (discriminant > 0) {
    root1 = (-b + sqrt(discriminant)) / (2*a);
    root2 = (-b - sqrt(discriminant)) / (2*a);

    printf("This equation has two real roots %f and %f \n", root1, root2);
  }

  if (discriminant < 0) {
    real = -b / (2*a);
    complex = sqrt(-discriminant) / 2*a;
    printf("%f", -b / (2*a));

    printf("The equation has two complex roots: \n");
    printf("1) %f + %fi \n", real, complex);
    printf("2) %f - %fi \n", real, complex);
  }
}