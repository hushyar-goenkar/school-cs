#include <stdio.h>
void main() {
  int a, b, c;

  printf("Give values of a b c: ");
  scanf("%d%d%d", &a, &b, &c);

  if (a >= b){
    if (a >= c) printf("The greatest number is %d \n", a);
    else printf("The greatest number is %d \n", c);
  }
  else {
    if (b >= c) printf("The greatest number is %d \n", b);
    else printf("The greatest number is %d \n", c);
  }
}