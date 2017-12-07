#ifndef INVALIDTYPENAMEEXCEPTION_H
#define INVALIDTYPENAMEEXCEPTION_H

#include <string>
using namespace std;

class InvalidTypeNameException
{
    public:
        InvalidTypeNameException(string message);
        string getMessage();

    private:
        string message;
};

#endif // INVALIDTYPENAMEEXCEPTION_H
