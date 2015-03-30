#include <iostream>
#include "list.h"
#include "iterator.h"

int main()
{
list test;
iterator it;

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
}

