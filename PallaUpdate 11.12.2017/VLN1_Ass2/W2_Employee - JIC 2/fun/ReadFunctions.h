#ifndef READFUNCTIONS_H
#define READFUNCTIONS_H
#include <string>
#include <vector>
#include "MyFunctions.h"
using namespace std;

class ReadFunctions /// Functions involving files,
{
    public:
        ReadFunctions();

        /// Here we check if a record already exists for given month year
        bool does_old_employee_exist(string ssn, int month, int year); /// We're only supposed to check if a SSN matches month and year

        /// Here we're finding the employeeNUM
        int find_employeeNUM(string ssn, int month, int year);

        /// Here we remove the old employee log which is has been replaced, new log goes to bottom of the list tho
        void remove_old_employee(int employeeNUM);


        /// Here we read all the lines in the file
        void read_raw_employee();

        /// Here we read from the files in an organized manner
        void read_fancy_employee();

        /// Here we delete all the lines in the file
        void delete_employee();

        /// Here we get a specific line from the file
        string get_Line_employee(int linenumber);

        /// Here we count the number of lines in the file
        int get_NumberOfLines_employee();

        /// Here we check if the file is empty
        bool fileNotEmpty_employee();

        /// Here we check if a specific line matches a line in the file
        bool check_LineMatches_employee(string line, int linenumber);

    private:
};

#endif // READFUNCTIONS_H
