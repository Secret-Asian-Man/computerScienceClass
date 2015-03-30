#ifndef PLANE_H
#define PLANE_H
#include "twodpointerclass.h"


class plane
{
public:
    plane();

    plane(twoDPointerClass other);
    plane(ITEM_TYPE* sizes);

    ~plane();

    void reserve (int row, int collumn, ITEM_TYPE id);
    void cancel(int id);
    bool isAvailible(int row, int collumn);
    ITEM_TYPE* search(ITEM_TYPE key);



private:
    twoDPointerClass _plane;
    int* _sizes;

};

#endif // PLANE_H
