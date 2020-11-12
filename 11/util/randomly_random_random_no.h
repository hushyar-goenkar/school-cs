// Generates a random number using many pseudo random nos
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Generates a no between 0 and 99 or 0 a and specified max
int generateRandomInt(int max) {
  int rand1 = random(),
    rand2 = random(),
    rand3 = random(),
    out = 0,
    i;

    for (i = 0; i <= rand1%10; i++) {
      out += (rand2 + rand3 * i)%i;
    }

    if (random()%2 == 0) {
      out = out%max;
    }
    else {
      out = out%max;
    }

    return out;
}