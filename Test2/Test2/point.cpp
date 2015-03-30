#include "point.h"
#include <iostream>


point::point()
{
    _x=0;
    _y=0;
}

point::point(float x, float y)
{
    _x=x;
    _y=y;
}

point::point (const point &other) //sets coords to the other coords
{
    _x=other._x;
    _y=other._y;

}

float point::get_x() const
{
    return _x;
}

float point::get_y() const
{
    return _y;
}

void point::set_x(float x)
{
    _x=x;

}

void point::set_y(float y)
{
    _y=y;

}

void point::set_xy(float x, float y)
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
    outs << "("<<aPoint.get_x()<<","<<aPoint.get_y()<<")";

    return outs; //if we don't return we cant chain like so: cout<<"blah"<<" hello"<<endl;
}
