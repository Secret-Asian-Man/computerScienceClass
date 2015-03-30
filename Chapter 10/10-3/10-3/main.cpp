#include <iostream>
#include "cdaccount.h"

using namespace std;

int main()
{
    CDAccount myAccount;
    myAccount.setData(myAccount);

    double rateFraction=myAccount.getInterest_rate()/100.0;
    double interest=myAccount.getBalance()*rateFraction*(myAccount.getTerm()/12.0);

    myAccount.setBalance(myAccount.getBalance()+interest);

//    cout<<"balance: "<<myAccount.getBalance()<<endl;
//    cout<<"interest_rate: "<<myAccount.getInterest_rate()<<endl;
//    cout<<"term: "<<myAccount.getTerm()<<endl;

    cout<<"When your CD matures in "<<myAccount.getTerm()<<" month(s), "<<endl;
    cout<<"it will have a balance of $"<<myAccount.getBalance()<<endl;

}

