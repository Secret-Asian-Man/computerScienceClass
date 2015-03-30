#include "rationalnumbers.h"
#include "Tools.h"
#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

/***********************************
 * Function:rationalNumbers
 * Purpose: default constructors
 * Parameters:
 * Returns:
 * Summary: sets numerator to 0 and denominator to 1
 * Notes:
 * ***********************************/
rationalNumbers::rationalNumbers():_numerator(0),_denominator(1)
{
    //blank
}

/***********************************
 * Function:rationalNumbers
 * Purpose: lets user start off with a ratio num/denom
 * Parameters:
 * Returns:
 * Summary:
 * Notes:
 * ***********************************/
rationalNumbers::rationalNumbers(int numerator,int denominator):_numerator(numerator),_denominator(denominator)
{
    //blank
}

/***********************************
 * Function:rationalNumbers
 * Purpose: lets user start off with a whole number
 * Parameters: a numerator number
 * Returns:
 * Summary:
 * Notes:
 * ***********************************/
rationalNumbers::rationalNumbers(int numerator):_numerator(numerator), _denominator(1)
{
    //blank
}

/***********************************
 * Function:
 * Purpose:
 * Parameters:
 * Returns:
 * Summary:
 * Notes:
 * ***********************************/
rationalNumbers::~rationalNumbers()
{

}

//accessors

/***********************************
 * Function:
 * Purpose:lets users have access to _numerator
 * Parameters:
 * Returns: _numerator
 * Summary:
 * Notes:
 * ***********************************/
int rationalNumbers::get_numberator()
{
    return _numerator;
}

/***********************************
 * Function:get_denominator
 * Purpose: lets users have access to denominator
 * Parameters:
 * Returns:_denominator
 * Summary:
 * Notes:
 * ***********************************/
int rationalNumbers::get_denominator()
{
    return _denominator;
}

//mutators

/***********************************
 * Function:setBoth
 * Purpose: sets both numerator and denominator
 * Parameters: 2 numbers
 * Returns:
 * Summary:
 * Notes:
 * ***********************************/
void rationalNumbers::setBoth(int numerator, int denominator)
{
    _numerator=numerator;
    _denominator=denominator;
}

/***********************************
 * Function:set_numerator
 * Purpose:sets numerator
 * Parameters:sets numerator to user input
 * Returns:a number
 * Summary:
 * Notes:
 * ***********************************/
void rationalNumbers::set_numerator(int number)
{
    _numerator=number;
}

/***********************************
 * Function:set_denominator
 * Purpose:sets denominator to user input
 * Parameters:a number
 * Returns:
 * Summary:
 * Notes:
 * ***********************************/
void rationalNumbers::set_denominator(int number)
{
    _denominator=number;
}

//functions

/***********************************
 * Function:print_numerator
 * Purpose:prints numerator
 * Parameters:
 * Returns:
 * Summary:
 * Notes:
 * ***********************************/
void rationalNumbers::print_numerator()
{
    cout<<_numerator;
}

/***********************************
 * Function:print_denominator
 * Purpose:prints denominator
 * Parameters:
 * Returns:
 * Summary:
 * Notes:
 * ***********************************/
void rationalNumbers::print_denominator()
{
    cout<<_denominator;
}

/***********************************
 * Function:printBoth
 * Purpose: prints num/denom
 * Parameters:
 * Returns:
 * Summary:
 * Notes:
 * ***********************************/
void rationalNumbers::printBoth()
{
    cout<<_numerator<<"/"<<_denominator;
}

/***********************************
 * Function:simplify
 * Purpose: simplifies the ratio
 * Parameters:
 * Returns:
 * Summary:
 * Notes:
 * ***********************************/
void rationalNumbers::simplify()
{
    int GCF=greatestCommonFactor(_numerator,_denominator);

    _numerator=_numerator/GCF;

    _denominator=_denominator/GCF;

}

/***********************************
 * Function:negate
 * Purpose: switches the sign on a number
 * Parameters:
 * Returns: a negated number
 * Summary:
 * Notes:
 * ***********************************/
rationalNumbers rationalNumbers::negate()
{
    return -1*_numerator;
}

/***********************************
 * Function:reciprocal
 * Purpose: flips the ratio upsidedown, if numerator isnt 0
 * Parameters:
 * Returns:
 * Summary: if the numerator isn't 0, the 2 variables swap places.
 * Notes:
 * ***********************************/
void rationalNumbers::reciprocal()
{
    if (_numerator!=0)
        swap(_numerator,_denominator);

    else
        cout<<"Error: Cannot divide by zero!"<<endl;
}

/***********************************
 * Function: +
 * Purpose: makes adding objects more intuative
 * Parameters: 2 objects
 * Returns: an object
 * Summary: Does the math using the numerator and denominator from 2 objects and saves the result in a 3rd object.
 *          Then simplifies and returns the 3rd object.
 * Notes:
 * ***********************************/
rationalNumbers operator +(const rationalNumbers &a, const rationalNumbers &b)
{
    rationalNumbers temp;

    temp._numerator=(a._numerator*b._denominator)+(b._numerator*a._denominator);
    temp._denominator=(a._denominator*b._denominator);

    temp.simplify();

    return temp;
}

/***********************************
 * Function: -
 * Purpose: makes adding objects more intuative
 * Parameters: 2 objects
 * Returns: an object
 * Summary: Does the math using the numerator and denominator from 2 objects and saves the result in a 3rd object.
 *          Then simplifies and returns the 3rd object.
 * Notes:
 * ***********************************/
rationalNumbers operator -(const rationalNumbers &a, const rationalNumbers &b)
{
    rationalNumbers temp;

    temp._numerator=(a._numerator*b._denominator)-(b._numerator*a._denominator);
    temp._denominator=(a._denominator*b._denominator);

    temp.simplify();

    return temp;

}

/***********************************
 * Function: *
 * Purpose: makes adding objects more intuative
 * Parameters: 2 objects
 * Returns: an object
 * Summary: Does the math using the numerator and denominator from 2 objects and saves the result in a 3rd object.
 *          Then simplifies and returns the 3rd object.
 * Notes:
 * ***********************************/
rationalNumbers operator *(const rationalNumbers &a, const rationalNumbers &b)
{
    rationalNumbers temp;

    temp._numerator=(a._numerator)*(b._numerator);
    temp._denominator=(a._denominator*b._denominator);

    temp.simplify();

    return temp;

}

/***********************************
 * Function: /
 * Purpose: makes adding objects more intuative
 * Parameters: 2 objects
 * Returns: an object
 * Summary: Does the math using the numerator and denominator from 2 objects and saves the result in a 3rd object.
 *          Then simplifies and returns the 3rd object.
 * Notes:
 * ***********************************/
rationalNumbers operator /(const rationalNumbers &a, const rationalNumbers &b)
{
    rationalNumbers temp;

    temp._numerator=(a._numerator)*(b._denominator);
    temp._denominator=(a._denominator*b._numerator);

    temp.simplify();

    return temp;

}

/***********************************
 * Function:ostream
 * Purpose:makes the cout operator more natural and clean looking
 * Parameters:a ostream, a class
 * Returns: a ostream(so you can chain more)
 * Summary:compiler grabs the data from either side of the <<, like so... cout<<class
 *         This function overloads the << operator so it will take a class and print out multiple things, in this case the numerator,
 *         a "/", and the denominator
 * Notes:
 * ***********************************/
ostream& operator << (ostream &outs, const rationalNumbers &ratio)
{
    outs << ratio._numerator << "/" << ratio._denominator;

    return outs; //if we don't return we cant chain like so: cout<<"blah"<<" hello"<<endl;
}

/***********************************
 * Function: istream
 * Purpose: makes the cin operator more natural and clean looking
 * Parameters: a istream and a class
 * Returns:a istream (so you can chain more)
 * Summary:compiler grabs the data from either side of the >>, like so... cin>>class
 *         This function overloads the >> operator so it will take a class and get input for more things, in this case numerator, a dummy, and denominator
 * Notes:
 * ***********************************/
istream& operator >> (istream &ins, rationalNumbers &ratio)
{
    char dummy;

    ins>>ratio._numerator;
    ins>>dummy;
    ins>>ratio._denominator;

    return ins;
}
