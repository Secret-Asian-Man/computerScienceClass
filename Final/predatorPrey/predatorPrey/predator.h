#ifndef PREDATOR_H
#define PREDATOR_H
#include "creature.h"


class predator:public creature
{
public:
    predator();
    predator(coords position);
    predator(int x, int y);
    ~predator();




//predators can: eat, starve, breed, move (call functions from parent)
};

#endif // PREDATOR_H
