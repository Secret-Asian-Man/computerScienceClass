#ifndef RANDOM_H
#define RANDOM_H


class random
{
public:
    random();
    random(int lo,int hi);

    //functions
    int getRandomNumber();


private:
    int _randomNumber;
    int _lo;
    int _hi;
    int randomize(int lo, int hi);
};

#endif // RANDOM_H
