#include "iterator.h"

iterator::iterator()
{
    _it=NULL;
}
iterator::iterator(node* head)
{
    _it=head;
}

iterator::~iterator()
{

}

ITEM_TYPE iterator::data()
{
    return _it->_item;
}

