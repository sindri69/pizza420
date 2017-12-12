#ifndef EXTRAREAD_H
#define EXTRAREAD_H

#include <iostream>
#include <fstream>
using namespace std;

class ExtraRead /// Here we are getting information about/from the ExtraList
{
    public:
        ExtraRead();

        int get_NumberOfLines();                             /// Here we count the number of lines in the file
        bool fileNotEmpty();                                 /// Here we check if the file is empty
        string get_Line(int linenumber);                     /// Here we get a specific line from the file
        bool check_LineMatches(string line, int linenumber); /// Here we check if a specific line matches a line in the file
        bool check_ExtraAlreadyExists(string name);          /// Here we see if a extra already exists
        int find_extraNUM(string name);                      /// Here we are finding the number of extra this "extra-name" is
};

#endif // EXTRAREAD_H
