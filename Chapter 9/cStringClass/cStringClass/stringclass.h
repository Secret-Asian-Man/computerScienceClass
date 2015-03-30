
#ifndef STRINGCLASS_H
#define STRINGCLASS_H
#include <iostream>

using namespace std;

class stringClass
{
public:
    //CONSTRUCTORS
    stringClass();
    stringClass(char *s); //because string class is allocating space we need the BIG 3.


    //BIG 3
    stringClass(const stringClass& other); //makes a new address and puts in the same values in that new address
    stringClass& operator =(const stringClass& S);
    ~stringClass(); //runs the delete[] function.

    //ACCESSORS
    char* get_s();
    int get_size();
    int get_capacity();

    //PRINT
    void printAddress();

    //FUNCTIONS //NOTE: possibly write a function that detects if the length of the new string will exceed capacity, and increase capacity if does.
    bool increaseCapacity(int size);
    void moveHouse(char* source, int size);
    int length();
    void copy(char* source);
    void concatenate(char* source);
    int compare(stringClass otherArray); //takes the array from this class, and another
    char *subString(int pos, int len); //already have the 4 variables cuz we gave it an address
    char* character(char key);
    char* str(char* key);
    void clear(); //Erases the contents of the string, which becomes an empty string (with a length of 0 characters)
    bool isEmpty(); //Returns whether the string is empty (i.e. whether its length is 0).
    char at(int position);//returns the character at that position inside of _s.
    void pushBack(char entry); //puts a character at the end of the string, increasing the size by 1
    void assign (char* str);//assigns a new value to the string, replacing its current contents.
    void insert(char* str, int position); //Inserts additional characters into the string right before the character indicated by pos
    void erase(int startingPosition, int length); //Erases the portion of the string value that begins at the character position pos and spans len characters
    //(or until the end of the string, if either the content is too short or if len is string::npos.
    void replace(int startingPosition, int length, char* str); //Replaces the portion of the string that begins at character pos and spans len characters
    //(or the part of the string in the range between [i1,i2)) by new contents.
    char* cStr();//Returns a pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string) representing the current value of the string object
    char* find(char* key, int pos);//Searches the string for the first occurrence of the sequence specified by its arguments.
    char* rFind(char* key, int pos); //Searches the string for the last occurrence of the sequence specified by its arguments.
    char* findFirstOf(char* set, int pos);//Searches the string for the first character that matches any of the characters specified in its arguments
    char* findFirstNotOf(char* set, int pos);//Searches the string for the first character that does not match any of the characters specified in its arguments.

    //OPERATORS
    // friend ostream&  operator <<(std::ostream& out, const stringClass& S);
    void  operator +=(stringClass other); //adds 1 string at end of another. Uses append function
    char* operator [](int position); //Returns a reference to the character at position pos in the string.

private:
    char* _s;
    int _size;
    int _capacity;//how much room have you allocated
};

#endif // STRINGCLASS_H
