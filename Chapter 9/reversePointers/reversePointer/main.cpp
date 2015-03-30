/***********************************
* Project: reversing cstrings with pointers
* Author: David Wu
* Purpose: to reverse a cstring, and learn pointers
* Notes:
* ***********************************/
#include <iostream>

using namespace std;

const int MAX=100;


int strLen(char *source);
void reverse(char* array);

int main()
{

    char array[MAX]="blah";

    cout<<"main array: "<<array<<endl;

    reverse(array);

    cout<<"main array: "<<array<<endl;


}

/***********************************
 * Function:reverse
 * Purpose: reverses the string
 * Parameters: a cstring
 * Returns: nothing
 * Summary: starting with 2 points on both sides of the cstring they converge to the middle, while swapping values with each other.
 * Notes:
 * ***********************************/
void reverse(char* array)
{
    int length=strLen(array);
    char* pos1=array;
    char* pos2=array+length;

    while (pos1<=pos2)
    {
        swap(*pos1, *pos2);

        pos1++;
        pos2--;
    }


}

/***********************************
 * Function: strLen
 * Purpose: finds the length of the string,
 * Parameters: a cstring
 * Returns: length of string
 * Summary: increments the address and the count by one until the value inside the address is NULL, then returns the count minus 1
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

    return count-1; //was pointing at null, now pointing at last char in the cstring

}

