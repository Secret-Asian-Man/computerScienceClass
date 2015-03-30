/***********************************
 * Project: Chapter 10, Question5 .
 * Author: David Wu
 * Purpose: counts up and down
 * Notes:
 * ***********************************/
#include <iostream>
#include <counter.h>

using namespace std;

int main()
{
    counter count;
    char command;
    bool run=true;

    cout<<"Increment (+), Decrement (-), Reset (r), Quit (q) "<<endl;

    while (run)
    {

        count.printCount();

        cout<<"Enter command: ";
        cin>>command;

        switch (command)
        {
        case 'R':
        case 'r':
            count.resetCount();
            break;

        case '+':
            ++count;
            break;

        case '-':
            --count;
            break;

        case 'q':
            run=false;
            break;

        default:
            cout<<"Invalid input!"<<endl;
        }

    }
    //    counter count2(100);

    //    count.printCount();
    //    count2.printCount();

    //    cout<<endl<<endl;

    //    ++count;
    //    count2.incrementCount();

    //    count.printCount();
    //    count2.printCount();

    //    cout<<endl<<endl;

    //    count.setCount(99);
    //    count2.setCount(22);

    //    cout<<"count: "<<count.getCount()<<endl;
    //    cout<<"count2: "<<count2.getCount()<<endl;

    //    cout<<endl<<endl;

    //==============================================================================


}



