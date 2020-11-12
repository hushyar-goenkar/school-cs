#include <stdio.h>
void main() {
  int a, b;
  char red[] = "\033[1;31;4m";
  char green[] = "\033[0;32;4m";
  char NC[] = "\033[0m";

  printf("Gimme the values of a/b: ");
  scanf("%d/%d", &a, &b);

  printf("initial values of %sa%s/%sb%s are %s%d%s/%s%d%s \n", red, NC, green, NC, red, a, NC, green, b, NC);

  a = a - b;
  b = a + b;
  a = b - a;

  printf("final values of %sa%s/%sb%s are %s%d%s/%s%d%s \n", red, NC, green, NC, red, a, NC, green, b, NC);
}