#include "TypeRepository.h"

TypeRepository::TypeRepository() { }

void TypeRepository::make_type(const Type& type) {
    ofstream fout;
    fout.open("type.txt", ios::app);
    if (fout.is_open()) {
        fout << type;
        fout.close();
    }
    else {
        cout << "Error! type.txt is not open" << endl;
    }
}
