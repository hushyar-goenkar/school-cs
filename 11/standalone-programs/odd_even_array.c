/**
 * Finding odd/even elems of an array
 */
#include <stdio.h>

void main() {
  int nos[6], day, i, even = 0, odd = 0;

  printf("Day(no) today?: ");
  scanf("%d", &day);

  printf("Car Nos: \n");
  for (i = 0; i < 6; i++) scanf("%d", &nos[i]);

  for (i = 0; i < 6; i++) {
    if (nos[i] % 2 == 0) even ++;
    else odd ++;
  }

  if (day%2 == 0) printf("You can drive %d of your cars today. \n", even);
  else printf("You can drive %d of your cars today. \n", odd);

  printf("Please obey traffic rules. Clean India, Green India \n - Kejriwal \n");
}