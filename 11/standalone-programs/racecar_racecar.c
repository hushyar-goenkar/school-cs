// Check whether a string is a palindrome
// raceCAR = RACecar

#include <stdio.h>
#include <string.h>
#include "COLORS!.h"

void main() {
  char str[20];
  int len, i = 0;
  _Bool racecar = "true";

  printf("Enter the string: ");
  scanf("%s", str);
  len = strlen(str);

  while (racecar && i < len / 2) {
    if (str[i] != str[len - i - 1]) {
      racecar = 0;
      break;
    }
    i++;
  }

  if (racecar) printf("%sRACECAR!%s\n", GREEN_FLASH, NC);
  else printf("%sNot a palindrome%s\n", RED_FLASH, NC);
}