#ifndef DRINKREAD_H
#define DRINKREAD_H

#include <iostream>
#include <fstream>
using namespace std;

class DrinkRead /// Here we are getting information about/from the DrinkList
{
    public:
        DrinkRead();

        int get_NumberOfLines();                             /// Here we count the number of lines in the file
        bool fileNotEmpty();                                 /// Here we check if the file is empty
        string get_Line(int linenumber);                     /// Here we get a specific line from the file
        bool check_LineMatches(string line, int linenumber); /// Here we check if a specific line matches a line in the file
        bool check_DrinkAlreadyExists(string name);          /// Here we see if a drink already exists
        int find_drinkNUM(string name);                      /// Here we are finding the number of drink this "drink-name" is
};

#endif // DRINKREAD_H
