// Converted from dynamic_mem.docx

#include <iostream>
#include <string>

using namespace std;

/**
 * Calculate total of n subjects
 * n is dynamic
 */

class Student {
	int n, *p;

	public:
		Student getData() {
			cout << "How many subjects?: ";
			cin >> n;

			p = new int(n);

			cout << "Enter the "<< n << " marks: ";
			for(int i = 0; i < n; i++) cin >> p[i];

	 		int total = 0;
			for(int i = 0; i < n; i++) total += p[i];

			cout << "Total: " << total << endl;

      return *this;
		}

		Student display() {
      cout << "Marks: ";
			for(int i = 0; i < n; i++) cout << p[i];

      return *this;
		}
};

int main() {
	Student S;
	S.getData().display();

  return 0;
}
