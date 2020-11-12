#include <stdio.h>

void main() {
  int base, height;

  printf("What is the height?: ");
  scanf("%d", &height);

  printf("What is the base?: ");
  scanf("%d", &base);

  printf("The area is \033[0;32;4m%f\033[0m \n", 0.5*base*height);
}