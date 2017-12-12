#ifndef TYPEMAKE_H
#define TYPEMAKE_H

#include "Type.h"
#include "TypeRepository.h"
#include "InvalidTypeNameBasicIsReservedException.h"
#include "InvalidTypeNameCustomIsReservedException.h"
#include "InvalidTypeNameNoAlphaException.h"
#include "InvalidTypeNameAlreadyTakenException.h"
#include "InvalidTypePriceException.h"

class TypeMake
{
    public:
        TypeMake();

        void make_type(const Type& type);

    private:
        TypeRepository type_repo;
        bool isValidTypeName(const Type& type);
        bool isValidTypePrice(const Type& type);
};

#endif // TYPEMAKE_H
