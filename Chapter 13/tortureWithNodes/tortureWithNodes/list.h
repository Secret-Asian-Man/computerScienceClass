#ifndef LIST_H
#define LIST_H
#include "nodes/node.h"

class list
{
    //fix _copy
    //do copy constructor
    //do = operator


public:
    //constructors
    list();
    list(node* head);
    list(const list& other); //BIG 3:copy constructor (DONE!)
    list(ITEM_TYPE input);
    ~list();//BIG 3:destructor (DONE!)

    //accessors
    node* getHead();


    //functions
    void _print();
    node* _walker(int distance);
    node* _search(ITEM_TYPE key);
    node* _findPrevious(node*position);
    void _printAll();
    void _deleteNode(node* position);
    void _deleteNode(ITEM_TYPE type);
    void _insertHead( ITEM_TYPE number);
    void _insertAfter(node* position, ITEM_TYPE input);
    void _insertBefore( node* position, ITEM_TYPE input);
    int _nodeCount();
    void _insertSort(ITEM_TYPE input);
    void _swap(node*& A, node*& B);
    ITEM_TYPE _at(int pos);
    void _reverse();
    void _deleteRepeat();
    //void _shuffle();
    void _copy(list source); //still needs testing
    void _eraseAll();

    ITEM_TYPE operator [](int pos); //runs _at
    void friend operator +=(list& destination,const list& other);
    list& operator =(const list& other); //BIG 3: = operator (done?)
//    void friend operator =(list& destination, const list& source);

private:
    node* _head;
};

#endif // LIST_H
