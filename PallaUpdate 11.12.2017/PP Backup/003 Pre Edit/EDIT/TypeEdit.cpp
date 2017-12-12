#include "TypeEdit.h"

TypeEdit::TypeEdit() { }

void TypeEdit::delete_type() { /// Here we open and close type-textFile without ios:app, which removes all lines in the file
    ofstream fout;
    fout.open ("type.txt");
    fout.close();
}

