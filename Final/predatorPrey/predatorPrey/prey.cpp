#include "prey.h"
#include <iostream>
#include "random.h"
using namespace std;

prey::prey():creature(PREY,0,0,false)
{

}

prey::prey(coords position):creature(PREY,position,false)
{

}

prey::prey(int x, int y):creature(PREY,x,y,false)
{

}


prey::~prey()
{

}

void prey::breed(creature* board[][ROWS])
{
    vector<coords> empty=emptySpots(board,creature::get_position()); //got my list of avalible spots
    if (empty.size()>0 )
    {
        if (creature::get_age()%PREY_BREEDING_TIME==0)
        {
            random ran1(0,empty.size()-1); //makes a random number

            coords temp (empty[ran1.getRandomNumber()]); //stores the random coordinate

            board[temp.get_x()][temp.get_y()]=new prey(temp);

        }

    }
}

void prey::move(creature* board[][ROWS])
{
    creature::move(board);

}

void prey::die(creature* board[][ROWS])
{
    //std::cout<<"333333333333333"<<std::endl;
}

