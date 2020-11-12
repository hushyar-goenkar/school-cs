// Converted from dynamic_mem.docx

#include <iostream>
using namespace std;

/**
 * Get the total of n different values.
 * Make an array of size n
 * n is dynamically given by user
 */

int main() {
	int n, sum = 0, per;

	cout << "How many values?: ";
	cin >> n;

	int *p = new int(n);

  cout << "Enter values: ";
	for (int i = 0; i < n; i++) cin >> p[i];

	for (int i = 0; i < n; i++) sum = sum +p[i];

	cout << "The total is " << sum << endl;

  return 0;
}
