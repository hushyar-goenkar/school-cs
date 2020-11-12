// Converted from basics.pdf

/**
 * Write a program to take from the user product id , qty and price and find the total price.
 */

#include <iostream>
using namespace std;

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

  cout << "Final amount is: " << price * qty << endl;

  return 0;
}
