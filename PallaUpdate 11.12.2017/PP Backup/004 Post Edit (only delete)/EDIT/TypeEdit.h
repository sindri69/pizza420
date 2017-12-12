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
        void delete_type();                /// Here we open and close the type file without ios::app, this removes all lines in the file
        void delete_type(int typeNUM);     /// Here we delete a type which matches the number
        void delete_type(string typeNAME); /// Here we delete a type which matches the name
};

#endif // TYPEEDIT_H
