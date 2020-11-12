// Getting no of days of the month using arrays
#include <stdio.h>

void main() {
  int a[13] = {
    0, // This value doesnt matter
    31, // First month
    28, // 2nd month
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31
  };

  int i;

  printf("Month?: ");
  scanf("%d", &i);

  printf("Days: %d \n", a[i]);
}