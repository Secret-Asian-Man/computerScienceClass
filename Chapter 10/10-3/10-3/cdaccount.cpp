#include "cdaccount.h"
#include <iostream>
using namespace std;



//constructors
CDAccount::CDAccount()
{
    balance=0;
    interest_rate=0;
    term=0;
}

CDAccount::CDAccount(double Balance, double Interest_rate, int Term)
{
    balance=Balance;
    interest_rate=Interest_rate;
    term=Term;
}


//accessors
double CDAccount::getBalance()
{
    return balance;
}

double CDAccount::getInterest_rate()
{
    return interest_rate;
}

int CDAccount::getTerm()
{
    return  term;
}



//mutators
double CDAccount::setBalance(double input)
{
    balance=input;
}

double CDAccount::setInterest_rate(double input)
{
    interest_rate=input;
}

int CDAccount::setTerm(int input)
{
    term=input;
}


//functions
void CDAccount::setData(CDAccount &theAccount)
{
    cout<<"Enter account balance: ";
    cin>> theAccount.balance;

    cout<<"Enter account interest rate: ";
    cin>> theAccount.interest_rate;

    cout<<"Enter number of months until maturity (must be at or under 12 months): ";
    cin>> theAccount.term;

}
