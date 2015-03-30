#ifndef TWODPOINTERCLASS_H
#define TWODPOINTERCLASS_H
#include "lowlevelfunctions_2dpointers.h"

class twoDPointerClass
{
public:
    //constructors
    twoDPointerClass();
    twoDPointerClass(int* sizes);
    twoDPointerClass(const twoDPointerClass& other);
    //twoDPointerClass(twoDPointerClass other);

    //destructor
    ~twoDPointerClass();

    //functions
    ITEM_TYPE** _allocateWithPointers();
    void _deallocate();
    void _printAll();
    void _initializeAll();
    bool _exist(int row, int collumn);
    ITEM_TYPE* _at(int row, int collumn);
    ITEM_TYPE _read(int row, int collumn);
    void _write(int row, int collumn, ITEM_TYPE input);
    ITEM_TYPE* _searchAll(ITEM_TYPE input);
    void _copyAll(ITEM_TYPE **source, int *sourceSize);


    //operators
    twoDPointerClass& operator =(const twoDPointerClass& other);
    ITEM_TYPE* operator ()(int row, int collumn);


    //I want the sizes array to be dynamic.@@@@@@@@@@@@@@@@@@@@@

private:
    ITEM_TYPE** _rows;
    int* _sizes;

};

#endif // TWODPOINTERCLASS_H
