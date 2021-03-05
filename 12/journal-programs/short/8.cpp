/**
 * STATEMENT: Define a class with two private data members d1 and d2
 * of type double and one private member function smaller(), that returns
 * the smaller of the two values.
 * Define two public member functions as follows:
 * get_data(double, double) - to assign values to the data members.
 * put_data()               - to display the data values and the
 *                            smaller of the two values by calling smaller()
 */

#include <iostream>
using namespace std;

class SmallerOfTheTwo {
  private:
    double d1, d2;
    double smaller() {
      if (d1 > d2) return d2;
      else return d1;
    }

  public:
    void get_data(double dOne, dobule dTwo) {
      d1 = dOne;
      d2 = dTwo;
    }

    void put_data() {
      cout << "d1: " << d1 << endl;
      cout << "d2: " << d2 << endl;
      cout << "smaller: " << smaller() << endl;
    }
};
