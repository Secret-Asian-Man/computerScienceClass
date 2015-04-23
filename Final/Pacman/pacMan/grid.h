#ifndef GRID_H
#define GRID_H
#include "object.h"
#include "constants.h"
#include <fstream>
#include <iostream>


class grid
{
public:
    grid();
    ~grid();





private:
    object* _board[X_DIMENSION][Y_DIMENSION]; //grid of creatures pointers
    std::ifstream _mapData;
    char _singleChar;



    //private functions
    void loadFile();
    void loadMap();

};

#endif // GRID_H
