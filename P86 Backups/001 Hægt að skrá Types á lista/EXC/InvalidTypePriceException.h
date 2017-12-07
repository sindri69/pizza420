#ifndef INVALIDTYPEPRICEEXCEPTION_H
#define INVALIDTYPEPRICEEXCEPTION_H

#include <string>
using namespace std;

class InvalidTypePriceException
{
    public:
        InvalidTypePriceException(string message);
        string getMessage();

    private:
        string message;
};

#endif // INVALIDTYPEPRICEEXCEPTION_H
