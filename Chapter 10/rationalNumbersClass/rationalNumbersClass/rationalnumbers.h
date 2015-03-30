#ifndef RATIONALNUMBERS_H
#define RATIONALNUMBERS_H
#include <iostream>

using namespace std;

class rationalNumbers
{
public:
    //constructors
    rationalNumbers();
    rationalNumbers(int numerator,int denominator);
    rationalNumbers(int numerator);

    //deconstructor
    ~rationalNumbers();

    //accessors
    int get_numberator();
    int get_denominator();

    //mutators
    void setBoth(int numerator, int denominator);
    void set_numerator(int number);
    void set_denominator(int number);

    //functions
    void simplify();
    void reciprocal();
    rationalNumbers negate();

    void print_numerator();
    void print_denominator();
    void printBoth();

    friend rationalNumbers operator + (const rationalNumbers &a, const rationalNumbers &b);
    friend rationalNumbers operator - (const rationalNumbers &a, const rationalNumbers &b);
    friend rationalNumbers operator * (const rationalNumbers &a, const rationalNumbers &b);
    friend rationalNumbers operator / (const rationalNumbers &a, const rationalNumbers &b);

    friend ostream& operator << (ostream &outs, const rationalNumbers &ratio);
    friend istream& operator >> (istream &outs, rationalNumbers &ratio);





private:
    int _numerator;
    int _denominator;
};

#endif // RATIONALNUMBERS_H
