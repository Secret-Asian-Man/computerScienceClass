#ifndef POINT_H
#define POINT_H
#include <iostream>

using namespace std;

class point
{
public:
    //constructors
    point();
    point(float x, float y);
    point (const point& other);

    //accessors
    float get_x() const;
    float get_y() const;

    //mutators
    void set_x(float x);
    void set_y(float y);
    void set_xy(float x, float y);

    //printers
    void print_x();
    void print_y();
    void print_xy();

    //operators
    point& operator =(const point& other);
    friend ostream& operator << (ostream &outs, const point &aPoint);


private:
    float _x;
    float _y;
};

#endif // POINT_H
