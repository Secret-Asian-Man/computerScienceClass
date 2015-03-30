#ifndef LIST_H
#define LIST_H
#include "node.h"
#include "iterator.h"

class list
{
public:
    //constructors
    list();

    //destructor
    ~list();

    //functions
    void _printAll();
    void _print();
    iterator _search(ITEM_TYPE key);
    void _insertHead( ITEM_TYPE number);
    void _insertBefore( node* position, ITEM_TYPE input);
    void _insertAfter(node* position, ITEM_TYPE input);
    void _insertSort(ITEM_TYPE input);
    void _swap(node*& A, node*& B);
    ITEM_TYPE _at(int pos);




private:
    node* _head;

};

#endif // LIST_H


//f(iterator Xi)//converts interator to node*
//{
//    node* x;
//    x=xi._head;
//}

//iterator f()//converts node* to interator
//{
//    node* x;

//    return iterator(x)
//}
