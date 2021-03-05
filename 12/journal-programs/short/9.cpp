/**
 * STATEMENT: Define a class BASE having one private data member num1
 * and one public data member num2, both of type fload.
 * Define public member functions:
 * input_data() - to read value num1.
 * get_num1() - to return the value of num1.
 * Extend the class BASE to another class DERIVED using public derivation.
 * Deine for class DERIVED, a private data member sum which is to be
 * calculated by adding num1 and num2 and a public member function:
 * get_data() - to read num2 and to call input_data() for reading value to and
 *              to compute sum.
 * show_data() - to output num1, num2 and sum
 * Write a main() to create object of type DERIVED and input and
 * output all data.
 */

#include <iostream>
using namespace std;

class BASE {
  private:
    float num1;

  public:
    float num2;

    void input_data() {
      cout << "Enter num1: ";
      cin >> num1;
    }

    float get_num1() {
      return num1;
    }
};

class DERIVED: public BASE {
  private:
    float sum;

  public:
    void get_data() {
      input_data();

      cout << "Enter num2: ";
      cin >> num2;

      sum = get_num1() + num2;
    }

    void show_data() {
      cout << "num1: " << get_num1() << endl;
      cout << "num2: " << num2 << endl;
      cout << "sum: " << sum << endl;
    }
};

int main() {
  DERIVED d;

  d.get_data();
  d.show_data();
}
