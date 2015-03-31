#ifndef LINKEDLISTFUNCTIONS_H
#define LINKEDLISTFUNCTIONS_H
#include "node.h"
#include "iterator.h"

template<typename T>
void print(node<T>* head);

template<typename T>
node<T>* walker(node<T>* head, int distance);

template<typename T>
node<T>* search(node<T>* head, T key);

template<typename T>
node<T>* findPrevious(node<T>* head, node<T>*position);

template<typename T>
void printAll(node<T>* head);

template<typename T>
void deleteNode(node<T>*& head, node<T>* position);

template<typename T>
void deleteNode(node<T>*& head, T type);

template<typename T>
void insertHead(node<T>*& head, T number);

template<typename T>
void insertAfter(node<T> *&head, node<T>* position, T input);

template<typename T>
void insertBefore(node<T>*& head, node<T>* position, T input);

template<typename T>
int nodeCount(node<T>* head);

template<typename T>
void insertSort(node<T>*& head, T input);

template<typename T>
void swap(node<T>*& A, node<T>*& B);

template<typename T>
T at(node<T> *head, int pos);

template<typename T>
void reverse(node<T>*& head);

template<typename T>
void deleteRepeat(node<T>*& head);

//void shuffle(node<T>*& head);

template<typename T>
void copy(node<T> *source, node<T>*& destination);//need to run eraseAll in here

template<typename T>
void eraseAll(node<T> *&head);

template<typename T>
node<T>* uniqueMerge(node<T>*& A,  node<T>*& B);







using namespace std;
/***********************************
* Function:print
* Purpose: prints the value of a single node
* Parameters: a node address
* Returns:nothing
* Summary:
* Notes:
************************************/
template<typename T>
void print(node<T>* head)
{
    if (head!=NULL)
    {
        cout<<*head;
    }
    else
        cout<<"NULL!!"<<endl;

}

/***********************************
* Function:printAll
* Purpose: prints the entire link-list of nodes
* Parameters: a node address
* Returns:nothing
* Summary: runs print function while incrementing thru the list
* Notes:
************************************/
template<typename T>
void printAll(node<T>* head)
{
    node<T>* headWalker=head;

    while (headWalker!=NULL){
        print(headWalker);
        headWalker = headWalker->next;
    }
    if (headWalker==NULL)
    {
        cout<<"NULL"<<endl;
    }
}

/***********************************
* Function:search
* Purpose: finds the node that holds the user specified input
* Parameters: a node address
* Returns: the address of the node where the value was found. Returns NULL if not found
* Summary: from the begginning, the pointer keeps moving on to the next node until the value matches what the user put, then returns the address,
*          otherwise it returns NULL if not found.
* Notes:
************************************/
template<typename T>
node<T>* search(node<T>* head, T key)
{
    node<T>* headWalker=head;

    while(headWalker!=NULL)
    {
        if (headWalker->_item==key)
        {
            return headWalker;
        }

        headWalker=headWalker->next;
    }
    return NULL;


}

/***********************************
* Function:deleteNode
* Purpose: deletes a node
* Parameters: a node address, the address of the node you want to delete
* Returns:nothing
* Summary: With respect to the current node, the previous node points directly to the next node.
* Notes:
************************************/
template<typename T>
void deleteNode(node<T>*& head, node<T>* position)
{
    if (position!=NULL) //if the list isn't empty...
    {
        node<T>* previousPos=findPrevious(head,position); //get the previous position
        node<T>* nextPos=position->next;//get the next position

        if (previousPos==NULL) //if there isn't a previous node...
        {
            head=head->next; //forget the current node and move on to the next
            delete position; //releases memory from node we forgotten
        }
        else
        {
            previousPos->next=nextPos;//forget the current node and move on to the next
            delete position;//releases memory from node we forgotten
        }
        //        if (head->next==NULL) //if there is only 1 node
        //        {
        //            delete head;
        //            head=NULL;
        //        }
    }
}

/***********************************
* Function:deleteNode
* Purpose: deletes a node
* Parameters: a node address, the address of the node you want to delete
* Returns:nothing
* Summary: With respect to the current node, the previous node points directly to the next node.
* Notes:
************************************/
template<typename T>
void deleteNode(node<T>*& head, T type)
{
    node<T>* position=search(head,type);

    if (position!=NULL) //if the list isn't empty...
    {
        node<T>* previousPos=findPrevious(head,position); //get the previous position
        node<T>* nextPos=position->next;//get the next position

        if (previousPos==NULL) //if there isn't a previous node...
        {
            head=head->next;//forget the current node and move on to the next
            delete position;//releases memory from node we forgotten
        }
        else
        {

            previousPos->next=nextPos;//forget the current node and move on to the next
            delete position;//releases memory from node we forgotten
        }
    }
}


/***********************************
* Function:insertBefore
* Purpose: inserts a node before the specified position
* Parameters: a node address, where to insert, what to insert
* Returns:nothing
* Summary: if there is nothing in the link list, or if the given position is the same as the head, run insert()
*           which will insert the new node at the begginning of the list. Else set the position to the previous node, and run insert after.
* Notes:
************************************/
template<typename T>
void insertBefore(node<T>*& head, node<T>* position, T input)
{

    node<T>* previousNode=findPrevious(head,position);

    if (position==NULL || head==position) //if there is nothing in the link list, or if the given position is the same as the head...
    {

        insertHead(head,input);// insert the new node in the front of the linklist
    }
    else
    {
        insertAfter(head,previousNode,input);
    }

}

/***********************************
* Function:insertAfter
* Purpose:inserts a node after the specified position
* Parameters: a node address, where to insert, what to insert
* Returns:nothing
* Summary:if there is nothing in the list insert the node normally. If the current position is the last node in the list, make a new node and point
*         the last node to the new node. Else everything is normal, so moake a new node with the user defined input, point it to the current node's
*         next node, then make the current node point ot the new one.
* Notes:
************************************/
template<typename T>
void insertAfter(node<T>*& head, node<T>* position, T input)
{
    node<T>* temp;


    if (position==NULL) //if there is nothing in the list...
    {
        insertHead(head,input);

    }
    else
    {
        if (position->next==NULL) //if it is the last node in the list...
        {
            temp=new node<T>(input); //makes a new node with the user defined input
            position->next=temp;
            temp->next=NULL;
        }
        else
        {
            temp=new node<T>(input); //makes a new node with the user defined input

            temp->next=position->next; //makes the new node point to the current node's next node.

            position->next=temp;//makes the current node point to the new node.
        }
    }

}

/***********************************
* Function:insertHead
* Purpose:inserts a node
* Parameters: a node address
* Returns:
* Summary:makes a new node with a value, and points it to the current head. Then the new node becomes the new head!
* Notes:
************************************/
template<typename T>
void insertHead(node<T>*& head, T number)
{
    node<T>* temp; //declares a new pointer
    temp=new node<T>; //points to a specific place

    temp->_item=number; //sets up the value of the new node

    temp->next=head; //sets up the next address of the new node, which is the address old node.
    //This new one goes in the front and points to the old one, which is now in the back. [new node]->[old node]<-[head]

    head=temp;//makes the new head to this new node [head]->[new node]->[old node]
}

/***********************************
* Function:findPrevious
* PreConditions: position points to a place in the linked list, list is not empty
* PostConditions: returns a pointer to the node before position. If position is pointing
*   to the first node in the list, it return NULL.
*   List is unchanged.
* Purpose:
* Parameters: the begginning of the node address, a position to find the previous of
* Returns:
* Summary:
* Notes:
************************************/
template<typename T>
node<T>* findPrevious(node<T>* head, node<T>*position)
{
    if(position==head) //if there isn't a previous node because at beginning of list...
    {
        return NULL;
    }

    node<T>* headWalker=head;

    while(headWalker->next!=position) //until it is the last node before position, do this...
    {
        headWalker=headWalker->next; //goes to the next position (works like incrementing)
    }

    return headWalker;

}

/***********************************
* Function:nodeCount
* Purpose: counds the number of nodes in a link-list
* Parameters: a node address
* Returns:  the number of nodes in integer form
* Summary:walker walks up to NULL, and keeps count using a for loop, then the count is returned
* Notes:
************************************/
template<typename T>
int nodeCount(node<T>* head)
{
    node<T>*headWalker=head;
    int i=0;

    for (i;headWalker!=NULL;i++)
    {
        headWalker=headWalker->next;
    }

    return i;

}

/***********************************
* Function:insertSort
* Purpose: finds where the node belongs in ascending order, and inserts itself there.
* Parameters: a node address
* Returns: nothing
* Summary: have a walker increment until it either hits the last node or hits a node with a greater value. If the result is pointing to the
*         last node, run insertAfter, otherwise run insertBefore.
* Notes: why not just insert it where ever, and sort the whole damn thing. I don't need a shadowWalker if I use "headWalker->next!=NULL"
*       DUPLICATES ARE NOT INSERTED!!!
************************************/
template<typename T>
void insertSort(node<T>*& head, T input)
{
    node<T>* headWalker=head;

    if (head==NULL) //if list is empty
    {
        insertBefore(head,headWalker,input); //just put it in the list
        return;
    }

    while (headWalker->_item<input && headWalker->next!=NULL)//as long as the item is less than the input,or NULL is not hit, keep incrementing.
    {
        headWalker=headWalker->next;
    }
    //when counting loop is over, headWalker should at the last node, or at found node.

    //    cout<<endl<<"input: "<<input<<endl;
    //    cout<<"item after loop: "<<headWalker->_item<<endl;

    if (headWalker->_item < input)
    {
        insertAfter(head,headWalker,input);
    }

    if (headWalker->_item > input)
    {
        insertBefore(head,headWalker,input);
    }








    //--------------------orginal-----------------------
    //    if (headWalker->next==NULL)//if at the last node
    //    {
    //        if (headWalker->_item!=input)
    //        {
    //            cout<<"2:";

    //            insertAfter(head,headWalker,input); //adds the new node to the end of the list.
    //        }
    //    }
    //    else
    //    {
    //        if (headWalker->_item!=input)
    //        {
    //            cout<<"3:";

    //            insertBefore(head,headWalker,input); //adds the new node to the begginning or the middle of the list.
    //        }
    //    }

    //-----------------------------------------------------



    //    insert(head,input);
    //    sortNode(head);

}

/***********************************
* Function:at
* Purpose: returns the value of the position you specify
* Parameters: address to a link list, how far to travel
* Returns:returns the value of the position you specify. returns NULL if not found
* Summary:
* Notes:
************************************/
template<typename T>
T at(node<T>* head, int pos)
{

    if (pos<nodeCount(head) && pos>=0)
    {
        node<T>* headWalker=head;

        for (int i=0;i<pos;i++)
        {
            headWalker=headWalker->next;
        }
        return headWalker->_item;
    }

    exit(1);
}


/***********************************
* Function:swap
* Purpose: swaps the values of 2 nodes
* Parameters: addresses of 2 nodes
* Returns: nothing
* Summary: works only if both nodes are not NULL. Value from node A is saved then node A becomes node B. Then node B becomes the saved value.
* Notes: swap values not addresses
************************************/
template<typename T>
void swap(node<T>*&A, node<T>*&B)
{
    if (A!=NULL && B!=NULL)
    {
        T bank=A->_item;

        A->_item=B->_item;
        B->_item=bank;

    }
    else
        cout<<"DEBUG: SWAP IS NULL! "<<endl;
}

/***********************************
* Function:reverse
* Purpose: reverses the values in the link-list
* Parameters:address of node
* Returns:nothing
* Summary:starting from both ends of the link-list, increment and decrement while calling swap and stopping in the middle.
* Notes:
************************************/
template<typename T>
void reverse(node<T>*& head)
{
    if(head!=NULL)//if list isn't empty
    {
        node<T>* start=head;
        node<T>* end= walker(head,nodeCount(head)-1);

        //        cout<<"START: ";printAll(start); cout<<endl<<endl;
        //        cout<<"END: ";printAll(end);cout<<endl<<endl;


        while (start!=end && end->next!=start) //while the addresses are NOT the same, or ARE past each other
        {
            swap(start,end);
            //cout<<"SWAPPING....";printAll(head);cout<<endl<<endl;

            start=start->next;
            end=findPrevious(head,end);
        }

    }

}

/***********************************
* Function:walker
* Purpose: walks along the list X amount of times and returns the position
* Parameters: address of node
* Returns: address of where it turned up after walking
* Summary: increments the walker [distance] amount of times
* Notes:
************************************/
template<typename T>
Iterator<T> walker(node<T>* head, int distance)
{
    if (distance<nodeCount(head) && distance>=0)
    {
        node<T>* headWalker=head;

        for (int i=0;i<distance;i++)
        {
            headWalker=headWalker->next;
        }

        return Iterator<T>(headWalker);
    }
    else
    {
        cout<<"DEBUG: NUMBER IN walker[] TOO BIG/small!"<<endl;
        return NULL;
    }
}

/***********************************
* Function:deleteRepeat
* Purpose: deletes repeated values in a link-list
* Parameters: address of begginning of link-list
* Returns: nothing
* Summary: uses search and delete.if it finds itself, it increments. if it finds something else it deletes itself, it doesn't increment and starts the search again
* Notes:
************************************/
template<typename T>
void deleteRepeat(node<T>*& head)
{
    //uses search and delete
    //if it finds itself, it increments
    //if it finds something else it deletes itself, it doesn't increment and starts the search again
    node<T>* headWalker=head;
    node<T>* found;
    node<T>* bank;

    while(headWalker!=NULL)
    {

        found=search(head,headWalker->_item);

        if (found==headWalker) //it found itself
        {
            headWalker=headWalker->next; //increment
        }
        else
        {
            bank=headWalker->next; //saves the next address of the node that is about to be deleted

            deleteNode(head,headWalker); //When deleting the spot isn't saved cuz address is gone. There is no shifting.

            headWalker=bank;//sets the headWalker to the saved spot which mimics shifting.
        }



    }


}

///***********************************
//* Function:shuffle
//* Purpose: shuffles the values in the link list
//* Parameters: address of begginning of link-list
//* Returns: nothing
//* Summary: uses a random number generator to decide which positions to swap, then swaps them.
//* Notes: random number generator sucks, not random enuff. Either pick 1 pair of random numbers and those numbers stick forever, or both numbers are the same.
//************************************/
//void shuffle(node<T>*& head)
//{
////    int ran1=random(0,nodeCount(head)-1);
////    int ran2=random(0,nodeCount(head)-1);
//    //maybe have a random number to know how many times to swap things around

////    cout<<ran1<<"       "<<ran2<<endl;
//    //NOT FINISHED!!!
//    //NOT FINISHED!!!
//    //NOT FINISHED!!!
//    //NOT FINISHED!!!
//    //NOT FINISHED!!!

//}

/***********************************
* Function:copy
* Purpose: makes a copy of a link-list
* Parameters:address of link-list to be copied, where it is going to be copied to
* Returns:nothing
* Summary: makes a new link-list and runs insert using values from the source until everything is duplicated. Then the address of the new link-list is passed on
* Notes: source shouldn't be pass by reference
************************************/
template<typename T>
void copy(node<T>* source, node<T>*& destination)
{
    node<T>* temp=NULL; //this new node is pointing to null
    node<T>* sourceWalker=walker(source,nodeCount(source)-1); //is at the end of the link-list


    while(sourceWalker!=NULL) //while the list isn't empty
    {
        insertHead(temp,sourceWalker->_item); //adding to new list using old one, keeping in mind things are inverted

        sourceWalker=findPrevious(source,sourceWalker); //decrementing
    }

    eraseAll(destination); //makes sure destination is clean

    destination=temp; //giving the new list to destination to return



}

/***********************************
* Function:eraseAll
* Purpose: deletes the entire link-list without leaking memory
* Parameters: the list to delete
* Returns: nothing
* Summary: Starts deleting from the last node and decreasing, until head is NULL again.
* Notes:
************************************/
template<typename T>
void eraseAll(node<T>*& head)
{
    //I can start from the back and decrement, or i can start from the front with a shadow walker.
    //with a shadow walker i know when to stop
    //with decrementing I don't need a shadow walker

    node<T>* end=walker(head,nodeCount(head)-1); //WARNING: takes advantage of the exception in the walker() function, ignore warning!
    //sets the pointer to the last node

    while(head!=NULL) //while the list isn't empty yet
    {
        deleteNode(head,end); //deletes the last node
        end=walker(head,nodeCount(head)-1); //sets the pointer to the new last node.
    }
}

/***********************************
* Function:uniqueMerge
* Purpose: merges 2 sorted lists. Unique values only.
* Parameters: 2 link lists
* Returns: nothing
* Summary:
* Notes:
************************************/
template<typename T>
Iterator<T> uniqueMerge(node<T>*& A,  node<T>*& B)
{
    node<T>* AWalker=A;
    node<T>* BWalker=B;
    node<T>* temp=NULL;

    while(AWalker!=NULL && BWalker!=NULL) //while we haven't reached the end of any of the lists
    {

        if(AWalker->_item < BWalker->_item) //put the smaller number into store
        {
            insertHead(temp,AWalker->_item);

            AWalker = AWalker->next;
        }

        else if(BWalker->_item < AWalker->_item) //put the smaller number into store
        {
            insertHead(temp,BWalker->_item);
            BWalker = BWalker->next;

        }

        else if(AWalker->_item == BWalker->_item) //EXCEPTION: pick one to put into store, and increment BOTH
        {
            insertHead(temp,AWalker->_item);
            AWalker = AWalker->next;
            BWalker = BWalker->next;
        }
    }
    //when the while loop is done one of the lists should be null
    //find out which one.
    //for the list that is null, take the leftovers from the other list, and put the leftovers into the store

    if(AWalker==NULL)
    {
        while(BWalker!=NULL)
        {
            insertHead(temp,BWalker->_item);
            BWalker = BWalker ->next;
        }
    }

    if(BWalker==NULL)
    {
        while(AWalker!=NULL)
        {
            insertHead(temp,AWalker->_item);
            AWalker = AWalker ->next;
        }
    }

    reverse(temp); //when everything is done reverse store, cuz everything is inserted backwards

    return Iterator<T>(temp);

}

#endif // LINKEDLISTFUNCTIONS_H
