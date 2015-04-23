#include "grid.h"
using namespace std;


grid::grid()
{
    loadFile();
    loadMap();
    _mapData.close();


}

grid::~grid()
{


}

void grid::loadFile()
{
    _mapData.open("PacManMap.txt");

    if (_mapData.fail()) //checks file
    {
        cout<<endl<<"****** Could not open file ******"<<endl;
        exit(0);
    }

}

void grid::loadMap()
{
    while(!_mapData.eof())
    {
        _mapData.get(_singleChar);
        if (_singleChar==13) //13 is the enter key
        {
            cout<<endl;
            //increment the row if it isn't past the MAX

        }
        else
        {
            cout<<_singleChar;
            //have a switch case that points to the correct object.

        }
    }
}

