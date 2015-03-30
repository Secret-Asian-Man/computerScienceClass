#ifndef SORTEDUNIQUE_H
#define SORTEDUNIQUE_H
#include "nodes/node.h"

class sortedUnique
{
public:

    //constructors
    sortedUnique();
    sortedUnique(node* head);
    sortedUnique(const sortedUnique& other);

    //destructors
    ~sortedUnique();

    //accessors
    node* get_head();

    //functions
    void _insert(ITEM_TYPE item);
    void _insert(node* head);
    void _delete(node* position);
    node* _search(ITEM_TYPE item);
    void _printAll();

    //operators
    ITEM_TYPE operator [](int pos);
    sortedUnique& operator =(const sortedUnique& other);


private:
    node* _head;
};

#endif // SORTEDUNIQUE_H
