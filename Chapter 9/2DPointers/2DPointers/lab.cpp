#include "lab.h"

#include <iostream>

lab::lab()
{
    twoDPointerClass temp;

    _lab=temp;
    _sizes=NULL;

}

lab::lab(twoDPointerClass other)
{
    _lab=other; //equal operator already takes care of deallocation
}

lab::lab(ITEM_TYPE* sizes)
{
    _sizes=sizes;
    twoDPointerClass temp(_sizes);

    _lab=temp;

}

lab::~lab()
{
    _lab._deallocate();
    delete[] _sizes;
}

void lab::login (int row, int collumn, ITEM_TYPE id)
{
    _lab._write(row,collumn,id);
}

void lab::logout(int id)
{
    ITEM_TYPE* temp=_lab._searchAll(id);

    if (temp!=NULL)
    {
        *temp=0;
    }
}

bool lab::isAvailible(int row, int collumn)
{
    return _lab._exist(row, collumn);
}

ITEM_TYPE* lab::search(ITEM_TYPE key)
{
    return _lab._searchAll(key);
}
