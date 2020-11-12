#include <stdio.h>

struct product {
  int pid, qty;
  float price, total;
} p[3];

void main() {
  int i;
  float finalPrice;

  for (i = 0; i < 3; i++) {
    printf("PID: ");
    scanf("%d", &p[i].pid);

    printf("QTY: ");
    scanf("%d", &p[i].qty);

    printf("Price: ");
    scanf("%f", &p[i].price);

    p[i].total = p[i].qty * p[i].price;
  }

  for (i = 0; i < 3; i++) {
    finalPrice += p[i].total;
  }

  printf("Final Price is %f \n", finalPrice);
}