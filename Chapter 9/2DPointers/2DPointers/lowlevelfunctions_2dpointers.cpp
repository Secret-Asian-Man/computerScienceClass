#include<iostream>
#include "lowlevelfunctions_2dpointers.h"

using namespace std;

/***********************************
* Function:allocate
* Purpose: allocates memory to use
* Parameters: takes an array of sizes
* Returns: address of allocated memory
* Summary: takes a bunch of sizes ie{1,6,3,4,-1}. relys on the end of the array having a -1 to stop.
* Notes: use pointers and walkers instead of something[i]
************************************/
ITEM_TYPE **allocate(int size [])
{
    int sizeTotal=0;
    for (sizeTotal;sizeTotal!=-1;sizeTotal++); //gives the amount of interesting elements size[] has

    int** rows; //pointer that points to an array of pointers.

    rows=new int* [sizeTotal]; //makes an array of pointers [sizeTotal] long, and lets rows** point to it.


    for (int i=0;i<sizeTotal;i++) //makes [sizeTotal] amount of normal int array of [ sizes[] ] long
    {

        rows[i]=new int [size[i]]; //in row#1, make a new normal int array that is size#1 long.

    }

    return rows; //can only return a dynamic array, not a static!
}

/***********************************
* Function: deallocate
* Purpose: releases memory
* Parameters: a pointer pointer, an array of sizes
* Returns: nothing
* Summary:
* Notes: FIX THIS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
************************************/
void deallocate(int** rows, int* size)
{
    int** rowsWalker=rows;

    int sizeTotal=0;
    for (sizeTotal;size[sizeTotal]!=-1;sizeTotal++); //gives the amount of interesting elements size[] has

    // cout<<"DEBUG sizeTotal: "<<sizeTotal<<endl;

    for (int i=0;i<sizeTotal;i++)
    {
        // cout<<"DEBUG *rowsWalker: "<<*rowsWalker<<endl;
        delete [] *rowsWalker;
        rowsWalker++;
    }

    delete[] rows;
}

/***********************************
* Function:allocateWithPointers
* Purpose: allocates memory to use
* Parameters:takes an array of sizes
* Returns:address of allocated memory
* Summary:
* Notes:
************************************/
ITEM_TYPE** allocateWithPointers(int *size)
{
    int sizeTotal=0;
    for (sizeTotal;size[sizeTotal]!=-1;sizeTotal++); //gives the amount of interesting elements size[] has

    ITEM_TYPE** rows; //pointer that points to an array of pointers.
    rows=new ITEM_TYPE* [sizeTotal]; //makes an array of pointers [sizeTotal] long, and lets rows** point to it.

    ITEM_TYPE** rowsWalker=rows; //referencing a double pointer (rows**) I get the address of the first slot
    int* sizeWalker=size; //makes a walker for sizes so I know how long each normal int[] array is


    while(*sizeWalker!=-1) //by dereferencing sizeWalker I can check the value inside of the normal int [] array
    {

        //        *rowsWalker=new ITEM_TYPE [*sizeWalker]; // Using the  array of pointers called rowsWalker,
        // have 1 of the pointers point to a new normal array of ints that is *sizeWalker long.
        //*rowsWalker because I want address inside slot

        *rowsWalker= allocate(*sizeWalker); // Using the  array of pointers called rowsWalker,


        sizeWalker++;
        rowsWalker++;
    }



    return rows; //can only return a dynamic array, not a static!
}

/***********************************
* Function:allocate
* Purpose: allocates a 1 dimensional space
* Parameters: a size
* Returns: address of allocated space
* Summary:
* Notes:
************************************/
ITEM_TYPE* allocate(int size)
{
    ITEM_TYPE* temp=new ITEM_TYPE [size];

    return temp;
}

/***********************************
* Function:print
* Purpose: prints a 1 dimensional array
* Parameters: an array, a size
* Returns: nothing
* Summary:
* Notes:
************************************/
void print(ITEM_TYPE *array, int size)
{
    ITEM_TYPE* arrayWalker=array;

    for (int i=0;i<size;i++)
    {
        cout<<*arrayWalker<<" ";
        arrayWalker++;
    }

    cout<<endl;
}

/***********************************
* Function:printAll
* Purpose: prints an entire 2 dimensional array
* Parameters: address of an array of pointers, array of sizes
* Returns: nothing
* Summary:
* Notes:
************************************/
void printAll(ITEM_TYPE** array, int* size)
{
    ITEM_TYPE** arrayWalker=array;
    int* sizeWalker=size;

    int sizeTotal=0;
    for (sizeTotal;size[sizeTotal]!=-1;sizeTotal++); //gives the amount of interesting elements size[] has

    for (int i=0;i<sizeTotal;i++)
    {

        print(*arrayWalker,*sizeWalker); //<------ test this

        sizeWalker++;
        arrayWalker++;
    }

}

/***********************************
* Function:initializeAll
* Purpose: initializes an entire 2D array in numerical order starting from 0
* Parameters: a pointer pointer, an array of sizes
* Returns: nothing
* Summary:
* Notes:
************************************/
void initializeAll(ITEM_TYPE** array, int* size)
{
    ITEM_TYPE** arrayWalker=array;
    int* sizeWalker=size;

    int sizeTotal=0;
    for (sizeTotal;size[sizeTotal]!=-1;sizeTotal++); //gives the amount of interesting elements size[] has

    for (int i=0;i<sizeTotal;i++)
    {


        initialize(*arrayWalker,*sizeWalker);

        sizeWalker++;
        arrayWalker++;
    }

}

/***********************************
* Function:initialize
* Purpose:initializes an single 1D array in numerical order starting from 0
* Parameters: a pointer pointer, an array of sizes
* Returns: nothing
* Summary:
* Notes:
************************************/
void initialize(ITEM_TYPE *array, int size)
{
    ITEM_TYPE* arrayWalker=array;

    for (int i=0;i<size;i++)
    {
        *arrayWalker=0;
        arrayWalker++;
    }
}

/***********************************
* Function:exist
* Purpose: to check if a slot exists
* Parameters: a pointer pointer, an array of sizes, a row selection, a collumn selection
* Returns: true if slot exists, false if it doesn't
* Summary:
* Notes:
************************************/
bool exist(ITEM_TYPE** array,int* size, int row, int collumn) //REMEMBER size is NOT 0 based //tested and works, do a lowlvl func that helps with read/write<-----
{
    ITEM_TYPE** arrayWalker=array;
    int* sizeWalker=size;
    int sizeTotal=0;
    for (sizeTotal;size[sizeTotal]!=-1;sizeTotal++); //for counting how many interesting elements in size

    if (row<0 || row>sizeTotal) //[row] has to be between 0 and amount of rows
    {
        return false;
    }

    for (int i=0;i<row;i++) //walks the walkers to the specified row
    {
        sizeWalker++;
        arrayWalker++;
    }

    if (collumn<0 || collumn>*sizeWalker-1) //[collumn] has to be between 0 and the size-1. Has -1 because comparing 0 based with 1 based.
    {
        return false;
    }

    return true; //every obstacle has been passed, return true
}

/***********************************
* Function:at
* Purpose: gets the address of the specified row and collumn
* Parameters:a pointer pointer, an array of sizes, a row selection, a collumn selection
* Returns: address of specified row and collumn
* Summary:
* Notes:
************************************/
ITEM_TYPE* at(ITEM_TYPE** array,int* size, int row, int collumn)
{
    ITEM_TYPE** rowWalker=array;
    ITEM_TYPE* collWalker;

    int* sizeWalker=size;
    int sizeTotal=0;
    for (sizeTotal;size[sizeTotal]!=-1;sizeTotal++); //for counting how many interesting elements in size


    if (exist(array,size,row,collumn))
    {
        for (int i=0;i<row;i++) //walks the rowWalker to the specified row
        {
            rowWalker++;
        }
        collWalker=*rowWalker;

        for (int i=0;i<collumn;i++) //walks the collWalker to the specified collumn
        {
            collWalker++;
        }


        return collWalker;
    }

    else
    {
        cout<<"DOESN'T EXIST!!"<<endl;
        exit(0);

    }
}

/***********************************
* Function:read
* Purpose: gets the value at the specified row and column
* Parameters:a pointer pointer, an array of sizes, a row selection, a collumn selection
* Returns: the value at the specified row and column
* Summary:
* Notes:
************************************/
ITEM_TYPE read(ITEM_TYPE** array,int* size, int row, int collumn) //high level function
{
    return *at(array, size,row,collumn);
}

/***********************************
* Function:write
* Purpose: overwrites the value at the specified row and column with the input
* Parameters:a pointer pointer, an array of sizes, a row selection, a collumn selection, user input
* Returns:nothing
* Summary:
* Notes:
************************************/
void write(ITEM_TYPE** array,int* size, int row, int collumn, ITEM_TYPE input) //high level function
{
    *at(array, size,row,collumn)=input;
}

/***********************************
* Function:search
* Purpose: searches a single 1D array for the input and gives the position
* Parameters: an array, a size, a input
* Returns: address of where the input is found, or NULL if not found
* Summary:
* Notes:
************************************/
ITEM_TYPE* search(ITEM_TYPE *array, int size, ITEM_TYPE input)
{
    ITEM_TYPE* arrayWalker=array;

    for (int i=0;i<size;i++)
    {

        if (*arrayWalker==input)
        {
            return arrayWalker;
        }

        arrayWalker++;
    }


    cout<<"NOT FOUND returning null!!"<<endl;
    return NULL;
}

/***********************************
* Function:searchAll
* Purpose: searches an entire 2D array for the input, then returns the address of where it was found
* Parameters:
* Returns:address of where it was foundm otherwise returns NULL
* Summary:
* Notes:
************************************/
ITEM_TYPE* searchAll(ITEM_TYPE** array, int* size, ITEM_TYPE input)
{
    ITEM_TYPE** arrayWalker=array;
    int* sizeWalker=size;
    int sizeTotal=0;
    for (sizeTotal;size[sizeTotal]!=-1;sizeTotal++); //for counting how many interesting elements in size

    ITEM_TYPE* temp;

    for (int i=0;i<sizeTotal;i++)
    {
        temp=search(*arrayWalker,*sizeWalker,input);
        //cout<<"DEBUG temp: "; cout<<temp<<": "<<*temp<<endl;

        if(temp==NULL)
        {
            arrayWalker++;
            sizeWalker++;
        }
        else if (*temp==input)
        {
            return temp;
        }


    }


    return NULL;
}

void copy( ITEM_TYPE *source, int sourceSize, ITEM_TYPE*&destination, int &destinationSize)
{
    destinationSize=sourceSize;

    ITEM_TYPE* newArray= new ITEM_TYPE [sourceSize]; //make a new array the same size as the source

    ITEM_TYPE* sourceWalker=source;
    ITEM_TYPE* newArrayWalker=newArray;

    for (int i=0;i<sourceSize;i++) //then copy the all the old stuff into the new array
    {

        *newArrayWalker=*sourceWalker;

        sourceWalker++;
        newArrayWalker++;
    }

    if (destination!=NULL)
    {
        delete[] destination;
    }

    destination=newArray;

}

void copyAll(ITEM_TYPE **source, int *sourceSize, ITEM_TYPE**&destination, int *&destinationSize)
{

    ITEM_TYPE **sourceWalker=source;
    ITEM_TYPE **destinationWalker=destination;
    int* sourceSizeWalker=sourceSize;
    int* destinationSizeWalker;

    int sourceSizeTotal=0;
    for (sourceSizeTotal;sourceSize[sourceSizeTotal]!=-1;sourceSizeTotal++); //for counting how many interesting elements in size

//    cout<<"11111111"<<endl;

    copy(sourceSize,sourceSizeTotal+1,destinationSize,sourceSizeTotal); //copies the sizes
    destinationSizeWalker=destinationSize; //points destinationSizeWalker to the NEW destinationSize
//    cout<<"222222222"<<endl;

    deallocate(destination,destinationSize); //deallocate is causing unstability
//    cout<<"333333333"<<endl;


    destination=allocateWithPointers(destinationSize);//reallocates destination with the same amount of slots as source
//    cout<<"44444444"<<endl;


    while (*sourceSizeWalker!=-1)
    {
        copy(*sourceWalker,*sourceSizeWalker,*destinationWalker,*destinationSizeWalker);

        sourceSizeWalker++;
        destinationSizeWalker++;
        sourceWalker++;
        destinationWalker++;
    }





    //use copy() for sizes and *source & *destination
}


/***********************************
* Function:
* Purpose:
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
void addEntry(ITEM_TYPE* &array, int &size, ITEM_TYPE entry)
{

    ITEM_TYPE* newArray;

    copy(array,size,newArray,size);
    size++;

    ITEM_TYPE* newArrayWalker=newArray+size; //goes to end of new array

    *newArrayWalker=entry;

    delete[]array;

    array=newArray;


}
