#ifndef MYCSTRINGS
#define MYCSTRINGS
#include <iostream>
using namespace std;

int strLen(char *source);
void strCpy(char* source, char* destination);
void strCat(char* source, char* destination);
int strCmp(char* string1, char* string2);
void subStr(char* source, char* sub, int start, int end);
char* strChr(char* source, char key);
char* strStr(char* source, char* key);


///***********************************
// * Function:strLen
// * Purpose: gets the length of a cstring
// * Parameters:a cstring
// * Returns: a length
// * Summary: counts up to null then returns the count
// * Notes:
// * ***********************************/
//int strLen(char *source)
//{
//    char* walker=source;

//    while (*walker!=NULL)
//    {
//        walker++;
//    }

//    return walker-source;

//}

///***********************************
// * Function:strCpy
// * Purpose: copys a cstring into another cstring
// * Parameters: 2 cstrings
// * Returns:nothing
// * Summary:copies the [source] into the [destination] one by one until [source] null is hit, then manually puts in a null at the end of [destination]
// * Notes:
// * ***********************************/
//void strCpy(char* source, char* destination) //done
//{

//    while (*source!=NULL)
//    {
//        *destination=*source;

//        source++;
//        destination++;
//    }

//    *destination=NULL;
//}

///***********************************
// * Function:strCat
// * Purpose: adds a string at the end of another string
// * Parameters: 2 strings
// * Returns:nothing
// * Summary:
// * Notes:
// * ***********************************/
//void strCat(char* source, char* destination)
//{

//    destination=destination+strLen(destination);

//    strCpy(source, destination);

//}

///***********************************
// * Function:strCmp
// * Purpose: compares 2 strings to each other and tells you if they are the same, or how they differ
// * Parameters:
// * Returns: -1 if first different character in string1 is SMALLER than the character in string2.
// *           0 if everything is the same.
// *           1 if first different character in string1 is BIGGER than the character in string2.
// * Summary: while none of the cstrings are null, keep comparing each sequential value to each other until something doesn't match, then compare
// *          the ascii values based on [string1] which will give the alphabetical order. if everything matches return a 0.
// * Notes:
// * ***********************************/
//int strCmp(char* string1, char *string2)
//{
//    char* string1Walker=string1;
//    char* string2Walker=string2;


//    while (*string1Walker!=NULL && *string2Walker!=NULL) //&& or ||?
//    {
//        if (*string1Walker!=*string2Walker)
//        {
//            if (*string1Walker<*string2Walker)
//            {
//                return -1;
//            }

//            if (*string1Walker>*string2Walker)
//            {
//                return 1;
//            }
//        }
//        string1Walker++;
//        string2Walker++;
//    }

//    return 0;

//}

///***********************************
// * Function: subStr
// * Purpose: grabs a chunk from a string
// * Parameters: a source, a place to store the chunk, where to start copying the chunk, where to end copying the chunk
// * Returns: nothing
// * Summary: I move the index to where I want to start copying. I then start copying the [source] into the [sub], until I hit [end] or the [source] null.
// * Notes:
// * ***********************************/
//void subStr(char* source, char* sub, int start, int end)
//{
//    char* sourceWalker=source+start;//points to the slot of where you want to start copying
//    char* subWalker=sub;

//    for (int i=0;i<end && *sourceWalker!=NULL;i++)
//    {
//        *subWalker=*sourceWalker; //copys the value of the thing at this address and put it into the address of the other thing.
//        subWalker++; //moves the cursor/index/address
//        sourceWalker++;//moves the cursor/index/address
//    }

//    *subWalker=NULL;
//}

///***********************************
// * Function:strChr
// * Purpose: gets address of where first instance of [key] is
// * Parameters:a cstring, a character
// * Returns: address where the where first instance of [key] is, else returns NULL if not found
// * Summary: cycles thru [source] and checks the value inside each address for a match, then returns the current address when found.
// *          Returns NULL if not found.
// * Notes:
// * ***********************************/
//char* strChr(char* source, char key)
//{
//    char* sourceWalker=source;

//    for (int i=0;*sourceWalker!=NULL;i++)
//    {
//        if(*sourceWalker==key)
//        {
//            return sourceWalker;
//        }

//        sourceWalker++;
//    }

//    return NULL;
//}

///***********************************
// * Function:strStr
// * Purpose: gives us the address of where a particular cstring is located in another cstring
// * Parameters: a big cstring, a cstring to find in the big cstring
// * Returns: the address of where the beggining of the cstring was found
// * Summary: Compares first value of [key] to all of [source], with strChr.
// *          If there is a match, take a [chunk] out of [source], with subStr(), from the current address in [source] to the length of [key].
// *          Use strCmp() to compare [chunk] to [key], if match return address, else keep going...
// *          When [source] hits NULL and nothing is returned, return NULL.
// * Notes: There is a serious and tiny pointer bug somewhere, perhaps subStr. if [key] has a length of 4, [temp] will only hold 3 instead of 4.
// *        Another serious bug is that subStr() will continue to copy into an array past NULL, even though I already told it not to...
// * ***********************************/
//char* strStr(char* source, char* key)
//{
//    //go thru array using a [walker]
//    //find first matching letter using the first letter of [key]
//    //take a [chunk] as long as strLen() of [key]
//    //compare that [chunk] with [key]
//    //if chunk matches key return current address of [walker]
//    //else increment [walker] and try again until NULL

//    char* sourceWalker=source;
//    char chunk[MAX]; //temporarily holds a chunk of characters
//    int length=strLen(key);

//    for (int i=0;*sourceWalker!=NULL;i++)//go thru array using a [walker]
//    {
//        if (strChr(sourceWalker,*key)!=NULL)    //find first matching letter using the first letter of [key]
//        {
//            subStr(source,chunk,i,length);    //take a [chunk] as long as strLen() of [key]

//            if (strCmp(chunk,key)==0)//if chunk matches key return current address of [walker]
//            {
//                return sourceWalker;
//            }
//        }

//        sourceWalker++;//else increment [walker] and try again until NULL
//    }

//    return NULL; //if nothing is found return NULL.

//    }

#endif // MYCSTRINGS

