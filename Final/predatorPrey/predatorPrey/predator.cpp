#include "predator.h"

predator::predator():creature(HUNTER,0,0,false)
{

}

predator::predator(coords position):creature(HUNTER,position,false)
{
    //blank
}

predator::predator(int x, int y):creature(HUNTER,x,y,false)
{

}


predator::~predator()
{

}

