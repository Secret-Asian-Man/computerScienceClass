#include "stokenize.h"


/***********************************
* Function:
* Purpose:
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
STokenize::STokenize()
{
    stringClass initialize;

    _s=initialize;
    _pos=0;
    _more=true;

    char digits[]="0123456789";
    char alpha[]="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    char punc[]="`~!@#$%^&*()-_=+\\]}[{;:'\"/?.>,<";
    char space[]=" \t";

//    stringClass _digits(digits);
//    stringClass _alpha(alpha);
//    stringClass _punc(punc);
//    stringClass _space(space);

//    charSet.push_back(_digits);
//    charSet.push_back(_alpha);
//    charSet.push_back(_punc);
//    charSet.push_back(_space);

    charSet.push_back((stringClass (space)));
    charSet.push_back((stringClass (alpha)));
    charSet.push_back((stringClass (digits)));
    charSet.push_back((stringClass (punc)));

}

/***********************************
* Function:
* Purpose:
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
STokenize::~STokenize()
{

}

/***********************************
* Function:
* Purpose:
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
STokenize::STokenize(const stringClass s)
{
    _s=s;
    _pos=0;
    _more=true;

    char digits[]="0123456789";
    char alpha[]="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    char punc[]="`~!@#$%^&*()-_=+\\]}[{;:'\"/?.>,<";
    char space[]=" \t";

    stringClass _digits(digits);
    stringClass _alpha(alpha);
    stringClass _punc(punc);
    stringClass _space(space);

    charSet.push_back(_digits);
    charSet.push_back(_alpha);
    charSet.push_back(_punc);
    charSet.push_back(_space);
}

/***********************************
* Function:
* Purpose:
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
int STokenize::getTokenType(char ch)
{
//    char digits[]="0123456789";
//    char alpha[]="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
//    char punc[]="`~!@#$%^&*()-_=+\|]}[{;:'\"/?.>,<";
//    char space[]=" ";


    if (strChr(charSet[0].get_s(),ch)!=NULL) //checks if the current character in the slot is part of the charSet, if it isn't return false, this is the wrong charSet.
        return 0;

    if (strChr(charSet[1].get_s(),ch)!=NULL) //checks if the current character in the slot is part of the charSet, if it isn't return false, this is the wrong charSet.
        return 1;

    if (strChr(charSet[2].get_s(),ch)!=NULL) //checks if the current character in the slot is part of the charSet, if it isn't return false, this is the wrong charSet.
        return 2;

    if (strChr(charSet[3].get_s(),ch)!=NULL) //checks if the current character in the slot is part of the charSet, if it isn't return false, this is the wrong charSet.
        return 3;

    return 4; //returns 4 if invalid character




    //    if (strChr(space,ch)!=NULL) //checks if the current character in the slot is part of the charSet, if it isn't return false, this is the wrong charSet.
    //        return 0;

//    if (strChr(alpha,ch)!=NULL) //checks if the current character in the slot is part of the charSet, if it isn't return false, this is the wrong charSet.
//        return 1;

//    if (strChr(digits,ch)!=NULL) //checks if the current character in the slot is part of the charSet, if it isn't return false, this is the wrong charSet.
//        return 2;

//    if (strChr(punc,ch)!=NULL) //checks if the current character in the slot is part of the charSet, if it isn't return false, this is the wrong charSet.
//        return 3;

//    return 4; //returns 4 if invalid character
}



/***********************************
* Function:
* Purpose:
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
//stringClass STokenize::zorg(stringClass charSet)
//{
//    //look at previous tokenizer

//}

/***********************************
* Function:
* Purpose:
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
void STokenize::nextstring(stringClass next)
{
    _s=next;
}

/***********************************
* Function:
* Purpose:
* Parameters:
* Returns:
* Summary:
* Notes: NEED TO MAKE A VECTOR OF CHARSETS. NEED TO MAKE A SUBSTRING TO GET THE ACTUAL TOKEN.
************************************/
Token STokenize::nextToken() //getNextToken
{
    //discover token type
    //find first of and first not of starting from position
    // get substring using the 2 found addresses
    //put substring into token class
    //deal with the _more/fail



    //use firstOf and firstNotOf to get positions to give
    //to subStr
    Token temp;
    char*_sWalker=_s.get_s()+_pos; //starts the cstring at the previous position


    temp.set_type(getTokenType(*_sWalker)); //find the type then use the type to get the token
    //sets the type by calling getTokenType and giving it the current character, which is at _sWalker

    char* foundFirst=_s.findFirstOf(charSet[temp.getType()].get_s(),_pos); //make a vector of charSets to help set these
    //in the stringClass _s, run the findFirstof function using the vector charSet at this slot determined by the token's current type, and using the current _pos
    char* foundLast=_s.findFirstNotOf(charSet[temp.getType()].get_s(),_pos);  //example vector: charSet[temp.getType()]
    //has to be here cuz relies on type being set already.

    char* rawToken=_s.subStringProto(foundFirst,foundLast); //want to do something like this
    //I want to use the 2 addresses i found earlier using firstOf and FirstNotOf to grab a substring. This would be my actual token. Then put it in the
    //token class using temp.set_token;

    //GO MAKE A NEW SUBSTRING


    //temp.set_token();


    _pos=_pos+temp.getTokenString().get_size() ;//updates the new position //should go at the end

    return temp;














    //    while (_more==true)
    //    {

    //    }


    //    char*=new char[]
    //            _s.findFirstOf()


    //            Token temp(,);

    //    temp.set_type(getTokenType(*_sWalker));

    //                return temp;
}

/***********************************
* Function:
* Purpose:
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
bool STokenize::fail()
{
    if (_more==false)
        return true;

    return false;
}

/***********************************
* Function:
* Purpose: turns false when there is nothing left to tokenize
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
bool STokenize::more()
{
    return _more;
}

/***********************************
* Function:
* Purpose:
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
int STokenize::pos()
{
    return _pos;
}

/***********************************
* Function:
* Purpose:
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
STokenize& operator >>(STokenize& s, Token& t)
{
    t=s.nextToken();

}


///***********************************
// * Function: istream
// * Purpose: makes the cin operator more natural and clean looking
// * Parameters: a istream and a class
// * Returns:a istream (so you can chain more)
// * Summary:compiler grabs the data from either side of the >>, like so... cin>>class
// *         This function overloads the >> operator so it will take a class and get input for more things, in this case numerator, a dummy, and denominator
// * Notes:
// * ***********************************/
//istream& operator >> (istream &ins, rationalNumbers &ratio)
//{
//    char dummy;

//    ins>>ratio._numerator;
//    ins>>dummy;
//    ins>>ratio._denominator;

//    return ins;
//}
