#include "TypeRepository.h"

TypeRepository::TypeRepository()
{
    //ctor
}

void TypeRepository::make_type(const Type& type) {
    ofstream fout;
    fout.open("type.txt", ios::app);
    if (fout.is_open()) {
        fout << type;
        fout.close();
    }
    else {
        /// throw error
    }
}
