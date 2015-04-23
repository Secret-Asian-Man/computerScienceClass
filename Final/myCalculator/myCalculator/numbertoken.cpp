#include "numbertoken.h"
#include <iostream>
using namespace std;
//number is 0
//operator is 1
//open parenthesis is 2
//closed parenthesis is 3
numberToken::numberToken()
{
    _token=0;
}

numberToken::numberToken(char* aToken):token(aToken,0)
{
    _token=atof(aToken);//converts cstring to an double and saves it.
}

numberToken::numberToken(double aToken)
{
    _token=aToken;
}

void numberToken::set_token(double input)
{
    _token=input;

}

void numberToken::set_token(char input[])
{
    _token=atof(input);
}

double numberToken::get_token()
{
    return _token;
}

void numberToken::print()
{
    cout<<"numberToken::print(): ";
    cout<<_token;
}

numberToken::~numberToken()
{

}

