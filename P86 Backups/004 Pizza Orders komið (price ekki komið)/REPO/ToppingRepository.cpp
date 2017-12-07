#include "ToppingRepository.h"

ToppingRepository::ToppingRepository()
{
    //ctor
}

void ToppingRepository::make_topping(const Topping& topping) {
    ofstream fout;
    fout.open("topping.txt", ios::app);
    if (fout.is_open()) {
        fout << topping;
        fout.close();
    }
    else {
        cout << "Error! topping.txt is not open" << endl;
    }
}
