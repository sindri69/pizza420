#include "InvalidTypePriceException.h"

InvalidTypePriceException::InvalidTypePriceException(string message)
{
    this->message = message;
}

string InvalidTypePriceException::getMessage()
{
    return this->message;
}
