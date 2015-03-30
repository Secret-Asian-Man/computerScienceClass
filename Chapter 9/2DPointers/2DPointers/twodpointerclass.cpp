#include "twodpointerclass.h"

twoDPointerClass::twoDPointerClass()
{
    _sizes=new int[1];
    _sizes[0]=-1;

    _rows=_allocateWithPointers();
    _initializeAll();

}

twoDPointerClass::twoDPointerClass(int* sizes)
{
    _sizes=sizes;

    _rows=_allocateWithPointers();
    _initializeAll();
}


twoDPointerClass::twoDPointerClass(const twoDPointerClass& other)
{

    _copyAll(other._rows,other._sizes);

}


twoDPointerClass::~twoDPointerClass()
{
    _deallocate();
}

/***********************************
* Function: deallocate
* Purpose: releases memory
* Parameters: a pointer pointer, an array of sizes
* Returns: nothing
* Summary:
* Notes: FIX THIS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
************************************/
void twoDPointerClass::_deallocate()
{
    deallocate(_rows,_sizes);
}

/***********************************
* Function:allocateWithPointers
* Purpose: allocates memory to use
* Parameters:takes an array of sizes
* Returns:address of allocated memory
* Summary:
* Notes:
************************************/
ITEM_TYPE** twoDPointerClass::_allocateWithPointers()
{
    return allocateWithPointers(_sizes);
}

/***********************************
* Function:printAll
* Purpose: prints an entire 2 dimensional array
* Parameters: address of an array of pointers, array of sizes
* Returns: nothing
* Summary:
* Notes:
************************************/
void twoDPointerClass::_printAll()
{
    printAll(_rows,_sizes);
}

/***********************************
* Function:initializeAll
* Purpose: initializes an entire 2D array in numerical order starting from 0
* Parameters: a pointer pointer, an array of sizes
* Returns: nothing
* Summary:
* Notes:
************************************/
void twoDPointerClass::_initializeAll()
{
    initializeAll(_rows,_sizes);
}

/***********************************
* Function:exist
* Purpose: to check if a slot exists
* Parameters: a pointer pointer, an array of sizes, a row selection, a collumn selection
* Returns: true if slot exists, false if it doesn't
* Summary:
* Notes:
************************************/
bool twoDPointerClass::_exist(int row, int collumn) //REMEMBER size is NOT 0 based //tested and works, do a lowlvl func that helps with read/write<-----
{
    return exist(_rows,_sizes,row, collumn);
}

/***********************************
* Function:at
* Purpose: gets the address of the specified row and collumn
* Parameters:a pointer pointer, an array of sizes, a row selection, a collumn selection
* Returns: address of specified row and collumn
* Summary:
* Notes:
************************************/
ITEM_TYPE* twoDPointerClass::_at(int row, int collumn)
{
    return at(_rows, _sizes, row, collumn);
}

/***********************************
* Function:read
* Purpose: gets the value at the specified row and column
* Parameters:a pointer pointer, an array of sizes, a row selection, a collumn selection
* Returns: the value at the specified row and column
* Summary:
* Notes:
************************************/
ITEM_TYPE twoDPointerClass::_read(int row, int collumn) //high level function
{
    return read(_rows,_sizes,row,collumn);
}

/***********************************
* Function:write
* Purpose: overwrites the value at the specified row and column with the input
* Parameters:a pointer pointer, an array of sizes, a row selection, a collumn selection, user input
* Returns:nothing
* Summary:
* Notes:
************************************/
void twoDPointerClass::_write(int row, int collumn, ITEM_TYPE input) //high level function
{
    write(_rows,_sizes,row,collumn,input);
}

/***********************************
* Function:searchAll
* Purpose: searches an entire 2D array for the input, then returns the address of where it was found
* Parameters:
* Returns:address of where it was foundm otherwise returns NULL
* Summary:
* Notes:
************************************/
ITEM_TYPE* twoDPointerClass::_searchAll(ITEM_TYPE input)
{
    return searchAll(_rows,_sizes,input);
}


void twoDPointerClass::_copyAll(ITEM_TYPE **source, int *sourceSize)
{

    ITEM_TYPE **sourceWalker=source;
    ITEM_TYPE **destinationWalker=_rows;
    int* sourceSizeWalker=sourceSize;
    int* destinationSizeWalker;

    int sourceSizeTotal=0;
    for (sourceSizeTotal;sourceSize[sourceSizeTotal]!=-1;sourceSizeTotal++); //for counting how many interesting elements in size

//    cout<<"11111111"<<endl;

    copy(sourceSize,sourceSizeTotal+1,_sizes,sourceSizeTotal); //copies the sizes
    destinationSizeWalker=_sizes; //points destinationSizeWalker to the NEW destinationSize
//    cout<<"222222222"<<endl;

    deallocate(_rows,_sizes); //deallocate is causing unstability
//    cout<<"333333333"<<endl;


    _rows=allocateWithPointers(_sizes);//reallocates destination with the same amount of slots as source
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

twoDPointerClass& twoDPointerClass::operator =(const twoDPointerClass& other)
{

    _deallocate();
    _copyAll(other._rows,other._sizes);


}
ITEM_TYPE* twoDPointerClass::operator ()(int row, int collumn)
{
     return _at(row,collumn);
}
