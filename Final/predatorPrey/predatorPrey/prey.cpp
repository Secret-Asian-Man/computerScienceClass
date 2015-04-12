#include "prey.h"

prey::prey():creature(PREY,0,0,false)
{

}

prey::prey(coords position):creature(PREY,position,false)
{

}

prey::prey(int x, int y):creature(PREY,x,y,false)
{

}


prey::~prey()
{

}

