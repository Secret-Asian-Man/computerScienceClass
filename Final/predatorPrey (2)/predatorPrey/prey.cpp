#include "prey.h"
#include <iostream>
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
   cout<<"wdadhtefw "<< creature::get_age()<<endl; //cant run get_age()?
//   std::cout<<"PREY BREED FIRED!!"<<std::endl;
//    if (creature::get_age()%PREY_BREEDING_TIME==0) //might breed right away at age 0
//    {

        creature::breed(board);
//    }
}

void prey::move(creature* board[][ROWS])
{
    creature::move(board);
    std::cout<<"prey age: "<<creature::get_age()<<std::
               endl;
}

void prey::die(creature* board[][ROWS])
{
    std::cout<<"333333333333333"<<std::endl;
}
