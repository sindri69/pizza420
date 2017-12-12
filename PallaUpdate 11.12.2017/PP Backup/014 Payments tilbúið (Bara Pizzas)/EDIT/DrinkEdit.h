#ifndef DRINKEDIT_H
#define DRINKEDIT_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class DrinkEdit
{
    public:
        DrinkEdit();
        void deleteDrink();                 /// Here we open and close the drink file without ios::app, this removes all lines in the file
        void deleteDrink(int drinkNUM);     /// Here we delete a drink which matches the number
        void deleteDrink(string drinkNAME); /// Here we delete a drink which matches the name
};

#endif // DRINKEDIT_H
