#include "EmployeeREPO.h"

EmployeeREPO::EmployeeREPO()
{
    //ctor
}

void EmployeeREPO::add_employee(const Employee& employee) {
    ofstream fout;
    fout.open("employee.txt", ios::app);
    if (fout.is_open()) {
        fout << employee;
        fout.close();
    }
    else {
        cout << "Error! employee.txt is not open" << endl;
    }
}
