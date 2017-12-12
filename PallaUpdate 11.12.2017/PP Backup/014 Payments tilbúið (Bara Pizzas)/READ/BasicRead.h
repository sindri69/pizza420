#ifndef BASICREAD_H
#define BASICREAD_H

#include<iostream>
#include<fstream>
using namespace std;

class BasicRead /// Here we are getting information about/from the BasicList
{
    public:
        BasicRead();

        int get_NumberOfLines();         /// Here we count the number of lines in the file
        bool fileNotEmpty();             /// Here we check if the file is empty
        string get_Line(int linenumber); /// Here we get a specific line from the file
};

#endif // BASICREAD_H
