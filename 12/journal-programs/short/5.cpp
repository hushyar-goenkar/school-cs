/**
 * STATEMENT: Define a class NUMBER_LIST having the following specifications:
 * Private data members:
 * num_list: an array of integers capable of storing max 10 numbers.
 * Public member functions:
 * read_list(): To read N(N<=10) numbers in the array num_list.
 * calc_product(): To compute the product of the numbers in the array
 *                 and display the numbers and their product.
 */

#include <iostream>
using namespace std;

class NUMBER_LIST {
  private:
    int num_list[10] = { 12, 17, 13, 1, 5, 3, 2, 6, 11, 10 };

  public:
    void read_list() {
      int N;

      cout << "Enter N: ";
      cin >> N;

      cout << "N Numbers: ";
      for (int i = 0; i < N; i++) cout << num_list[i] << " ";
      cout << endl;
    }

    void calc_product() {
      int product = 1;

      cout << "Numbers: ";
      for (int i = 0; i < 10; i++) {
        cout << num_list[i] << " ";
        product *= num_list[i];
      }
      cout << endl;

      cout << "Product: " << product << endl;
    }
};
