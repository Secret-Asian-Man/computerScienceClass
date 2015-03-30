#include <iostream>
#include "stokenize.h"

using namespace std;

int main()
{
    char source[1000]="A really long string!! 123";
    char* sourcePointer=source;
    stringClass sourceStringClass(sourcePointer);
    STokenize sourceSTokenizer(sourceStringClass);
    Token finalToken;


    finalToken=sourceSTokenizer.nextToken();

    cout<<"finalToken: "<<finalToken<<endl;

}

