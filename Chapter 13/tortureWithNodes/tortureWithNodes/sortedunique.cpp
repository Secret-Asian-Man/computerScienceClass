#include "sortedunique.h"
#include "iostream"
#include "LinkedListFuncs/linkedlistfunctions.h"

using namespace std;

/***********************************
* Function:sortedUnique (default)
* Purpose: default constructor
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
sortedUnique::sortedUnique()
{
    _head=NULL;

}

/***********************************
* Function:sortedUnique (with node)
* Purpose:
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
sortedUnique::sortedUnique(node* head)
{
    _head=NULL;

    node* headWalker=head;

    while(headWalker!=NULL)
    {
        insertSort(_head,headWalker->_item);
        headWalker=headWalker->next;
    }

}

/***********************************
* Function:sortedUnique (copy constructor)
* Purpose:
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
sortedUnique::sortedUnique(const sortedUnique& other)
{
    _head=NULL;
    copy(other._head,_head);
}

/***********************************
* Function: ~sortedUnique (destructor)
* Purpose:
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
sortedUnique::~sortedUnique()
{
    eraseAll(_head);
}

/***********************************
* Function:_printAll
* Purpose: printing out entire link-list for debugging
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
void sortedUnique::_printAll()
{
    printAll(_head);
}


/***********************************
* Function:_insert
* Purpose: inserts a single item into the right place
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
void sortedUnique::_insert(ITEM_TYPE item)
{
    insertSort(_head,item);
}

/***********************************
* Function:_insert
* Purpose: inserts an entire link-list with everything sorted
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
void sortedUnique::_insert(node* head)
{
    node* headWalker=head;

    while(headWalker!=NULL)
    {
        insertSort(_head,headWalker->_item);
        headWalker=headWalker->next;
    }

}

/***********************************
* Function:_delete
* Purpose: deletes a single node
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
void sortedUnique::_delete(node* position)
{
    deleteNode(_head, position);
}

/***********************************
* Function:_search
* Purpose: gets the address of the items you are searching for
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
node* sortedUnique::_search(ITEM_TYPE item)
{
    return search(_head,item);
}

/***********************************
* Function: operator []
* Purpose: gives the value of the item at the distance you specify
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
ITEM_TYPE sortedUnique::operator [](int pos)
{
    return at(_head,pos);
}

/***********************************
* Function: operator =
* Purpose: sets one instance of the class to equal another, with different addresses
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
sortedUnique& sortedUnique::operator =(const sortedUnique& other)
{
    eraseAll(_head);
    copy(other._head,_head);
}

/***********************************
* Function:get_head
* Purpose: gets the _head node
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
node* sortedUnique::get_head()
{
    return _head;
}
