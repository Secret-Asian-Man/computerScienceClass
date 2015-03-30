#ifndef TOKENIZE_H
#define TOKENIZE_H
#include "stringclass.h"

using namespace std;

class tokenize
{
public:
    tokenize();
    ~tokenize();
    tokenize(stringClass s, int type);
    tokenize(char ch, int type);

    friend ostream& operator <<(ostream& outs, const tokenize& t);
    int& Type();
    stringClass& tokenString();

private:
    stringClass _token;
    int& type;
};

#endif // TOKENIZE_H
