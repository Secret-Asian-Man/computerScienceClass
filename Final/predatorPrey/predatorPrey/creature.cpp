#include "creature.h"
#include "random.h"
using namespace std;

creature::creature()
{
    _creatureType='NULL';
    _hasMoved=false;
    _age=0;
}

creature::creature(char creatureType,coords position,bool hasMoved=false)
{
    _creatureType=creatureType;
    _hasMoved=hasMoved;
    _position=position;
    _age=0;

}

creature::creature(char creatureType, int x, int y, bool hasMoved)
{
    _creatureType=creatureType;
    _hasMoved=hasMoved;
    _position.set_xy(x,y);
    _age=0;

}

creature::~creature()
{

}

char creature::get_creatureType()
{
    return _creatureType;
}

coords creature::get_position()
{
    return _position;
}

bool creature::get_hasMoved()
{
    return _hasMoved;
}


void creature::set_creatureType(char creatureType)
{
    _creatureType=creatureType;
}

void creature::set_hasMoved(bool hasMoved)
{
    _hasMoved=hasMoved;
}

void creature::set_position(coords xy)
{
    _position=xy;
}

void creature::set_position(int x, int y)
{
    coords temp(x,y);

    _position=temp;
}

/***********************************
* Function:move
* Purpose: moves creature to a random place in a 3x3 square, with itself as the center.
* Parameters:
* Returns:
* Summary:while taking advantage of the fact that the craeture's own space is considered not empty, the program cycles through
* the 3x3 box relative to the creature. Then all coordinates of empty spaces are logged into a vector.
*The coordinates inside the vector will be accessed in a random slot to get a random coordinate.
* Notes:
************************************/
void creature::move(creature* board[][ROWS]) //creature now knows what the world is because it is passed on in the arguments. Don't forget to check if creature has moved already.
{

    vector<creature*> possibleMoves=surroundings(board,_position);

    cout<<possibleMoves.size()<<endl;
    for (int i=0;i<possibleMoves.size();i++)
    {
    }
















    //    vector<coords> possibleMoves;
    //    //make an array of possible moves then pick a random one to move to
    //    //I want to make a function that takes in the grid, and a coordinate, and returns a vector of possible moves
    //    for (int i=_position.get_x()-1;i<_position.get_x()+2;i++) //get_x()-1 starts off at row 0 stopping at row 2, because <3
    //    {

    //        for (int j=_position.get_y()-1;j<_position.get_y()+2;j++)//get_y()-1 starts off at coll 0 stopping at coll 2, because <3
    //        {
    //            if (board[i][j]==NULL) //if the spot is empty...
    //            {
    //                cout<<"i: "<<i<<", "<<"j: "<<j<<endl;
    //                possibleMoves.push_back(coords(i,j));//add the coords of that spot to the list

    //            }
    //            else
    //            {
    //                cout<<"Full"<<endl;
    //            }
    //        }
    //    }
    //    cout<<"possibleMoves.size(): "<<possibleMoves.size()<<endl;


    //    for (int i=0;i<possibleMoves.size();i++)
    //    {

    //      possibleMoves[i].print_xy(); cout<<endl;
    //    }




    ////    random ran1(0, possibleMoves.size()); //gets a random number from 0 to the size of the vector

    ////    if (board[_position.get_x()][_position.get_y()]->get_hasMoved()==false) //if the creature at that slot hasn't moved yet...
    ////    {
    ////        board[_position.get_x()][_position.get_y()]->set_hasMoved(true);//says the creature has moved now
    ////        board[_position.get_x()][_position.get_y()]->set_position(possibleMoves.at(ran1.getRandomNumber())); //sets the new coordinates

    ////        board[possibleMoves.at(ran1.getRandomNumber()).get_x()][possibleMoves.at(ran1.getRandomNumber()).get_y()]=board[_position.get_x()][_position.get_y()]; //actually moves the creature. Picks a random coord from the vector, and points it to the creature
    ////        board[_position.get_x()][_position.get_y()]=NULL; //sets the original space to NULL.
    ////    }

}

void creature::die(creature* board[][ROWS])
{
    delete board[_position.get_x()][_position.get_y()];
    board[_position.get_x()][_position.get_y()]=NULL;
}

void creature::breed(creature* board[][ROWS])
{

}

creature& creature::operator =(const creature& other)
{
    _creatureType=other._creatureType;
    _hasMoved=other._hasMoved;
    _position=other._position;
    _age=other._age;

}

//should I return the coords or the creatures? Which is more useful
vector<creature*> creature::surroundings(creature* board[][ROWS], coords target)
{
    vector<creature*> temp;

    // (x)(2)+1
target.print_xy();cout<<endl;
    for (int i=target.get_x()-RADAR_RANGE;i<target.get_x()+((/*maybe get rid of the *2  */RADAR_RANGE)+1);i++) //get_x()-1 starts off at row 0 stopping at row 2, because <3
    {

        for (int j=target.get_y()-RADAR_RANGE;j<target.get_y()+((RADAR_RANGE)+1);j++)//get_y()-1 starts off at coll 0 stopping at coll 2, because <3
        {
            if (board[i][j]==NULL) //if the spot is empty...
            {
                cout<<"pushing back null"<<endl;
                temp.push_back(NULL);//add the coords of that spot to the list
            }
            else
            {
                cout<<"Found, pushing...   ";  board[i][j]->get_position().print_xy();   cout<<endl;
                temp.push_back(board[i][j]);
            }
        }
    }

    cout<<"surroundings size: "<<temp.size()<<endl;
    return temp;
}
