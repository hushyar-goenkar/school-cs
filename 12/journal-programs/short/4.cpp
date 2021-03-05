/**
 * STATEMENT: Write a C++ program to count the number of vowels in a given line of text. Output
 * the line of text and the number of vowels in it.
 */

#include <iostream>
#include <ctype.h>
#include <string.h>

using namespace std;

class CountVowels {
  private:
    const char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };

    bool isVowel(char c) {
      c = tolower(c);

      for (int i = 0; i < 5; i++) if (vowels[i] == c) return true;
      return false;
    }

  public:
    CountVowels() {
      string str;
      int numVowels = 0;

      cout << "Enter the string: ";
      getline(cin, str);

      for (int i = 0; i < str.length(); i++) {
        numVowels += isVowel(str[i]);
      }

      cout << "String: " << str << endl;
      cout << "Vowels: " << numVowels << endl;
    }
};

int main() {
  CountVowels V;

  return 0;
}
