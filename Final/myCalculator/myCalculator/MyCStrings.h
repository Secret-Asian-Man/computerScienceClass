#ifndef MYCSTRING_H
#define MYCSTRING_H

using namespace std;


int FindAny (char source[], char digits[], int pos);
int FindNotAny (char source[], char digits[], int pos);
int StrChr( char source[], char character);
int StrLen(char a[]);
void StrCat (char source[], char destination[]);
void StrNCat (char source[], char destination[], int number);
void StrCpy(char source[], char destination[]);
void StrNCpy(char source[], char destination[], int num);
int StrCmp(char a[], char a2[]);
void SubStr(char source[], char destination[], int start, int end);
void frequencies(char source[], char list[], int frequency[], int &total);





/***********************************
 * Function: FindAny
 * Purpose: Takes 1 array and sees if that particular slot equals to anything in a second array.
 * Parameters: 2 char arrays, starting position
 * Returns: Returns the position of the first thing found, if nothing is found returns -1.
 * Notes:
 * ***********************************/
int FindAny (char source[], char digits[], int pos)
{
    for (int i=pos; source[i] != '\0'; i++)
    {
        if(StrChr(digits,source[i])!=-1)
            return i;
    }

    return -1;
}

/***********************************
 * Function: FindNotAny
 * Purpose: Finds the next time a slot in the first array, has nothing that matches the stuff in the second array.
 * Parameters: 2 arrays,starting position
 * Returns: the ending position in int, -1 if something is found.
 * Notes:
 * ***********************************/
int FindNotAny (char source[], char digits[], int pos)
{
    for (int i=pos; source[i] != '\0'; i++)
    {
        if(StrChr(digits,source[i])==-1)
            return i;
    }

    return -1;
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
 * Function: StrNCpy
 * Purpose: Same as StrCpy(), except if the second array doesn’t fit into the first array, the first array has 0’s as filler until filled up to null.
 * Parameters: 2 char arrays
 * Returns: 1 char array
 * Notes:
 * ***********************************/
void StrNCpy(char source[], char destination[], int num)
{
    int i=0;

    for (i; i<num && source[i]!='\0';i++)
    {
        destination[i]=source[i];
    }

    for (i;source[i]!='\0';i++)
    {
        destination[i]='0';
    }

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
 * Function: StrRChr
 * Purpose: Searches the array for the inputted character, starting from null down to 0.
 * Parameters: Character array, a character
 * Returns: int postion of found character, or -1 if not found
 * Notes:
 * ***********************************/
int StrRChr( char source[], char character)
{
    int Stringlength=StrLen(source);

    for (int i=Stringlength;i>0;i--)
    {
        if (source[i]==character)
        {
            return i;
        }
    }
    return -1;
}


/***********************************
 * Function: StrLen
 * Purpose: counts number of interesting elements in the character array
 * Parameters: char array
 * Returns: int interesting elements
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
 * Notes:
 * ***********************************/
void StrCat (char source[], char destination[])
{
    int nullPosition=StrLen(destination)+1;
    //cout<<"DEBUG nullPosition: "<<nullPosition<<endl;

    for (int i=0;destination[i]!='\0';i++)
    {
        destination[nullPosition+i]=destination[i];
        // cout<<"DEBUG destination[nullPosition+i]: "<<destination[nullPosition+i]<<"     "<<i<<endl;
    }
}

/***********************************
 * Function: StrNCat
 * Purpose: Same as StrCat(), except  user can pick how many characters in the second array they want to copy at the end of the first array
 * Parameters: 2 character arrays, int number
 * Returns: a character array
 * Notes:
 * ***********************************/
void StrNCat (char source[], char destination[], int number)
{
    int nullPosition=StrLen(destination); //pointing at null in destination[]

    for (int i=0;i<number;i++)
    {
        destination[nullPosition+i]=source[i];
    }

    destination[nullPosition+number]='\0';

}

/***********************************
 * Function: StrCmp
 * Purpose: Alphabetical order rules.
 * Parameters: 2 char strings
 * Returns: returns 1 if 1st array goes first, return -1 if 2nd array goes first, returns 0 if both are identical.
 * Notes: Capital letters?
 * ***********************************/
int StrCmp(char a[], char a2[])
{
    int i=0;

    for (i; a[i]==a2[i] && (a[i]!=NULL || a2[i]!=NULL);i++);//cycles thru the arrays until a difference or NULL is hit


    if (a[i]<a2[i]) //if 1st array has lower ascii value returns 1
        return 1;

    if (a2[i]<a[i])//if 2nd array has lower ascii value returns -1
        return -1;

    if (StrLen(a)<StrLen(a2)) //if everything was the same so far, the shortest string wins
        return 1;

    if (StrLen(a2)<StrLen(a)) //if everything was the same so far, the shortest string wins
        return -1;


    return 0;// everything is the same, return 0.

}

/***********************************
 * Function: SubStr
 * Purpose: copies and paste one string into the beginning of another
 * Parameters: 2 arrays, start and end position
 * Returns: a pasted array
 * Notes:
 * ***********************************/
void SubStr(char source[], char destination[], int start, int end)
{
    int i;

    for( i=start; i <= end; i++)
    {
        destination[i-start]=source[i];
        //cout<<"DEBUG i: "<<i<<endl;
    }

    destination [i-start]=NULL;
}

/***********************************
 * Function: Show
 * Purpose: Points at postion for debugging
 * Parameters: an array, a position ot point at
 * Returns: Nothing
 * Notes:
 * ***********************************/
void Show(char a[], int pos)
{
    int i;
    char pointer[StrLen(a)];

    cout<<a<<endl;

    for (i=0;i<pos;i++)
    {
        pointer[i]='-';
    }

    pointer[i]='^';
    pointer[i+1]=NULL;


    cout<<pointer<<endl;
}

/***********************************
 * Function: frequencies
 * Purpose: counts how many times this particular character occured in this array
 * Parameters: char source[], char list[], int frequency[], int &total
 * Returns: char source[], char list[], int frequency[], int &total
 * Summary: Cycles thru all the characters in the given array, and if it currently is not on the list it adds it to the list and keeps count,
 *          if already found on the list, it adds to the count.
 * Notes:
 * ***********************************/
void frequencies(char source[], char list[], int frequency[], int &total)
{
    for (int i=0;source[i]!=NULL;i++) //while the source doesn't equal null keep increasing i
    {
        if (StrChr(list,source[i])!=-1)// if this particular character in source matches anything in the list, frequency[i]++
        {
            frequency[StrChr(list,source[i])]++;
        }

        if (StrChr(list,source[i])==-1)//if this particulat character isnt found in the list, add it to the list and frequency++
        {
            list[i]=source[i];
            frequency[i]++;
            total++;
        }
    }
}
#endif // MYCSTRING_H
