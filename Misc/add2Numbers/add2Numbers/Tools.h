#ifndef TOOLS_H
#define TOOLS_H
#include <cmath>
#include <iostream>
using namespace std;

template <typename T>
T Random(T lo, T hi);

template <typename T>
void swap2Numbers(T &num1, T &num2);

template <typename T>
void sort (T a[], T total);

// \/ \/ \/ \/ \/ \/ \/ \/Biggest Number \/ \/ \/ \/ \/ \/ \/ \/
template <typename T>
T biggestOf3Numbers (T input1, T input2, T input3);
template <typename T>
T biggestOf2Numbers(T num1, T num2);
// /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\

template <typename T>
void reorderAsending(T &num1, T &num2);

template <typename T>
void reverse(T a[], T total);

template <typename T>
void UniversalConversion (T X, T x, T &Y, T &y, T a, T b,T c);

template <typename T>
T trianglePerimeter(T side1, T side2, T side3);

template <typename T>
void Show(T a[], int pos);

template <typename T>
void initializeArray(T a[],int total);

template <typename T>
T getInput(T min, T max);

template <typename T>
T getInput();

char getChar();

int greatestCommonFactor(int num1, int num2);

string int2String (int number);





// \/ \/ \/ \/ \/ \/ \/ \/Bitwise\/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/
bool testBit(int binary, int position);
int SetBit(int binary, bool set, int position);
int mask (int position);
// /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\




//================================================================================================================================
#include <cstdlib>
using namespace std;

//================================================================================================================================

/******************************************
Function: Biggestof3
Purpose: gets and returns the greater of 3 numbers
Parameters: double input1, double input2, double input3
Returns: greater of the 3 numbers
Notes: Calls max (double input1, double input2) once to go thru the 1st 2 numbers, and one more time for the 3rd number.
*******************************************/
template <typename T>
T biggestOf3Numbers (T input1, T input2, T input3)
{
    T result=0;

    result= biggestOf2numbers (input1, input2);
    result= biggestOf2numbers (result, input3);

    return result;
}

/***********************************
 * Function: mask
 * Purpose: Determines bit position
 * Parameters: const int "position"
 * Returns: the position in binary
 * Notes:
 * ***********************************/
int mask (int position)
{
    return (1<<position);
}

/***********************************
 * Function: SetBit
 * Purpose: compiles the binary data
 * Parameters: int binary, bool set, int position
 * Returns: binary data
 * Notes:
 * ***********************************/
int SetBit(int binary, bool set, int position)
{
    if (set)
    {
        binary=binary | mask(position);
    }

    return binary;
}

/***********************************
 * Function: testBit
 * Purpose: decompiles the binary data
 * Parameters: int binary, const int "position"
 * Returns: true/false
 * Notes:
 * ***********************************/
bool testBit(int binary, int position)
{
    int masked=mask(position); //for some reason you HAVE TO set "binary&mask(position)" and "mask(position)" to a variable before you == them.
    int anded=binary&mask(position);

    //    cout<<"DEBUG testbit masked: "<<masked<<endl;
    //    cout<<"DEBUG testbit anded: "<<anded<<endl;


    if (anded==masked)
        return true;

    else
        return false;
}

/***********************************
 * Function: trianglePerimeter
 * Purpose: calculates the perimeter of a triangle
 * Parameters: 3 sides
 * Returns: perimeter
 * Notes:
 * ***********************************/
template <typename T>
T trianglePerimeter(T side1, T side2, T side3)
{
    T perimeter=0;

    perimeter=side1+side2+side3;

    return perimeter;
}
/***********************************
 * Function: UniversalConversion
 * Purpose: converts any 2 units given to it to any other 2 units
 * Parameters: double X, double x, double &Y, double &y, double a, double b,double c
 * Returns: double &Y, double &y
 * Notes:
 * ***********************************/
template <typename T>
void UniversalConversion (T X, T x, T &Y, T &y, T a, T b,T c)
{
    //UniversalConversion(feet, inches, meters, cm, FEET2INCHES, INCHES2CM, CM2METERS);

    //    inches`=inches`+(feet`*FEET2INCHES`); //adds inches and feet together as inches

    //    centimeters`=inches`*INCHES2CM`; //converts inches to centimeters

    //    meters`=floor (centimeters`/CM2METERS`);

    //    centimeters`=((centimeters`/CM2METERS`)-meters`)*CM2METERS`

    x=x+(X*a); //converts feet/pounds to inches/ounces
    //cout<<"DEBUG UniversalConversion x: "<<x<<endl;

    y=x*b; //converts inches/ounces to centimeters/grams
    //cout<<"DEBUG UniversalConversion y: "<<y<<endl;

    Y=floor(y/c); //converts centimeters/grams to meters/kilograms and drops the decimals
    //cout<<"DEBUG UniversalConversion Y: "<<Y<<endl;

    y=((y/c)-Y)*c; //takes the dropped decimals and multiplys it by the conversion rate to get remaining centimeters/grams
    //cout<<"DEBUG UniversalConversion y: "<<y<<endl;
}
/***********************************
 * Function: getInput
 * Purpose: gets a number between min and max
 * Parameters: min, max
 * Returns: a number
 * Summary:
 * Notes:
 * ***********************************/
template <typename T>
T getInput(T min, T max)
{
    T input;

    cout<<"Enter a number "<<min<<"-"<<max<<": ";

    cin>>input;

    if (input>=min && input<=max)
        return input;

    return 0;
}

/***********************************
 * Function: getInput
 * Purpose: gets a input from user
 * Parameters: nothing
 * Returns: a input
 * Summary:
 * Notes:
 * ***********************************/
template <typename T>
T getInput()
{
    T input;

    cin>>input;

    return input;
}

/***********************************
 * Function: Random
 * Purpose: gnerates a random number
 * Parameters: int lo, int hi
 * Returns: a random number
 * Notes: Needs   declaration: "srand(time(0));", " #include <time.h>", "#include <cstdlib>"
 * ***********************************/
template <typename T>
T Random(T lo, T hi) //range of valid numbers
{
    T range = hi-lo+1;

    T randomNumber = lo + (rand() % range);

    return randomNumber;
}

/***********************************
 * Function: getChar
 * Purpose: gets and returns a character
 * Parameters: nothing
 * Returns: a char
 * Summary:
 * Notes:
 * ***********************************/
char getChar()
{
    char character;

    cin>>character;

    return character;
}

/***********************************
 * Function:swap2Numbers
 * Purpose: swaps the value of 2 numbers
 * Parameters: 2 numbers
 * Returns: nothing
 * Notes:
 * ***********************************/
template <typename T>
void swap2Numbers(T &num1, T &num2)
{
    T bank=0;

    bank=num1;
    num1=num2;
    num2=bank;
}

/***********************************
 * Function: sort
 * Purpose: reorders array in ascending order
 * Parameters: array, total
 * Returns: array in ascending order
 * Notes:
 * ***********************************/
template <typename T>
void sort (T a[], T total)
{

    for (int i=0; i<total; i++)
    {
        for (int j=i+1; j<total; j++)
        {
            reorderAsending(a[j],a[i]);
        }
    }

}

/***********************************
 * Function: biggestOf2numbers
 * Purpose: finds the biggest number
 * Parameters: 2 numbers
 * Returns: the biggest number
 * Summary:
 * Notes:
 * ***********************************/
template <typename T>
T biggestOf2Numbers(T num1, T num2)
{
    if (num1>num2)
    {
        return num1;
    }
    else
        return num2;
}

/***********************************
 * Function: smallestOf2numbers
 * Purpose: finds the smallest number
 * Parameters: 2 numbers
 * Returns: the smallest number
 * Summary:
 * Notes:
 * ***********************************/
template <typename T>
T smallestOf2numbers(T num1, T num2)
{
    if (num1<num2)
    {
        return num1;
    }
    else
        return num2;
}


/***********************************
 * Function: reorderAsending
 * Purpose: find biggest of 2 numbers, reorders them in ascending order and sends them back.
 * Parameters: 2 numbers
 * Returns: 2 numbers in ascending order
 * Notes:
 * ***********************************/
template <typename T>
void reorderAsending(T &num1, T &num2)
{
    T bank=0;

    if (num1<num2)
    {
        bank=num2;
        num2=num1;
        num1=bank;
    }
}

/***********************************
 * Function: largest2Smallest
 * Purpose: reorders 2 numbers in descending order
 * Parameters: 2 numbers
 * Returns: 2 numbers in descending order
 * Summary:
 * Notes:
 * ***********************************/
template <typename T>
void largest2Smallest(T &num1, T &num2)
{
    T big=biggestOf2Numbers(num1,num2);
    T small=smallestOf2numbers(num1,num2);

    num1=big;
    num2=small;
}
/***********************************
  * Function:reverse
  * Purpose: reverses the array
  * Parameters: an array and the size of the array
  * Returns: the reversed array
  * Notes:
  * ***********************************/
template <typename T>
void reverse(T a[], int total)
{
    int i=0;
    int j=total-1;

    while (i<total/2)
    {
        swap2Numbers(a[i],a[j]);

        i++;
        j--;
    }
}

/***********************************
 * Function: Show
 * Purpose: Points at postion for debugging
 * Parameters: an array, a position ot point at
 * Returns: Nothing
 * Notes:
 * ***********************************/
template <typename T>
void Show(T a[], int pos)
{
    int i;
    T pointer[StrLen(a)];

    cout<<a<<endl;

    for (i=0;i<pos;i++)
    {
        pointer[i]='-';
    }

    pointer[i]='^';
    pointer[i+1]=NULL;


    cout<<pointer<<endl;
}
/***********************************
 * Function: initializeArray
 * Purpose: Initializes the array to int 0
 * Parameters: an array
 * Returns: an array
 * Notes:
 * ***********************************/
template <typename T>
void initializeArray(T a[],int total)
{
    for (int i=0;i<total;i++)
    {
        a[i]=0;
    }
}

/***********************************
 * Function: greatestCommonFactor
 * Purpose: finds the greatest common factor between 2 numbers
 * Parameters: 2 numbers
 * Returns: the greatest common factor
 * Summary:
 * Notes:
 * ***********************************/
int greatestCommonFactor(int num1, int num2)
{
    if (num1!=0 && num2!=0) //accounts for 0 exception
    {
        num1=abs(num1);//accounts for negative number exception
        num2=abs(num2);//accounts for negative number exception

        largest2Smallest(num1,num2); //reorders numbers in descending order

        for (int i=num1;i>0;i--) //starting from the top number, checks 1 factor of num1 against all numbers of num2 for a match, then returns the match.
        {
            if (num1%i==0)
            {
                for (int j=1;j<=num2;j++)
                {
                    if (i==static_cast <double> (num2)/j)
                        return i; //1 is always a factor
                }
            }
        }
    }
    return 0;
}
/***********************************
 * Function: int2String
 * Purpose: converts an interger into a string
 * Parameters: an integer
 * Returns: a string
 * Summary: Finds the biggest decimal place then works it way down, converting each digit in that decimal place into a char, and then adding that char to the end of a string.
 * Notes:
 * ***********************************/
string int2String (int number)
{
    string aString="";
    char aChar;

    int i=1;//can't divide by 0
    for  (i; i<=number; i=i*10); //this chunk finds how many places a number has, by multiplying i by 10 until it is bigger than the number, then dividing i by 10 once, cuz it is now off by one.
    i=i/10; //accounts for off by one

    while (i>0)
    {
        aChar=(number/i)+'0'; //converts a int to a char
        aString=aString+aChar; //adds the char at the end of the string

        number=number%i; //12345 becomes 2345 becomes 345 etc...
        i=i/10; //changes the decimal place
    }

    return aString;
}
#endif // TOOLS_H
