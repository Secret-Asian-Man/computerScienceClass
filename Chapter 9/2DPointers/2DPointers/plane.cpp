#include "plane.h"
#include "iostream"

plane::plane()
{
    twoDPointerClass temp;

    _plane=temp;
    _sizes=NULL;

}

plane::plane(twoDPointerClass other)
{
    _plane=other; //equal operator already takes care of deallocation
}

plane::plane(ITEM_TYPE* sizes)
{
    _sizes=sizes;
    twoDPointerClass temp(_sizes);

    _plane=temp;

}

plane::~plane()
{
    _plane._deallocate();
    delete[] _sizes;
}

void plane::reserve (int row, int collumn, ITEM_TYPE id)
{
    _plane._write(row,collumn,id);
}

void plane::cancel(int id)
{
    ITEM_TYPE* temp=_plane._searchAll(id);

    if (temp!=NULL)
    {
        *temp=0;
    }
}

bool plane::isAvailible(int row, int collumn)
{
    return _plane._exist(row, collumn);
}

ITEM_TYPE* plane::search(ITEM_TYPE key)
{
    return _plane._searchAll(key);
}
