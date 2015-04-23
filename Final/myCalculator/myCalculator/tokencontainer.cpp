#include "tokencontainer.h"
#include "MyCStrings.h"
#include "constants.h"
#include "numbertoken.h"
#include "operatortoken.h"
#include "openparenthesistoken.h"
#include "closedparenthesistoken.h"



tokenContainer::tokenContainer()
{

}

tokenContainer::tokenContainer(char *equation, int position)
{
    _equation=equation;
    _position=position;
        while (getNextToken(_equation,_position)) //while we aren't done cycling thru the sourceString, keep getting the next token.
        {

        }
}
//bool tokenContainer::getNextToken(char source[], int &pos, char token[], int &type)
tokenContainer::tokenContainer(string equation, int position)
{
    char temp[equation.length()];
    cstr(equation,temp);//converts string to a cstring

    _equation=temp;
    _position=position;

    while (getNextToken(_equation,_position)) //while we aren't done cycling thru the sourceString, keep getting the next token.
    {
    }
}

tokenContainer::~tokenContainer()
{

}

void tokenContainer::print()
{
    cout<<"DEBUG tokenContainer::print() SIZE: "<<_container.size()<<endl;
    for (int i=0;i<_container.size();i++)
    {
        _container[i]->print();
        cout<<endl;
    }
}

bool tokenContainer::getNextToken(char source[], int &pos)
{
    //===========================================charSets============================================
    char digits[]="0123456789";
    char operators[]="+-*/";
    char openParenthesis[]="(";
    char closedParenthesis[]=")";
    //===============================================================================================

    char* atoken;//makes a new empty pointer for a cstring. Will be pointed to something when zorg is called.
    char* walker=atoken;
    if (pos>=StrLen(source)) //when the position is pointing to the end of the the source, we are done, so return false.
    {
        //cout<<"THE END!!"<<endl;
        return false;
    }


    if (zorg(source,digits,atoken,pos)) //running zorg with the space char array as the charSet.
    {
        //make new token types in here and push it into the list
                    cout<<"DEBUG getNextToken *atoken: "<<atoken<<endl;

        _container.push_back(new numberToken(atoken));
                //cout<<"digits!"<<endl;
                //type=0;
                return true;
    }

    if (zorg(source,operators,atoken,pos)) //running zorg with the space alpha array as the charSet.
    {

        _container.push_back(new operatorToken(atoken));
        //cout<<"operators!"<<endl;
        //type=1;
        return true;
    }

    if (zorg(source,openParenthesis,atoken,pos)) //running zorg with the space digits array as the charSet.
    {

        //cout<<"openParenthesis!"<<endl;
        //type=2;
        return true;
    }

    if (zorg(source,closedParenthesis,atoken,pos)) //running zorg with the punc char array as the charSet.
    {

        //cout<<"closedParenthesis!"<<endl;
        //type=3;
        return true;
    }

    pos++;

}

bool tokenContainer::zorg(char source[], char charSet[], char* &tokenPointer, int &pos)
{

    if (!find(source[pos],charSet)) //checks if the current character in the slot is part of the charSet, if it isn't return false, this is the wrong charSet.
        return false;

    int start=FindAny(source, charSet, pos); // starting from the pos, finds the first instance a character from the charSet shows up in the source, then
    // returns the position.

    int end=FindNotAny(source, charSet, pos);// starting from the pos, finds the last instance a character from the charSet shows up in the source, then
    // returns the position after the last instance.


    if (end==-1) //if the array has no end, then the length of the entire array is the ending position. (Note: starting pos doesn't have to be 0.)
        end=StrLen(source);

    tokenPointer=new char[start+(end-1)];
    pos=end; //saves and returns the position where this function left off.

    SubStr (source, tokenPointer, start, end-1); //makes the token by copying and pasting stuff from position [start] to position [end] inthe source array, into
    // the token array.

    return true;

}

bool tokenContainer::find(char key, char charSet[])
{
    int length=StrLen(charSet);

    for (int i=0;i<length;i++) //comparing the key to everything in the charSet
    {
        if (key==charSet[i])
            return true;
    }

    return false;

}

void tokenContainer::cstr(string source, char* dest)
{

    for(int i = 0; i < source.length(); i++){
        dest[i] = source[i];
    }
    dest[source.length()] ='\0';
}
