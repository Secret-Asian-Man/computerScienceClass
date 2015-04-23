#ifndef TOKEN_H
#define TOKEN_H


class token
{
public:
    token();
    token(char* aToken,int tokenType);
    ~token();

    virtual void print();



private:
    char* _token; //points to the cstring
    int _tokenType;

};

#endif // TOKEN_H
