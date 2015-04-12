#ifndef ITERATOR_H_INCLUDED
#define ITERATOR_H_INCLUDED
#include "node.h"
#include "linkedlistfunctions.h"

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
    bool operator ==(const Iterator& other);
    bool operator !=(const Iterator& other);

    T operator *();

    void operator ++();

//private:
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

Iterator<T>::~Iterator()
{

}


template<typename T>
T Iterator<T>::data()
{
    return _it->_item;
}

template<typename T>
T Iterator<T>:: operator *()
{
    return _it->_item;
}

template<typename T>
bool Iterator<T>::operator ==(const Iterator& other)
{
    if (_it==other._it)
    {
        return true;
    }

    else
    {
        return false;
    }
}

template<typename T>
bool Iterator<T>::operator !=(const Iterator& other)
{
    if (_it==other._it)
    {
        return false;
    }

    else
    {
        return true;
    }
}


template<typename T>
void Iterator<T>:: operator ++()
{
    _it=_it->next;
}



#endif // ITERATOR_H
