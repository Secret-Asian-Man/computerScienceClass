#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <iostream>
#include<fstream>

template<typename T>
class node
{
public:
    //constructors
    node();
    node(T item);

    T _item;
    node* next;

  //operators

    template <typename TT>
    friend std::ostream& operator <<(std::ostream& outs, const node<TT> &printMe);
    //friend operator =(node A,node B);

};

template <typename T>
node<T>::node():_item(), next(NULL)
{
//    _item=;
//    next=NULL;

}

template <typename T>
node<T>::node(T item)
{
    _item=item;
    next=NULL;
}

template <typename TT>
std::ostream& operator <<(std::ostream& outs, const node<TT> &printMe)
{
    outs<<"["<<printMe._item<<"]-> ";
    return outs;
}

#endif // NODE_H
