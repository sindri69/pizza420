#ifndef TOPPINGREAD_H
#define TOPPINGREAD_H

#include <iostream>
#include <fstream>
using namespace std;

class ToppingRead /// Here we are getting information about/from the ToppingList
{
    public:
        ToppingRead();

        int get_NumberOfLines();                             /// Here we count the number of lines in the file
        bool fileNotEmpty();                                 /// Here we check if the file is empty
        string get_Line(int linenumber);                     /// Here we get a specific line from the file
        bool check_LineMatches(string line, int linenumber); /// Here we check if a specific line matches a line in the file
        bool check_ToppingAlreadyExists(string name);        /// Here we see if a type already exists
        int find_toppingNUM(string name);                    /// Here we are finding the number of type this "type-name" is
};

#endif // TOPPINGREAD_H
