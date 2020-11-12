// Converted from pract.txt

#include <iostream>
using namespace std;

/**
 * Reverse a given number
 * NOTE: THIS IS THE BOARD FORMAT. MAKE A CLASS AND DO EVERYTHING IN ITS CONSTRUCTOR.
 */

class Reverse {
	int m;
	public:
		Reverse() {
			cout << "Enter the number: ";
			cin >> m;

			int n = 0;
			while(m > 0) {
				n = n * 10 + m % 10;
				m = m / 10;
			}

			cout << "The reverse is: " << n << endl;
		}
};

int main() {
	Reverse rno;
  return 0;
}
