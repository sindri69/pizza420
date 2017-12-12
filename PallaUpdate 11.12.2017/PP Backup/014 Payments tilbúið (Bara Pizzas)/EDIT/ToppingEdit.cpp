#include "ToppingEdit.h"
#include "ToppingRead.h"
#include "UserInputUI.h"
#include "ConstValues.h"

ToppingEdit::ToppingEdit() { }

void ToppingEdit::deleteTopping() { /// Here we open and close the topping file without ios::app, this removes all lines in the file
    ofstream fout;
    fout.open ("topping.txt");
    fout.close();
}
void ToppingEdit::deleteTopping(int toppingNUM) { /// Here we delete a topping which matches the number
    ToppingRead tr;
    if (tr.fileNotEmpty()) {
        vector<string> v;           /// This is the vector we're using
        string line;                /// Lines from file
        ifstream fin ("topping.txt");
        while (getline(fin,line)) { /// Each line in the file becomes an element in the vector
            v.push_back(line);
        }
        fin.close();

        int topping_num = ( (toppingNUM * NUMBEROFVALUESINTOPPING) - NUMBEROFVALUESINTOPPING); /// Topping 1 would have index {0,1,2,3} , Topping 2 would have index {4,5,6,7} etc.

        for (int i = 0; i < NUMBEROFVALUESINTYPE; i++) { /// We remove all the elements of this toppingNUM
            v.erase(v.begin() + topping_num);
        }

        ofstream fout ("topping.txt"); /// Finally we overwrite the old file with the modified vector
        for (unsigned int i = 0; i < v.size(); i++) {
            fout << v[i] << endl;
        }
        fout.close();
    }
    else {
        cout << "File is empty" << endl;
    }
}
void ToppingEdit::deleteTopping(string toppingNAME) { /// Here we delete a topping which matches the name
    ToppingRead tr;                                   /// We do this by finding the toppingNUM end letting the other function do the actual removal
    UserInputUI ui;
    string line;
    bool namefound = false;
    int linecount = 1, loopcount = 1;
    for (int i = 0; i < (tr.get_NumberOfLines() / NUMBEROFVALUESINTOPPING); i++) { /// We need to find the toppingNUM that matches this toppingNAME
        if (ui.convert_StringToLowerCase(tr.get_Line(linecount)) == ui.convert_StringToLowerCase(toppingNAME)) {
            namefound = true;
            break;
        }
        linecount = linecount + NUMBEROFVALUESINTOPPING;
        loopcount++;
    }
    if (namefound) { /// Here we're just making sure that it only deletes a topping if it is a match
        deleteTopping(loopcount);
    }
}




