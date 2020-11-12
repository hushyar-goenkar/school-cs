#include <stdio.h>

void main() {
  int month, year, days;

  printf("Enter the month number: ");
  scanf("%d", &month);

  switch(month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      days = 31;
      break;

    case 4:
    case 9:
    case 11:
      days = 30;
      break;
    
    case 2:
      printf("Enter year: ");
      scanf("%d", &year);
      if (year%4 == 0) days = 29;
      else days = 28;
      break;
  }

  printf("The number of days is %d \n", days);
}