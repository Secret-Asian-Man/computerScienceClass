#ifndef CDACCOUNT_H
#define CDACCOUNT_H


class CDAccount
{
public:

    //constuctors
    CDAccount();
    CDAccount(double balance, double interest_rate, int term);

    //accessors
    double getBalance();
    double getInterest_rate();
    int getTerm();

    //mutators
    double setBalance(double input);
    double setInterest_rate(double input);
    int setTerm(int input);
    void setData(CDAccount &theAccount); //sets data for all 3 members (variables)

    //functions


private:
    double balance;
    double interest_rate;
    int term; //months until maturity


};

#endif // CDACCOUNT_H
