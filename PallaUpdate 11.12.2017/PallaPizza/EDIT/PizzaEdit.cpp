#include "PizzaEdit.h"
#include "PizzaRead.h"
#include "UserInputUI.h"
#include "ConstValues.h"

PizzaEdit::PizzaEdit() { }

void PizzaEdit::deletePizza() { /// Here we open and close the type file without ios::app, this removes all lines in the file
    ofstream fout;
    fout.open ("pizza.txt");
    fout.close();
}
void PizzaEdit::replaceLine(string newline, int oldlinenum) {
    int index = oldlinenum - 1;
    vector <string> v;
    string line;                /// Lines from file
    ifstream fin ("pizza.txt");
    while (getline(fin,line)) { /// Each line in the file becomes an element in the vector
        v.push_back(line);
    }
    fin.close();

    v.erase(v.begin() + index);
    v.insert(v.begin() + index,newline);

    ofstream fout ("pizza.txt"); /// Finally we overwrite the old file with the modified vector
    for (unsigned int i = 0; i < v.size(); i++) {
        fout << v[i] << endl;
    }
    fout.close();
}
void PizzaEdit::payforPizza(string pID) {
    PizzaRead pr;
    UserInputUI ui;
    int linecount = 1;
    for (int i = 0; i < (pr.get_NumberOfLines() / NUMBEROFVALUESINPIZZA); i++) {
        if (ui.convert_StringToLowerCase(pID) == ui.convert_StringToLowerCase(pr.get_Line(linecount))) {
            replaceLine("1", linecount + 5);
        }
        linecount = linecount + NUMBEROFVALUESINPIZZA;
    }
}
