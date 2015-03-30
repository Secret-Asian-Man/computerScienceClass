#include <iostream>

using namespace std;

const int MAX=100;

void StrCpy(char source[], char destination[]);
int StrLen(char a[]);
void StrCat (char source[], char destination[]);
int StrChr( char source[], char character);
int FirstOf (char source[], char compareToThis[], int pos);
int FirstNotOf (char source[], char compareToThis[], int pos);


int main()
{
    char source[MAX]="blah911blech";
    char destination[MAX]="food595";
    char digits[]="0123456789";

    cout<<"Original destination array: "<<destination<<endl;
    StrCpy(source,destination);
    cout<<"Modified destination array: "<<destination<<endl;
    cout<<endl<<endl<<endl;

    cout<<source<<endl;
    cout<<"The length of source array is:"<<StrLen(source)<<endl;
    cout<<endl<<endl<<endl;

    cout<<"(Need to fix) Source ("<<source<<") concatinated with destination ("<<destination<<") is:"<<endl; //FIX THIS!!
    StrCat(source, destination);
    cout<<destination<<endl;
    cout<<source<<endl;
    cout<<endl<<endl<<endl;

    cout<<"The letter a, in "<<source<<" is at position: "<<StrChr(source,'a')<<endl;
    cout<<endl<<endl<<endl;



    cout<<"Using the list "<<digits<<" I can tell the digits in "<<source<<" \nstarts at position "<<FirstOf(source,digits,0)
       <<" and ends at position "<<FirstNotOf(source,digits,FirstOf(source,digits,0))<<endl;


    cout<<endl<<endl;

}
/***********************************
 * Function: StrCpy
 * Purpose: Copies all the interesting elements from 1 array into the second array, overwriting the null in-between and adding a new one at the end.
 * Parameters: 2 char arrays
 * Returns: 1 char array
 * Notes:
 * ***********************************/
void StrCpy(char source[], char destination[])
{
    for (int i=0;source[i]!='\0';i++)
    {
        destination[i]=source[i];

        if(source[i]=='\0')
        {
            destination[i+1]='\0';
        }
    }
}

/***********************************
 * Function: StrLen
 * Purpose: counts number of interesting elements in the character array
 * Parameters: char array
 * Returns: amount of interesting elements
 * Notes:
 * ***********************************/
int StrLen(char a[])
{
    int total=0;

    while (a[total]!='\0')
    {
        total++;
    }

    return total;
}

/***********************************
 * Function: StrCat
 * Purpose: adds a string at end of another string
 * Parameters: 2 character arrays
 * Returns: a character array
 * Notes: FIX THIS!!!
 * ***********************************/
void StrCat (char source[], char destination[])
{
    int nullPosition=StrLen(destination)+1;
    int i=nullPosition;
    //cout<<"DEBUG nullPosition: "<<nullPosition<<endl;

    for ( i;source[i-nullPosition]!='\0';i++)
    {
        //cout<<"DEBUG source[i-nullPosition]: "<<source[i-nullPosition]<<endl;
        destination[i]=source[i-nullPosition];
        //cout<<"DEBUG destination: "<<destination<<endl;
        // cout<<"DEBUG destination[nullPosition+i]: "<<destination[nullPosition+i]<<"     "<<i<<endl;
    }

    destination[i]=NULL;
}

/***********************************
 * Function: StrChr
 * Purpose: Searches the array for the inputted character, starting from 0 up to null.
 * Parameters: Character array, a character
 * Returns: int postion of found character, or -1 if not found
 * Notes:
 * ***********************************/
int StrChr( char source[], char character)
{
    int length=StrLen(source);

    for (int i=0;i<length;i++)
    {
        if (source[i]==character)
        {
            return i;
        }
    }
    return -1;
}

/***********************************
 * Function: FirstOf
 * Purpose: Takes 1 array and sees if that particular slot equals to anything in a second array.
 * Parameters: 2 char arrays, starting position
 * Returns: Returns the position of the first thing found, if nothing is found returns -1.
 * Notes:
 * ***********************************/
int FirstOf (char source[], char compareToThis[], int pos)
{
    for (int i=pos; source[i] != '\0'; i++)
    {
        if(StrChr(compareToThis,source[i])!=-1)
            return i;
    }

    return -1;
}

/***********************************
 * Function: FirstNotOf
 * Purpose: Finds the next time a slot in the first array, has nothing that matches the stuff in the second array.
 * Parameters: 2 arrays,starting position
 * Returns: the ending position in int, -1 if something is found.
 * Notes:
 * ***********************************/
int FirstNotOf (char source[], char compareToThis[], int pos)
{
    for (int i=pos; source[i] != '\0'; i++)
    {
        if(StrChr(compareToThis,source[i])==-1)
            return i;
    }

    return -1;
}
