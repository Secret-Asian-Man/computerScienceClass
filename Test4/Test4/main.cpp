#include <iostream>
#include <cstring>

using namespace std;

char* allocate(int size);


int main()
{
    //    char*s=allocate(100);

    //    strcpy(s, "This is a test!!");
    //    cout<<s<<endl;






    //    for (int i=0;i<100000;i++) //testing allocating space without deleting
    //    {
    //        for (int j=0;j<100000;j++)
    //        {
    //            char* s=allocate(10000);
    //            cout<<i<<", "<<j<<endl;
    //        }
    //    }






    for (int i=0;i<100000;i++) //testing allocating space with deleting
    {
        for (int j=0;j<100000;j++)
        {
            char* s=allocate(100);
            cout<<i<<", "<<j<<endl;
            delete[] s; //<=== releases memory
        }
    }
}

char* allocate(int size)
{
    char* temp;
    temp=new char[size];

    return temp;
}
