#include "stringclass.h"


void Delete(char* array);


stringClass::stringClass()
{

    _size=0;
    _capacity=2;
    char*newArray=new char [_capacity];
    _s=newArray;

}

/***********************************
* Function:stringClass
* Purpose: creates new string class using a cstring input from user
* Parameters: a cstring input from user
* Returns:
* Summary: Measures the length of the cstring, then keeps increasing the capacity by the power of 2
*          until the capacity is bigger than the length. Then a new pointer is created with that capcity
*          Then, the user's cstring is copied over to the new cstring.
* Notes:
************************************/
stringClass::stringClass(char* s)
{
    int length=strLen(s);
    _capacity=2;

    if(increaseCapacity(length))
    {
        moveHouse(s,length);
    }
}

/***********************************
* Function:copy constructor
* Purpose: makes a new address and puts in the same values in that new address, and gives that address to _s
* Parameters: 2 stringClass objects
* Returns: nothing
* Summary:makes a new address that has the same capacity as other._capacity. Then copy the stuff from other._s into the new array.
*         Then forgets the address of the current _s, and gives it the new Address, along with the new capacity and size.
*
* Notes:
************************************/
stringClass::stringClass(const stringClass& other)
{
    int newCapacity=other._capacity;
    char* newArray= new char [newCapacity];


    strCpy(other._s,newArray);

    delete[] _s;

    _s=newArray;
    _capacity=newCapacity;
    _size=other._size;


}

/***********************************
* Function: copy operator
* Purpose: makes a new address and puts in the same values in that new address, and gives that address to _s
* Parameters: 2
* Returns:2 stringClass objects
* Summary:makes a new address that has the same capacity as other._capacity. Then copy the stuff from other._s into the new array.
*         Then forgets the address of the current _s, and gives it the new Address, along with the new capacity and size.
* Notes:
************************************/
stringClass& stringClass::operator =(const stringClass& S)
{
    if (&S==this)
    {
        return *this;
    }

    char* newArray= new char [S._capacity];

    strCpy(S._s,newArray);

    delete[] _s;

    _s=newArray;
    _capacity=S._capacity;
    _size=S._size;


}


/***********************************
* Function: destructor
* Purpose:
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
stringClass::~stringClass()
{
    //delete[] _s;
}

//PRINT

/***********************************
* Function:printAddress
* Purpose: prints the current address of _s
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
void stringClass::printAddress()
{
    cout<<&_s;
}

//ACCESSORS

/***********************************
* Function:get_s
* Purpose: gets the current value of _s
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
char* stringClass::get_s()const //TRYING TO COUT THIS IN A << OPERATOR
{
    return _s;
}

/***********************************
* Function:get_size
* Purpose:gets the current value of _size
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
int stringClass::get_size()
{
    return _size;
}

/***********************************
* Function:get_capacity
* Purpose:gets the current value of _capacity
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
int stringClass::get_capacity()
{
    return _capacity;
}

//functions
/***********************************
* Function:increaseCapacity
* Purpose: increases capacity, and checks if it has been activated
* Parameters: a size to compare to
* Returns: true if function was activated, false if not
* Summary:if the current capacity is bigger than the size then, no need to run the function, get out and return false.
*         Else, keep doubling the capacity until the capacity is bigger than the size, then return true.
* Notes:
************************************/
bool stringClass::increaseCapacity(int size)
{
    if(_capacity>=size)
    {
        return false;
    }

    while (_capacity<size) //keep doubling the capacity until it is bigger than the length of the new cstring
    {
        _capacity=_capacity*2;
    }

    return true;

}

/***********************************
* Function:moveHouse
* Purpose: moves stuff to a new address
* Parameters: a cstring, the size of the cstring
* Returns: nothing
* Summary: makes a new address and moves everything from the old address into the new one. Then releases the memeory from the old address.
* Notes:
************************************/
void stringClass::moveHouse(char* source, int size)
{
    char* newPointer= new char[_capacity]; //new home
    strCpy(source,newPointer);//moving stuff

    delete[] _s; //abandoning old house

    _s=newPointer; //moving in new house

    _size=size;
}

/***********************************
* Function:length
* Purpose: gets the length
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
int stringClass::length()
{
    return strLen(_s);
}

/***********************************
* Function:copy
* Purpose:copies a cstring into _s
* Parameters:a cstring
* Returns:nothing
* Summary:if the source is bigger than the current capacity, increase the capacity and then move the stuff over.
* Notes:
************************************/
void stringClass::copy(char* source)
{
    int length=strLen(source);

    if  (increaseCapacity(length))
    {
        moveHouse(source,length);
    }
    else
    {
        strCpy(source,_s);
    }

}

/***********************************
* Function:concatenate
* Purpose: adds a cstring to the end of the current cstring
* Parameters:another cstring
* Returns:nothing
* Summary:make a new array with a big enuff capacity to hold these two strings and put everything in there.
* Notes:
************************************/
void stringClass::concatenate(char* source)
{
    int length=_size+strLen(source);

    if (increaseCapacity(length))
    {
        moveHouse(_s,length);
        strCat(source,_s);
    }
    else
    {
        _size=length;
        strCat(source,_s);
    }
}

void  stringClass::operator +=(stringClass other) //adds 1 string at end of another. Uses append function
{
    int length=_size+strLen(other._s);

    if (increaseCapacity(length))
    {
        moveHouse(_s,length);
        strCat(other._s,_s);
    }
    else
    {
        _size=length;
        strCat(other._s,_s);
    }

}

/***********************************
* Function:compare
* Purpose: compares 2 strings
* Parameters: 2 stringClass objects
* Returns: -1 if first different character in string1 is SMALLER than the character in string2.
*           0 if everything is the same.
*           1 if first different character in string1 is BIGGER than the character in string2.
* Summary:
* Notes:
************************************/
int stringClass::compare(stringClass otherArray) //takes the array from this class, and another
{
    return strCmp(_s,otherArray._s);
}

/***********************************
* Function: subString
* Purpose:creates a new cstring using part of a old one
* Parameters: starting and ending position
* Returns:
* Summary:
* Notes:Still needs testing
************************************/
char* stringClass::subString(int pos, int len) //already have the 4 variables cuz we gave it an address
{
    int size=len-pos;
    char* sub=new char[size];

    subStr(_s,sub,pos,len);

    return sub;
}
char* stringClass:: subStringProto(char* start, char* end)
{
    char* startWalker=start;
    char* endWalker=end;

    char*sub=new char[(end-start)+1];

    subStr(_s,sub,start-_s,end-_s);
     //finish!!


}



/***********************************
* Function:character
* Purpose: gets address of where first instance of [key] is
* Parameters: a character to search for
* Returns:
* Summary:
* Notes:
************************************/
char* stringClass::character(char key)
{
    return strChr(_s,key);
}

/***********************************
* Function:str
* Purpose: gives us the address of where a particular cstring is located in another cstring
* Parameters: cstring of what to search for
* Returns:
* Summary:
* Notes:
************************************/
char* stringClass::str(char* key)
{
    return strStr(_s,key);
}

/***********************************
* Function:clear
* Purpose: //Erases the contents of the string, which becomes an empty string (with a length of 0 characters)
* Parameters:
* Returns:
* Summary:makes a new empty address, forgets the old address, then sets _s tot he new address
* Notes:
************************************/
void stringClass::clear()
{
    _size=0;
    _capacity=2;

    delete[] _s;

    _s=new char[_capacity];

    *_s=NULL;
}

/***********************************
* Function:isEmpty
* Purpose: checks if the cstring is empty or not
* Parameters:
* Returns: true if empty, false if not
* Summary:if the value of the first slot in the array is NULL and the size is 0 return true.
* Notes: keep or exclude && _size==0?
************************************/
bool stringClass::isEmpty() //Returns whether the string is empty (i.e. whether its length is 0).
{
    if (*_s==NULL && _size==0) //keep or exclude && _size==0?
    {
        return true;
    }
    else
        return false;
}

/***********************************
* Function:at
* Purpose:returns the character at that position inside of _s.
* Parameters: a postion
* Returns:returns the character at that position inside of _s
* Summary: sets the address tot he position and returns the value inside that position
* Notes:
************************************/
char stringClass::at(int position)//returns the character at that position inside of _s.
{
    char* _sWalker=_s+position;

    return *_sWalker;
}

/***********************************
* Function:pushBack
* Purpose: puts a character at the end of the string, increasing the size by 1
* Parameters: the character you want at the end
* Returns: nothing
* Summary: creates a new array to make sure there is no overflow, then copies everything over.
*          Then goes to the end of the array and puts in the user's entry
* Notes:
************************************/
void stringClass::pushBack(char entry)
{
    int length=_size+1;
    char* walker;

    if(increaseCapacity(length))
    {
        moveHouse(_s,length);
    }
    else
    {
        _size=length;
    }

    walker=_s;

    while(*walker!=NULL)
    {
        walker++;
    }

    *walker=entry;

    walker++;

    *walker=NULL;

}

/***********************************
* Function:assign
* Purpose:assigns a new value to the string, replacing its current contents.
* Parameters: the new cstring
* Returns:
* Summary: clears the current string then copies the new one over
* Notes:
************************************/
void stringClass::assign (char* str)
{
    clear();
    copy(str);
}

/***********************************
* Function:insert
* Purpose: Inserts additional characters into the string right before the character indicated by pos
* Parameters: the cstring to insert, where to insert
* Returns:
* Summary:
* Notes: needs work
************************************/
void stringClass::insert(char* str, int position)
{
    //starting from position, shift everything to the right strLen(str) amount of times
    //set the value at position to str starting from position to strLen(str)
    //or
    //put in half of _s, then put in the new string, then put in other half of _s

    //    char* firstHalf=new char[position];
    //    char* otherHalf=new char[_size-position];
    //    char* _sWalker=_s;

    //    cout<<"DEBUG position: "<<position<<endl;
    //    cout<<"DEBUG _size-position: "<<_size-position<<endl;


    //    cout<<"DEBUG firstHalf: "<<firstHalf<<endl;
    //    cout<<"DEBUG otherHalf: "<<otherHalf<<endl;


}

/***********************************
* Function:erase
* Purpose:Erases the portion of the string value that begins at the character position pos and spans len characters
*        (or until the end of the string, if either the content is too short or if len is string::npos.
* Parameters: position to start erasing, position to stop erasing
* Returns:
* Summary:
* Notes:
************************************/
void stringClass::erase(int startingPosition, int length)
{
    char* _sWalker=_s;


    for (int i=0;i<startingPosition;i++) //moves to starting position
    {
        _sWalker++;
    }

    for (int i=0;i<length && _sWalker!=NULL;i++) //runs Delete function [length] amount of times
    {
        Delete(_sWalker);
    }

}

/***********************************
* Function:replace
* Purpose: Replaces the portion of the string that begins at character pos and spans len characters
*          (or the part of the string in the range between [i1,i2)) by new contents.
* Parameters:  position to start deleting, position to stop deleting, cstring you want to insert
* Returns:
* Summary:replaces by deleting from start position to length, then inserting your cstring at the starting position.
* Notes:
************************************/
void stringClass::replace(int startingPosition, int length, char* str)
{
    //delete start thru length
    //insert str

    char* _sWalker=_s+startingPosition;

    for (int i=0;i<length;i++)
    {
        Delete(_sWalker);
    }

    insert(str,startingPosition);
}

/***********************************
* Function:cStr
* Purpose:
* Parameters:
* Returns:
* Summary:
* Notes:
************************************/
char* stringClass::cStr()//Returns a pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string) representing the current value of the string object
{
    //what?!
}

/***********************************
* Function:find
* Purpose: Searches the string for the first occurrence of the sequence specified by its arguments.
* Parameters:cstring to find, position to start the search from
* Returns: the location of the found element
* Summary: starting from the starting position till the end of the main cstring, check to see the the 1st letter of the key matches anything in the string
*          , if it does, take a chunk strlen(key) long out and compare the key to it. Repeat this until you run out of the main cstring, or it is found.
* Notes:
************************************/
char* stringClass::find(char* key, int pos=0)
{
    char* _sWalker=_s;
    char* found;

    for (int i=pos;*_sWalker!=NULL;i++) //starting from position till the end
    {
        found=strStr(_sWalker,key);
        _sWalker++;

        if (found!=NULL)
        {
            return found;
        }
    }

    return NULL;

}

/***********************************
* Function:rFind
* Purpose:Searches the string for the last occurrence of the sequence specified by its arguments.
* Parameters:cstring to find, position to start the search from
* Returns:the location of the found element
* Summary:starting from the end of the main string till the beginning, check to see the the 1st letter of the key matches anything in the string
*          , if it does, take a chunk strlen(key) long out and compare the key to it. Repeat this until you run out of the main cstring, or it is found.
* Notes:
************************************/
char* stringClass::rFind(char* key, int pos=0)
{
    int length=strLen(_s);
    char* _sWalker=_s+length; //starts at end of cstring
    char* found;
    char* overview=_s;

    for (int i=pos;i<length-pos;i++)
    {
        found=strStr(_sWalker,key);
        _sWalker--;

        if (found!=NULL)
        {
            return found;
        }
    }

    return NULL;

}

/***********************************
* Function:findFirstOf
* Purpose:Searches the string for the first character that matches any of the characters specified in its arguments
* Parameters: the character set, the position to start the search from
* Returns:the location of the found element
* Summary: starting from the specified position, keep checking each value from _s to see if it matches anything in the set. If it does return the position
*          if there is no match return NULL.
* Notes:
************************************/
char* stringClass::findFirstOf(char* set, int pos=0)
{
    char* _sWalker=_s+pos;

    while (*_sWalker!=NULL)
    {
        if (strChr(set,*_sWalker)!=NULL)
        {
            return _sWalker;
        }

        _sWalker++;
    }

    return NULL;
}

/***********************************
* Function:findFirstNotOf
* Purpose:Searches the string for the first character that does not match any of the characters specified in its arguments.
* Parameters:the character set, the position to start the search from
* Returns:the location of the found element
* Summary:starting from the specified position, keep checking each value from _s to see if it doesn't match anything in the set.
*  If it doesn't return the position, if everything matches return NULL.
* Notes:
************************************/
char* stringClass::findFirstNotOf(char* set, int pos=0)
{
    char* _sWalker=_s+pos;

    while (*_sWalker!=NULL)
    {
        if (strChr(set,*_sWalker)==NULL)
        {
            return _sWalker;
        }

        _sWalker++;
    }

    return NULL;
}

/***********************************
* Function:Delete
* Purpose: deletes from array
* Parameters: an array
* Returns: nothing
* Summary: shifts everything on the right of the address left by one, then adds a NULL at the end
* Notes:
************************************/
void Delete(char* array)

{
    char* arrayWalker=array;
    char* end=array+strLen(array);
    char* nextPos=array+1; //moves the value from pos+1 into pos

    while(*nextPos!=NULL)
    {
        *arrayWalker=*nextPos;

        arrayWalker++;
        nextPos++;
    }

    *end=NULL;
}

ostream&  operator <<(std::ostream& out, const stringClass& S)
{
    out<<S._s;

    return out;
}
