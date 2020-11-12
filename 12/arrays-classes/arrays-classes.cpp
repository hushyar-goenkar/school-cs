// Converted from arrays_classes.docx


#include <iostream>
#include <string.h>

using namespace std;

class Product {
  int prodid, qty, price;
  char pname[20];

  public:
    void getData(int p, int q, int pr, char pn[20]) {
      prodid = p;
      qty = q;
      price = pr;
      strcpy(pname, pn);
    }

    void display() {
      cout << "the details are";
      cout << prodid << price << qty << pname;
    }

    void calc() {
      int tot = price * qty;
      int dis = tot * 10 / 100;
      int tot = tot - dis;

      cout << "total is " << tot;
    }
};

void main() {
  Product P[5];
  int p, q, pr, i, choice;
  char pn[20];

  i = 0;
  do {

    cout << "Enter the details (id, quantity, price and prod name)";
    cin >> p >> q >> pr >> pn;

    P[i].getData(p, q, pr, pn);
    P[i].display();
    P[i].calc();

    cout << "do you want to continue 1 for yes 0 for no";
    cin >> choice;
    i++;
  }
  while (choice==1);
}
