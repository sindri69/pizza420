#include "EmployeeRepository.h"


EmployeeRepository::EmployeeRepository()
{
    //ctor
}


void EmployeeRepository::make_employee(const Employee& employee){
    ofstream fout;
    fout.open("employee.txt", ios::app);
    if(fout.is_open()) {
        fout << employee;
        fout.close();
    }
    else {
        cout << "Error!employee.txt is not open" << endl;
    }
}

