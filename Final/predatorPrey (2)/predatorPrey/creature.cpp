#include "creature.h"
#include "random.h"
using namespace std;

creature::creature()
{
    _creatureType=NULL;
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

int creature::get_age()
{
    return _age;
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
void creature::set_age(int input)
{
    _age=input;
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

    //cout<<"Original: "; _position.print_xy(); cout<<endl;

    vector<coords> empty=emptySpots(board,_position);

    if (empty.size()>0)
    {
        random ran1(0,empty.size()-1);

        //            for (int i=0;i<empty.size();i++) //prints out the vector
        //            {

        //                empty[i].print_xy();
        //            }
        //            cout<<endl<<endl;

        //    cout<<empty.size()<<endl;

        //i want to move orignal to random new location, if it hasnt moved already. remember to update coords
        //0.) if it hasn't moved already
        //1.) update coords
        //2.) set moved to true
        //3.) set random new location to point the original
        //4.) set original to point to NULL


        coords randomCoord(empty[ran1.getRandomNumber()]);
        //        cout<<"limit: "<<ran1._lo<<"    "<<ran1._hi<<endl;
        //        cout<<"pick random #: "<<ran1.getRandomNumber()<<endl;
        coords bank(_position);

        //        cout<<"moving to: "; randomCoord.print_xy(); cout<<endl;


        board[randomCoord.get_x()][randomCoord.get_y()]=
                board[_position.get_x()][_position.get_y()]; //All it does is set random new location to point the original.

        _position=randomCoord; //updates the coords

        board[bank.get_x()][bank.get_y()]=NULL; //sets original to NULL


        //        cout<<"moved to: "; randomCoord.print_xy(); cout<<endl;






    }
    _age++;
}

void creature::die(creature* board[][ROWS])
{
    //this die function has been called because someone else says it is time to die!
    //cout<<"11111111111111111"<<endl;
    delete board[_position.get_x()][_position.get_y()];
    board[_position.get_x()][_position.get_y()]=NULL;
}
void creature::eat(creature* board[][ROWS], vector<creature *> entities) //calls die and move
{
    //scroll through the entire vector for a prey, if there is none move normally, if there is eat it.
    //Randomize vector?

    //random ran1(0,entities.size()-1);

    for (int i=0;i<entities.size();i++) //going through entire vector
    {
        if (entities[i]->get_creatureType()==PREY) //looking for the first prey
        {
            coords preyPos(entities[i]->get_position()); //saves the coords of the food
            coords hunterPos(creature::get_position()); //saves original coords of the hunter

            entities[i]->die(board); //kills the food



            board[preyPos.get_x()][preyPos.get_y()]=board[hunterPos.get_x()][hunterPos.get_y()];//points dead prey's pointer to hunter now, aka moves hunter to the food's position
            board[hunterPos.get_x()][hunterPos.get_y()]->set_position(preyPos); //updates the hunter's coordinates
            board[hunterPos.get_x()][hunterPos.get_y()]=NULL;//sets hunter's previous position to NULL

            i=entities.size(); //after the prey is eaten, stop looking for new ones.
        }
    }


}

void creature::breed(creature* board[][ROWS])
{
    //this breed function has been called because someone else says it is time to breed!
    //if in your surroundings there is someone of the same type, and an a empty spot.
    //spawn someone of your type into the empty spot
   // cout<<"CREATURE BREED FIRED"<<endl;
    vector<coords> empty=emptySpots(board,_position); //got my list of avalible spots

    if (empty.size()>0)
    {
        cout<<"BREEDING : "<<endl;
        random ran1(0,empty.size()-1); //makes a random number

        coords temp (empty[ran1.getRandomNumber()]); //stores the random coordinate

        board[temp.get_x()][temp.get_y()]=new creature(_creatureType, temp ,false);

    }







    //uses surroundings function and emptySpots function
}
void creature::increment_age()
{
    _age=_age+1; //THIS LINE DOESN'T WORK?!?!?!

}

creature& creature::operator =(const creature& other)
{
    _creatureType=other._creatureType;
    _hasMoved=other._hasMoved;
    _position=other._position;
    _age=other._age;

}

//should I return the coords or the creatures? Which is more useful
vector<creature*> creature::surroundings(creature* board[][ROWS], coords target) //for breed/eating
{
    vector<creature*> temp;

    for (int i=target.get_x()-RADAR_RANGE;i<target.get_x()+((RADAR_RANGE)+1);i++) //get_x()-1 starts off at row 0 stopping at row 2, because <3
    {

        for (int j=target.get_y()-RADAR_RANGE;j<target.get_y()+((RADAR_RANGE)+1);j++)//get_y()-1 starts off at coll 0 stopping at coll 2, because <3
        {
            if (board[i][j]!=NULL && board[i][j]->get_position()!=target) //if the spot is empty...
            {
                if (board[i][j]->get_creatureType()!=WALLS)
                {
                    temp.push_back(board[i][j]);//add the coords of that spot to the list

                }
            }
        }
    }

    return temp;

    //    vector<creature*> temp;

    //    for (int i=target.get_x()-RADAR_RANGE;i<target.get_x()+((RADAR_RANGE)+1);i++) //get_x()-1 starts off at row 0 stopping at row 2, because <3
    //    {

    //        for (int j=target.get_y()-RADAR_RANGE;j<target.get_y()+((RADAR_RANGE)+1);j++)//get_y()-1 starts off at coll 0 stopping at coll 2, because <3
    //        {

    //                if (board[i][j]->get_position()!=target && board[i][j]!=NULL)
    //                {
    //                    cout<<"Found, pushing...   ";  board[i][j]->get_position().print_xy();   cout<<endl;
    //                    temp.push_back(board[i][j]);

    //                }
    //        }
    //    }

    //    return temp;
}

vector<coords> creature::emptySpots(creature* board[][ROWS], coords target) //for moving
{
    vector<coords> temp;

    for (int i=target.get_x()-RADAR_RANGE;i<target.get_x()+((RADAR_RANGE)+1);i++) //get_x()-1 starts off at row 0 stopping at row 2, because <3
    {

        for (int j=target.get_y()-RADAR_RANGE;j<target.get_y()+((RADAR_RANGE)+1);j++)//get_y()-1 starts off at coll 0 stopping at coll 2, because <3
        {
            if (board[i][j]==NULL) //if the spot is empty...
            {
                temp.push_back(coords(i,j));//add the coords of that spot to the list
            }
        }
    }

    return temp;
}

//void creature::randomizeVector(vector<creature*> &me)
//{
//    random ran1(0,me.size());
//    random ran2(0,me.size());

//    for (int i=0;i<HOW_RANDOM;i++)
//    {

//        swap(me[ran1.getRandomNumber()],me[ran2.getRandomNumber()]); //@@@ IT WONT SWAP!!!!!!!

//    }

//    //    for (int i=0;i<me.size();i++) //prints out the vector
//    //    {
//    //        cout<<i<<":"<<me[i]<<"  ";
//    //    }
//    //cout<<endl<<endl;

//}

