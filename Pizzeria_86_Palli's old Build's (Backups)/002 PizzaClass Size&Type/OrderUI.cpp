#include <iostream>
#include <fstream>
#include "MainUI.h"
#include "OrderUI.h"
#include "Pizza.h"
using namespace std;

OrderUI::OrderUI()
{
    //ctor
}

OrderUI::~OrderUI()
{
    //dtor
}

void OrderUI::start_orderUI() {

    char selection = '\0';

    while (selection != 'q') {

        cout << "Pizzeria_86_Programma (Orders)" << endl;
        cout << "1: Add Order" << endl;
        cout << "2: See list of all Orders" << endl;
        cout << "3: Return to Main" << endl;

        cin >> selection;

        if (selection == '1') {
            int choice;

            cout << "How many pizzas do you wish to add to the list? ";
            cin >> choice;

            for (int i = 0; i < choice; i++) {
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
        else if (selection == '2') {
            Pizza pizza;
            ifstream fin;
            fin.open("pizza_list.txt");

            if (fin.is_open()) {
                int number_of_lines = 0;
                std::string line;
                std::ifstream myfile("pizza_list.txt");

                while (std::getline(myfile, line))
                ++number_of_lines;

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
        else if (selection == '3') {
            selection = 'q';
        }
    }
}
