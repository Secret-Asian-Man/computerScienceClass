/***********************************
 * Project: Tokenizer
 * Author: David Wu
 * Purpose: separates words, numbers, spaces, and puncuation from each other and keeps track of which is which.
 * Notes:
 * ***********************************/
#include <iostream>
#include<MyCStrings.h>

using namespace std;

bool getNextToken (char source[], int &pos, char token[], int &type);
bool zorg(char source[], char charSet[], char token[], int &pos);
bool find(char key, char charSet[]);

const int MAX=100;


int main()
{
    char sourceString[MAX]="Test 123 blah blahs!@#";
    char token[MAX];
    int type=0;
    int pos=0;

    while (getNextToken(sourceString,pos,token,type)) //while we aren't done cycling thru the sourceString, keep getting the next token.
    {
        cout<<"type "<<type<<" :";
        cout<<token<<endl;
    }


    cout<<"DONE!!"<<endl<<endl;
}



/***********************************
 * Function: getNextToken
 * Purpose: keep getting next token until there are no more in source.
 * Parameters: char source[], char charSet[], int &pos, char token[], int &type
 * Returns: a boolean, postion, type of charSet
 * Notes:
 * ***********************************/
bool getNextToken (char source[], int &pos, char token[], int &type)
{
    //===========================================charSets============================================
    char digits[]="0123456789";
    char alpha[]="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    char punc[]="`~!@#$%^&*()-_=+\|]}[{;:'\"/?.>,<";
    char space[]=" ";
    //===============================================================================================

    if (pos>=StrLen(source)) //when the position is pointing to the end of the the source, we are done, so return false.
    {
        //cout<<"THE END!!"<<endl;
        return false;
    }

    if (zorg(source,space,token,pos)) //running zorg with the space char array as the charSet.
    {
        //cout<<"space!"<<endl;
        type=0;
        return true;
    }

    if (zorg(source,alpha,token,pos)) //running zorg with the space alpha array as the charSet.
    {
        //cout<<"alpha!"<<endl;
        type=1;
        return true;
    }

    if (zorg(source,digits,token,pos)) //running zorg with the space digits array as the charSet.
    {
        //cout<<"digits!"<<endl;
        type=2;
        return true;
    }

    if (zorg(source,punc,token,pos)) //running zorg with the punc char array as the charSet.
    {
        //cout<<"punc!"<<endl;
        type=3;
        return true;
    }

    pos++;
}

/***********************************
 * Function:zorg
 * Purpose:tokenizes a string
 * Parameters:a char array to tokenize, a char array to compare to, a char array to store tokens in, a position to start from
 * Returns:true if everything is ok, false if wrong charSet
 * Summary: First checks if the current character in the slot is part of the charSet, if it isn't return false, this is the wrong charSet.
 *          Then finds the starting and ending postion of a token using findAny and FindNotAny. If findNotAny doesn't find anything, the length
 *          of the string becomes end position. Finally, the start position to the ending position of the source is copied into the token array.
 * Notes:
 * ***********************************/
bool zorg(char source[], char charSet[], char token[], int &pos)
{
    if (!find(source[pos],charSet)) //checks if the current character in the slot is part of the charSet, if it isn't return false, this is the wrong charSet.
        return false;

    int start=FindAny(source, charSet, pos); // starting from the pos, finds the first instance a character from the charSet shows up in the source, then
    // returns the position.

    int end=FindNotAny(source, charSet, pos);// starting from the pos, finds the last instance a character from the charSet shows up in the source, then
    // returns the position after the last instance.


    if (end==-1) //if the array has no end, then the length of the entire array is the ending position. (Note: starting pos doesn't have to be 0.)
        end=StrLen(source);

    pos=end; //saves and returns the position where this function left off.

    SubStr (source, token, start, end-1); //makes the token by copying and pasting stuff from position [start] to position [end] inthe source array, into
    // the token array.

    return true;
}

/***********************************
 * Function: find
 * Purpose: checks if a specific character is in a character array
 * Parameters: a character, and a char array
 * Returns: true if found, false if not found
 * Summary: compares a single char to all of an char array for a match. Then returns true if there is a match, and false if not.
 * Notes:
 * ***********************************/
bool find(char key, char charSet[])
{
    int length=StrLen(charSet);

    for (int i=0;i<length;i++) //comparing the key to everything in the charSet
    {
        if (key==charSet[i])
            return true;
    }

    return false;
}
