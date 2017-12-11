#ifndef BASICREAD_H
#define BASICREAD_H

#include<iostream>
#include<fstream>
using namespace std;

class BasicRead /// Here we are getting information about/from the BasicList
{
    public:
        BasicRead();

        int get_NumberOfLines_basic();         /// Here we count the number of lines in the file
        bool fileNotEmpty_basic();             /// Here we check if the file is empty
        string get_Line_basic(int linenumber); /// Here we get a specific line from the file
};

#endif // BASICREAD_H
