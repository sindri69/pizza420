#ifndef MAINUI_H
#define MAINUI_H

#include "Employee.h"
#include "EmployeeSERV.h"

#include "ReadFunctions.h" /// Functions that read from text files
#include "MyFunctions.h"  /// Other functions (some redundant)

#include <cstdlib> /// system("CLS");  It cleans our screen, making it more neat !
#include <iostream>
#include <fstream>

using namespace std;

class MainUI
{
    public:
        MainUI();

        void start_MainMenu();

    private:
        Employee create_employee();
        EmployeeSERV addemployee;
};

#endif // MAINUI_H
