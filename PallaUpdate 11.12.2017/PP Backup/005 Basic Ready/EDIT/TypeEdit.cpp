#include "TypeEdit.h"
#include "TypeRead.h"
#include "UserInputUI.h"
#include "ConstValues.h"

TypeEdit::TypeEdit() { }

void TypeEdit::delete_type() { /// Here we open and close the type file without ios::app, this removes all lines in the file
    ofstream fout;
    fout.open ("type.txt");
    fout.close();
}
void TypeEdit::delete_type(int typeNUM) { /// Here we delete a type which matches the number
    TypeRead tr;
    if (tr.fileNotEmpty_type()) {
        vector<string> v;           /// This is the vector we're using
        string line;                /// Lines from file
        ifstream fin ("type.txt");
        while (getline(fin,line)) { /// Each line in the file becomes an element in the vector
            v.push_back(line);
        }
        fin.close();

        int type_num = ( (typeNUM * NUMBEROFVALUESINTYPE) - NUMBEROFVALUESINTYPE); /// Type 1 would have index {0,1,2,3} , Type 2 would have index {4,5,6,7} etc.

        for (int i = 0; i < NUMBEROFVALUESINTYPE; i++) { /// We remove all the elements of this typeNUM
            v.erase(v.begin() + type_num);
        }

        ofstream fout ("type.txt"); /// Finally we overwrite the old file with the modified vector
        for (unsigned int i = 0; i < v.size(); i++) {
            fout << v[i] << endl;
        }
        fout.close();
    }
    else {
        cout << "File is empty" << endl;
    }
}
void TypeEdit::delete_type(string typeNAME) { /// Here we delete a type which matches the name
    TypeRead tr;                              /// We do this by finding the typeNUM end letting the other function do the actual removal
    UserInputUI ui;
    string line;
    bool namefound = false;
    int linecount = 1, loopcount = 1;
    for (int i = 0; i < (tr.get_NumberOfLines_type() / NUMBEROFVALUESINTYPE); i++) { /// We need to find the typeNUM that matches this typeNAME
        if (ui.convert_StringToLowerCase(tr.get_Line_type(linecount)) == ui.convert_StringToLowerCase(typeNAME)) {
            namefound = true;
            break;
        }
        linecount = linecount + NUMBEROFVALUESINTYPE;
        loopcount++;
    }
    if (namefound) { /// Here we're just making sure that it only deletes a type if it is a match
        delete_type(loopcount);
    }
}




