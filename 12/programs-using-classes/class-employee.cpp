// Converted from programs_using_classes.docx

/**
 * Define a class Employee with the following specification:
 * Private Members:
 *  • Ename and Deptname of char.
 *  • Salary and bonus of type float.
 *  • Callbonus() function to calculate bonus given to an employee according to the following conditions:
 *    Deptname 		bonus
 *    Accounts		4%of salary
 *    HR 			5% of salary
 *    IT			3% of salary
 *    Marketing 		4% of salary
 *    For all others	 2% of salary
 * Public Members:
 *  • Constructor to initialize ename and deptname to NULL   and salary and bonus to 0.
 *  • A function read() to get from the user the details of employee and call function callbonus().
*/

#include <iostream>
#include <string.h>
#include "../util/COLORS!.hpp" // Terminal Colors

using namespace std;

#define numDepartments 5 // Number of departments

class Employee {
  private:
    const char deptNames[numDepartments][10] = {
      "accounts",
      "hr",
      "it",
      "marketing",
      "other"
    };

    const float deptBonuses[numDepartments] = { // In %age
      4, // 0th position in above array
      5, // 1st position in above array
      3,
      4,
      2
    };

    char eName[30]; // Employee Name
    char deptName[10]; // Department Name (cane be one of deptNames array)
    float salary, bonus;

    int calBonus() {
      for (int i = 0; i < numDepartments; i++) {
        if (strcmp(deptNames[i], deptName) == 0) { // Check department name agains the defined departments
          bonus = salary * deptBonuses[i] / 100;
          return bonus;
        }
      }
      // If the code didn't return and reached this point, it means that the dept was not found.
      cout << "Department Name Invalid";
      throw "Department Name Invalid";
      return 0;
    }

  public:
    Employee() {
      strcpy(eName, "NULL");
      strcpy(deptName, "NULL");

      bonus = 0;
      salary = 0;
    }

    Employee read() {
      cout << "Enter The Employee Name: " << ORANGE_NO_FLASH;
      cin >> eName;
      cout << NC;

      cout << "Department Names: \n";
      for (int i = 0; i < numDepartments; i++) cout << GREEN_NO_FLASH << deptNames[i] << ORANGE_NO_FLASH << "(" << deptBonuses[i] << "%)" << NC << " ";
      cout << endl;

      bool isDeptValid = false;
      while(!isDeptValid) {
        cout << "Type the department name(case sensitive): " << ORANGE_NO_FLASH;
        cin >> deptName;
        cout << NC;

        for (int i = 0; i < numDepartments; i++) if (strcmp(deptNames[i], deptName) == 0) {
          isDeptValid = true;
          break;
        }
      }

      cout << "Enter Salary(₹): " << ORANGE_NO_FLASH;
      cin >> salary;
      cout << NC;

      calBonus();
      return *this;
    }

    Employee display() {
      cout << "Employee Name: " << ORANGE_NO_FLASH << eName << NC << endl;
      cout << "Department Name: " << ORANGE_NO_FLASH << deptName << NC << endl;
      cout << "Salary: " << ORANGE_NO_FLASH << "₹" << bonus << NC << endl;
      cout << "Bonus: " << ORANGE_NO_FLASH << "₹" << bonus << NC << endl;

      return *this;
    }
};

int main() {
  Employee e1;
  e1.read().display();

  return 0;
}
