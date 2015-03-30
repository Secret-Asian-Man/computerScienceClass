/***********************************
 * Project: deleteRepeat
 * Author: David Wu
 * Purpose: Deletes all repeated values in one shot.
 * Notes: deleteRepeat has 1 for loop, and 1 if statement
 * ***********************************/
#include <iostream>

using namespace std;

const int MAX=100;

void deleteRepeat(int a[], int &total);
void Delete(int a[], int index, int &total);
int searchNext (int a[], int input, int index, int total);
void display(int a[], int total);



int main()
{
    int array[MAX];
    int total=9;

    array[0]=-1; //brute force array filling for testing
    array[1]=-1;
    array[2]=-1;
    array[3]=1;
    array[4]=2;
    array[5]=3;
    array[6]=1;
    array[7]=2;
    array[8]=999;

    cout<<"Original Array: ";
    display(array, total); //Before
    cout<<endl<<endl;

    deleteRepeat(array,total);
    cout<<"Modified Array: ";
    display(array, total); //After

    cout<<endl<<endl;
}

/***********************************
 * Function:deleteRepeat
 * Purpose: deletes all reoccuring numbers in an array
 * Parameters: an int array, amount of interesting elements
 * Returns:nothing
 * Summary:Using the value at position [i] in an array, runs searchNext function.
 *          If searchNext finds something, deleteRepeat runs delete and COMPENSATES for the delete function shifting everything to the left once
 *          by decreasing i by 1.
 * Notes:
 * ***********************************/
void deleteRepeat(int a[], int &total)
{
    for (int i=0;i<total;i++)
    {
        int position=searchNext(a, a[i], i, total);

        if (position!=-1)
        {
            display(a, total);  //debugger

            cout<<endl;     //debugger
            cout<<"DEBUG deleteRepeat: deleting duplicate "<<a[i]<<" at position "<<position<<endl;     //debugger
            cout<<endl<<endl;   //debugger

            Delete(a,position,total);
            i--;    //compensates for the delete function shifting everything to the left once.
        }
    }
}

/***********************************
 * Function: Delete
 * Purpose: deletes a number in an array
 * Parameters: int a[], int total, int index
 * Returns: nothing
 * Summary: moves the data from position [index+1] into position [index], [total] amount of times. Then total--.
 * Notes:
 * ***********************************/
void Delete(int a[], int index, int &total)
{
    for (int i=index; i<total;i++)
    {
        a[i]=a[i+1];
    }

    total--;

    if (index==total && index>0)
        index=total-1;
}

/***********************************
 * Function:searchNext
 * Purpose:finds next occurence of a number
 * Parameters: an int array, a user input, a place to start the scan (left to right), amount of interesting elements
 * Returns: postion of number if found, otherwise returns -1
 * Summary: starting from the index+1 check the rest of the array for the user defined number.
 * Notes:
 * ***********************************/
int searchNext (int a[], int input, int index, int total)
{

    for (int i=index+1; i<total; i++)
    {
        if (input==a[i])
        {
            cout<<"DEBUG searchNext: found duplicate "<<input<<" at position "<<i<<endl; //debugger
            return i;
        }
    }
    return -1;

}

/***********************************
 * Function:display
 * Purpose: displays array
 * Parameters:int a[], int total, int index
 * Returns:Nothing
 * Notes:
 * ***********************************/
void display(int a[], int total)
{

    for (int i=0; i<total; i++)
    {

        cout<<a[i]<<" ";

    }

}
