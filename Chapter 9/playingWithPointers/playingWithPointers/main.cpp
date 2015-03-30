/***********************************
 * Project: playing with pointers
 * Author: David Wu
 * Purpose: to play with pointy things
 * Notes:
 * ***********************************/
#include <iostream>
using namespace std;


int pointerTestFunction(int* pointerA);

int main()
{
    int *iPointer;
    int i=50;

    iPointer=&i;

    cout<<*iPointer<<endl<<endl; //dereferencer. displays the value inside the address
    cout<<"============================================="<<endl;

    char *chPointer;
    char array[]="hello"; //each character in hello has it's own address next to each other, like neighbors.

    chPointer=array;//notice we don't need &array cuz an array is already a pointer/reference

    cout<<*chPointer<<endl<<endl; // outputs the value currently at that address

    chPointer++; //points to h slot

    cout<<*chPointer<<endl<<endl;

    chPointer++;//points to e slot

    cout<<*chPointer<<endl<<endl;

    chPointer++;//points to l slot

    cout<<*chPointer<<endl<<endl;

    chPointer++;//points to next l slot

    cout<<*chPointer<<endl<<endl;

    chPointer++;//points to o slot

    cout<<*chPointer<<endl<<endl;

    *chPointer='z'; //SETS the current slot in the array, to z

    cout<<*chPointer<<endl<<endl;

    chPointer=array; //<==== this line sets the address back to the BEGINNING of the array.

    cout<<*chPointer<<endl<<endl;


    cout<<"============================================="<<endl;

    pointerTestFunction(iPointer);
    cout<<*iPointer<<endl;



}

int pointerTestFunction(int* pointerA)
{
    *pointerA=666;

    return *pointerA;
}
