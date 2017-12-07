#ifndef EMPLOYEEREPOSITORY_H
#define EMPLOYEEREPOSITORY_H

#include "Employee.h"
#include "EmployeeRepository.h"
#include <fstream>


class EmployeeRepository
{
    public:
        EmployeeRepository();
        void make_employee(const Employee& employee);

    private:
};

#endif // EMPLOYEEREPOSITORY_H
