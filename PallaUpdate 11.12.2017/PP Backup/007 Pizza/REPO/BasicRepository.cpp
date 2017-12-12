#include "BasicRepository.h"

BasicRepository::BasicRepository() { }

void BasicRepository::make_basic(const Basic& basic) {
    ofstream fout;
    fout.open("basic.txt");
    if (fout.is_open()) {
        fout << basic;
        fout.close();
    }
    else {
        cout << "Error! basic.txt is not open" << endl;
    }
}
