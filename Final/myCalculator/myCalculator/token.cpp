#include "token.h"
#include <iostream>
using namespace std;

token::token()
{
    _token=NULL;
    _tokenType=-1;
}

token::token(char *aToken, int tokenType)
{
    cout<<"DEBUG token::*aToken: "<<*aToken<<endl;

    _token=aToken;
    _tokenType=tokenType;
}

token::~token()
{

}

void token::print()
{
    cout<<"token::print(): ";
    cout<<*_token;
}

