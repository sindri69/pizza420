#include <iostream>
#include <UI.h>

using namespace std;

int main()
{
    UI::main_menu();
}


























/*
Practical course 1
week 2 assignment - Employee’s monthly salary
You are to create a program using a 3 layered architecture. You should use the following
directory/folder structure for your classes
● Model classes should reside in a folder called models
● UI classes should reside in a folder called UI
● Service classes should reside in a folder called services
● Repository classes should reside in a folder called repositories
The program should hold information about employee salary records.
A single employee salary record has the following properties
● The name of the employee
● The employee's social security number (SSN, kennitala)
● The salary for a given month
● The month (can be stored as an integer)
● The year (can be stored as an integer)

NOTE:​ ​Records about employee salaries can be stored in a text file or a binary file.
An employee can have many records in the datastore (text or binary file).

A user should be able to
● Add a salary record
● Get all salary records for a given SSN
● Get a total Salary for a given year and a given SSN
● Get the name of the employee with the highest total salary for a given year
However, an employee may not have multiple records for the same month. If a record for
employee with SSN 1234567890 is added for february 2017 but there is already a record for
that month, then the existing record should be overwritten with the new one.

NOTE:​ ​Here are some validation issues you need to keep in mind. If any of these validations
state that a given property is invalid an exception should be thrown.
● An employee’s name may only contain letters and it may contain more than a single
word
● An employee’s SSN should be of length 10 and should only hold numeric values
● The salary cannot be any number, you should validate that it is a legitimate number
● The month and year should be validated, that is, there are only 12 months in the year
and it is only the year 2017.
○ A record for august 2021 is invalid
● Validate that a file is definately open

Remember to consider what is the right place for these operations and remember that the kind
of exception matters. InvalidMonthException and InvalidYearException is not the same thing!
If the project has many types of Exceptions it is common to create a directory/folder for the
exception classes. It is important that when an exception is thrown that the program does not
crash so you will have to use try catch blocks in the appropriate places.
It is important in this assignment to use the proper project structure and place classes where
they belong!
The design of the user interface is completely up to you but remember that the UI should
contain minimal logic!
*/
