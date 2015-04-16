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

    void  move(creature* board[][ROWS]);
    void breed(creature* board[][ROWS]);
    void die(creature* board[][ROWS]);

private:
    int _hunger;

    //predators can: eat, starve, breed, move (call functions from parent)
};

#endif // PREDATOR_H
