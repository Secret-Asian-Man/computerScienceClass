#ifndef CURSOREDLIST_H
#define CURSOREDLIST_H

#include "iterator.h"
#include "list.h"

template <typename T>
class cursoredList:list<T>
{
public:
    cursoredList();
    ~cursoredList();

    void insertAfter(T input);
    void insertBefore(T input);
    void inserthead(T input);
    void Delete();
    Iterator<T> search(T key);
    void fill();
    void cursorLeft();
    void cursorRight();

    template <typename TT>
    friend std::ostream& operator <<(std::ostream& outs, const Iterator<TT> &printMe);



private:
Iterator<T> _cursor;

};


template <typename T>
cursoredList<T>::cursoredList():list<T>(NULL)
{

}


template <typename T>
cursoredList<T>::~cursoredList()
{

}


template <typename T>
void cursoredList<T>::insertAfter(T input)
{
    list<T>::_insertHead(input);
}

template <typename T>
void cursoredList<T>::insertBefore(T input)
{

}

template <typename T>
void cursoredList<T>::inserthead(T input)
{

}

template <typename T>
void cursoredList<T>::Delete()
{

}

template <typename T>
Iterator<T> cursoredList<T>::search(T key)
{

}

template <typename T>
void cursoredList<T>::fill()
{

}

template <typename T>
void cursoredList<T>::cursorLeft()
{

}

template <typename T>
void cursoredList<T>::cursorRight()
{

}

template <typename TT>
std::ostream& operator <<(std::ostream& outs, const Iterator<TT> &printMe)
{
    outs<<"["<<list<TT>::_print()<<"]-> ";
    return outs;
}


#endif // CURSOREDLIST_H
