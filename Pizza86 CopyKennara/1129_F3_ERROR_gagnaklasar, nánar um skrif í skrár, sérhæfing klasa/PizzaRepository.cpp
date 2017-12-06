#include "PizzaRepository.h"
#include "Pizza.h"
#include <fstream>
using namespace std;

PizzaRepository::PizzaRepository()
{
    //ctor
}

PizzaRepository::~PizzaRepository()
{
    //dtor
}

void PizzaRepository::storePizza(const Pizza& pizza) {

    ofstream fout;
    fout.open("pizzas.txt");

    fout << pizza;

    fout.close();
}

Pizza PizzaRepository::retrievePizza() {

    ifstream fin;
    fin.open("pizzas.txt");

    Pizza pizza;
    fin >> pizza;

    fin.close();

    return pizza;
}
