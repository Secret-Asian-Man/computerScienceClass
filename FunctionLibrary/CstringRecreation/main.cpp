#include <iostream>
#include "MyCStrings.h"
using namespace std;



int main()
{
    char a[]="01234";
    char a2[]="56789";

    StrCpy(a,a2);

    cout<<"DEBUG main: "<<a2<<endl;


}


