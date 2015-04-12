#ifndef CURSOREDLIST_H
#define CURSOREDLIST_H

#include "iterator.h"
#include "list.h"

template <typename T>
class cursoredList:public list<T>
{
public:
    cursoredList();
    cursoredList(Iterator<T> cursor);
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
    //blank
}

template <typename T>
cursoredList<T>::cursoredList(Iterator<T> cursor):list<T>(cursor)
{
    //blank
}

template <typename T>
cursoredList<T>::~cursoredList()
{
    //    list<T>::~list();
}


template <typename T>
void cursoredList<T>::insertAfter(T input)
{
    list<T>::_insertAfter(_cursor,input);
}

template <typename T>
void cursoredList<T>::insertBefore(T input)
{
    list<T>::_insertBefore(_cursor, input);
}

template <typename T>
void cursoredList<T>::inserthead(T input)
{
    list<T>::_insertHead(input);
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
    _cursor=list<T>::_findPrevious(_cursor);
}

template <typename T>
void cursoredList<T>::cursorRight()
{
    _cursor._it=_cursor._it->next;
}

template <typename TT>
std::ostream& operator <<(std::ostream& outs, const Iterator<TT> &printMe)
{
    outs<<"["<<list<TT>::_print()<<"]-> ";
    return outs;
}


#endif // CURSOREDLIST_H
