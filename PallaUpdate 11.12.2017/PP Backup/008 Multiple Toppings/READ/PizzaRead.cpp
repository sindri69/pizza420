#include "PizzaRead.h"
#include "ConstValues.h"
#include "UserInputUI.h"

PizzaRead::PizzaRead() { }

int PizzaRead::get_NumberOfLines() { /// Here we count the number of lines in the file
    int numberoflines = 0;
    string line;
    ifstream fin ("pizza.txt");
    if (fin.is_open()) {
        while (getline(fin,line)) { /// We use a simple while loop to count the number of lines
            ++numberoflines;
        }
        fin.close();
    }
    return numberoflines;
}
bool PizzaRead::fileNotEmpty() { /// Here we check if the file is empty
    if (get_NumberOfLines() == 0) {
        return false;
    }
    return true;
}
string PizzaRead::get_Line(int linenumber) { /// Here we get a specific line from the file
    ifstream fin ("pizza.txt");
    string s = "";
    if (fin.is_open()) {
        for (int i = 1; i <= linenumber; i++) { /// We loop our way to the correct line, then return it
            getline(fin,s);
        }
        fin.close();
    }
    return s;
}
bool PizzaRead::check_LineMatches(string line, int linenumber) { /// Here we check if a specific line matches a line in the file
    UserInputUI ui;
    if (ui.convert_StringToLowerCase(get_Line(linenumber)) == ui.convert_StringToLowerCase(line)) { /// We use other functions to see if the lines match
        return true;                                                                                /// Don't have to worry about caps lock either
    }
    return false;
}
bool PizzaRead::check_PizzaIDAlreadyExists(string pID) { /// Here we see if a pizzaID already exists
    if (fileNotEmpty()) {
        ifstream fin ("pizza.txt");
        int linenum = 1;
        for (int i = 0; i < (get_NumberOfLines() / NUMBEROFVALUESINPIZZA); i++) { /// For the number of pizzas ...
            if (check_LineMatches(pID,linenum)) {
                fin.close();
                return true;
            }
            linenum = linenum + NUMBEROFVALUESINPIZZA;
        }
        fin.close();
    }
    return false;
}
