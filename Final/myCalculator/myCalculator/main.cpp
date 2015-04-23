//have the container class hold the string and position
//have the container class do the tokenizing and create the new token types
//have the container class store the new token types inside the container

#include <iostream>
#include "tokencontainer.h"

//note: need to "CONFIG += c++11" to use stoi

using namespace std;



int main()
{
    tokenContainer test("5+6");

    test.print();



    return 0;
}
