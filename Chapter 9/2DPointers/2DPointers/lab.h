#ifndef LAB_H
#define LAB_H
#include "twodpointerclass.h"

class lab
{
public:
    lab();
    lab(twoDPointerClass other);
    lab(ITEM_TYPE* sizes);

    ~lab();

    void login (int row, int collumn, ITEM_TYPE id);
    void logout(int id);
    bool isAvailible(int row, int collumn);
    ITEM_TYPE* search(ITEM_TYPE key);



private:
    twoDPointerClass _lab;
    int* _sizes;
};

#endif // LAB_H
