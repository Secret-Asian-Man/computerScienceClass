#include "counter.h"
#include <iostream>
using namespace std;


counter::counter()
{
    count=0;
}

counter::counter(int number)
{
    count=number;
}

counter::~counter()
{

}

//mutator
/***********************************
 * Function: setCount
 * Purpose: sets count to inputted number
 * Parameters: a number
 * Returns: nothing
 * Summary: if the input is postive, change count to that input
 * Notes:
 * ***********************************/
void counter::setCount(int number)
{
    if (number>=0)
    {
        count=number;
    }
}

//accessor
/***********************************
 * Function: getCount
 * Purpose: gets the count
 * Parameters: none
 * Returns: the count
 * Summary: returns the count
 * Notes:
 * ***********************************/
int counter::getCount()
{
    return count;
}

//functions
/***********************************
 * Function: printCount
 * Purpose: prints the count
 * Parameters: none
 * Returns: nothing
 * Summary: couts the count
 * Notes:
 * ***********************************/
void counter::printCount()
{
    cout<<"count: "<<count<<endl;
}

/***********************************
 * Function: resetCount
 * Purpose: resets count back to 0
 * Parameters:
 * Returns:
 * Summary:
 * Notes:
 * ***********************************/
void counter::resetCount()
{
    count=0;
}

/***********************************
 * Function: incrementCount
 * Purpose: increments count by 1
 * Parameters: none
 * Returns: nothing
 * Summary: increments count by one.
 * Notes:
 * ***********************************/
void counter::incrementCount()
{
    count=count+1;
}

/***********************************
 * Function: ++
 * Purpose: increments count by 1
 * Parameters: counter object
 * Returns: nothing
 * Summary:
 * Notes: MUST be called like so... ++blah
 * ***********************************/
void operator ++(counter &total)
{
    total.count=total.count+1;

}

/***********************************
 * Function: decrementCount
 * Purpose: decrements count by 1
 * Parameters: none
 * Returns: nothing
 * Summary: as long as count is a positive number, decrement count
 * Notes:
 * ***********************************/
void counter::decrementCount()
{
    if (count>=0)
    {
        count=count-1;
    }
}

/***********************************
 * Function: --
 * Purpose: decrements count by 1
 * Parameters: counter object
 * Returns: nothing
 * Summary:
 * Notes: MUST be called like so... --blah
 * ***********************************/
void operator --(counter &total)
{
    if (total.count>0)
    total.count=total.count-1;
}

