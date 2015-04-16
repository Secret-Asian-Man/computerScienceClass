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

    void breed(creature* board[][ROWS]);
    void move(creature* board[][ROWS]);
    void die(creature* board[][ROWS]);

    //prey can:move, breed, die (getKilled)
};

#endif // PREY_H
