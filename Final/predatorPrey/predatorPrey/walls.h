#ifndef WALLS_H
#define WALLS_H
#include "creature.h"

class walls:public creature
{
public:
    walls(coords position);
    walls(int x, int y);

    ~walls();




};

#endif // WALLS_H
