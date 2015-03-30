#ifndef COUNTER_H
#define COUNTER_H


class counter
{
public:
    //constructor
    counter();
    counter(int number);

    //deconstructor
    ~counter();

    //mutator
    void setCount(int number);

    //accessor
    int getCount();

    //functions
    void printCount();
    void resetCount(); //sets counts to 0
    void incrementCount(); //obsolete
    void decrementCount(); //obsolete

    friend void operator ++(counter &total); //increments count
    friend void operator --(counter &total); //decrements count


private:
    int count;

};

#endif // COUNTER_H
