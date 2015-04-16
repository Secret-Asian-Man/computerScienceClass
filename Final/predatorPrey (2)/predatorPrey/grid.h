#ifndef GRID_H
#define GRID_H

#include "creature.h"
#include "constants.h"

class grid
{
public:
    grid();
    ~grid();

    void intializeGrid(); //sets all the pointers in the 2d grid to NULL (same thing as CTOR)

    void step();

    void print();

private:
    creature* _board[ROWS][COLLS]; //grid of creatures pointers
    void placeWalls();
    void placeCreature(creature *critter);//can pass in a child
    void reset();

};

#endif // GRID_H
