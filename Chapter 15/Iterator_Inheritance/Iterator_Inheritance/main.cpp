#include <iostream>
#include "cursoredlist.h"

using namespace std;

int main()
{
    cursoredList<int> test;

    char command=' ';
    int number=0;


    while(command!='q' || command !='Q')
    {
        cout<<"Input Command: ";cin>>command;
        switch (command)
        {
        case 'a':
        case 'A':
            cout<<"Insert number: "; cin>>number;
            test.insertAfter(number);
            break;

        case 'i':
        case 'I':
            cout<<"Insert number: "; cin>>number;
            test.insertBefore(number);
            break;

        case 'd':
        case 'D':
            test.Delete();
            break;

        case 's':
        case 'S':
            cout<<"Insert number: "; cin>>number;
            test.search(number);
            break;

        case 'f':
        case 'F':
            test.fill();
            break;

        case 'l':
        case '4':
            test.cursorLeft();
            break;

        case 'r':
        case '6':
            test.cursorRight();
            break;

        default:
            cout<<"Invalid key..."<<endl;
        }

    }



}
