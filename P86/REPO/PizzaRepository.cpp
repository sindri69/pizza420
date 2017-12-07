#include "PizzaRepository.h"

PizzaRepository::PizzaRepository()
{
    //ctor
}

void PizzaRepository::make_pizza(const Pizza& pizza) {
    ofstream fout;
    fout.open("pizza.txt", ios::app);
    if (fout.is_open()) {
        fout << pizza;
        fout.close();
    }
    else {
        cout << "Error! pizza.txt is not open" << endl;
    }
}
