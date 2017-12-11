#ifndef BASICREPOSITORY_H
#define BASICREPOSITORY_H

#include "Basic.h"
#include "BasicRepository.h"
#include <fstream>

class BasicRepository
{
    public:
        BasicRepository();

        void make_basic(const Basic& basic);
};

#endif // BASICREPOSITORY_H
