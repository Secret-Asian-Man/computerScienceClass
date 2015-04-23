#include "node.h"

using namespace std;

node::node():_item(0), _right(NULL), _left(NULL)
{

}

node::node(ITEM_TYPE item)
{
    _item=item;
    _right=NULL;
    _left=NULL;
}

ostream& operator <<(ostream& outs, const node &printMe)
{
    outs<<"["<<printMe._item<<"]-> ";
    return outs;
}


