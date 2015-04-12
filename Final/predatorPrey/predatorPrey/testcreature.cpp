#include "testcreature.h"

testCreature::testCreature()
{
    _position.set_xy(0,0);
}

testCreature::testCreature(int x, int y)
{
    _position.set_xy(x,y);
}

testCreature::testCreature(coords xy)
{
    _position.set_xy(xy.get_x(),xy.get_y());
}


testCreature::~testCreature()
{

}

void testCreature::moveRight(creature* board[][ROWS]) //creature now knows what the world is because it is passed on in the arguments. Don't forget to check if creature has moved already.
{
    if (board[_position.get_x()][_position.get_y()+1]==NULL)
    {
        board[_position.get_x()][_position.get_y()+1]=board[_position.get_x()][_position.get_y()]; //the slot next to original now also points at the original
        board[_position.get_x()][_position.get_y()]=NULL; //points the original pointer to NULL now

    }

}
