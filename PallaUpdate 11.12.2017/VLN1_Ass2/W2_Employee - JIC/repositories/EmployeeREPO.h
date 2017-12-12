#ifndef EMPLOYEEREPO_H
#define EMPLOYEEREPO_H

#include "Employee.h"
#include "EmployeeREPO.h"
#include <fstream>

class EmployeeREPO
{
    public:
        EmployeeREPO();
        void add_employee(const Employee& employee);

    private:
};

#endif // EMPLOYEEREPO_H
