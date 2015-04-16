//3 types of creatures: Predator, prey, wall
//Creatures can: can eat, starve, breed, move

#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include "constants.h"
#include "coords.h"
#include <vector>

class creature
{
public:
    creature();
    creature(char creatureType, coords position, bool hasMoved);
    creature(char creatureType, int x, int y, bool hasMoved);
    ~creature();

    //accessors
    char get_creatureType();
    coords get_position();
    bool get_hasMoved();
    int get_age();

    //mutators
    void set_creatureType(char creatureType);
    void set_hasMoved(bool hasMoved);
    void set_position(coords xy);
    void set_position(int x, int y);
    void set_age(int input);


    //functions

    //creature now knows what the world is because it is passed on in the arguments.
    //Don't forget to check if creature has moved already.
    // when moving update the address, delete the old one, then REMEMBER to update the xy coordinates!!!
    void virtual die(creature* board[][ROWS]);
    void virtual eat(creature* board[][ROWS], std::vector<creature*> entities); //calls die and move
    void virtual breed(creature *board[][ROWS]);
    void virtual move(creature* board[][ROWS]);
    void increment_age();

    //operators
    creature& operator =(const creature& other);


private:

    char _creatureType; //stores what kind of creature it is
    bool _hasMoved; //starts as false, changes to true when moved. Remember to reset to true after everything has moved.
    coords _position;
    int _age;

protected:
    std::vector<coords> emptySpots(creature* board[][ROWS], coords target);
    std::vector<creature*> surroundings(creature* board[][ROWS], coords target);
//    void randomizeVector(std::vector<creature*> &me);


};

#endif // CREATURE_H
