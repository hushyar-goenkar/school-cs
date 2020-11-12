#include <stdio.h>
void main() {
  int f;
  char green[] = "\033[0;32;4m";
  char NC[] = "\033[0m";

  printf("Enter Farenheit temperature: ");
  scanf("%d", &f);

  printf("Celsius temperature is %s%d%s C \n", green, (f - 32) * 5 / 9, NC);
}