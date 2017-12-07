#include "Employee.h"
#include <string>

Employee::Employee(string name, string kennitala, double salary, int month, int year)
{
    this -> name = name;
    this -> kennitala = kennitala;
    this -> salary = salary;
    this -> month = month;
    this -> year = year;
}

string Employee::get_name() const{
        return this ->name;
}
string Employee::get_kennitala() const{
        return this ->kennitala;
}
double Employee::get_salary() const{
        return this->salary;
}
int Employee::get_month() const{
        return this->month;
}
int Employee::get_year() const{
        return this->year;
}

ostream& operator << (ostream& out, const Employee& employee){
    out << employee.name << endl;
    out << employee.kennitala << endl;
    out << employee.salary << endl;
    out << employee.month << endl;
    out << employee.year << endl;
    return out;
}

