//Just finished testing searchAll(), need to do make 2D pointerClass, plane class, and lab class.
//remember to post tests on the CMD Mark

#include "lowlevelfunctions_2dpointers.h"
#include "twodpointerclass.h"
#include "plane.h"
#include "lab.h"

#include <iostream>

using namespace std;

const int MAX=100;



int main()
{
    int sizes[MAX]={5,5,5,5,5,-1};
    int sizes2[MAX]={7,7,7,-1};
    int* sizesPointer=sizes;
    int* sizesPointer2=sizes2;
























    return 0;
}





///***********************************
//* Function:findLength
//* Purpose:
//* Parameters:
//* Returns:
//* Summary:
//* Notes: NEEDS -1 to work!!
//************************************/
//int findLength(int* array)
//{
//    int* arrayWalker=array;
//    int count=0;

//    for (count;*arrayWalker!=-1;count++)
//    {
//        arrayWalker++;
//    }

//    return count;
//}


//-------examples----------
//int** allocate(int* sizes);
//int** copy(int** copyThis, int* )







//`````````````````````````````````
// calling blah[5][6]
// returns the item at row 5. collumn 6

//int* TwoD::operator[](int row)
//{
//    int** rowWalker=row;

//    for (int i=0;i<row;i++)
//    {
//        rowWalker++;
//    }

//    return *rowWalker;
//}

//``````````````````````````````````




//``````````````````````````````````
//calling: blah(5,6)=666; // sets the value at (5,6) to 666
//calling: cout<<blah(1,9); //outputs the value at (1,9)

//    int& operator()(int row, int col)
//    {
//        //returns the value at (row,col)
//    }

//``````````````````````````````````





//class Plane{
//Plane()
//{
//int new sizes[]={4,4,4,4,4,4-1};
//seats=rowSizes
//}
//private:
//twoDseats;
//----------------------------
