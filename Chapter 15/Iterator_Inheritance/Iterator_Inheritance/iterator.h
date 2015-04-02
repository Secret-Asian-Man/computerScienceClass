#ifndef ITERATOR_H_INCLUDED
#define ITERATOR_H_INCLUDED
#include "node.h"

template<typename T>
class Iterator
{

public:

    template<typename TT>
    friend class list;

    //constructors
    Iterator();
    Iterator(node<T>* head);

    //destructor
    ~Iterator();

    //functions
    T data();

    //operators
    //Iterator ==(const Iterator& other);

private:
    node<T>* _it;
};


template<typename T>
Iterator<T>::Iterator()
{
    _it=NULL;
}

template<typename T>
Iterator<T>::Iterator(node<T>* head)
{
    _it=head;
}

template<typename T>
T Iterator<T>::data()
{
    return _it->_item;
}



#endif // ITERATOR_H
