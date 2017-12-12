#ifndef EXTRAREPOSITORY_H
#define EXTRAREPOSITORY_H

#include "Extra.h"
#include "ExtraRepository.h"
#include <fstream>

class ExtraRepository
{
    public:
        ExtraRepository();
        void make_extra(const Extra& extra);
};

#endif // EXTRAREPOSITORY_H
