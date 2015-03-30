#ifndef BIGINT_H
#define BIGINT_H


class bigInt
{
public:
    //constructors
    bigInt();
    bigInt(int number);
    bigInt(char* number);

    //destructors
    ~bigInt();

    //accessors
    char* get_bigInt();

    //mutators
    void set_bigInt(int number);
    void set_bigInt(char* number);
    void set_bigInt(char number); //keeps running cin.get and appending until enter(10) is pressed

    //functions
    void append(char number); //takes a character and put it at the end of _bigInt
    void add(const bigInt& other); //sets the _bigInt here to the total of _bigInt+ other._bigInt
    void reverse(); //reverses _bigInt

    //operators
    friend bigInt operator +(const bigInt& A, const bigInt& B); //adds 2 bigInts together






private:
    char* _bigInt;
};

#endif // BIGINT_H
