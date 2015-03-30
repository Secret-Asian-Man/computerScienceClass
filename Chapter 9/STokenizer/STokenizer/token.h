#ifndef TOKEN_H
#define TOKEN_H
#include "stringclass.h"

using namespace std;


class Token
{
public:
    //constructors
    Token();
    Token(stringClass s, int type);

    //destructors
    ~Token();

    //mutators
    void set_type(int number);
    void set_token(stringClass A);

    //accessors
    int& getType();
    stringClass& getTokenString();

    //operators
    friend ostream& operator <<(ostream& outs, const Token& t);

private:
    stringClass _token;
    int _type;
};

#endif // TOKEN_H
