#include <stdio.h>

void main() {
  int choice, r, h;

  printf("Sphere(1) or Cone(2): ");
  scanf("%d", &choice);

  printf("Enter the radius: ");
  scanf("%d", &r);

  switch(choice) {
    case 1:
      printf("Area of sphere is %f \n", 3.14 * r * r * r * (4.0/3.0));
      break;
    case 2:
      printf("Enter the height: ");
      scanf("%d", &h);
      printf("Area of cone is: %f \n", 3.14 * r * r * h * (1.0/3.0));
      break;
  }
}