#include <iostream>
#include <fstream>
using namespace std;



int main()
{
    char singleChar;

    ifstream myStream;

    myStream.open("PacManMap.txt");
    if (myStream.fail()) //checks file
    {
        cout<<endl<<"****** Could not open file ******"<<endl;
        exit(0);
    }
            while(!myStream.eof())
            {
                myStream.get(singleChar);
                if (singleChar==13)
                {
                    cout<<endl;
                }
                else
                cout<<singleChar;
            }

            cout<<endl;
}
