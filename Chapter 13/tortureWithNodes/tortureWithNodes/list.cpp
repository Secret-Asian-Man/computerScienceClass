#include "list.h"
#include "LinkedListFuncs/linkedlistfunctions.h"
#include "iostream"
using namespace std;

//need to finish copy and copy constructor and eraseAll


list::list()
{
    _head=NULL;
}
list::list(node* head)
{
    _head=NULL;
    copy(head,_head);
}

list::list(const list& other)
{
    _head=NULL;
    copy(other._head,_head);
}

list::list(ITEM_TYPE input)
{

    _head=NULL;
    insertHead(_head,input);
}



list::~list()
{
    _eraseAll();
}

node* list::getHead()
{
    return _head;
}


void list::_print()
{
    print(_head);
}

node* list::_walker(int distance)
{
    return walker(_head,distance);
}

node* list::_search(ITEM_TYPE key)
{
    return search(_head,key);
}

node* list::_findPrevious(node* position)
{
    return findPrevious(_head,position);
}

void list::_printAll()
{
    printAll(_head);
}

void list::_deleteNode(node* position)
{
    deleteNode(_head,position);
}

void list::_deleteNode(ITEM_TYPE type)
{
    deleteNode(_head,type);

}

void list::_insertHead( ITEM_TYPE number)
{
    insertHead(_head,number);
}

void list::_insertAfter(node* position, ITEM_TYPE input)
{
    insertAfter(_head,position,input);
}

void list::_insertBefore( node* position, ITEM_TYPE input)
{
    insertBefore(_head,position,input);
}

int list::_nodeCount()
{
    return nodeCount(_head);
}

void list::_insertSort(ITEM_TYPE input)
{
    insertSort(_head,input);
}

void list::_swap(node*& A, node*& B)
{
    swap(A,B);
}

ITEM_TYPE list::_at(int pos)
{
    return at(_head,pos);
}

void list::_reverse()
{
    reverse(_head);
}

void list::_deleteRepeat()
{
    deleteRepeat(_head);
}

//void list::_shuffle()
//{
//    shuffle(_head);
//}

void list::_copy(list source)
{
    //should work, don't know why it DOESN'T WORK!
    copy(source._head,_head); //already have erase all in lower lvl copy
}

void list::_eraseAll()
{
    eraseAll(_head);
}


ITEM_TYPE list::operator [](int pos)
{
    return _at(pos);
}

void operator +=(list& destination, const list& source)
{
    node* destinationEnd=walker(destination._head,nodeCount(destination._head)-1); //at the last node of itself
    node* sourceWalker=source._head;

    while(sourceWalker!=NULL)
    {
        insertAfter(destination._head,destinationEnd,sourceWalker->_item);

        destinationEnd=walker(destination._head,nodeCount(destination._head)-1); //WARNING: taking advantage of exception in walker() function, ignore warning!
        //sets to the new last node
        //destinationEnd=destinationEnd->next; //sets the end to the new end
        sourceWalker=sourceWalker->next;
    }


}

list &list::operator =(const list& other)
{

    //might need return this

    eraseAll(_head);
    copy(other._head,_head);

}

//void list::operator =(list& destination, const list& source)
//{
//    copy(source._head,destination._head);

//}

