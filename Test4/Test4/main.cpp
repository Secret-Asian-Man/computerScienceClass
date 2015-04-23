#include <iostream>

using namespace std;

void cstr(string source, char* dest){

    for(int i = 0; i < source.length(); i++){
        dest[i] = source[i];
    }
    dest[source.length()] ='\0';
}

int main()
{
    string testString="blah blah";

    char testCString[1000];

    cstr(testString,testCString);



    cout<<testString.c_str();
    cout<<endl;
}
