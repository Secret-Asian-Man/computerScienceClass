#include <iostream>
#include <list>
#include <random.h>

using namespace std;


void printList( list<char> aList);


int main()
{
    random randomNumber(0,10);

    for (int i=0;i<5;i++)
    {
        cout<<"Random number: "<<randomNumber.getRandomNumber()<<endl;

    }


}
