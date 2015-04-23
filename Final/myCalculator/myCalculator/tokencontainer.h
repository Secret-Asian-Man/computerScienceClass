#ifndef TOKENCONTAINER_H
#define TOKENCONTAINER_H
#include "token.h"
#include <deque>
#include <iostream>

class tokenContainer
{
public:
    tokenContainer();
    tokenContainer(char* equation, int position=0);
    tokenContainer(std::string equation, int position=0 );

    ~tokenContainer();

    void print();


private:
std::deque<token*> _container;
char* _equation; //contains the equation to be coverted
int _position;

//private functions
bool getNextToken (char source[], int &pos);
bool zorg(char source[], char charSet[], char *&tokenPointer, int &pos);
bool find(char key, char charSet[]);
void cstr(std::string source, char* dest); //converts string to cstring


};

#endif // TOKENCONTAINER_H
