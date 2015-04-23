#ifndef NUMBERTOKEN_H
#define NUMBERTOKEN_H
#include "token.h"
#include "constants.h"

class numberToken:public token
{
public:
    numberToken();
    numberToken(char *aToken);
    numberToken(double aToken);

    ~numberToken();

    //mutators
    void set_token(double input);
    void set_token(char input[]);

    //accessors
    double get_token();

    //functions
    void print();


private:
    double _token;


    //private functions
    int cStringToInt(char token[MAX]);
};

#endif // NUMBERTOKEN_H
