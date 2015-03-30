#include "token.h"


/***********************************
* Function:default constructor
* Purpose:
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
Token::Token()
{
    stringClass initialize;

    _token=initialize;
    _type=4;
}


/***********************************
* Function: constructor
* Purpose: cosntructs the class with a stringClass object and a int type
* Parameters:stringClass object, integer representing the type
* Returns:
* Summary:
* Notes:
************************************/
Token::Token(stringClass s, int type)
{
    _token=s;
    _type=type;
}


/***********************************
* Function: destructor
* Purpose:
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
Token::~Token()
{

}

/***********************************
 * Function:getType
 * Purpose:accessor for the _type
 * Parameters:
 * Returns:
 * Summary:
 * Notes:
 ************************************/
int& Token::getType()
{
    return _type;
}

/***********************************
* Function:getTokenString
* Purpose: accessor for the stringClass _token
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
stringClass& Token::getTokenString()
{
    return _token;
}

/***********************************
* Function:set_type
* Purpose: sets the type to user specified
* Parameters: a number
* Returns:
* Summary:
* Notes:
************************************/
void Token::set_type(int number)
{
    _type=number;
}

/***********************************
* Function:set_token
* Purpose: sets the _token to user specified
* Parameters: a stringClass object
* Returns:
* Summary:
* Notes:
************************************/
void Token::set_token(stringClass A)
{
    _token=A;
}

/***********************************
* Function: operator <<
* Purpose:
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
ostream& operator <<(ostream& outs,const Token& t) //(ostream& outs, const Token& t)
{
    outs<<t._token; //<<<<<<<<<!!!!!


    return outs;
}

///***********************************
// * Function:ostream
// * Purpose:makes the cout operator more natural and clean looking
// * Parameters:a ostream, a class
// * Returns: a ostream(so you can chain more)
// * Summary:compiler grabs the data from either side of the <<, like so... cout<<class
// *         This function overloads the << operator so it will take a class and print out multiple things, in this case the numerator,
// *         a "/", and the denominator
// * Notes:
// * ***********************************/
//ostream& operator << (ostream &outs, const rationalNumbers &ratio)
//{
//    outs << ratio._numerator << "/" << ratio._denominator;

//    return outs; //if we don't return we cant chain like so: cout<<"blah"<<" hello"<<endl;
//}
