#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <vector>
#include "point.h"
#include <list>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;



//make it automatic, it keeps going to a certain iteration then comes back.
//need a auto iterate
//need a goBack function

//need a counter in the corner to count amount of iterations.
//make a input box for angles (google sfml get inputs).




const double ANGLE=90   ; //Change the angle for fun!
const bool COLORS=false; //set to true or false
const bool CLOCKWISE=false; //set to true or false
const bool DEBUG=true; //set to true or false
const int MAX_ITERATIONS=11; //Automatically iterates X amount of times











const double WINDOW_WIDTH=800;
const double WINDOW_HEIGHT=600;
const sf::Vector2f BACKGROUND_OFFSET(-500,-800);

const double CIRCLE_RADIUS=2;
const double MOVE_RATE=25;
const double POINT_OFFSET=550;
const int AX=50;
const int AY=0;
const int BX=550;
const int BY=0;
const double RATE=1*1000;





void iterateList(list<point> &aList, double angle); //highest level function
void printList(list<point> aList); //must use [const &] to work
template <typename T>
T Random(T lo, T hi);
void randomizeAllLineColors (sf::VertexArray &lines, list<point> listOfPoints);
void setAllLinePostitions(sf::VertexArray &lines, list<point> listOfPoints);
point NewDragonPoint(point &startpoint, point &endpoint, double theta, bool turnclockwise);
void goBack (list<point> &listOfPoints);



int main()
{
    srand(time(0));
    double moveRate=MOVE_RATE;
    bool toggleDirection=true;
    bool toggleAuto=false;
    int iterationCount=0;

    point A(AX,AY);
    point B(BX,BY);

    list<point> listOfPoints;
    listOfPoints.push_back(A); //manually added point A
    listOfPoints.push_back(B); //manually added point B

    if (DEBUG)
    {
        cout<<"size of list: "<<listOfPoints.size()<<endl<<"Loading...";
    }


    //```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Dragon Fractal");
    sf::View view(sf::Vector2f(-300, -300), sf::Vector2f(WINDOW_WIDTH+300, WINDOW_HEIGHT+300));
    view.setCenter((WINDOW_WIDTH/2)+350, (WINDOW_HEIGHT/2)+150);

    sf::Texture texture;
    sf::Sprite background;

    if (!texture.loadFromFile("DragonFractalBackground.png"))
        cout<<"File not found."<<endl;

    background.setTexture(texture);
    background.setPosition(BACKGROUND_OFFSET); //-500,-800


    sf::Clock clock; //keeps track in microSeconds how much time has elapsed  (1 second= 1,000,000 microSeconds)
    sf::Time time=sf::Time::Zero; //holds the value from clock, but time can return micro,mili, or normal seconds.

    while (window.isOpen())
    {

        //===================auto========================
        if (toggleAuto==true)
        {
            time=clock.getElapsedTime();
            if (time.asMilliseconds()>=RATE-time.asMilliseconds())
            {
                if (DEBUG)
                {
                    cout<<"DEBUG time: "<<time.asMilliseconds()<<endl;
                    cout<<"DEBUG iterationCount: "<<iterationCount<<endl;

                }

                if (toggleDirection==true)
                {
                    if (iterationCount>=MAX_ITERATIONS)
                    {
                        toggleDirection=false;
                    }

                    iterateList(listOfPoints,ANGLE); //fills up the list
                    iterationCount++;

                }
                if (toggleDirection==false)
                {
                    if (iterationCount<=0)
                    {
                        toggleDirection=true;
                    }
                    goBack(listOfPoints);
                    iterationCount--;



                }


                clock.restart();

            }

        }



        //====================================================

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }

            if(event.key.code==sf::Keyboard::Space && event.type==sf::Event::KeyReleased) //runs only if the space key is released
            {
                //draw next iteration
                if (iterationCount<=MAX_ITERATIONS)
                {
                    iterateList(listOfPoints,ANGLE); //fills up the list
                    iterationCount++;
                }

                if (DEBUG)
                {
                    cout<<endl;printList(listOfPoints);cout<<endl<<endl<<endl;
                }
            }

            if(event.key.code==sf::Keyboard::Tab && event.type==sf::Event::KeyReleased) //runs only if the space key is released
            {
                toggleAuto=!toggleAuto;
            }

            if(event.key.code==sf::Keyboard::BackSpace && event.type==sf::Event::KeyReleased) //runs only if the space key is released
            {
                if (iterationCount>0)
                {
                    goBack(listOfPoints);
                    iterationCount--;
                }

                if (DEBUG)
                {
                    cout<<endl;printList(listOfPoints);cout<<endl<<endl<<endl;
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
            {

                view.zoom(0.9f);
                moveRate=moveRate/1.1;//rounding messes up the moveRate
                if (DEBUG)
                {
                    cout<<"DEBUG moveRate: "<<moveRate<<endl;
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
            {
                view.zoom(1.1f);
                moveRate=moveRate*1.1; //rounding messes up the moveRate
                if (DEBUG)
                {
                    cout<<"DEBUG moveRate: "<<moveRate<<endl;
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                view.move(sf::Vector2f(-moveRate,0));
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                view.move(sf::Vector2f(moveRate,0));
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                view.move(sf::Vector2f(0,-moveRate));
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                view.move(sf::Vector2f(0,moveRate));
            }
        }

        window.clear(sf::Color::Black);

        sf::VertexArray lines(sf::LinesStrip, listOfPoints.size());


        setAllLinePostitions(lines,listOfPoints);

        if (COLORS)
        {
            randomizeAllLineColors(lines,listOfPoints);
        }

        window.draw(background);
        window.draw(lines);

        window.setView(view);
        window.display();
    }
    return 0;
}

//```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

/***********************************
* Function:iterateList
* Purpose: generates multiple new points and adds them to the list in a specific order.
* Parameters: a list with 2 points already in it, an angle
* Returns: nothing
* Summary: refer to notes.
* Notes://highest level function
************************************/
void iterateList(list<point> &aList, double angle)
{
    //refer to notes and start adding to the list.

    bool clockWise=CLOCKWISE; //starts as false

    list<point>::iterator it=aList.begin();
    it++; //starts the iterator at the second slot

    list<point>::iterator itPrevious=aList.begin(); //want to start itPrevious just before main iterator


    while(it != aList.end()) //while iterator hasn't reached the end of the list
    {
        aList.insert(it,NewDragonPoint(*itPrevious, *it, angle, clockWise));


        clockWise=!clockWise;

        itPrevious=it;
        it++;

    }

}


/***********************************
* Function:RandomColor
* Purpose: returns a randon color from the rainbow
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
sf::Color RandomColor()
{
    int randomNumber=Random(1,7);
    // cout<<"DEBUG randomNumber: "<<randomNumber<<endl;

    //return sf::Color::White;

    switch (randomNumber)
    {

    case 1:
        return sf::Color(255,0,0); //red
        break;

    case 2:
        return sf::Color(255,127,0); //orange
        break;

    case 3:
        return sf::Color(255,255,0); //yellow
        break;

    case 4:
        return sf::Color(0,255,0); //green
        break;

    case 5:
        return sf::Color(0,0,255); //blue
        break;

    case 6:
        return sf::Color(75,0,130); //indigo
        break;

    case 7:
        return sf::Color(143,0,255); //violet
        break;

    default:
        cout<<"Invalid key..."<<endl;
    }

}

/***********************************
 * Function: Random
 * Purpose: gnerates a random number
 * Parameters: int lo, int hi
 * Returns: a random number
 * Notes: Needs   declaration: "srand(time(0));", " #include <time.h>", "#include <cstdlib>"
 * ***********************************/
template <typename T>
T Random(T lo, T hi) //range of valid numbers
{
    T range = hi-lo+1;

    T randomNumber = lo + (rand() % range);

    return randomNumber;
}

/***********************************
* Function:NewDragonPoint
* Purpose: calculates the 3rd point
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
point NewDragonPoint(point &startpoint, point &endpoint, double theta, bool turnclockwise) //Uses cmath, assumes global constant PI is defined, theta is in degrees.
{
    point R; //temporarily holds the 3rd point
    double rx,ry; //for holding distances
    double A = cos(M_PI*theta/180); //cosine of the radian version

    theta=90-theta/2;
    if(turnclockwise) //reverses the angle
        theta*=-1;

    theta=M_PI*theta / 180;
    rx=endpoint.get_x()-startpoint.get_x(); //finds distance
    ry=endpoint.get_y()-startpoint.get_y(); //finds distance

    R.set_x((1/sqrt(2*(1-A)))*(rx*cos(theta)-ry*sin(theta)) + startpoint.get_x());
    R.set_y((1/sqrt(2*(1-A)))*(rx*sin(theta)+ry*cos(theta)) + startpoint.get_y());

    return R;
}

/***********************************
* Function:setAllLinePostitions
* Purpose: plays connect the dots using the points in the list
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
void setAllLinePostitions(sf::VertexArray &lines, list<point> listOfPoints)
{
    list<point>::iterator it=listOfPoints.begin();

    for (int i=0;i<listOfPoints.size();i++)
    {

        lines[i].position = sf::Vector2f(it->get_x()+POINT_OFFSET,-it->get_y()+POINT_OFFSET); //gets the coords from the list

        it++;
    }
}

/***********************************
* Function:randomizeAllLineColors
* Purpose: assigns a random color from the rainbow to every point in the list
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
void randomizeAllLineColors (sf::VertexArray &lines, list<point> listOfPoints)
{
    list<point>::iterator it=listOfPoints.begin();

    for (int i=0;i<listOfPoints.size();i++)
    {
        lines[i].color = RandomColor();

        it++;
    }
}

/***********************************
* Function:printList
* Purpose: Prints the entire list of points using (x,y) format
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
void printList( list<point> aList)
{
    list<point>::iterator it=aList.begin();

    while(it != aList.end())
    {
        cout<<*it<<" ";


        it++; //iterator doesn't actually get changed
    }

}

/***********************************
* Function:goBack
* Purpose:
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
void goBack (list<point> &listOfPoints)
{
    list<point>::iterator it=listOfPoints.begin();

    list<point>::iterator start=listOfPoints.begin();
    list<point>::iterator end=listOfPoints.end();
    end--;



    while(it != listOfPoints.end())
    {
        if (it!=start && it!=end)
        {
            it=listOfPoints.erase(it);
        }

        it++; //iterator doesn't actually get changed
    }



}


