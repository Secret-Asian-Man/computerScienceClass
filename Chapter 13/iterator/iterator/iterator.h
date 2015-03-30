#ifndef ITERATOR_H
#define ITERATOR_H
#include "node.h"


class iterator
{
public:

    //constructors
    iterator();
    iterator(node* head);

    //destructor
    ~iterator();

    //functions
    ITEM_TYPE data();



    friend class list;

private:
    node* _it;
};

#endif // ITERATOR_H
