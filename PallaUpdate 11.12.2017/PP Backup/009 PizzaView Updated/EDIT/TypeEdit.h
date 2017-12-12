#ifndef TYPEEDIT_H
#define TYPEEDIT_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class TypeEdit
{
    public:
        TypeEdit();
        void deleteType();                /// Here we open and close the type file without ios::app, this removes all lines in the file
        void deleteType(int typeNUM);     /// Here we delete a type which matches the number
        void deleteType(string typeNAME); /// Here we delete a type which matches the name
};

#endif // TYPEEDIT_H
