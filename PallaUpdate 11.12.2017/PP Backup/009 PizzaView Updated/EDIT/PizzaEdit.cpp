#include "PizzaEdit.h"

PizzaEdit::PizzaEdit() { }

void PizzaEdit::deletePizza() { /// Here we open and close the type file without ios::app, this removes all lines in the file
    ofstream fout;
    fout.open ("pizza.txt");
    fout.close();
}
