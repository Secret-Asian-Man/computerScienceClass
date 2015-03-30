#ifndef FTOKENIZE_H
#define FTOKENIZE_H
#include "stokenize.h"
#include "token.h"

class fTokenize
{
public:
    const int MAX_BLOCK=50;

    //constructors
    fTokenize();
    ~fTokenize();
    fTokenize(char* fname);

    //accessors
    bool more(); //returns the current value of _more
    int pos();//returns the current value of _pos
    int blockPos();//returns the current value of _blockPos

    //functions
    Token nextToken();

    //operators
    friend fTokenize& operator >>(fTokenize& F, Token& T);

private:
    bool getNewBlock(); //gets the new block from the file
    std::ifstream _f;//file being tokenized
    STokenize _stk;//the stokenize  object to tokenize the current block
    int _pos; //current position inthe file
    int _blockPos;//current position in the current block
    bool _more;//false if last token in the las block has been processed and now we are at the end of the last block;


};

#endif // FTOKENIZE_H
