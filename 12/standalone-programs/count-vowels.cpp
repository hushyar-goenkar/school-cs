#include <iostream>
#include <ctype.h>
#include <string.h>

using namespace std;

const char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };
bool isVowel(char c) {
  c = tolower(c);

  for (int i = 0; i < 5; i++) if (vowels[i] == c) return true;
  return false;
}

int main() {
  string str;
  int numVowels = 0;

  cout << "Enter the string: ";
  cin >> str;

  for (int i = 0; i < str.length(); i++) {
    numVowels += isVowel(str[i]);
  }

  cout << "Vowels: " << numVowels << endl;

  return 0;
}
