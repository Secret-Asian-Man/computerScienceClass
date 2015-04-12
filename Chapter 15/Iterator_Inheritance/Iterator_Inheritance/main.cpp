#include <iostream>
#include "cursoredlist.h"

using namespace std;

int main()
{
    cursoredList<int> test;

    char command=' ';
    int number=0;
    bool run=true;


    while(run)
    {
        cout<<endl<<endl<<"H: Insert Head | A: Insert After | B: Insert Before | D: Delete | S: Search | F:Fill | 4: Left | 6: Right | Q: Quit"<<endl;
        cout<<"Input Command: ";
        cin>>command;

        switch (command)
        {
        case 'a':
        case 'A':
            cout<<"Insert number: "; cin>>number;
            test.insertAfter(number);
            break;

        case 'b':
        case 'B':
            cout<<"Insert number: "; cin>>number;
            test.insertBefore(number);
            break;

        case 'h':
        case 'H':
            cout<<"Insert number: "; cin>>number;
            test.inserthead(number);
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

        case 'q':
        case 'Q':
            run=false;
            break;


        default:
            cout<<"Invalid key..."<<endl;
            break;
        }
        test.print();

    }



}
