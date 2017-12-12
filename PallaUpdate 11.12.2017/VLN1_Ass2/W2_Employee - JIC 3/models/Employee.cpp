#include "Employee.h"

Employee::Employee(string name, string ssn, double salary, int month, int year) {
    this->name = name;
    this->ssn = ssn;
    this->salary = salary;
    this->month = month;
    this->year = year;
}

string Employee::get_name() const {
    return this->name;
}
string Employee::get_ssn() const {
    return this->ssn;
}
double Employee::get_salary() const {
    return this->salary;
}
int Employee::get_month() const {
    return this->month;
}
int Employee::get_year() const {
    return this->year;
}

ostream& operator << (ostream& out, const Employee& employee) {
    out << employee.name << endl;
    out << employee.ssn << endl;
    out << employee.salary << endl;
    out << employee.month << endl;
    out << employee.year << endl;

    return out;
}
