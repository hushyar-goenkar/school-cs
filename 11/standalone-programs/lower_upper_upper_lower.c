// Convert all lowercase characters to uppercace and vice versa in a string

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main() {
  char str[20];
  int len, i = 0;

  printf("Enter the string: ");
  scanf("%s", str);
  len = strlen(str);

  for (i = 0; i < len; i++) {
    if (isalpha(str[i])) {
      if (islower(str[i])) str[i] = toupper(str[i]);
      else str[i] = tolower(str[i]);
    }
  }
  printf("New String: %s\n", str);
}