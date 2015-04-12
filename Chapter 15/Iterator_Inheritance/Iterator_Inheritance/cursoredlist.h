// cursoredList is a child from the 2 parents list and iterator. Use functions from list and iterator to make a list of nodes that has a interator.
//Iterator is just a node pointer, calm down.


#ifndef CURSOREDLIST_H
#define CURSOREDLIST_H

#include "iterator.h"
#include "list.h"
#include "random.h"

template <typename T>
class cursoredList:public list<T>, public Iterator<T>
{
public:
    cursoredList();
    cursoredList(Iterator<T> cursor);
    cursoredList(const cursoredList& other); //BIG 3:copy constructor
    ~cursoredList();

    void insertAfter(const T &input);
    void insertBefore(const T &input);
    void inserthead(const T &input);
    void Delete();
    void search(const T &key);
    void fill();
    void cursorLeft();
    void cursorRight();
    bool isNull();

    void print();

    template <typename TT>
    friend std::ostream& operator <<(std::ostream& outs, const Iterator<TT> &printMe);

    cursoredList& operator =(const cursoredList& other); //BIG 3: = operator


private:
    Iterator<T> _cursor;

};


template <typename T>
cursoredList<T>::cursoredList():list<T>()
{
    _cursor=list<T>::getHead(); //sets the iterator to point at null
}

template <typename T>
cursoredList<T>::cursoredList(Iterator<T> cursor):list<T>(cursor)
{
    _cursor=list<T>::getHead();//sets the iterator to point at null
}

template <typename T>
cursoredList<T>::~cursoredList()
{
    cout<<"cursorList ended!!!"<<endl;

}


template <typename T>
void cursoredList<T>::insertAfter(const T &input)
{
    if (isNull()==false)
    {
        list<T>::_insertAfter(_cursor,input);
    }
    else
    {
        list<T>::_insertHead(input);
    }

}

template <typename T>
void cursoredList<T>::insertBefore(const T &input)
{
    if (isNull()==false)
    {
        list<T>::_insertBefore(_cursor, input);
    }
    else
    {
        list<T>::_insertHead(input);
    }
}

template <typename T>
void cursoredList<T>::inserthead(const T &input)
{
    list<T>::_insertHead(input);
    _cursor=list<T>::getHead(); //sets the iterator to point at the head
}

/***********************************
* Function:Delete()
* Purpose: deletes a node
* Parameters:
* Returns:
* Summary:
* Notes: Has 2 exceptions: deleting nothing, deleting last node, deleting frist node
************************************/
template <typename T>
void cursoredList<T>::Delete()
{
    if (isNull()==false)//if the list isn't empty...
    {
        if (_cursor._it->next==NULL) //if this is the last node...
        {
            Iterator<T> temp=_cursor;

            _cursor= list<T>::_findPrevious(_cursor);
            list<T>::_deleteNode(temp);
        }
        else if(true) //if this is the first node...
        {
            Iterator<T> temp=_cursor;
            _cursor._it=_cursor._it->next;
            list<T>::_deleteNode(temp);


        }
        else
        {
            list<T>::_deleteNode(_cursor);  //else just delete it normally
        }
    }
    else
    {
        cout<<"DEBUG LIST IS EMPTY!! "<<endl;
    }

}

template <typename T>
void cursoredList<T>::search(const T &key)
{
    Iterator<T> found=list<T>::_search(key);

    if (true)
    {

        if (found==NULL)
        {
            return;
        }
        else
            _cursor=list<T>::_search(key);

    }



}

template <typename T>
void cursoredList<T>::fill()
{

    random ran1(1,10);
    random ran2(1,10);


    for (int i=0;i<ran1.getRandomNumber();i++)
    {

        list<T>::_insertHead(ran2.getRandomNumber());

    }

}

template <typename T>
void cursoredList<T>::cursorLeft()
{
    if (isNull()==false && _cursor!=list<T>::getHead()) //if the list isn't empty and the iterator isn't at the first node then...
    {
        _cursor=list<T>::_findPrevious(_cursor); //decrement the iterator
    }

}

template <typename T>
void cursoredList<T>::cursorRight()
{
    if (  isNull()==false && _cursor._it->next!=NULL) //if the list isn't empty, and iterator is not at the last node then...
    {
        _cursor._it=_cursor._it->next; //increment the iterator
    }

}

template <typename T>
bool cursoredList<T>::isNull()
{
    if (_cursor._it==NULL)
        return true;
    else
        return false;
}

template <typename T>
void cursoredList<T>::print()
{

    node<T>* walker=list<T>::getHead()._it;


    while(walker)
    {
        if (walker ==_cursor._it)
        {
            cout << "*" << *walker;
        }
        else
        {
            cout << *walker;
        }
        walker=walker->next;
        //have a walker walk along the link-list, and if the
        //address of the current node is the same as the address
        //of the iterator, print out brackets.

    }
    cout<<"NULL" << endl;


}


template <typename TT>
std::ostream& operator <<(std::ostream& outs, const Iterator<TT> &printMe)
{
    outs<<"["<<list<TT>::_print()<<"]-> ";
    return outs;
}



#endif // CURSOREDLIST_H
