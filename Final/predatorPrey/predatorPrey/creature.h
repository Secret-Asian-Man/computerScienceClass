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

    //mutators
    void set_creatureType(char creatureType);
    void set_hasMoved(bool hasMoved);
    void set_position(coords xy);
    void set_position(int x, int y);


    //functions

    //creature now knows what the world is because it is passed on in the arguments.
    //Don't forget to check if creature has moved already.
    // when moving update the address, delete the old one, then REMEMBER to update the xy coordinates!!!
    void  move(creature* board[][ROWS]);
    void die(creature* board[][ROWS]);
    void breed(creature* board[][ROWS]);
    std::vector<creature*> surroundings(creature* board[][ROWS], coords target);

    //operators
    creature& operator =(const creature& other);


private:
    char _creatureType; //stores what kind of creature it is
    bool _hasMoved; //starts as false, changes to true when moved. Remember to reset to true after everything has moved.
    coords _position;
    int _age;


    //3 types of creatures: Predator, prey, wall
    //Creatures can: can eat, starve, breed, move


};

#endif // CREATURE_H
