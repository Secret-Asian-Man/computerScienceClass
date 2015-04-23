#ifndef NODE_H
#define NODE_H

#include <iostream>

typedef int ITEM_TYPE;
class node
{
public:
    //constructors
    node();
    node(ITEM_TYPE item);

    ITEM_TYPE _item;
    node* _right;
    node* _left;

  //operators
    friend std::ostream& operator <<(std::ostream& outs, const node &printMe);
    //friend operator =(node A,node B);

};

#endif // NODE_H
