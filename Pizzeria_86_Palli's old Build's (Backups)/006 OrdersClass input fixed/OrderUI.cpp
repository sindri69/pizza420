#include <iostream>
#include <fstream>
#include "MainUI.h"
#include "OrderUI.h"
#include "Pizza.h"
#include "myFunctions.h"
using namespace std;

/* �etta const value er mj�g mikilv�t! */
/* �egar fleiri values b�tast vi� Pizza.h �urfum vi� a� uppf�ra �essa t�lu */
/* Annars mun "See list of all Orders" ekki skila �llum listanum! */

const int numberOfValuesInPizzaClass = 8;

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

        /* Basic loop */
        /* Velur 1. fyrir a� b�ta vi� listann, */
        /* Velur 2. til a� sj� allan listan */
        /* Velur 3. til a� fara aftur � mainUI */

        cout << "Pizzeria_86_Programma (Orders)" << endl;
        cout << "1: Add Order" << endl;
        cout << "2: See list of all Orders" << endl;
        cout << "3: Return to Main" << endl;

        cin >> selection;

        if (selection == '1') { /*H�r erum vi� a� b�ta vi� PizzaListann */
            int choice;

            cout << "How many pizzas do you wish to add to the list? ";
            cin >> choice;

            for (int i = 0; i < choice; i++) {
                Pizza pizza;                             /* Kalla� � Pizza.h */
                pizza.setVerbose(true);                  /* Verbose l�tur aukatexta fylgja me� */
                cin >> pizza;                            /* B�tum vi� PizzaClassa */
                ofstream fout;                           /* ofstream b�tir vi� texta */
                fout.open("PizzaList.txt", ios::app);    /* opnum pizzalista textfilei�, "ios:app" l�tur okkur b�ta vi� listann � sta� �ess a� over-write-a hann */
                pizza.setVerbose(false);                 /* Viljum ekki f� aukatexta � filei� */
                fout << pizza;                           /* Prentum listann � skjali� */
                fout.close();                            /* Lokum pizzalista textfilei� */
            }
        }
        else if (selection == '2') {
            cout << "feature coming soonish" << endl;
        }
        else if (selection == '3') { /* �etta endar loopi� og sendir okkur aftur � mainUI */
            selection = 'q';
        }
    }
}
