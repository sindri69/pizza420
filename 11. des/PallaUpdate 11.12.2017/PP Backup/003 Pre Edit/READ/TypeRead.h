#ifndef TYPEREAD_H
#define TYPEREAD_H

#include <iostream>
#include <fstream>
using namespace std;

class TypeRead /// Here we are getting information about/from the TypeList
{
    public:
        TypeRead();

        int get_NumberOfLines_type();                             /// Here we count the number of lines in the file
        bool fileNotEmpty_type();                                 /// Here we check if the file is empty
        string get_Line_type(int linenumber);                     /// Here we get a specific line from the file
        bool check_LineMatches_type(string line, int linenumber); /// Here we check if a specific line matches a line in the file
        bool check_TypeAlreadyExists_type(string name);           /// Here we see if a type already exists
};

#endif // TYPEREAD_H
