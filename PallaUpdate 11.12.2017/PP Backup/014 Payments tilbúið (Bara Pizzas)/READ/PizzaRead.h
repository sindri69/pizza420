#ifndef PIZZAREAD_H
#define PIZZAREAD_H

#include <iostream>
#include <fstream>
using namespace std;

class PizzaRead /// Here we are getting information about/from the PizzaList
{
    public:
        PizzaRead();

        int get_NumberOfLines();                             /// Here we count the number of lines in the file
        bool fileNotEmpty();                                 /// Here we check if the file is empty
        string get_Line(int linenumber);                     /// Here we get a specific line from the file
        bool check_LineMatches(string line, int linenumber); /// Here we check if a specific line matches a line in the file
        bool check_PizzaIDAlreadyExists(string pID);         /// Here we see if a pizza has an ID identical to an already existing one
        double getTotalPrice(string pID);                    /// Here we calculate the total price for all the pizzas matching the pID
};

#endif // PIZZAREAD_H
