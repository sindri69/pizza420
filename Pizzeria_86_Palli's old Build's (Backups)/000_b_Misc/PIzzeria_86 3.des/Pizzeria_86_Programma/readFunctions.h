#ifndef READFUNCTIONS_H
#define READFUNCTIONS_H
#include <string>
using namespace std;

class readFunctions
{
    public:
        readFunctions();
        virtual ~readFunctions();

        /* Functions that read from "PizzasList.txt" */
        bool fileExists_PizzaList();            /* Check if the file exists */
        int get_NumberOfLines_PizzaList();      /* Count the number of lines */
        string get_Line_PizzaList(int line);    /* Get line number "line" */
        void read_PizzaList();                  /* Read all the lines in the file */
        void read_PizzaListFancy();

        /* Functions that read from "TypesList.txt" */
        bool fileExists_TypesList();            /* Check if the file exists */
        int get_NumberOfLines_TypesList();      /* Count the number of lines */
        string get_Line_TypesList(int line);    /* Get line number "line" */
        void read_TypesList();                  /* Read all the lines in the file */

        /* Functions that read from "ToppingsList.txt" */
        bool fileExists_ToppingsList();         /* Check if the file exists */
        int get_NumberOfLines_ToppingsList();   /* Count the number of lines */
        string get_Line_ToppingsList(int line); /* Get line number "line" */
        void read_ToppingsList();               /* Read all the lines in the file */

        /* Functions that read from "DrinksList.txt" */
        bool fileExists_DrinksList();           /* Check if the file exists */
        int get_NumberOfLines_DrinksList();     /* Count the number of lines */
        string get_Line_DrinksList(int line);   /* Get line number "line" */
        void read_DrinksList();                 /* Read all the lines in the file */

        /* Functions that read from "ExtrasList.txt" */
        bool fileExists_ExtrasList();           /* Check if the file exists */
        int get_NumberOfLines_ExtrasList();     /* Count the number of lines */
        string get_Line_ExtrasList(int line);   /* Get line number "line" */
        void read_ExtrasList();                 /* Read all the lines in the file */

    protected:

    private:
};

#endif // READFUNCTIONS_H
