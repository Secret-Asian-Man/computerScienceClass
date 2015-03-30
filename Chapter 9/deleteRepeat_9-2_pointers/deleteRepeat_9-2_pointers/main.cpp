/***********************************
* Project:deleteRepeat with pointers. Chapter 9, Question 2.
* Author: David Wu
* Purpose: deletes duplicates in a cstring, using pointers
* Notes:
* ***********************************/
#include <iostream>
#include <cstring>

using namespace std;

void deleteRepeat(char* array);
char* searchNext (char* array, char key);
void Delete(char* array);

int main()
{
    char test[100]="aabbcc123123abc";
    char* temp=test;

    //    cout<<"DEBUG temp orginal: "<<temp<<endl;

    deleteRepeat(test);

    //    cout<<"DEBUG MAIN test: "<<test<<endl;
}

/***********************************
* Function:deleteRepeat
* Purpose: deletes repeated characters in an array
* Parameters: an array
* Returns: nothing
* Summary: [key] starts at 0, and [found] is an address from a conducted search starting from just after [key] to the end. When something is found,
*          it is deleted. When something is not found, the [key] increments. When we run out of characters to key in, we are done.
* Notes:
************************************/
void deleteRepeat(char* array)
{
    char* found=array;
    char* key=array;
    char chartest;

        do
        {
        chartest = *key;
            found=searchNext(key,*key); //finds the address of the key value after the key address

            cout<<"DEBUG deleteRepeat key: "<<key<<endl;

            if (found!=NULL) //if something IS found...
            {
                cout<<"DEBUG deleteRepeat found: "<<found<<endl;
                Delete(found);
                cout<<"DEBUG deleteRepeat deleted: "<<found<<endl;
            }
            else
            {
                cout<<"NOT FOUND!!"<<endl;
                key++;
                found=key; //returns found to the key address so it is ready to run the search again

            }
            cout<<"DEBUG OVERVIEW: "<<array<<endl;
            cout<<endl<<endl<<endl;

        }while (*key!=NULL);
}



/***********************************
* Function:Delete
* Purpose: deletes from array
* Parameters: an array
* Returns: nothing
* Summary: shifts everything on the right of the address left by one, then adds a NULL at the end
* Notes:
************************************/
void Delete(char* array)

{
    char* end=array+strlen(array);
    char* nextPos=array+1; //moves the value from pos+1 into pos

    while(*array!=NULL || *nextPos!=NULL)
    {
        *array=*nextPos;

        array++;
        nextPos++;
    }

    *end=NULL;
}

/***********************************
* Function:searchNext
* Purpose: finds the next of the same thing
* Parameters: a cstring, what to search for
* Returns: address of where thing is found
* Summary: If we aren't already at the end of the array, increment the position. Then keep checking and incrementing position until we get a match.
*          Return the address of the match.
* Notes:
************************************/
char* searchNext (char* array, char key)
{
    if (*array!=NULL)
    {
        array++;
    }

    while(*array!=NULL)
    {
        if (*array==key)
        {
            return array;
        }

        array++;
    }

    return '\0';
}

