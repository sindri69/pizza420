#include "DrinkRepository.h"

DrinkRepository::DrinkRepository() { }

void DrinkRepository::make_drink(const Drink& drink) {
    ofstream fout;
    fout.open("drink.txt", ios::app);
    if (fout.is_open()) {
        fout << drink;
        fout.close();
    }
    else {
        cout << "Error! drink.txt is not open" << endl;
    }
}
