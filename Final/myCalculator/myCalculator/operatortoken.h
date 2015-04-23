#ifndef OPERATORTOKEN_H
#define OPERATORTOKEN_H
#include "token.h"


class operatorToken:public token
{
public:
    operatorToken(char* aOperator);
    ~operatorToken();

    //accessors
    void set_operator(char aOperator);
    void set_precedence(int precedence);

    //mutators
    char get_operator();
    int get_precedence();

    //functions
    void print();



private:
    char _operator;
    int _precedence;
};

#endif // OPERATORTOKEN_H
