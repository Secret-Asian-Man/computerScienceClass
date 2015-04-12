#ifndef PREY_H
#define PREY_H
#include "creature.h"

class prey:public creature
{
public:
    prey();
    prey(coords position);
    prey(int x, int y);
    ~prey();




    //prey can:move, breed, die (getKilled)
};

#endif // PREY_H
