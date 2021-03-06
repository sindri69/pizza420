#include "TypeRead.h"
#include "UserInputUI.h"

const int NUMBEROFVALUESINTYPE = 4; /// { name, price of large, price of medium, price of small }

TypeRead::TypeRead() { }

int TypeRead::get_NumberOfLines_type() { /// Here we count the number of lines in the file
    int numberoflines = 0;
    string line;
    ifstream fin ("type.txt");
    if (fin.is_open()) {
        while (getline(fin,line)) { /// We use a simple while loop to count the number of lines
            ++numberoflines;
        }
        fin.close();
    }
    return numberoflines;
}
bool TypeRead::fileNotEmpty_type() { /// Here we check if the file is empty
    if (get_NumberOfLines_type() == 0) {
        return false;
    }
    return true;
}
string TypeRead::get_Line_type(int linenumber) { /// Here we get a specific line from the file
    ifstream fin ("type.txt");
    string s = "";
    if (fin.is_open()) {
        for (int i = 1; i <= linenumber; i++) { /// We loop our way to the correct line, then return it
            getline(fin,s);
        }
        fin.close();
    }
    return s;
}
bool TypeRead::check_LineMatches_type(string line, int linenumber) { /// Here we check if a specific line matches a line in the file
    UserInputUI ui;
    if (ui.convert_StringToLowerCase(get_Line_type(linenumber)) == ui.convert_StringToLowerCase(line)) { /// We use other functions to see if the lines match
        return true;                                                                                     /// Don't have to worry about caps lock either
    }
    return false;
}
bool TypeRead::check_TypeAlreadyExists_type(string name) { /// Here we see if a type already exists
    if (fileNotEmpty_type()) {
        ifstream fin ("type.txt");
        int linenum = 1;
        for (int i = 0; i < (get_NumberOfLines_type() / NUMBEROFVALUESINTYPE); i++) { /// For the number of types ...
            if (check_LineMatches_type(name,linenum)) {
                fin.close();
                return true;
            }
            linenum = linenum + NUMBEROFVALUESINTYPE;
        }
        fin.close();
    }
    return false;
}
