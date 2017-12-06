#include <iostream>
#include <fstream>

using namespace std;

class DataClass {

private:
    int i;
    double d;
    string str;
    char c;

    bool verbose;

public:

    DataClass() {
        i = 0;
        d = 0.0;
        str = "";
        c = ' ';

        verbose = true;
    }

    void setVerbose(bool v) {
        verbose = v;
    }

    friend istream& operator >> (istream& in, DataClass& data) {

        if (data.verbose) {
            cout << "Enter integer: ";
        }
        in >> data.i;

        if (data.verbose) {
            cout << "Enter double: ";
        }
        in >> data.d;

        if (data.verbose) {
            cout << "Enter string: ";
        }
        in >> ws;
        getline(in,data.str);

        if (data.verbose) {
            cout << "Enter char: ";
        }
        in >> data.c;

        return in;
    }

    friend ostream& operator << (ostream& out, const DataClass& data) {

        if (data.verbose) {
            out << "Integer: ";
        }
        out << data.i << endl;

        if (data.verbose) {
            out << "Double : ";
        }
        out << data.d << endl;

        if (data.verbose) {
            out << "String : ";
        }
        out << data.str << endl;

        if (data.verbose) {
            out << "Char   : ";
        }
        out << data.c << endl;

        return out;
    }

};

int main()
{
    DataClass data1;

    data1.setVerbose(true);

    cin >> data1;

    ofstream fout;
    fout.open("text_file_DataClass.txt");

    data1.setVerbose(false);
    fout << data1;
    fout.close();

    DataClass data2;

    ifstream fin;
    fin.open("text_file_DataClass.txt");
    data2.setVerbose(false);
    if (fin.is_open()) {
        fin >> data2;
        fin.close();
    }
    else {
        cout << "Could not open file" << endl;
    }

    data2.setVerbose(true);
    cout << data2;

    return 0;
}
