// Converted from arrays_classes.docx

/**
 * Write a program to create a class employee with variables empid, ename and array of salary with size 5.
 * Create array of object and find the average salary of total salary of employees.
 */
# include <iostream>
using namespace std;

class Employee {
    int empid;
    char ename [30];
    int salary [5];
public:
    void getdata () {
        cout << "Please enter the employee ID";
        cin >> empid;
        cout << "Please enter the name of the employee";
        cin >> ename;
        cout << "Please enter the salaries with its components";
        for (int i = 0; i < 5; i ++) {cin >> salary[i];}
    }
    int calc_salary () {
        int net_salary = 0;

        for (int i = 0; i < 5 ; i ++) {
            net_salary = net_salary+
             salary [i];
                }
        return net_salary;
   }
};

int main  () {
    Employee e[5];
    int sum = 0;
    for (int
         i = 0; i < 5; i ++) {

        e[i].getdata();
        sum = sum + e[i].calc_salary();

    }
    cout << "Your company needs to pay the employees "<<sum<< " and to me, double of that";


}

