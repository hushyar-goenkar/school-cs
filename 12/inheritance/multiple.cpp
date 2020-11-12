// Converted from inheritance.docx

#include <iostream>
#include <string>
#include "../util/COLORS!.hpp"
using namespace std;

/**
 * MULTI: Derived class inherits from multiple base classes
 */

/**
 * EXAMPLE:
 */

class Student {
  public:
    int rollNo;
    string Sname; // student name

    Student(int rn, string sn) {
      rollNo = rn;
      Sname = sn;
    }

  protected:
    Student display() {
      cout << "Roll No: " << ORANGE_UNDER << rollNo << NC << endl;
      cout << "Name of Student: " << ORANGE_UNDER << Sname << NC << endl;

      return *this;
    }
};

class Teacher {
  public:
    string Tname; // teacher name

    Teacher(string tn) {
      Tname = tn;
    }

  protected:
    Teacher display() {
      cout << "Teacher Name: " << ORANGE_UNDER << Tname << NC << endl;

      return *this;
    }
};

/**
 * CONSTRUCTOR: Both constructors can be extended by separating with a comma ,
 * see below
 */

class Course: public Teacher, public Student {
  public:
    int courseId;
    string courseName;

    /**
     * @param cid Course ID
     * @param cn Course Name
     * @param rn Student Roll No
     * @param sn Student Name
     * @param tn Teacher Name
     */
    Course(
      int cid,
      string cn,
      int rn,
      string sn,
      string tn
    ): Student(rn, sn), Teacher(tn) {
      courseId = cid;
      courseName = cn;
    }

    Course display() {
      cout << "Course Id: " << ORANGE_UNDER << courseId << NC << endl;
      cout << "Course Name: " << ORANGE_UNDER << courseName << NC << endl;
      Student::display();
      Teacher::display();

      return *this;
    }
};

int main() {
  Course C1(87539319, "Computer Science", 1729, "Ramanujan", "Hardy");

  C1.display();

  return 0;
}
