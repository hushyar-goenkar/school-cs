// Concatenate two strings

#include <stdio.h>
#include <string.h>

void main() {
  char str1[40], str2[20];

  printf("String1?: ");
  gets(str1);

  printf("String2?: ");
  gets(str2);

  strcat(str1, str2);
  printf("Concatenated string: %s\n", str1);
}