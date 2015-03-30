#ifndef STACK_H
#define STACK_H
#include "LinkedListFuncs/linkedlistfunctions.h"

//NEED BIG 3
//NEED BIG 3
//NEED BIG 3
//NEED BIG 3
//NEED BIG 3



class stack
{
public:
    //constructors
    stack();
    stack(const stack& other); //BIG 3:copy constructor

    //destructors
    ~stack();//BIG 3:destructor

    //functions
    void push(ITEM_TYPE item);
    ITEM_TYPE pop();
    bool empty();
    ITEM_TYPE peek();
    void print();


    stack& operator =(const stack& other); //BIG 3: = operator



private:
    node* _top;
};

#endif // STACK_H
