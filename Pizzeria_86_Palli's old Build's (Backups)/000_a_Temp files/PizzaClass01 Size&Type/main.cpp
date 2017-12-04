#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Pizza {
    private:
        string p_size;
        string p_type;
        bool verbose;
    public:
        Pizza() {
            p_size = "L";
            p_type = "Margherita";
            verbose = true;
        }
        void setVerbose(bool v) {
            verbose = v;
        }
        friend istream& operator >> (istream& in, Pizza& pizza) {
            if (pizza.verbose) {
                cout << "Enter size: ";
            }
            in >> ws;
            getline (in, pizza.p_size);

            if (pizza.verbose) {
                cout << "Enter type: ";
            }
            in >> ws;
            getline (in, pizza.p_type);

            return in;
        }
        friend ostream& operator << (ostream& out, const Pizza& pizza) {

            if (pizza.verbose) {
                cout << "Size = " << pizza.p_size << ", Type = " << pizza.p_type << endl;
            }
            else {
                out << pizza.p_size << endl;
                out << pizza.p_type << endl;
            }

            return out;
        }
};

int main()
{
    int i_choice;
    string choice;

    cout << "Hello human, would you like to add a pizza to the list? ";
    cin >> choice;

    if (choice == "yes" || choice == "Yes" || choice == "YES" || choice == "y" || choice == "Y") {

        cout << "How many pizzas do you wish to add to the list? ";
        cin >> i_choice;

        for (int i = 0; i < i_choice; i++) {
            Pizza pizza;
            pizza.setVerbose(true);
            cin >> pizza;
            ofstream fout;
            fout.open("pizza_list.txt", ios::app);
            pizza.setVerbose(false);
            fout << pizza;
            fout.close();
        }
    }

    cout << "Would you like to see the complete list of heroes? ";
    cin >> choice;

    if (choice == "yes" || choice == "Yes" || choice == "YES" || choice == "y" || choice == "Y") {

        Pizza pizza;
        ifstream fin;
        fin.open("pizza_list.txt");

        if (fin.is_open()) {
            int number_of_lines = 0;
            string line;
            ifstream myfile("pizza_list.txt");

            while (getline(myfile, line)) {
                ++number_of_lines;
            }

            for (int i = 0; i < (number_of_lines / 2); i++) {
                pizza.setVerbose(false);
                fin >> pizza;
                pizza.setVerbose(true);
                cout << pizza;
            }
        }
        else {
            cout << "Could not find pizza list" << endl;
        }
    }

    return 0;
}
