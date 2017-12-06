#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char input = '0';

    while (input != 'q') {

        cout << "r: Read" << endl;
        cout << "w: Write" << endl;
        cout << "q: Quit" << endl;
        cin >> input;

        if (input == 'w') {

            string str;
            int i;
            double d;

            cout << "Enter a string: ";
            cin >> str;
            cout << "Enter an integer: ";
            cin >> i;
            cout << "Enter a double: ";
            cin >> d;

            ofstream fout;
            fout.open("DataTextFile.txt", ios::app);
            fout << str << endl;
            fout << i << endl;
            fout << d << endl;
            fout.close();
        }
        else if (input == 'r') {

            string str;
            int i;
            double d;

            ifstream fin;
            fin.open("DataTextFile.txt");

            if (fin.is_open()) {
                while (!fin.eof()) { /* EndOfFile does not register, all values printed twice */
                    fin >> str;
                    fin >> i;
                    fin >> d;
                    cout << "String:  " << str << endl;
                    cout << "Integer: " << i << endl;
                    cout << "Double:  " <<d << endl;
                }
                fin.close();
            }
            else {
                cout << "File not open" << endl;
            }
        }
    }

    return 0;
}
