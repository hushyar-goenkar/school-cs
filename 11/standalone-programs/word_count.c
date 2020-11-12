// Count the number of words in a string
// Algo Copyright Harsh Khandeparkar

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main() {
  int wordCount = 0, i;
  _Bool wordEncountered;
  char string[20];

  printf("String?: ");
  gets(string);

  wordEncountered = !isspace(string[0]);
  if (wordEncountered) wordCount++; // If first character is not a space, the string starts with a word

  for (i = 1; i < strlen(string); i++) {
    if (isspace(string[i])) {
      if (wordEncountered) wordEncountered = 0;
    }
    else {
      if (!wordEncountered) {
        wordEncountered = 1;
        wordCount++;
      }
    }
  }

  printf("word count: %d\n", wordCount);
}