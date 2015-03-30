/***********************************
* Project: cstring class
* Author: David Wu
* Purpose: to recreat the cstring library
* Notes: should capacity ever shrink?
* ***********************************/
#include <iostream>
#include "stringclass.h"

using namespace std;

int main()
{
    char testChar[1000]="1234";
    char testChar2[1000]="fwoofie";
    char* chPointer=testChar;
    char*chPointer2=testChar2;
    char reallyLongString[1000]="4594450qwa544737ertyuio9pasdfghjklzx9cvbnm";

    stringClass test(chPointer);
    stringClass test2(reallyLongString);
    stringClass test3(chPointer2);


    cout<<"constructor"<<endl;
    test.printAddress(); cout<<endl;
    cout<<test.get_s()<<endl;
    cout<<"size: "<<test.get_size()<<endl;
    cout<<"capacity: "<<test.get_capacity()<<endl;

    cout<<endl<<endl<<endl;

    cout<<"copy"<<endl;
    test.copy(reallyLongString);
    test.printAddress();cout<<endl;
    cout<<test.get_s()<<endl;
    cout<<"size: "<<test.get_size()<<endl;
    cout<<"capacity: "<<test.get_capacity()<<endl;

    cout<<endl<<endl<<endl;


    cout<<"concatenate"<<endl;
    test.concatenate(testChar);
    test.printAddress();cout<<endl;
    cout<<test.get_s()<<endl;
    cout<<"size: "<<test.get_size()<<endl;
    cout<<"capacity: "<<test.get_capacity()<<endl;

    cout<<endl<<endl<<endl;


    cout<<".compare: "<<test.compare(test2)<<endl;

    cout<<endl<<endl<<endl;

    cout<<".character: "<<test.character('2')<<endl;


    cout<<endl<<endl<<endl;

    test.pushBack('p');
    test.printAddress();cout<<endl;
    cout<<test.get_s()<<endl;
    cout<<"size: "<<test.get_size()<<endl;
    cout<<"capacity: "<<test.get_capacity()<<endl;

    cout<<endl<<endl<<endl;

    cout<<"clear"<<endl;
    test.clear();
    test.printAddress();cout<<endl;
    cout<<test.get_s()<<endl;
    cout<<"size: "<<test.get_size()<<endl;
    cout<<"capacity: "<<test.get_capacity()<<endl;

    cout<<endl<<endl<<endl;

    cout<<"isEmpty"<<endl;
    if (test.isEmpty())
        cout<<"IS EMPTY!"<<endl;
    else
        cout<<"IS NOT EMPTY!"<<endl;

    cout<<endl<<endl<<endl;

    cout<<"assign"<<endl;
    test.assign(reallyLongString);
    test.printAddress();cout<<endl;
    cout<<test.get_s()<<endl;
    cout<<"size: "<<test.get_size()<<endl;
    cout<<"capacity: "<<test.get_capacity()<<endl;

    cout<<endl<<endl<<endl;

    cout<<"isEmpty"<<endl;
    if (test.isEmpty())
        cout<<"IS EMPTY!"<<endl;
    else
        cout<<"IS NOT EMPTY!"<<endl;

    cout<<endl<<endl<<endl;

    cout<<"erase"<<endl;
    test.erase(2,5);
    test.printAddress();cout<<endl;
    cout<<test.get_s()<<endl;
    cout<<"size: "<<test.get_size()<<endl;
    cout<<"capacity: "<<test.get_capacity()<<endl;


    cout<<endl<<endl<<endl;

    cout<<"find"<<endl;
    char key[1000]="9";
    test.printAddress();cout<<endl;
    cout<<test.get_s()<<endl;
    cout<<"FOUND AT: "<<test.find(key,0)<<endl;
    cout<<"size: "<<test.get_size()<<endl;
    cout<<"capacity: "<<test.get_capacity()<<endl;

    cout<<endl<<endl<<endl;

    cout<<"rFind"<<endl;
    test.printAddress();cout<<endl;
    cout<<test.get_s()<<endl;
    cout<<"FOUND AT: "<<test.rFind(key,0)<<endl;
    cout<<"size: "<<test.get_size()<<endl;
    cout<<"capacity: "<<test.get_capacity()<<endl;

    cout<<endl<<endl<<endl;


    char alpha[]="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

    cout<<"findFirstOf"<<endl;
    test.printAddress();cout<<endl;
    cout<<test.findFirstOf(alpha,0)<<endl;
    cout<<"size: "<<test.get_size()<<endl;
    cout<<"capacity: "<<test.get_capacity()<<endl;

    cout<<endl<<endl<<endl;

    cout<<"findFirstNotOf"<<endl;
    test.printAddress();cout<<endl;
    cout<<test.findFirstNotOf(alpha,6)<<endl;
    cout<<"size: "<<test.get_size()<<endl;
    cout<<"capacity: "<<test.get_capacity()<<endl;

    cout<<endl<<endl<<endl;

    cout<<"= operator"<<endl;
    cout<<"address before 2: ";test2.printAddress();cout<<endl;
    cout<<"address before 3: ";test3.printAddress();cout<<endl;
    test2=test3;
    cout<<"address after 2: ";test2.printAddress();cout<<endl;
    cout<<"address after 3: ";test3.printAddress();cout<<endl;
    cout<<test2.get_s()<<endl;
    cout<<"size: "<<test2.get_size()<<endl;
    cout<<"capacity: "<<test2.get_capacity()<<endl;


//    cout<<endl<<endl<<endl;


//    cout<<"insert"<<endl;
//    test2.insert(chPointer2,4);
//    test2.printAddress();cout<<endl;
//    cout<<test2.findFirstNotOf(alpha,6)<<endl;
//    cout<<"size: "<<test2.get_size()<<endl;
//    cout<<"capacity: "<<test2.get_capacity()<<endl;

}

