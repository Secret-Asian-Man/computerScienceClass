#ifndef ITERATOR_H
#define ITERATOR_H
#include "node.h"

template<typename T>
class Iterator
{
public:

    //constructors
    Iterator();
    Iterator(node<T>* head);

    //destructor
    ~Iterator();

    //functions
    T data();


    template <typename TT>
    friend class list;

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
