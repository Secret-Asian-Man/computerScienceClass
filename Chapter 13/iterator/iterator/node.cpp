#include "node.h"

using namespace std;

node::node():_item(), next(NULL)
{
//    _item=;
//    next=NULL;

}

node::node(ITEM_TYPE item)
{
    _item=item;
    next=NULL;
}

ostream& operator <<(ostream& outs, const node &printMe)
{
    outs<<"["<<printMe._item<<"]-> ";
    return outs;
}

// operator =(node A,node B)
//{
//    A.next=B.next;
//    A._item=B._item;
//}
