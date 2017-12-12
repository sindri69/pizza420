#include "ExtraEdit.h"
#include "ExtraRead.h"
#include "UserInputUI.h"
#include "ConstValues.h"

ExtraEdit::ExtraEdit() { }

void ExtraEdit::deleteExtra() { /// Here we open and close the extra file without ios::app, this removes all lines in the file
    ofstream fout;
    fout.open ("extra.txt");
    fout.close();
}
void ExtraEdit::deleteExtra(int extraNUM) { /// Here we delete a extra which matches the number
    ExtraRead er;
    if (er.fileNotEmpty()) {
        vector<string> v;           /// This is the vector we're using
        string line;                /// Lines from file
        ifstream fin ("extra.txt");
        while (getline(fin,line)) { /// Each line in the file becomes an element in the vector
            v.push_back(line);
        }
        fin.close();

        int extra_num = ( (extraNUM * NUMBEROFVALUESINEXTRA) - NUMBEROFVALUESINEXTRA); /// Extra 1 would have index {0,1,2,3} , Extra 2 would have index {4,5,6,7} etc.

        for (int i = 0; i < NUMBEROFVALUESINEXTRA; i++) { /// We remove all the elements of this extraNUM
            v.erase(v.begin() + extra_num);
        }

        ofstream fout ("extra.txt"); /// Finally we overwrite the old file with the modified vector
        for (unsigned int i = 0; i < v.size(); i++) {
            fout << v[i] << endl;
        }
        fout.close();
    }
    else {
        cout << "File is empty" << endl;
    }
}
void ExtraEdit::deleteExtra(string extraNAME) { /// Here we delete a extra which matches the name
    ExtraRead er;                               /// We do this by finding the drinkNUM end letting the other function do the actual removal
    UserInputUI ui;
    string line;
    bool namefound = false;
    int linecount = 1, loopcount = 1;
    for (int i = 0; i < (er.get_NumberOfLines() / NUMBEROFVALUESINEXTRA); i++) { /// We need to find the extraNUM that matches this extraNAME
        if (ui.convert_StringToLowerCase(er.get_Line(linecount)) == ui.convert_StringToLowerCase(extraNAME)) {
            namefound = true;
            break;
        }
        linecount = linecount + NUMBEROFVALUESINEXTRA;
        loopcount++;
    }
    if (namefound) { /// Here we're just making sure that it only deletes an extra if it is a match
        deleteExtra(loopcount);
    }
}




