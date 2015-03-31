//#include "stack.h"
//#include "iostream"
//using namespace std;

//stack::stack()
//{
//    _top=NULL;
//}

//stack::stack(const stack& other)
//{
//    _top=NULL;
//    copy(other._top,_top);
//}

//stack::~stack()
//{
//    eraseAll(_top);
//}

//stack& stack::operator =(const stack& other)
//{
//    eraseAll(_top);
//    copy(other._top,_top);
//}

//void stack::push(ITEM_TYPE item)
//{
//    insertHead(_top,item);
//}

//ITEM_TYPE stack::pop()
//{

//    if (empty()==false)
//    {
//    ITEM_TYPE bank=_top->_item;
//    deleteNode(_top,_top);
//    return bank;
//    }
//    else
//    {
//        cout<<"pop EMPTY"<<endl;
//        exit(1);
//    }


//}

//bool stack::empty()
//{

//    if (_top==NULL)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }

//}

//ITEM_TYPE stack::peek()
//{

//    if (empty()==false)
//    {
//    return _top->_item;
//    }
//    else
//    {
//        cout<<"peek EMPTY"<<endl;
//        exit(1);
//    }

//}

//void stack::print()
//{
//    printAll(_top);
//}
