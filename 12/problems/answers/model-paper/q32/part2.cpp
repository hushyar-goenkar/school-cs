// From model-paper.pdf
#include <iostream>
using namespace std;

/**
 * Write a complete C++ procedural program to generate the following pattern
 *          *
 *        * * *
 *      * * * * *
 *    * * * * * * *
 *  * * * * * * * * *
 */

#define bottom_width 9
#define character "*"

int main() {
  for (int i = 0; i < (bottom_width + 1) / 2; i++) {
    for (int j = 0; j < bottom_width - 2 * i; j++ ) cout << " "; // Offset spaces

    for (int j = 0; j < 4 * i + 1; j++) { // Triangle
      if (j % 2 == 0) cout << character; // one "*"
      else cout << " "; // one " "
    }

    cout << endl;
  }

  return 0;
}
