/***********************************
* Project: Add Entry. Chapter 9, Question 6.
* Author: David Wu
* Purpose: adds or deletes specified things from a dynamic array (an array that changes sizes.)
* Notes: I'm having alot of issues with delete[]. Which one do I delete?
* ***********************************/
#include <iostream>

using namespace std;

string* initialize(string* strPointer, string input);
string* walker(string* strPointer, int input);
string* addEntry(string *dynamicArray,  int &size, string newEntry);
string* search(string* array, int size, string key, int &count);
void Delete(string* array, int& size, int count);
string* deleteEntry(string *dynamicArray, int &size, string entryToDelete);


int main()
{
    int size=5;
    string* strPointer;
    strPointer=new string [size];
    string* home=strPointer; //saves the beginning address

    strPointer=initialize(strPointer,"1"); //testing
    strPointer=initialize(strPointer,"22");
    strPointer=initialize(strPointer,"333");
    strPointer=initialize(strPointer,"4444");
    strPointer=initialize(strPointer,"55555");

    strPointer=home;
    //    cout<<"DEBUG strPointer@@: "<<*strPointer<<endl;

    strPointer=addEntry(strPointer,size,"this is a new entry");
    strPointer=addEntry(strPointer,size,"more new entries!");


    if(strPointer!=NULL) //for testing
    {
        cout<<"DEBUG strPointer@@: "<<*strPointer<<endl;
        strPointer++;

        cout<<"DEBUG strPointer@@: "<<*strPointer<<endl;
        strPointer++;

        cout<<"DEBUG strPointer@@: "<<*strPointer<<endl;
        strPointer++;

        cout<<"DEBUG strPointer@@: "<<*strPointer<<endl;
        strPointer++;

        cout<<"DEBUG strPointer@@: "<<*strPointer<<endl;
        strPointer++;

        cout<<"DEBUG strPointer@@: "<<*strPointer<<endl;
        strPointer++;

        cout<<"DEBUG strPointer@@: "<<*strPointer<<endl;

    }
    else
    {
        cout<<"NULL detected"<<endl;
    }
}

/***********************************
* Function:addEntry
* Purpose: adds a new entry to a dynamicArray
* Parameters:an array, size of the array, the entry you want to put in
* Returns: the address of the new array
* Summary:  This function should create a new dynamic array one element larger
            than  dynamicArray,  copy  all  elements  from  dynamicArray  into  the
            new array, add the new entry onto the end of the new array, increment
            size, delete dynamicArray, and return the new dynamic array.

* Notes:
************************************/
string* addEntry(string *dynamicArray,  int &size, string newEntry)
{
    size++;

    string* newArray;
    newArray=new string [size];
    string* walker_dynamicArray=dynamicArray;
    string* walker_newArray=newArray;


    for (int i=1;i<size;i++)
    {
        *walker_newArray=*walker_dynamicArray;

        walker_dynamicArray++;
        walker_newArray++;
    }


    *walker_newArray=newEntry;

    delete[] dynamicArray; //running this thing crashes me? what am i supposed to delete then?
    //dyanamicArray is currently pointing at something that doesnt belong to me, because of dynamicArray++

    return newArray;
}


/***********************************
* Function:deleteEntry
* Purpose: makes a array with new size, and deletes the specified string
* Parameters:a string array, a the size of that array, the string to delete
* Returns: address of new array
* Summary:  This function should search dynamicArray for entryToDelete. If not
            found,  the  request  should  be  ignored  and  the  unmodiﬁed
            dynamicArray  returned.  If  found,  create  a  new  dynamic  array  one
            element  smaller  than  dynamicArray.  Copy  all  elements  except
            entryToDelete  into  the  new  array,  delete  dynamicArray,  decrement
            size, and and return the new dynamic array.
* Notes: put in walkers for newArray. Already got one for strPointer.
************************************/
string* deleteEntry(string *dynamicArray, int &size, string entryToDelete)
{
    int count=0;
    string* strPointer=dynamicArray;
    string* found=search(dynamicArray,size,entryToDelete,count); //address IS at the location where the entry is found

    if (found!=NULL) //it has to find it to delete it, so we dont have to worry about size becoming negative
    {

        Delete(found,size,count);//deletes the current address //already did size-- in this function

        string* newArray;
        newArray=new string [size]; //makes a new array taht can exist outside the function
        string* home=newArray; //saves the very beginning address, so we can go back home anytime

        for (int i=0;i<size;i++) //deleted the entry in the old array, so now i can directly copy everything over to the new array.
        {
            *newArray=*strPointer;

            newArray++;
            strPointer++;
        }

        delete[] dynamicArray; //releases memory at the old array location
        newArray=home;//sets the address back to the beginning.

        return newArray;

    }

    delete[] dynamicArray;//releases memory at the old array location
    return NULL; //not found so return NULL

}

/***********************************
* Function:initialize
* Purpose: For testing purposes
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
string* initialize(string* strPointer, string input)
{
    *strPointer=input;

    //cout<<"DEBUG strPointer: "<<*strPointer<<endl;

    strPointer++;

    return strPointer;
}

/***********************************
* Function:walker
* Purpose: moves the address [input] many times to the left or right
* Parameters: a pointer, a negative/positive input
* Returns:the new address
* Summary: if user enters a negative input, the walker walks backwards, else it walks forward
* Notes:
************************************/
string* walker(string* strPointer, int input)
{
    if (input<0)
    {
        for (int i=0;i<(input*-1);i++)
        {
            strPointer--;
        }
        return strPointer;
    }
    else
    {
        for (int i=0;i<input;i++)
        {
            strPointer++;
        }
        return strPointer;
    }
}

/***********************************
* Function:search
* Purpose: finds the address where the value you want is
* Parameters: an array, the size of the array, the thing you want to search for, how far you went before you found it (I need a better method)
* Returns: the address of the value you want
* Summary:while keeping track of how far you searched for the key, when you find the key, return the location, otherwise return NULL.
* Notes:
************************************/
string* search(string* array,int size,string key, int& count)
{
    for (count=0;count<size;count++)
    {
        if (*array==key)
        {
            return array;
        }
        array++;
    }
    return NULL;

}
/***********************************
* Function:Delete
* Purpose: deletes a address, and shifts everything left
* Parameters:a array, the size of array, number to help determine how many times to shift left.
* Returns: nothing
* Summary:using 2 address, 1 starting the the address you want to delete, and the other to the right by 1, we move everything over starting from
*         the count to the size-1 of the array. Then we decrement the size.
* Notes:
************************************/
void Delete(string* array, int& size, int count)

{
    string* nextPos=array+1; //moves the value from pos+1 into pos


    for (int i=count;i<size-1;i++)
    {
        *array=*nextPos;

        array++;
        nextPos++;
    }

    size--;
}
