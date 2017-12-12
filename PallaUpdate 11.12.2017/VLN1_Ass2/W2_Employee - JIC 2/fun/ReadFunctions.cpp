#include "ReadFunctions.h"
#include "MyFunctions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

const int NUMBEROFVALUESINEMPLOYEE = 5;

ReadFunctions::ReadFunctions()
{
    //ctor
}

/// Here we check if a record already exists for given month year
bool ReadFunctions::does_old_employee_exist(string ssn, int month, int year) {
    MyFunctions myfun;
    bool ssnmatches = false;   /// We're checking if SSN, month and year ALL match an employee in the file
    bool monthmatches = false;
    bool yearmatches = false;
    string linefromfile;
    string smonth = myfun.convert_IntegerToString(month); /// We have to change month and year to string
    string syear = myfun.convert_IntegerToString(year);   /// Since we're comparing them to strings
    if (fileNotEmpty_employee()) { /// If the file is empty there won't be any matches, obviously
        int linecount = 1; /// We begin checking line 1
        for (int i = 0; i < (get_NumberOfLines_employee() / NUMBEROFVALUESINEMPLOYEE); i++) { /// For the number of employees on the file
            linecount++; /// we're not checking name
            if (check_LineMatches_employee(ssn,linecount)) {
                ssnmatches = true;
            }
            linecount++;
            linecount++; /// we're not checking salary
            if (check_LineMatches_employee(smonth,linecount)) {
                monthmatches = true;
            }
            linecount++;
            if (check_LineMatches_employee(syear,linecount)) {
                yearmatches = true;
            }
            linecount++;
            if (ssnmatches && monthmatches && yearmatches) { /// If SSN matches month and year we return true
                return true;
            }
            else { /// Else we continue checking
                ssnmatches = false;
                monthmatches = false;
                yearmatches = false;
            }
        }
    } /// If there are no matches, return false
    return false;
}

/// Here we're finding the employeeNUM
int ReadFunctions::find_employeeNUM(string ssn, int month, int year) {
    MyFunctions myfun;
    bool ssnmatches = false;
    bool monthmatches = false;
    bool yearmatches = false;
    string linefromfile;
    string smonth = myfun.convert_IntegerToString(month); /// We have to change month and year to string
    string syear = myfun.convert_IntegerToString(year);   /// Since we're comparing them to strings
    int linecount = 1;   /// We begin checking line 1
    int EmployeeNUM = 1; /// One loop for each employee
    for (int i = 0; i < (get_NumberOfLines_employee() / NUMBEROFVALUESINEMPLOYEE); i++) { /// For the number of employees on the file
            linecount++; /// we're not checking name
            if (check_LineMatches_employee(ssn,linecount)) {
                ssnmatches = true;
            }
            linecount++;
            linecount++; /// we're not checking salary
            if (check_LineMatches_employee(smonth,linecount)) {
                monthmatches = true;
            }
            linecount++;
            if (check_LineMatches_employee(syear,linecount)) {
                yearmatches = true;
            }
            linecount++;
            if (ssnmatches && monthmatches && yearmatches) { /// If SSN matches month and year we return true
                return EmployeeNUM;
            }
            else { /// Else we continue checking
                ssnmatches = false;
                monthmatches = false;
                yearmatches = false;
                EmployeeNUM++; /// on the the next employee !
            }
    }
    cout << "Error finding EmployeeNUM!" << endl;
    return 0; /// Since we have already checked that a employee does match, we should never not have a match here !
}

/// Here we remove the old employee log which is going to be replaced, new one goes to the end of the new file
void ReadFunctions::remove_old_employee(int employeeNUM) {
    vector<string> v;               /// This is the vector we're using
    string line;                    /// Lines from file
    ifstream fin ("employee.txt");
    if (fin.is_open()) {
        while (getline(fin,line)) {
            v.push_back(line);      /// Each line of the file becomes an element in the vector
        }
        fin.close();
    }
    else {
        cout << "File not open" << endl;
    }
    /// Employee 1 would have index {0,1,2,3,4} , Employ 2 would have index {5,6,7,8,9} etc.
    int empnum = ( (employeeNUM * 5) - 5);

    v.erase(v.begin() + empnum); /// It's enough to just replace the old employee info, the new employee info would be at the end of this vector BTW !
    v.erase(v.begin() + empnum); /// Each time the line is removed the index moves too so we don't need to change the index number
    v.erase(v.begin() + empnum);
    v.erase(v.begin() + empnum);
    v.erase(v.begin() + empnum);

    ofstream fout ("employee.txt"); /// Finally we overwrite the old file with the modified vector
    if (fout.is_open()) {
        for (unsigned int i = 0; i < v.size(); i++) {
            fout << v[i] << endl;
        }
        fout.close();
    }
    else {
        cout << "File not open" << endl;
    }
}

void ReadFunctions::read_raw_employee() {
    if (fileNotEmpty_employee()) {
        string line;
        ifstream fin ("employee.txt");
        if (fin.is_open()) {
            while (getline(fin,line)) {
                cout << line << endl;
            }
            fin.close();
        }
        else {
            cout << "File not open" << endl;
        }
    }
    else {
        cout << "File is empty" << endl;
    }
}

void ReadFunctions::read_fancy_employee() {
    if (fileNotEmpty_employee()) {
        int line = 1;
        for (int i = 0; i < (get_NumberOfLines_employee() / NUMBEROFVALUESINEMPLOYEE); i++) {
            string name = get_Line_employee(line);
            line++;
            string ssn = get_Line_employee(line);
            line++;
            string salary = get_Line_employee(line);
            line++;
            string month = get_Line_employee(line);
            line++;
            string year = get_Line_employee(line);
            line++;

            cout << "Name: " << name << "   SSN: " << ssn;
            cout << "   Salary: " << salary << "   ";

            if (month == "1") {
                cout << "January ";
            }
            else if (month == "2") {
                cout << "February ";
            }
            else if (month == "3") {
                cout << "March ";
            }
            else if (month == "4") {
                cout << "April ";
            }
            else if (month == "5") {
                cout << "May ";
            }
            else if (month == "6") {
                cout << "June ";
            }
            else if (month == "7") {
                cout << "July ";
            }
            else if (month == "8") {
                cout << "August ";
            }
            else if (month == "9") {
                cout << "September ";
            }
            else if (month == "10") {
                cout << "October ";
            }
            else if (month == "11") {
                cout << "November ";
            }
            else if (month == "12") {
                cout << "December ";
            }
            else {
                cout << "Error, month does not exist" << endl;
            }
            cout << year << endl << endl;
        }
    }
    else {
        cout << "File is empty" << endl;
    }
}

void ReadFunctions::delete_employee() {
    ofstream fout;
    fout.open ("employee.txt");
    fout.close();
}

string ReadFunctions::get_Line_employee(int linenumber) {
    ifstream fin ("employee.txt");
    string s = "";
    if (fin.is_open()) {
        for (int i = 1; i <= linenumber; i++) {
            getline(fin,s);
        }
        fin.close();
    }
    return s;
}


int ReadFunctions::get_NumberOfLines_employee() {
    int numberoflines = 0;
    string line;
    ifstream fin ("employee.txt");
    if (fin.is_open()) {
        while (getline(fin,line)) {
            ++numberoflines;
        }
        fin.close();
    }
    return numberoflines;
}


bool ReadFunctions::fileNotEmpty_employee() {
    if (get_NumberOfLines_employee() == 0) {
        return false;
    }
    return true;
}

bool ReadFunctions::check_LineMatches_employee(string line, int linenumber) {
    MyFunctions myfun;
    if (myfun.convert_StringToLowerCase(get_Line_employee(linenumber)) == myfun.convert_StringToLowerCase(line)) {
        return true;
    }
    return false;
}

