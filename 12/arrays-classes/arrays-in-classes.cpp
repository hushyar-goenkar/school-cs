// Converted from arrays_classes.docx
// Converted, fixed style, fixed errors

#include <iostream>
using namespace std;

class Student {
	int rollno, marks[6], total;
	char name[30];

	public:
		void getdata() {
			cout << "Enter the rollno and name";
			cin >> rollno >> name;
			cout << "Enter 6 subject marks";

			for(int i = 0; i < 6; i++) cin >> marks[i];
		}

		void display() {
			cout << "Rollno and name is " << rollno << name;
			cout << "The marks are ";

			int tot;
			for(int i = 0; i < 6; i++) {
				tot += marks[i];
				cout << "Total marks is " << tot;
			}
		}
};

void main() {
	Student s1, s2;
	s1.getdata();
	s2.getdata();
	s1.display();
	s2.display();
}