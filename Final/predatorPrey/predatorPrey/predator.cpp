#include "predator.h"
#include "random.h"
#include <vector>

using namespace std;

predator::predator():creature(HUNTER,0,0,false)
{
    _hunger=0;
}

predator::predator(coords position):creature(HUNTER,position,false)
{
    _hunger=0;
}

predator::predator(int x, int y):creature(HUNTER,x,y,false)
{
    _hunger=0;
}


predator::~predator()
{

}

void  predator::move(creature* board[][ROWS])
{
    coords target=creature::get_position();
    vector<creature*> entities=creature::surroundings(board,target);
    bool food=false;

        for (int i=0;i<entities.size();i++) //checks entire list to see if there is food availible
        {
            if (entities[i]->get_creatureType()==PREY)
            {
                food=true;
                i=entities.size();
            }
        }

    if (food==true) //hunt down prey
    {
        _hunger=0;
        creature::eat(board,entities);
        creature::increment_age();
    }
    else //move normally
    {
        creature::move(board);
        _hunger++;
    }
//cout<<"Hunter age: "<<creature::get_age()<<endl;
//cout<<"Hunter hunger: "<<_hunger<<endl;

}

void predator::breed(creature* board[][ROWS])
{
    vector<coords> empty=emptySpots(board,creature::get_position()); //got my list of avalible spots
    if (empty.size()>0 )
    {
        if (creature::get_age()%PREDATOR_BREEDING_TIME==0)
        {
            random ran1(0,empty.size()-1); //makes a random number

            coords temp (empty[ran1.getRandomNumber()]); //stores the random coordinate

            board[temp.get_x()][temp.get_y()]=new predator(temp);

        }

    }
}

void predator::die(creature* board[][ROWS])
{
    //cout<<"2222222222222222222"<<endl;
    if (_hunger>=PREDATOR_DEATH_TIME)
    {

        creature::die(board);
    }
}
