/***********************************
* Project: tourture with nodes
* Author: David Wu
* Purpose: to learn nodes!
* Notes:what is the difference between headWalker!=NULL and headWalker->next!=NULL ? (off by one. headWalker!=NULL gives the exact amount of nodes)
*       -Always check for off-by-one, and empty list.
* ***********************************/
#include <iostream>
#include <list.h>
#include <linkedlistfunctions.h>
#include <stack.h>
#include <node.h>
#include "Iterator.h"


int main()
{
    //    --------------------Testing sortedUnique------------------------------------

    node<string>* testString=NULL;
    node<char>* testChar=NULL;

    insertHead(testString,string("guy")); //"something" is a character array, must convert to string object.
    insertHead(testString,string("person"));
    insertHead(testString,string("there"));
    insertHead(testString,string("Hi"));

    insertHead(testChar,'O');
    insertHead(testChar,'L');
    insertHead(testChar,'L');
    insertHead(testChar,'E');
    insertHead(testChar,'H');




    printAll(testChar);
    printAll(testString);


    list<int> test;
    Iterator<int> it;

    for (int i=0;i<5;i++)
    {
        test._insertHead(i);
        test._printAll();

    }


    it=test._search(3);

    std::cout<<"Data: "<<it.data();

    it=test._search(4);

    std::cout<<"Data: "<<it.data();
    it=test._search(1);

    std::cout<<"Data: "<<it.data();
    it=test._search(0);

    std::cout<<"Data: "<<it.data();


    std::cout<<std::endl<<std::endl;
        return 0;


//    sortedUnique head1(head);
//    sortedUnique copy(head1);
//    sortedUnique empty;

//    cout<<"original head1: ";head1._printAll();
//    cout<<"original copy: ";copy._printAll();
//    cout<<"original empty: ";empty._printAll();



//    cout<<"modified head1: ";head1._printAll();
//    cout<<"modified copy: ";copy._printAll();
//    cout<<"modified empty: ";empty._printAll();


    //-------------------------------------------------------------------------------



    //--------------------Testing Stack and Queue------------------------------------
    //    node* head=NULL;
    //    for (int i=5;i>=0;i--) //initializes a link-list of nodes
    //    {
    //        insertHead(head,i+10);
    //    }
    //    queue testQueue;


    //    for (int i=5;i>=0;i--)
    //    {
    //        testQueue.push(i+10);
    //    }
    //    cout<<"testQueue: ";testQueue.print();
    //    cout<<"original head: ";printAll(head);



    //    queue queueCopy(testQueue);

    //    cout<<"queueCopy: ";queueCopy.print();


    //    cout<<endl<<endl;

    //    for (int i=0;i<5;i++)
    //    {
    //        cout<<testQueue.pop()<<endl;
    //    }


    //    cout<<"Peeking: "<<testQueue.peek()<<endl;
    //--------------------------------------------------------

    //================testing low level functions==============================


    //    node* head=NULL;
    //    node* head2=NULL;
    //    node*temp=NULL;
    //    //        for (int i=4;i>=0;i--) //initializes a link-list of nodes
    //    //        {
    //    //            insertHead(head,i+10);
    //    //            insertHead(head2,i+100);
    //    //        }

    //    for (int i=10;i>=0;i--)
    //    {
    //        if (i%2==0)
    //        {
    //            insertHead(head,i);
    //        }
    //        else
    //        {
    //            insertHead(head2,i);
    //        }

    //    }

    ////    insertHead(head,666);
    ////    insertHead(head2,626);

    //    cout<<"original head: "; printAll(head);
    //    cout<<"orignal head2: ";printAll(head2);

    //    temp=uniqueMerge(head,head2);

    //    cout<<"orignal temp: ";printAll(temp);





    //=========================================================================













    //        node* head=NULL;
    //        for (int i=9;i>=0;i--) //initializes a link-list of nodes
    //        {
    //            insertHead(head,i+10);
    //        }
    //    list listTest(head);

    //    listTest._printAll();











    //    node* source=NULL;
    //    node* destination=NULL;

    //    for (int i=7;i>0;i--) //initializes a link-list of nodes
    //    {
    //        insertHead(source,i+10);
    //        insertHead(destination,i+100);
    //    }

    //            insertHead(source,1);
    //            insertHead(source,2);
    //            insertHead(source,3);
    //            insertHead(source,1);
    //            insertHead(source,2);
    //            insertHead(source,3);
    //            insertHead(source,8);
    //            insertHead(source,8);
    //            insertHead(source,8);
    //            insertHead(source,2);

    //    cout<<"original source: ";printAll(source);cout<<endl<<endl;

    //    cout<<"original destination: ";printAll(destination);cout<<endl<<endl;

    //    cout<<"original source: "<<source<<endl<<endl;

    //    //cout<<"original destination: "<<destination<<endl<<endl;

    //    deleteNode(source, source);




    //    eraseAll(source);
    //    copy(source,destination);
    //    //cout<<nodeCount(source)<<endl<<endl;
    //    //cout<<at(source,5)<<endl<<endl;
    //deleteNode(source,source);
    //    //reverse(source);

    //    for (int i=0;i<11;i++)
    //    {
    //        deleteNode(source,source);
    //        cout<<"overview source: ";printAll(source);cout<<endl<<endl;

    //    }

    //    cout<<"modifed source: ";printAll(source);cout<<endl<<endl;

    //    cout<<"modifed destination: ";printAll(destination);cout<<endl<<endl;

    //    cout<<"original source: "<<source<<endl<<endl;

    //    //cout<<"original destination: "<<destination<<endl<<endl;












    //    node* head=NULL;
    //    node* test;
    //    node* headWalker;

    //    cout<<"Initialize: "<<endl;
    //    for (int i=14;i>=0;i--) //initializes a link-list of nodes
    //    {
    //        insertHead(head,i+10);
    //    }
    //    cout<<endl<<endl;
    //    headWalker=head; //sets the head back to beginning


    //    //printAll(head);cout<<endl<<endl;

    //    for (int i=0;i<5;i++) //moves forward 2 times
    //    {
    //        headWalker=headWalker->next;
    //        //printAll(headWalker);cout<<endl;
    //    }

    //    printAll(head);cout<<endl;

    //    cout<<endl<<endl;
    //    cout<<"reverseNode: "<<endl;
    //    reverse(head);
    ////    printAll(head);
    //    cout<<endl;






















}

