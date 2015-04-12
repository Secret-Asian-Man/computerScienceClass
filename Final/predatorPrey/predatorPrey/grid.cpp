#include "grid.h"
#include "constants.h"
#include "iostream"
#include "testcreature.h"
#include "walls.h"
#include "prey.h"
#include "predator.h"
#include "random.h"
#include <iostream>

using namespace std;

grid::grid()
{
    intializeGrid(); //sets EVERYTHING to NULL.
    placeWalls();

    for (int i=0;i<AMOUNT_OF_PREDATORS;i++)
    {
        placeCreature(new predator);
    }

    for (int i=0;i<AMOUNT_OF_PREY;i++)
    {
        placeCreature(new prey);
    }

}

grid::~grid()
{

}


void grid::intializeGrid() //currently points EVERYTHING to null
{
    for (int i=0;i<ROWS;i++)
    {
        for (int j=0;j<COLLS;j++)
        {
            if (_board[i][j]!=NULL)
            {
                _board[i][j]=NULL; //has not taken walls into account
            }
        }
    }

}

/***********************************
* Function:placeWalls
* Purpose: places the walls
* Parameters:
* Returns:
* Summary:places a wall creature around the boarders
* Notes:
************************************/
void grid::placeWalls()
{

    for (int i=0;i<ROWS;i++)
    {
        _board[0][i]=new walls(0,i);

        _board[ROWS-1][i]=new walls(ROWS-1,i);
    }

    for (int i=0;i<COLLS;i++)
    {
        _board[i][0]=new walls(i,0);
        _board[i][COLLS-1]=new walls(i,COLLS-1);

    }
}

void grid::placeCreature(creature* critter) //places creature in a random empty spot
{
    //random numbers

    if (AMOUNT_OF_CREATURES<(ROWS-2)*(COLLS-2))
    {


        random ran1(0,ROWS-1);
        random ran2(0,COLLS-1);

        if (DEBUG)
        {
            cout<<"ran1: ";ran1.printRandom();cout<<endl;
            cout<<"ran2: ";ran2.printRandom();cout<<endl<<endl;
        }

        bool tryAgain=true;

        while (tryAgain==true) //keeps trying to place critter in a random place until success
        {
            if (_board[ran1.getRandomNumber()][ran2.getRandomNumber()]==NULL) //if the spot is empty...
            {
                _board[ran1.getRandomNumber()][ran2.getRandomNumber()]=critter; //put a critter.
                critter->set_position(ran1.getRandomNumber(),ran2.getRandomNumber()); //sets new coords

                if(DEBUG)
                {
                    cout<<"PLACED! "<<endl;
                    cout<<"ran1: ";ran1.printRandom();cout<<endl;
                    cout<<"ran2: ";ran2.printRandom();cout<<endl;
                    critter->get_position().print_xy(); cout<<endl;
                }

                tryAgain=false;
            }
            else
            {
                ran1.newRandom(); //get new random coordinates...
                ran2.newRandom();

                //            if (DEBUG)
                //            {
                //                cout<<"Trying again..."<<endl;
                //                cout<<"ran1: ";ran1.printRandom();
                //                cout<<" ran2: ";ran2.printRandom();cout<<endl;
                //            }

                tryAgain=true;
            }

        }
    }
    else
    {
        cout<<"TOO MANY CRITTERS!!!"<<endl;
        exit(0);
    }
}


void grid::step()
{
    for (int i=1;i<ROWS-1;i++)
    {
        for (int j=1;j<COLLS-1;j++)
        {
            if (_board[i][j]!=NULL)
            {
                _board[i][j]->move(_board);//<---@@@@@ problem
                //_board[i][j]->get_position().print_xy();cout<<endl;
            }
            else
            {
                    //cout<<"grid step empty : "<<endl;
            }
        }
    }

}

void grid::print()
{

    for (int i=0;i<ROWS;i++)
    {
        for (int j=0;j<COLLS;j++)
        {

            if (_board[i][j]!=NULL)//if the slot is taken print that creature's type
            {
                cout<<_board[i][j]->get_creatureType()<<" "; //currently printing NULL.

            }
            else
            {
                cout<<EMPTY<<" "; //prints a empty slot
            }
            //@@@@@@ want set and print out the wall next
        }
        cout<<endl;
    }

}
