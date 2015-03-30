#include "random.h"
#include <cstdlib>
#include <time.h>

random::random()
{
    srand(time(0));

    _lo=0;
    _hi=1000;

    _randomNumber=randomize(_lo,_hi);

}

random::random(int lo,int hi)
{
    srand(time(0));

    _lo=lo;
    _hi=hi;

    _randomNumber=randomize(_lo,_hi);

}

int random::getRandomNumber()
{
    return _randomNumber;
}


/***********************************
 * Function: Random
 * Purpose: generates a random number
 * Parameters: int lo, int hi
 * Returns: a random number
 * Notes: Needs   declaration: "srand(time(0));", " #include <time.h>", "#include <cstdlib>"
 * ***********************************/
int random::randomize(int lo, int hi)
{
    int range = hi-lo+1;
    int randomNumber = lo + (rand() % range);

//    int randomNumber= rand()%hi+lo; //gives a random number between lo and hi, inclusive.

    return randomNumber;
}
