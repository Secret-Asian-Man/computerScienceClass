#include <iostream>

using namespace std;

const int MAX=100;

void Delete(string* array, int& size);

int main()
{

    string array[MAX]={"Hello","blah","bike"};
    string* test=array;
    int size=3;

    cout<<"DEBUG test: "<<*test<<endl;
    cout<<"DEBUG size: "<<size<<endl;

    Delete(test,size);
    cout<<"DEBUG size: "<<size<<endl;

    Delete(test,size);
    cout<<"DEBUG size: "<<size<<endl;

    cout<<"DEBUG test: "<<*test<<endl;

}
void Delete(string* array, int& size)

{
    string* end=array+size;
    string* nextPos=array+1; //moves the value from pos+1 into pos

    for (int i=0;i<size;i++)
    {
        *array=*nextPos;

        array++;
        nextPos++;
    }

    size--;
}
