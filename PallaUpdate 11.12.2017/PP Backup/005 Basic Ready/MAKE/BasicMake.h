#ifndef BASICMAKE_H
#define BASICMAKE_H

#include "Basic.h"
#include "BasicRepository.h"
#include "InvalidBasicPriceException.h"

class BasicMake
{
    public:
        BasicMake();

        void make_basic(const Basic& basic);

    private:
        BasicRepository basic_repo;
        bool isValidBasicPrice(const Basic& basic);
};

#endif // BASICMAKE_H
