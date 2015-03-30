/***********************************
 * Project: addNumbersAtAnyBase
 * Author: David Wu
 * Purpose:adds binary, decimals, hex, etc...
 * Notes:
 * ***********************************/
#include <iostream>
#include<Tools.H>
#include<MyCStrings.h>

using namespace std;

const int MAX=100;
const int BASE=10;

void add2Numbers(char charArray1[], char charArray2[], char answer[]);
void add2CharArrays(char charArray1[],char charArray2[],char answer[], int limit);
void carryOver(char source[], int base);
void debugger_charWithIntValue (char source);
void shiftRight (char array[], int &length);
void hexify(char source[], int length);


int main()
{
    char bigNumberSet1[MAX]="111";
    char bigNumberSet2[MAX]="911";
    char answer[MAX];

    cout<<bigNumberSet1<<"+"<<bigNumberSet2<<"=";


    add2Numbers(bigNumberSet1,bigNumberSet2,answer);
    carryOver(answer,BASE);

    cout<<answer<<endl;


}

/***********************************
 * Function:add2Numbers
 * Purpose: adds 2 big numbers together the dumb way, without worrying about carrying over
 * Parameters: 2 char arrays representing the number, and a char array to hold the answer.
 * Returns: a rawly added answer in a char array
 * Summary: First finds the length of both char arrays you want added, then find the biggest length. Both arrays are reversed then padded with zeros
 *          until both arrays are the same length. Both arrays are then converted to represent integer values. Both arrays are added together, without
 *          worrying about carrying over, and the answer is put into another char array called answer[]. The answer[] array is reversed and done!
 * Notes:
 * ***********************************/
void add2Numbers(char charArray1[],char charArray2[],char answer[])
{
    int length1=StrLen(charArray1); //gets the length of both arrays for future reuse
    int length2=StrLen(charArray2);
    int biggestLength=biggestOf2Numbers(length1,length2); //gets the biggest length between the two.

    reverse(charArray1,length1); //reverses the array
    reverse(charArray2,length2);

    padZeros(charArray1,'0',biggestLength); //pads the shortest array with '0's to line up with the biggest array
    padZeros(charArray2,'0',biggestLength);

    //    cout<<"charArray1: "<<charArray1<<endl; //debug
    //    cout<<"charArray2: "<<charArray2<<endl; //debug

    charArrayToIntValue(charArray1); //converts entire char array to represent int values
    charArrayToIntValue(charArray2);

    add2CharArrays(charArray1,charArray2,answer, biggestLength);//adds the two arrays, which currently have int values, together without worrying about bases and remainders.

    charArrayToCharValue(answer,biggestLength); //converts entire char array to represent char values

    //    cout<<"answer: "<<answer<<endl;//debug

    reverse(answer,biggestLength); //reverses the answer back

    //    cout<<"real answer: "<<answer<<endl;//debug

}

/***********************************
 * Function: add2CharArrays
 * Purpose: adds 2 char arrays together starting from position 0 to position [limit].
 * Parameters: 2 char arrays to add together, a char array to hold the answer, an int to specify when to stop adding
 * Returns: a char array holding the added arrays
 * Summary: adds 1 char at a time starting for position 0 to position [limit]
 * Notes:
 * ***********************************/
void add2CharArrays(char charArray1[],char charArray2[],char answer[], int limit)
{
    for (int i=0;i<=limit;i++)
    {
        answer[i]=charArray1[i]+charArray2[i];
    }
}

/***********************************
 * Function:carryOver
 * Purpose: carries over the remainder of a number to the previous slot
 * Parameters:a char array, and a base to get the remainder
 * Returns: a char array with carried numbers
 * Summary:After finding the length of the source, we would get the ending position. We use the ending position and decrement from there until we hit 0.
 *
 * Notes: Whenever something in the array =0, it seems to be converted into a NULL instead of a character '0'
 *        When the char array is converted to int array, char '0' becomes int 0, and int 0 is the same as char '\0'. That screws up StrLen and things
 *        don't get printed. (RESOLVED)
 * ***********************************/
void carryOver(char source[], int base)
{
    int length=StrLen(source);
    int remainder=0;
    int bank=0;

    charArrayToIntValue(source);

    for (int i=length;i>0;i--)
    {
        bank=(source[i]%base)+remainder;
        //cout<<"DEBUG bank: "<<bank<<endl;

        remainder=source[i]/base;

        // debugger_charWithIntValue(source[i]);
        //cout<<"DEBUG source[i]: "<<source[i]<<endl;
        source[i]=bank;
        //cout<<"DEBUG (source[i]/base)+remainder: "<<source[i]<<endl;


        //cout<<"DEBUG remainder: "<<remainder<<endl;
    }

    //after all that processing is done, source[0] is left untouched so we can deal with it manually
    //keep shifting and carrying over using the base until there is no more remainder.

    while (remainder>0)
    {
        shiftRight(source, length);
        source[0]=remainder; //<----@@@@@@@@@@@@@@ not done
    }

    charArrayToCharValue(source, length);

    source[length+1]='\0';

}

/***********************************
 * Function: shiftRight
 * Purpose: shifts everything in a cstring to the right
 * Parameters: a cstring
 * Returns: a shifted cstring
 * Summary: moves everything to the right once, starting from the right, going to the left. Then puts a null at the new end.
 * Notes:
 * ***********************************/
void shiftRight (char array[], int &length)
{
    length++;

    for (int i=length;i>=0;i++)
    {
        array[i]=array[i-1];
    }

    //array[length+1]=NULL;
}

/***********************************
 * Function: hexify
 * Purpose: converts a array to display hex values
 * Parameters: a source cstring, a size/total/length
 * Returns: nothing
 * Summary:using a fixed cstring for hex (0-F), hex is converted to represent integers, then the source array
 * Notes: run inside of add2Numbers(), after converting to int values
 * ***********************************/
void hexify(char source[], int length)
{
    char hexValues[]="0123456789ABCDEF"; //convert into int values before adding to the source
    int hexArrayLength=StrLen(hexValues);

    charArrayToIntValue(hexValues);

    for (int i=0;i<length;i++)
    {
        source[i]=hexValues[source[i]];// <--- right now 'A'+'0' fix it
    }

    charArrayToCharValue(hexValues,hexArrayLength);
}


void debugger_charWithIntValue (char source)
{
    intToChar(source);
    cout<<"DEBUG debugger_charWithIntValue: "<<source<<endl;
    charToInt(source);
}
