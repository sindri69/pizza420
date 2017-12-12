#ifndef TYPEUI_H
#define TYPEUI_H

#include "Type.h"
#include "TypeMake.h"

#include <cstdlib> /// system("CLS");  It cleans our screen, making it more neat !
#include <iostream>
using namespace std;

class TypeUI
{
    public:
        TypeUI();
        void start_TypesMenu();

    private:
        Type create_type();
        TypeMake maketype;
};

#endif // TYPEUI_H
