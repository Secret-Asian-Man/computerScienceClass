//note: change ALL the node<T>* to Iterator<T>
//The functions will take in a Iterator<T>, convert it to a node<T>*, process, convert it back to a Iterator<T>, then finally return the iterator<T>
//Convert Iterators<T> into node<T>* by accessing the Iterator's

#ifndef LIST_H
#define LIST_H
#include "node.h"
#include "Iterator.h"
#include "linkedlistfunctions.h"

template<typename T>
class list
{
public:
    //constructors
    list();
    list(Iterator<T> head);
    list(const list& other); //BIG 3:copy constructor (DONE!)
    list(T input);
    ~list();//BIG 3:destructor (DONE!)

    //accessors
    Iterator<T> getHead();


    //functions
    void _print();
    Iterator<T> _walker(int distance);
    Iterator<T> _search(T key);
    Iterator<T> _findPrevious(Iterator<T>position);
    void _printAll();
    void _deleteNode(Iterator<T> position);
    void _deleteNode(T type);
    void _insertHead( T number);
    void _insertAfter(Iterator<T> position, T input);
    void _insertBefore( Iterator<T> position, T input);
    int _nodeCount();
    void _insertSort(T input);
    void _swap(Iterator<T>& A, Iterator<T>& B);
    T _at(int pos);
    void _reverse();
    void _deleteRepeat();
    //void _shuffle();
    void _copy(list source); //still needs testing
    void _eraseAll();

    T& operator [](int pos); //runs _at
    void friend operator +=(list& destination,const list& other);
    list& operator =(const list& other); //BIG 3: = operator (done?)
//    void friend operator =(list& destination, const list& source);

private:
    node<T>* _head;
};




template<typename T>
list<T>::list()
{
    _head=NULL;
}

template<typename T>
list<T>::list(Iterator<T> head)
{
    _head=NULL;
    copy(head,_head);
}

template<typename T>
list<T>::list(const list& other)
{
    _head=NULL;
    copy(other._head,_head);
}

template<typename T>
list<T>::list(T input)
{

    _head=NULL;
    insertHead(_head,input);
}

template<typename T>
list<T>::~list()
{
    _eraseAll();
}

template<typename T>
Iterator<T> list<T>::getHead()
{
    return Iterator<T>(_head);
}


template<typename T>
void list<T>::_print()
{
    print(_head);
}

template<typename T>
Iterator<T> list<T>::_walker(int distance)
{
    return Iterator<T>(walker(_head,distance));
}

template<typename T>
Iterator<T> list<T>::_search(T key)
{
    return Iterator<T>(search(_head,key));
}

template<typename T>
Iterator<T> list<T>::_findPrevious(Iterator<T> position)
{
    return Iterator<T>(findPrevious(_head,position._it));
}

template<typename T>
void list<T>::_printAll()
{
    printAll(_head);
}

template<typename T>
void list<T>::_deleteNode(Iterator<T> position)
{
    deleteNode(_head,position._it);
}

template<typename T>
void list<T>::_deleteNode(T type)
{
    deleteNode(_head,type);

}

template<typename T>
void list<T>::_insertHead( T number)
{
    insertHead(_head,number);
}

template<typename T>
void list<T>::_insertAfter(Iterator<T> position, T input)
{
    insertAfter(_head,position._it,input);
}

template<typename T>
void list<T>::_insertBefore( Iterator<T> position, T input)
{
    insertBefore(_head,position._it,input);
}

template<typename T>
int list<T>::_nodeCount()
{
    return nodeCount(_head);
}

template<typename T>
void list<T>::_insertSort(T input)
{
    insertSort(_head,input);
}

template<typename T>
void list<T>::_swap(Iterator<T>& A, Iterator<T>& B)
{
    swap(A._it,B._it);
}

template<typename T>
T list<T>::_at(int pos)
{
    return at(_head,pos);
}

template<typename T>
void list<T>::_reverse()
{
    reverse(_head);
}

template<typename T>
void list<T>::_deleteRepeat()
{
    deleteRepeat(_head);
}

template<typename T>
void list<T>::_copy(list<T> source)
{
    //should work, don't know why it DOESN'T WORK!
    copy(source._head,_head); //already have erase all in lower lvl copy
}

template<typename T>
void list<T>::_eraseAll()
{
    eraseAll(_head);
}

template<typename T>
T& list<T>::operator [](int pos)
{
    return _at(pos);
}

template<typename T>
void operator +=(list<T>& destination, const list<T>& source)
{
    Iterator<T> destinationEnd=walker(destination._head,nodeCount(destination._head)-1); //at the last node of itself
    Iterator<T> sourceWalker=source._head;

    while(sourceWalker!=NULL)
    {
        insertAfter(destination._head,destinationEnd._it,sourceWalker._it->_item);

        destinationEnd=walker(destination._head,nodeCount(destination._head)-1); //WARNING: taking advantage of exception in walker() function, ignore warning!
        //sets to the new last node
        //destinationEnd=destinationEnd->next; //sets the end to the new end
        sourceWalker=sourceWalker._it->next;
    }


}

template<typename T>
list<T> &list<T>::operator =(const list<T>& other)
{

    //might need return this

    eraseAll(_head);
    copy(other._head,_head);

}


#endif // LIST_H
