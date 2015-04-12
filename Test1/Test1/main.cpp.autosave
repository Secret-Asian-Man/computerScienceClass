#include <iostream>
#include <vector>

using namespace std;


class testObject
{
public:

    testObject();

    int number;

};
testObject::testObject()
{
    number=1;
}


//i want to test out if I can return NULL inside a vector when it is expecting an object
//seems i have to convert the vector to take in pointers before I can store a NULL in there. How do i make a
//pointer pointing to an object?
int main()
{

vector <testObject*> objVector;
testObject* pointer=new testObject();


for (int i=0;i<5;i++)
{
    objVector.push_back(new testObject());
    objVector.push_back(NULL);
}

for (int i=0;i<objVector.size();i++)
{
    cout<<objVector[i].number<<endl;
}


}

