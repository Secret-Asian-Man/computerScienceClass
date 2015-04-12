#ifndef TESTCREATURE_H
#define TESTCREATURE_H
#include "constants.h"
#include "coords.h"
#include "creature.h"

class testCreature:public creature
{
public:
    //constructors
    testCreature();
    testCreature(int x, int y);
    testCreature(coords xy);

    //destructor
    ~testCreature();


    //functions
    void moveRight(creature* board[][ROWS]); //creature now knows what the world is because it is passed on in the arguments. Don't forget to check if creature has moved already.

private:
    coords _position; //location of testCreature
};

#endif // TESTCREATURE_H
