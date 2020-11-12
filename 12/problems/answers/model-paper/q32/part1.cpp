// From model-paper.pdf
#include <iostream>
using namespace std;

/**
 * Write a complete C++ procedural program to generate the following pattern.
 * @@@@@
 *    @
 *   @
 *  @
 * @@@@@
 */

#define size 5
#define character "@"

int main() {
  /**
   * ALGORITHM:
   * size -> Height and width of the Z (both height and width equal)
   *
   * MATHS: A mathematical equation x * (1 - x) = x *(2 - x)
   * can be usually solved by cancelling x on both sides
   * UNLESS x = 0; In this case both sides become 0 and the equation is satisfied
   * x = 0 is therefore, another solution of the given equation.
   *
   * PATTERN: if we define the coordinates x and y
   * Then this pattern is defined by the following conditions:
   * 1) If x = (size - y); show a "@"
   * 2) If x = 0 or x = size; show a "@"
   *
   * These conditions can be written in equations
   * x = 0;
   * x = size; ie x - size = 0
   * x = size - y;
   *
   * We can now club these equations (without using logical operators)
   * x = (size - y) and (x - size) = 0 are solutions.
   * Therefore: (x - size) * x = (x - size) * (size - y)
   *
   * Also x = 0 is a solution
   * therefore, x * (x - size) * x = x * (x -size) * (size - y)
   *
   * COPYRIGHT: © Harsh K
   */
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i * (size - 1 - i) * i  == i * (size - 1 - i) * (size - 1 - j)) cout << character;
      else cout << " ";
    }

    cout << endl;
  }

  return 0;
}
