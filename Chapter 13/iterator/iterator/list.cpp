#include "list.h"
#include "linkedlistfunctions.h"

list::list()
{
    _head=NULL;
}

list::~list()
{

}

void list::_print()
{
    print(_head);
}

void list::_printAll()
{
    printAll(_head);
}

iterator list::_search(ITEM_TYPE key)
{
    return iterator(search(_head,key));
}

void list::_insertHead( ITEM_TYPE number)
{
    insertHead(_head,number);
}

void list::_insertBefore( node* position, ITEM_TYPE input)
{
    insertBefore(_head,position,input);
}

void list::_insertAfter(node* position, ITEM_TYPE input)
{
    insertAfter(_head,position,input);
}

void list::_insertSort(ITEM_TYPE input)
{
    insertSort(_head,input);
}

void list::_swap(node*& A, node*& B)
{
    swap(A,B);
}
