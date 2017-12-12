#include "BasicRead.h"

BasicRead::BasicRead() { }

int BasicRead::get_NumberOfLines_basic() { /// Here we count the number of lines in the file
    int numberoflines = 0;
    string line;
    ifstream fin ("basic.txt");
    if (fin.is_open()) {
        while (getline(fin,line)) {
            ++numberoflines;
        }
        fin.close();
    }
    return numberoflines;
}
bool BasicRead::fileNotEmpty_basic() { /// Here we check if the file is empty
    if (get_NumberOfLines_basic() == 0) {
        return false;
    }
    return true;
}
string BasicRead::get_Line_basic(int linenumber) { /// Here we get a specific line from the file
    ifstream fin ("basic.txt");
    string s = "";
    if (fin.is_open()) {
        for (int i = 1; i <= linenumber; i++) {
            getline(fin,s);
        }
        fin.close();
    }
    return s;
}
