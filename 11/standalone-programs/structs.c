// Structs in C

#include <stdio.h>
#include <string.h>

struct student { // Definition
  int rollno; // Properties
  char name[30];
  float maths, cs, eng, total;
} s; // Don't forget the `;`

void main() {
  struct student s1, s2; // Instantiation (instance is called an object)
  // OR array of objects
  // struct student s[2]
 
  scanf("%d", &s1.rollno); // Set the properties
  gets(s1.name);
  scanf("%f%f%f", &s1.eng, &s1.cs, &s1.maths);

  s1.total = s1.eng + s1.maths + s1.cs;

  printf("%f", s1.total); // Get the properties
}