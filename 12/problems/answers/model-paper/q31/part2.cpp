// From model-paper.pdf

#include <iostream>
using namespace std;

/**
 * Write a user defined function in C++ named “concat“ which accepts three strings
 * S1, S2 and S3 as arguments and concatenates S1 and S2 into S3 without using
 * standard library function.
 */

/**
 * @param s1 First string
 * @param l1 Length of first string
 * @param s2 Second string
 * @param l2 Length of second string
 * @param s3 Final string of length l1 + l2
 *
 * @returns s1 + s2 after storing in s3
 */
char* concat(char s1[], int l1, char s2[], int l2, char s3[]) {
  for (int i = 0; i < l1; i++) s3[i] = s1[i];
  for (int i = 0; i < l2; i++) s3[l1 + i] = s2[i];

  return s3;
}

int main() {
  int l1 = 15;
  char s1[l1] = "Concatenation ";

  int l2 = 24;
  char s2[l2] = "is not related to cats.";

  char s3[l1 + l2];
  concat(s1, l1, s2, l2, s3);

  for (int i = 0; i < l1 + l2; i++) cout << s3[i];
  cout << endl;

  return 0;
}
