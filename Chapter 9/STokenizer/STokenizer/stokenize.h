#ifndef STOKENIZE_H
#define STOKENIZE_H
#include "token.h"
#include "stringclass.h"
#include <vector>

class STokenize
{
public:
    //constructors
    STokenize();
    STokenize(const stringClass s);

    //destructors
    ~STokenize();

    //accessors
    bool more(); //returns the current value of _more
    int pos(); //returns the current value of _pos
    int getTokenType(char ch);

    //functions
    //stringClass zorg(stringClass charSet);
    void nextstring(stringClass next); //gets the token
    Token nextToken();
    bool fail(); //true when _more is false
    friend STokenize& operator >>(STokenize& s, Token& t);

private:
    stringClass _s; //is holding the string, and has a bunch of tools as a bonus.
    int _pos; //remembers the position of which token you left off on
    bool _more; //false when you try to get the next token but it fails.
    vector <stringClass> charSet;
};

#endif // STOKENIZE_H
