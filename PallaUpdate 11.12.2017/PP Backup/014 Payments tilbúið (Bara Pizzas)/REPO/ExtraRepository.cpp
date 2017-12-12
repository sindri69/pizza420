#include "ExtraRepository.h"

ExtraRepository::ExtraRepository() { }

void ExtraRepository::make_extra(const Extra& extra) {
    ofstream fout;
    fout.open("extra.txt", ios::app);
    if (fout.is_open()) {
        fout << extra;
        fout.close();
    }
    else {
        cout << "Error! extra.txt is not open" << endl;
    }
}
