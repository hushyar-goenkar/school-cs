/**
* Get from the user:
* Prod id
* QTY
* Find total price
*/

#include <iostream>
using namespace std;

float priceMap[] = {10, 20, 40, 10, 100, 60, 80, 12, 15, 12.353512};

int main() {
  int pid, qty;
  double price;

  cout << "Prod id?: ";
  cin >> pid;

  cout << "Quantity?: ";
  cin >> qty;

  price = priceMap[pid] * qty;

  cout << "Price: Rs. " << price << endl;

  return 0;
}