#ifndef EXTRAEDIT_H
#define EXTRAEDIT_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class ExtraEdit
{
    public:
        ExtraEdit();
        void deleteExtra();                 /// Here we open and close the extra file without ios::app, this removes all lines in the file
        void deleteExtra(int extraNUM);     /// Here we delete a extra which matches the number
        void deleteExtra(string extraNAME); /// Here we delete a extra which matches the name
};


#endif // EXTRAEDIT_H
