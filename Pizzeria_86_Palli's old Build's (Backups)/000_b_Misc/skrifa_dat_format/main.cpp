#include <iostream>
#include <fstream>
using namespace std;

// Svona skrifar madur og les gögn i binary skrá.

class DataClass {

    private:
        int i;
        double d;
        char str[16];
        char c;

        bool verbose;
    public:
        DataClass() {
            i = 0;
            d = 0.0;
            str[0] = '\0';
            c = ' ';
            verbose = true;

        }

        void setVerbose(bool v) {
            verbose = v;
    }
        friend istream& operator >> (istream& in, DataClass& data) {

            if(data.verbose) {
                cout << "Enter integer:  ";
            }
            in >> data.i;

            if(data.verbose){
            cout << "Enter real number: ";
            }
            in >> data.d;


            if(data.verbose) {
            cout << "Enter string:   ";
            }
             in >> data.str;

            if (data.verbose) {
            cout << "Enter character:    ";
            }
            in >> data.c;
            return in;
        }

        friend ostream& operator << (ostream& out, const DataClass& data) {

            if(data.verbose) {
                out << "Integer: ";
            }
            out << data.i << endl;

            if(data.verbose) {
                out << "Real number: ";
            }
            out << data.d << endl;

            if (data.verbose) {
                out << "String: ";
            }
            out << data.str << endl;

            if(data.verbose){
                out << "Character: ";
            }
            out << data.c << endl;

            return out;
        }

};

int main()
{
    DataClass data1;



    cin >> data1;

    ofstream fout;
    fout.open("binary_file_DataClass.dat", ios::binary|ios::app);

    fout.write((char*)(&data1), sizeof(DataClass));

    fout.close();


    DataClass data2;

    ifstream fin;
    fin.open("binary_file_DataClass.dat", ios::binary);



    if(fin.is_open()) {
        fin.seekg(0, fin.end);
        int recordCount = fin.tellg() / sizeof(DataClass);
        fin.seekg(0,fin.beg);

        for(int i = 0; i < recordCount; i++) {
            fin.read((char*)(&data2), sizeof(DataClass));
            cout << data2 << endl;
        }
    }
    else {
        cout << "Could not open file" << endl;
    }
    fin.close();



    return 0;
}
