#include <iostream>
#include <time.h>
#include<Tools.H>
#include<MyCStrings.h>

using namespace std;

const int MAX=100;


int main()
{

    char source[MAX]="123456789";
    char destination[MAX]="456789";

    char* chPointer=source;

    Delete(chPointer,9);
    cout<<"DEBUG source: "<<source<<endl;

}

