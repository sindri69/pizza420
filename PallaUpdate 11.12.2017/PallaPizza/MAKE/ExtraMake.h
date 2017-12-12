#ifndef EXTRAMAKE_H
#define EXTRAMAKE_H

#include "Extra.h"
#include "ExtraRepository.h"
#include "InvalidExtraNameNoAlphaException.h"
#include "InvalidExtraNameAlreadyTakenException.h"
#include "InvalidExtraPriceException.h"

class ExtraMake
{
    public:
        ExtraMake();

        void make_extra(const Extra& extra);

    private:
        ExtraRepository extra_repo;
        bool isValidExtraName(const Extra& extra);
        bool isValidExtraPrice(const Extra& extra);
};

#endif // EXTRAMAKE_H
