#include "operatortoken.h"
#include "token.h"
#include <iostream>


operatorToken::operatorToken(char* aOperator):token(aOperator,1)
{
    _operator=*aOperator;

    switch (_operator)
    {
    case '+':
        _precedence=1;
        break;

    case '-':
        _precedence=1;
        break;

    case '*':
        _precedence=2;

        break;

    case '/':
        _precedence=2;
        break;

    case '(':
        _precedence=3;
        break;

    case ')':
        _precedence=3;

        break;
    default:
        std::cout<<"Invalid key..."<<std::endl;
    }

}

operatorToken::~operatorToken()
{

}

void operatorToken::set_operator(char aOperator)
{
    _operator=aOperator;
}

void operatorToken::set_precedence(int precedence)
{
    _precedence=precedence;
}

char operatorToken::get_operator()
{
    return _operator;
}

int operatorToken::get_precedence()
{
    return _precedence;
}

void operatorToken::print()
{
    std::cout<<"operatorToken::print(): ";
    std::cout<<_operator;
}


