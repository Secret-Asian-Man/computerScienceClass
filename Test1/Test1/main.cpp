#include <iostream>
using namespace std;

char* subStringProto(char* start, char* end);
void subStr(char* source, char* sub, int start, int end);

int main()
{
    char source[1000]="A really long string";

    char* start=source+2;
    char* end=source+7;
    char* final;

    final=subStringProto(start,end);






}
char*  subStringProto(char* start, char* end)
{
    char* startWalker=start;
    char* endWalker=end;

    int subtract =end-start;
    cout<<"DEBUG start: "<<start<<endl;
    cout<<"DEBUG end: "<<end<<endl;
    cout<<"DEBUG end-start: "<<end-start<<endl;
    cout<<"DEBUG subtract: "<<subtract<<endl;


    char*sub=new char[end-start];




//    subStr(_s,sub,start-_s,end-_s);
    //finish!!

}



/***********************************
 * Function: subStr
 * Purpose: grabs a chunk from a string
 * Parameters: a source, a place to store the chunk, where to start copying the chunk, where to end copying the chunk
 * Returns: nothing
 * Summary: I move the index to where I want to start copying. I then start copying the [source] into the [sub], until I hit [end] or the [source] null.
 * Notes:
 * ***********************************/
void subStr(char* source, char* sub, int start, int end)
{
    char* sourceWalker=source+start;//points to the slot of where you want to start copying
    char* subWalker=sub;

    for (int i=0;i<end && *sourceWalker!=NULL;i++)
    {
        *subWalker=*sourceWalker; //copys the value of the thing at this address and put it into the address of the other thing.
        subWalker++; //moves the cursor/index/address
        sourceWalker++;//moves the cursor/index/address
    }

    *subWalker=NULL;
}
