/***********************************
 * Project: dateAndMonthClass Chapter 10, Question 6.
 * Author: David Wu
 * Purpose:finds what month it is, based on a number input or 3 letters.
 * Notes:
 * ***********************************/
#include <iostream>
#include "month.h"

using namespace std;

int main()
{
    month theMonth(15);
    month anotherMonth;

    cout<<"Testing constructors: "<<endl;
    theMonth.printMonth(); //tests the constructors
    cout<<endl<<endl;


    cout<<"Testing user entering invalid month \"jzp\": "<<endl;
    theMonth.setCurrentMonth('j','z','p'); //month 0 cuz not found
    theMonth.printMonth(); //tests the setcurrentMonth
    cout<<endl<<endl;

    cout<<"Testing user entering invalid month \"25\": "<<endl;
    theMonth.setCurrentMonth(25); //month 0 cuz not found
    theMonth.printMonth(); //tests the setcurrentMonth
    cout<<endl<<endl;

    cout<<"Testing entering \"jul\": "<<endl;
    theMonth.setCurrentMonth('j','u','l');
    theMonth.printMonth(); //tests the setcurrentMonth
    cout<<endl<<endl;


    cout<<"Testing default constructor: "<<endl;
    anotherMonth.printMonth(); //tests the anotherMonth
    cout<<endl<<endl;

    cout<<"Testing set month using number: "<<endl;
    anotherMonth.setCurrentMonth(8);
    anotherMonth.printMonth(); //tests the anotherMonth
    cout<<endl<<endl;


}

