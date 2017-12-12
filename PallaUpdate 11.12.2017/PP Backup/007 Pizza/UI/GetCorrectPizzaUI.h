#ifndef GETCORRECTPIZZAUI_H
#define GETCORRECTPIZZAUI_H

#include <iostream>
using namespace std;

class GetCorrectPizzaUI
{
    public:
        GetCorrectPizzaUI();

        /// Here we make sure the user creates a correct pizza
        string getCorrectID();
        string getCorrectSize();
        string getCorrectType();
        string getCorrectTopping(string ptype);
        double getCorrectPrice(string psize, string ptype, string ptopping);
};

#endif // GETCORRECTPIZZAUI_H
