#include <iostream>
#include <vector>
#include <random.h>
#include <cstdlib>
#include <time.h>

using namespace std;



int main()
{
    srand(time(0));

    vector<int> test;
    for (int i=0;i<5;i++)
    {
        test.push_back(i);
    }

    random ran1(0,test.size());
    random ran2(0,test.size());



    test.swap(test[2]);


    for (int i=0;i<test.size();i++)
    {
        cout<<test[i]<<" ";
    }

    cout<<endl<<endl;


}
