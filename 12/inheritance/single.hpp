// Converted from single_inheritance.docx

/**
 * SINGLE: A class inherits from a single base class.
 * Derived class: The class which inherits
 * Base class: The class which is inherited
 */

#include <iostream>
#include <string.h>
using namespace std;

class Base {
  private:
    int a;

  protected:
    int b;

  public:
    int c;

    void getData() {
      cout << "Enter three numbers: ";
      cin >> a >> b >> c;
    }

    int getA() {
      return a;
    }
};

/**
 * PUBLIC: Public data members of base class become public in derived class
 * Protected remain protected
 * Private is private so not inherited
 * Need to use setters and getters eg: getA to get and set the private variables.
 */
class PublicDerived: public Base {
  int d, sum;
  public:
    void getD() {
      cout << "Enter something: ";
      cin >> d;
    }

    void disp() {
      cout << "d: " << d << " Sum: " << sum;
    }

    void calc() {
      sum = getA() // Used a getter since a is private
        + b + c;
    }
};

/**
 * PRIVATE: Public and protected data members of base class are private in derived class
 */

class PrivateDerived: private Base {
  // Everything is same except that whatever is derived will become private and can't be accessed if this derived class is rederived
  int d, sum;
  public:
    void getD() {
      cout << "Enter something: ";
      cin >> d;
    }

    void disp() {
      cout << "d: " << d << " Sum: " << sum;
    }

    void calc() {
      sum = getA() // Used a getter since a is private
        + b + c;
    }
};

/**
 * PROTECTED: Similar but protected and public both become protected in derived class
 */

/** USING CONSTRUCTORS:
 * Constructor of base class can be extended
 * No matter the access level of inheritance
 * The base class constructor is called first, then derived class.
 */

class StudentInfo {
  protected:
    int rollNo;
    char name[20];

  public:
    StudentInfo(int r, char n[20]) {
      rollNo = r;
      strcpy(name, n);
    }
};

/**
 * DESTRUCTOR: The derived class destructor will be called first then the base class.
 */

/** PUBLIC EXAMPLE: */
class Marks: public StudentInfo {
  float cs, english, maths, total;

  public:
    Marks(float c, float e, float m, int r, char n[20]): StudentInfo(r, n) {
      cs = c;
      english = e;
      maths = m;
    }

    Marks calc() {
      total = cs + english + maths;

      return *this;
    }

    Marks display() {
      cout << "Roll No: " << rollNo << endl;
      cout << "Total: " << total << endl;

      return *this;
    }
};
