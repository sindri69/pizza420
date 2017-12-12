#ifndef PIZZAEDIT_H
#define PIZZAEDIT_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class PizzaEdit
{
    public:
        PizzaEdit();

        void deletePizza();

        void replaceLine(string newline, int oldlinenum);

        void payforPizza(string pID);
};

#endif // PIZZAEDIT_H
