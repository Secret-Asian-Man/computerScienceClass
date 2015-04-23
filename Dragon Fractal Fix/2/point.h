#ifndef POINT_H
#define POINT_H
#include <iostream>

using namespace std;

class point
{
public:
    //constructors
    point();
    point(double x, double y);
    point (const point& other);

    //accessors
    double get_x();
    double get_y();

    //mutators
    void set_x(double x);
    void set_y(double y);
    void set_xy(double x, double y);

    //printers
    void print_x();
    void print_y();
    void print_xy();

    //operators
    point& operator =(const point& other);
    friend ostream& operator << (ostream &outs, const point &aPoint);

private:
    double _x;
    double _y;
};

#endif // POINT_H
