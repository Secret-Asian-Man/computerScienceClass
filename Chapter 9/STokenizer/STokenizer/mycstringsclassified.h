#ifndef MYCSTRINGSCLASSIFIED_H
#define MYCSTRINGSCLASSIFIED_H


class mycstringsClassified
{
public:
    mycstringsClassified();
    ~mycstringsClassified();



    //functions
    int strLen(char *source);
    void strCpy(char* source, char* destination);
    void strCat(char* source, char* destination);
    int strCmp(char* string1, char* string2);
    void subStr(char* source, char* sub, int start, int end);
    char* strChr(char* source, char key);
    char* strStr(char* source, char* key);

};

#endif // MYCSTRINGSCLASSIFIED_H
