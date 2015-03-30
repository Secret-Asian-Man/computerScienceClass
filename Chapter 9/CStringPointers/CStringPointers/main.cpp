#include <iostream>

using namespace std;

const int MAX=100;

int strLen(char* source);
void strCpy(char* source, char* destination);
void strCat(char* source, char* destination);
int strCmp(char* string1, char* string2);
void subStr(char* source, char* sub, int start, int end);
char* strChr(char* source, char key);
char* strStr(char* source, char* key);



int main()
{
    char source[MAX]="A really long string";
    char destination[MAX]="really";
    char test[MAX];

    cout<<"strchr: "<<strChr(source, 'z')<<endl<<endl;
}

/***********************************
 * Function:strLen
 * Purpose: gets the length of a cstring
 * Parameters:a cstring
 * Returns: a length
 * Summary: counts up to null then returns the count
 * Notes:
 * ***********************************/
int strLen(char *source)
{
    int count=0;

    while (*source!=NULL)
    {
        source++;
        count++;
    }

    return count;

}

/***********************************
 * Function:strCpy
 * Purpose: copys a cstring into another cstring
 * Parameters: 2 cstrings
 * Returns:nothing
 * Summary:copies the [source] into the [destination] one by one until [source] null is hit, then manually puts in a null at the end of [destination]
 * Notes:
 * ***********************************/
void strCpy(char* source, char* destination) //done
{
    char* sourceWalker=source;
    char* destinationWalker=destination;

    while (*sourceWalker!=NULL)
    {
        *destinationWalker=*sourceWalker;

        sourceWalker++;
        destinationWalker++;
    }

    *destinationWalker=NULL;
}

/***********************************
 * Function:strCat
 * Purpose: adds a string at the end of another string
 * Parameters: 2 strings
 * Returns:nothing
 * Summary:
 * Notes:
 * ***********************************/
void strCat(char* source, char* destination)
{

    destination=destination+strLen(destination);

    strCpy(source, destination);

}

/***********************************
 * Function:strCmp
 * Purpose: compares 2 strings to each other and tells you if they are the same, or how they differ
 * Parameters:
 * Returns: -1 if first different character in string1 is SMALLER than the character in string2.
 *           0 if everything is the same.
 *           1 if first different character in string1 is BIGGER than the character in string2.
 * Summary: while none of the cstrings are null, keep comparing each sequential value to each other until something doesn't match, then compare
 *          the ascii values based on [string1] which will give the alphabetical order. if everything matches return a 0.
 * Notes:
 * ***********************************/
int strCmp(char* string1, char* string2)
{

    while (*string1!=NULL || *string2!=NULL)
    {
        if (*string1!=*string2)
        {
            if (*string1<*string2)
            {
                return -1;
            }

            if (*string1>*string2)
            {
                return 1;
            }
        }
        string1++;
        string2++;
    }

    return 0;

}

/***********************************
 * Function: subStr
 * Purpose: grabs a chunk from a string
 * Parameters: a source, a place to store the chunk, where to start copying the chunk, where to end copying the chunk
 * Returns: nothing
 * Summary: I move the index to where I want to start copying. I then start copying the [source] into the [sub], until I hit [end] or the [source] null.
 * Notes:
 * ***********************************/
void subStr(char* source, char* sub, int start, int end)
{
    source=source+start; //points to the slot of where you want to start copying
    for (int i=0;i<end && *source!=NULL;i++)
    {
        *sub=*source; //copys the value of the thing at this address and put it into the address of the other thing.
        sub++; //moves the cursor/index/address
        source++;//moves the cursor/index/address
    }

}

/***********************************
 * Function:strChr
 * Purpose: gets address of where first instance of [key] is
 * Parameters:a cstring, a character
 * Returns: address where the where first instance of [key] is, else returns NULL if not found
 * Summary: cycles thru [source] and checks the value inside each address for a match, then returns the current address when found.
 *          Returns NULL if not found.
 * Notes:
 * ***********************************/
char* strChr(char* source, char key)
{
    //walker?

    for (int i=0;*source!=NULL;i++)
    {
        if(*source==key)
        {
            return source;
        }

        source++;
    }

    return NULL;
}

/***********************************
 * Function:strStr
 * Purpose: gives us the address of where a particular cstring is located in another cstring
 * Parameters: a big cstring, a cstring to find in the big cstring
 * Returns: the address of where the beggining of the cstring was found
 * Summary: Compares first value of [key] to all of [source], with strChr.
 *          If there is a match, take a [chunk] out of [source], with subStr(), from the current address in [source] to the length of [key].
 *          Use strCmp() to compare [chunk] to [key], if match return address, else keep going...
 *          When [source] hits NULL and nothing is returned, return NULL.
 * Notes: There is a serious and tiny pointer bug somewhere, perhaps subStr. if [key] has a length of 4, [temp] will only hold 3 instead of 4.
 *        Another serious bug is that subStr() will continue to copy into an array past NULL, even though I already told it not to...
 * ***********************************/
char* strStr(char* source, char* key)
{
    char chunk[MAX];

    int length=strLen(key);
    char* chPointer=strChr(source, *key);
    cout<<"DEBUG chPointer: "<<chPointer<<endl;



    while (*source!=NULL)
    {
        subStr(source,chunk,0,length);
        cout<<"DEBUG temp: "<<chunk<<":"<<strCmp(key,chunk)<<endl;

        if (strCmp(key,chunk)==0)
        {
            cout<<"FOUND FOUND FOUND!"<<endl;
            return chPointer;
        }

        source++;

    }

    cout<<"RETURNING NULL......."<<endl;
    return NULL;


}
