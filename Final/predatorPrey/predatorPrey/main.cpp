//Chapter 15, #11

//Minimal: Grid, coords, creature move

#include <iostream>
#include "grid.h"
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    srand(time(NULL));

    grid test;

    while(true)
    {
        test.step();

        test.print();
        cin.get(); //gets next generation
        system("cls"); //clears the screen

    }


}

