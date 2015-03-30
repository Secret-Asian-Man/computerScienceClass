#include <iostream>
#include <list>

using namespace std;


void printList( list<char> aList);


int main()
{
    list<char> test;
    test.push_back('A');
    test.push_back('B');

    list<char>::iterator it= test.begin();
    cout<<"DEBUG it: "<<*it<<endl;


    it= test.end();
    it--;
    cout<<"DEBUG it: "<<*it<<endl;


    //printList(test);




    cout<<endl<<endl;
}


void printList( list<char> aList)
{
    list<char>::iterator it=aList.begin();

    while(it != aList.end())
    {
        cout<<*it<<" ";


        it++; //iterator doesn't actually get changed
    }

}


void next(list<char> &test)
{
    list<char>::iterator itMain=test.begin();
    list<char>::iterator itBefore=test.begin();

    itMain++; //starts off iterator at the second position

    while(itMain != test.end()) //while iterator hasn't reached the end of the list
    {

        //test.insert(*itBefore-*itMain+64);

        itMain++;
        itBefore++;

    }


}
