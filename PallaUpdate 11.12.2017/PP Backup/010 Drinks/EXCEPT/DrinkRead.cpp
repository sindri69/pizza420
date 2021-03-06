#include "DrinkRead.h"
#include "ConstValues.h"
#include "UserInputUI.h"

DrinkRead::DrinkRead() { }

int DrinkRead::get_NumberOfLines() { /// Here we count the number of lines in the file
    int numberoflines = 0;
    string line;
    ifstream fin ("drink.txt");
    if (fin.is_open()) {
        while (getline(fin,line)) { /// We use a simple while loop to count the number of lines
            ++numberoflines;
        }
        fin.close();
    }
    return numberoflines;
}
bool DrinkRead::fileNotEmpty() { /// Here we check if the file is empty
    if (get_NumberOfLines() == 0) {
        return false;
    }
    return true;
}
string DrinkRead::get_Line(int linenumber) { /// Here we get a specific line from the file
    ifstream fin ("drink.txt");
    string s = "";
    if (fin.is_open()) {
        for (int i = 1; i <= linenumber; i++) { /// We loop our way to the correct line, then return it
            getline(fin,s);
        }
        fin.close();
    }
    return s;
}
bool DrinkRead::check_LineMatches(string line, int linenumber) { /// Here we check if a specific line matches a line in the file
    UserInputUI ui;
    if (ui.convert_StringToLowerCase(get_Line(linenumber)) == ui.convert_StringToLowerCase(line)) { /// We use other functions to see if the lines match
        return true;                                                                                     /// Don't have to worry about caps lock either
    }
    return false;
}
bool DrinkRead::check_DrinkAlreadyExists(string name) { /// Here we see if a drink already exists
    if (fileNotEmpty()) {
        ifstream fin ("drink.txt");
        int linenum = 1;
        for (int i = 0; i < (get_NumberOfLines() / NUMBEROFVALUESINDRINK); i++) { /// For the number of drinks ...
            if (check_LineMatches(name,linenum)) {
                fin.close();
                return true;
            }
            linenum = linenum + NUMBEROFVALUESINDRINK;
        }
        fin.close();
    }
    return false;
}
int DrinkRead::find_drinkNUM(string name) { /// Here we are finding the number of drink this "drink-name" is
    int linecount = 1, drinkNUM = 1;
    for (int i = 0; i < (get_NumberOfLines() / NUMBEROFVALUESINDRINK); i++) { /// For the number of drinks ...
            if (check_LineMatches(name,linecount)) { /// We are checking lines {1,5,9,13 ... etc}
                return drinkNUM;
            }
            linecount = linecount + NUMBEROFVALUESINDRINK; /// For each loop we jump a few lines
            drinkNUM = drinkNUM + 1;                        /// For each loop the TypeNUM changes
    }
    cout << "Error finding DrinkNUM!" << endl;
    return 0; /// Since we have already checked that a drink does match, there should always be a match !
}
