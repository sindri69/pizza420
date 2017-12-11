#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
using namespace std;

class Employee
{
    public:
        Employee(string name, string ssn, double salary, int month, int year);

        string get_name() const;
        string get_ssn() const;
        double get_salary() const;
        int get_month() const;
        int get_year() const;

        friend ostream& operator << (ostream& out, const Employee& employee);

    private:
        string name;
        string ssn;
        double salary;
        int month;
        int year;
};

#endif // EMPLOYEE_H
