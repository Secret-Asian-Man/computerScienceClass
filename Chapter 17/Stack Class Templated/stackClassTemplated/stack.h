#ifndef STACK_H
#define STACK_H
#include "linkedlistfunctions.h"


template<typename T>
class stack
{
public:
    //constructors
    stack();
    stack(const stack& other); //BIG 3:copy constructor

    //destructors
    ~stack();//BIG 3:destructor

    //functions
    void push(T item);
    T pop();
    bool empty();
    T peek();
    void print();


    stack& operator =(const stack<T> &other); //BIG 3: = operator



private:
    node<T>* _top;
};

template<typename T>
stack<T>::stack()
{
    _top=NULL;
}

template<typename T>
stack<T>::stack(const stack& other)
{
    _top=NULL;
    copy(other._top,_top);
}

template<typename T>
stack<T>::~stack()
{
    eraseAll(_top);
}

template<typename T>
stack<T>& stack<T>::operator =(const stack<T>& other)
{
    eraseAll(_top);
    copy(other._top,_top);
}

template<typename T>
void stack<T>::push(T item)
{
    insertHead(_top,item);
}

template<typename T>
T stack<T>::pop()
{

    if (empty()==false)
    {
    T bank=_top->_item;
    deleteNode(_top,_top);
    return bank;
    }
    else
    {
        cout<<"pop EMPTY"<<endl;
        exit(1);
    }


}

template<typename T>
bool stack<T>::empty()
{

    if (_top==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }

}

template<typename T>
T stack<T>::peek()
{

    if (empty()==false)
    {
    return _top->_item;
    }
    else
    {
        cout<<"peek EMPTY"<<endl;
        exit(1);
    }

}

template<typename T>
void stack<T>::print()
{
    printAll(_top);
}

#endif // STACK_H
