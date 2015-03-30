#include "queue.h"
#include "iostream"
using namespace std;

queue::queue()
{
    _front=_rear=NULL;
}

queue::queue(const queue& other)
{
    _front=_rear=NULL;
    copy(other._front,_front);
}

queue::~queue()
{
    _rear=NULL;
    eraseAll(_front);
}

/***********************************
* Function:push
* Purpose: puts items in the link-list
* Parameters: the item you want to put in
* Returns:
* Summary:adds items to end of the list using insertAfter(_front,_rear), and keeping track where
*         _rear is.
* Notes:
************************************/
void queue::push(ITEM_TYPE item)
{
    if (empty())
    {
        insertHead(_front,item);
        _rear=_front;
    }
    else
    {
        insertAfter(_front,_rear,item);
        _rear=_rear->next;
    }
}

/***********************************
* Function:pop
* Purpose: deletes the next node and returns the value
* Parameters: none
* Returns: value of deleted node which is the last node
* Summary:runs deleteNode() on _front, and sets _front to the new next node.
*           then returns the value of the node it deleted.
* Notes: if the list is empty exit the program by returning nothing or running exit.
************************************/
ITEM_TYPE queue::pop()
{
    if (empty()==false)
    {
        ITEM_TYPE bank=_front->_item;

        deleteNode(_front,_front);

        return bank;
    }
    else
    {
        cout<<"pop EMPTY!!"<<endl;
        exit(1);
    }


}

/***********************************
* Function:empty
* Purpose: checks if the link-list is empty
* Parameters: none
* Returns: true if list is empty, false if the list has something in it
* Summary:
* Notes:
************************************/
bool queue::empty()
{

    if (_front==NULL) //if list is empty...
    {
        return true;
    }
    else
    {
        return false;
    }

}

/***********************************
* Function:peek
* Purpose: looks at the value of the next node in line
* Parameters: none
* Returns: value of the next node in line
* Summary: returns the value of _front
* Notes:
************************************/
ITEM_TYPE queue::peek()
{
    if (empty()==false)
    {
        return _front->_item;
    }
    else
    {
        cout<<"peek EMPTY!!"<<endl;
        exit(1);
    }
}

/***********************************
* Function:print
* Purpose:
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
void queue::print()
{
    printAll(_front);
}

queue& queue::operator =(const queue& other)
{

    eraseAll(_front);
    copy(other._front,_front);
    _rear=walker(_front,nodeCount(_front)-1);

}
