#ifndef TOPPINGEDIT_H
#define TOPPINGEDIT_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class ToppingEdit
{
    public:
        ToppingEdit();
        void deleteTopping();                   /// Here we open and close the topping file without ios::app, this removes all lines in the file
        void deleteTopping(int toppingNUM);     /// Here we delete a topping which matches the number
        void deleteTopping(string toppingNAME); /// Here we delete a topping which matches the name
};

#endif // TOPPINGEDIT_H
