// Converted from dynamic_mem.docx

#include <iostream>
using namespace std;

int main() {
	int n, m;

	cout << "Enter rows and cols: ";
	cin >> n >> m;

	int **a = new int*[n]; // Pointer of array of pointers

	for(int j = 0; j < n; j++) a[j] = new int[m];

	for (int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) cin >> a[i][j];
	}

	cout << "The entered matrix is: ";

	for (int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
