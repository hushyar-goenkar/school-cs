// Converted from programs_using_classes.docx

/**
 * Define a class Tour with complete function definitions with following specification.
 * Private Members:
 * Tcode Integer, adults, children and distance, total.
 * Public Functions:
 * AssignFare() which will calculate and assign the value to Total based on the following condition
 * For Adults : fare is Rs. 500 if Distance is >=1500. And fare get reduced by 25% if distance is <1500.
 * For children : fixed rate is Rs. 50. Find total fare.
 * Also write functions getdata() and display () to enter and display the values of private variables.
*/

#include <iostream>
#include <string.h>
#include "../../util/COLORS!.hpp"

using namespace std;

class Tour {
  private:
    int tCode; // Ticket Code
    int numAdults, numChildren;
    float distance;
    float totalFare = 0;

    const int childrenFare = 50;
    const int adultFare[2] = { 375, 500 }; // First value for distance <1500 and second for >= 1500

  public:
    Tour assignFare() {
      // Calculate children fare which is constant
      totalFare += childrenFare * numChildren;

      // Add adult fare
      totalFare += adultFare[distance >= 1500 ? 1 : 0] * numAdults;

      return *this;
    }

    Tour getData() {
      cout << "Enter Ticket Code(integer): " << ORANGE_NO_FLASH;
      cin >> tCode;
      cout << NC;

      cout << "Enter Number Of Adults: " << ORANGE_NO_FLASH;
      cin >> numAdults;
      cout << NC;

      cout << "Enter Number Of Children: " << ORANGE_NO_FLASH;
      cin >> numChildren;
      cout << NC;

      cout << "Enter Tour Distance(km): " << ORANGE_NO_FLASH;
      cin >> distance;
      cout << NC;

      return *this;
    }

    Tour display() {
      cout << "Ticket Code: " << ORANGE_NO_FLASH << tCode << NC << endl;
      cout << "Adults: " << ORANGE_NO_FLASH << numAdults << NC << endl;
      cout << "Children: " << ORANGE_NO_FLASH << numChildren << NC << endl;
      cout << "Distance: " << ORANGE_NO_FLASH << distance << NC << endl;
      cout << "Total Fare: " << ORANGE_NO_FLASH << totalFare << NC << endl;

      return *this;
    }
};

int main() {
  Tour t;
  t.getData().assignFare().display();

  return 0;
}
