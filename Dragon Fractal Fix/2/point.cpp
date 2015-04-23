#include "point.h"
#include <iostream>

using namespace std;
point::point()
{
    _x=0;
    _y=0;
}

point::point(double x, double y)
{
    _x=x;
    _y=y;
}

point::point (const point &other) //sets coords to the other coords
{
    _x=other._x;
    _y=other._y;

}

double point::get_x()
{
    return _x;
}

double point::get_y()
{
    return _y;
}

void point::set_x(double x)
{
    _x=x;

}

void point::set_y(double y)
{
    _y=y;

}

void point::set_xy(double x, double y)
{
    _x=x;
    _y=y;
}

void point::print_x()
{
    std::cout<<_x;
}

void point::print_y()
{
    std::cout<<_y;
}

void point::print_xy()
{
    std::cout<<"("<<_x<<","<<_y<<")";
}

point &point::operator =(const point& other)
{
    _x=other._x;
    _y=other._y;
}

ostream& operator <<(ostream &outs, const point &aPoint)
{
    outs << "("<<aPoint._x<<","<<aPoint._y<<")";

    return outs; //if we don't return we cant chain like so: cout<<"blah"<<" hello"<<endl;
}
