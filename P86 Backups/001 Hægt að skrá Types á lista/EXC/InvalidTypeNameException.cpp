#include "InvalidTypeNameException.h"

InvalidTypeNameException::InvalidTypeNameException(string message)
{
    this->message = message;
}

string InvalidTypeNameException::getMessage()
{
    return this->message;
}
