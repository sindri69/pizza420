#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class AdminTypes {
private:
    string a_types;
    double a_price;
    bool verbose;
public:
    AdminTypes() {
        a_types = "";
        a_price = 0.0;
        verbose = true;
    }
    void setTypes(string s) {
        a_types = s;
    }
    void setPrice(double p) {
        a_price = p;
    }
    void setVerbose(bool v) {
        verbose = v;
    }
    string getTypes() {
        return a_types;
    }
    double getPrice() {
        return a_price;
    }
    bool getVerbose() {
        return verbose;
    }

    friend istream& operator >> (istream& in, AdminTypes& admintypes) {

        if (admintypes.verbose) {
            cout << "Enter type: ";
        }
        in >> ws;
        getline (in, admintypes.a_types);

        if (admintypes.verbose) {
            cout << "Enter price: ";
        }
        in >> admintypes.a_price;

        return in;
    }

    friend ostream& operator << (ostream& out, const AdminTypes& admintypes) {

        if (admintypes.verbose) {
            cout << admintypes.a_types << " (Price: $" << admintypes.a_price << ")" << endl;
        }
        else {
            out << admintypes.a_types << endl;
            out << admintypes.a_price << endl;
        }

        return out;
    }

};

int main() /* AdminTypesUI */
{
    char selection = '\0';

    while (selection != 'q') {

        cout << "Pizzeria_86_Programma (Administrator / Types) " << endl;
        cout << "1: Create new Types-List (replaces old one)" << endl;
        cout << "2: Add toppings to Types-List" << endl;
        cout << "3: Edit current Types-List" << endl;
        cout << "4: See current Types-List" << endl;
        cout << "5: Return to Main" << endl;

        cin >> selection;

        if (selection == '1') {
            int choice;

            cout << "How many types do you want to add? ";
            cin >> choice;

            ofstream tempfout;
            tempfout.open("AdminTypesList.txt");
            tempfout.close();

            for (int i = 0; i < choice; i++) {
                AdminTypes admintypes;
                admintypes.setVerbose(true);
                cin >> admintypes;
                ofstream fout;
                fout.open("AdminTypesList.txt", ios::app);
                admintypes.setVerbose(false);
                fout << admintypes;
                fout.close();
            }

        }
        else if (selection == '2') {
            int choice;

            cout << "How many types do you want to add? ";
            cin >> choice;

            for (int i = 0; i < choice; i++) {
                AdminTypes admintypes;
                admintypes.setVerbose(true);
                cin >> admintypes;
                ofstream fout;
                fout.open("AdminTypesList.txt", ios::app);
                admintypes.setVerbose(false);
                fout << admintypes;
                fout.close();
            }
        }
        else if (selection == '3') {
            cout << "Feature not available (in development)" << endl;
        }
        else if (selection == '4') {
            AdminTypes admintypes;
            ifstream fin;
            fin.open("AdminTypesList.txt");

            if (fin.is_open()) {
                int number_of_lines = 0;
                string line;
                ifstream myfile("AdminTypesList.txt");

                while (getline(myfile, line)) {
                    ++number_of_lines;
                }

                for (int i = 0; i < (number_of_lines / 2); i++) {
                    admintypes.setVerbose(false);
                    fin >> admintypes;
                    admintypes.setVerbose(true);
                    cout << admintypes;
                }
        }
        else {
            cout << "Could not find types list" << endl;
        }
        }
        else if (selection == '5') {
            selection = 'q';
        }
    }
}
