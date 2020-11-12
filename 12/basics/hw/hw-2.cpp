// Converted from basics.pdf

/**
 * Write a program to take from the user product id, qty and price and find the total price by giving discount of 10 %.
 */

#include <iostream>
using namespace std;

#define discount 10 // 10% discount

int main() {
  int prodId, // product id
    qty, // Quantity
    price;

  cout << "Product Id: ";
  cin >> prodId;

  cout << "Quantity: ";
  cin >> qty;

  cout << "Price: ";
  cin >> price;

  cout << "Final amount is: " << price * qty * (1 - discount) / 100 << endl;

  return 0;
}
