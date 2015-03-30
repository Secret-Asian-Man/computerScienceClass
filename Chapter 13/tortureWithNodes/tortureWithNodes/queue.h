#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedListFuncs/linkedlistfunctions.h"

//STILL NEED BIG 3
//STILL NEED BIG 3
//STILL NEED BIG 3
//STILL NEED BIG 3
//STILL NEED BIG 3

class queue
{
public:
    //constructors
    queue();
    queue(const queue& other);//BIG 3:copy constructor

    //destructors
    ~queue();//BIG 3:destructor

    //functions
    void push(ITEM_TYPE item);
    ITEM_TYPE pop();
    bool empty();
    ITEM_TYPE peek();
    void print();

    //operators
    queue& operator =(const queue& other);//BIG 3: = operator



private:
    node* _front;
    node* _rear;
};

#endif // QUEUE_H
