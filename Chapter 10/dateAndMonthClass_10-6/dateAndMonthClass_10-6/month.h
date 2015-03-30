#ifndef MONTH_H
#define MONTH_H
#include <iostream>
using namespace std;

class month
{
public:
    //constructors
    month();
    month(char letter1, char letter2, char letter3);
    month(int monthNumber);

    //deconstructor
    ~month();

    //accessors
    int getMonthNumber(); //accessor for the number of the month
    string getMonthName(); //converts a number to a month name



    //mutators
    void setCurrentMonth(int monthNumber);
    void setCurrentMonth(char letter1, char letter2, char letter3);


    //functions
    void printMonth();
    int findMonth(string month);



private:
    int currentMonth; //1 for jan, 2 for feb, etc...
    const string months[12] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};

};

#endif // MONTH_H
