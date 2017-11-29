#include <iostream>
#include <fstream>
using namespace std;

class DataClass {

    private:
        int i;
        double d;
        string str;
        char c;
    public:
        DataClass() {
            i = 0;
            d = 0.0;
            str = "";
            c = ' ';

        }

        friend istream& operator >> (istream& in, DataClass& data) {

            cout << "Enter integer: ";
            in >> data.i;

            cout << "Enter real number:";
            in >> data.d;

            cout << "Enter string: ";
            in >> data.str;

            cout << "Enter character: ";
            in >> data.c;
            return in;
        }

        friend ostream& operator << (ostream& out, const DataClass& data) {

            out << "Integer: " << data.i << endl;
            out << "Real number: " << data.d << endl;
            out << "String: " << data.str << endl;
            out << "Character: " << data.c << endl;
            return out;
        }

};

int main()
{
    DataClass data1;

    cin >> data1;

    ofstream fout;
    fout.open("text_file_DataClass.txt");

    fout << data1;
    fout.close();

    DataClass data2;

    ifstream fin;
    fin.open("text_file_DataClass.txt");

    if(fin.is_open()) {
        fin >> data2;


    }
    else {

        cout << "Could not open file" << endl;
    }

    cout << data2;

    return 0;
}
