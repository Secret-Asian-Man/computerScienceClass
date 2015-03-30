#include "ftokenize.h"

fTokenize::fTokenize()
{

}

fTokenize::~fTokenize()
{

}

fTokenize::fTokenize(char* fname)
{

}

//accessors
bool fTokenize::more() //returns the current value of _more
{
    return _more;
}

int fTokenize::pos()//returns the current value of _pos
{
    return _pos;
}

int fTokenize::blockPos()//returns the current value of _blockPos
{
    return _blockPos;
}

//functions
Token fTokenize::nextToken()
{

}

//operators
friend fTokenize& operator >>(fTokenize& F, Token& T)
{

}
