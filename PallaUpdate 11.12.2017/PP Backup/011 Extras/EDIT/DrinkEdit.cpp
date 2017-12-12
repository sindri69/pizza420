#include "DrinkEdit.h"
#include "DrinkRead.h"
#include "UserInputUI.h"
#include "ConstValues.h"

DrinkEdit::DrinkEdit() { }

void DrinkEdit::deleteDrink() { /// Here we open and close the drink file without ios::app, this removes all lines in the file
    ofstream fout;
    fout.open ("drink.txt");
    fout.close();
}
void DrinkEdit::deleteDrink(int drinkNUM) { /// Here we delete a drink which matches the number
    DrinkRead dr;
    if (dr.fileNotEmpty()) {
        vector<string> v;           /// This is the vector we're using
        string line;                /// Lines from file
        ifstream fin ("drink.txt");
        while (getline(fin,line)) { /// Each line in the file becomes an element in the vector
            v.push_back(line);
        }
        fin.close();

        int drink_num = ( (drinkNUM * NUMBEROFVALUESINDRINK) - NUMBEROFVALUESINDRINK); /// Drink 1 would have index {0,1,2,3} , Drink 2 would have index {4,5,6,7} etc.

        for (int i = 0; i < NUMBEROFVALUESINDRINK; i++) { /// We remove all the elements of this drinkNUM
            v.erase(v.begin() + drink_num);
        }

        ofstream fout ("drink.txt"); /// Finally we overwrite the old file with the modified vector
        for (unsigned int i = 0; i < v.size(); i++) {
            fout << v[i] << endl;
        }
        fout.close();
    }
    else {
        cout << "File is empty" << endl;
    }
}
void DrinkEdit::deleteDrink(string drinkNAME) { /// Here we delete a drink which matches the name
    DrinkRead dr;                               /// We do this by finding the drinkNUM end letting the other function do the actual removal
    UserInputUI ui;
    string line;
    bool namefound = false;
    int linecount = 1, loopcount = 1;
    for (int i = 0; i < (dr.get_NumberOfLines() / NUMBEROFVALUESINDRINK); i++) { /// We need to find the drinkNUM that matches this drinkNAME
        if (ui.convert_StringToLowerCase(dr.get_Line(linecount)) == ui.convert_StringToLowerCase(drinkNAME)) {
            namefound = true;
            break;
        }
        linecount = linecount + NUMBEROFVALUESINDRINK;
        loopcount++;
    }
    if (namefound) { /// Here we're just making sure that it only deletes a drink if it is a match
        deleteDrink(loopcount);
    }
}




