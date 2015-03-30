#include "month.h"

/***********************************
 * Function: month
 * Purpose: constructor that defaults the current month to 1 which is jan
 * Parameters:
 * Returns:
 * Summary:
 * Notes:
 * ***********************************/
month::month()
{
    currentMonth=1;
}

/***********************************
 * Function: month
 * Purpose: sets the month number using 3 letter inputs
 * Parameters:3 chars
 * Returns:nothing
 * Summary:takes 3 chars and gives it to set current month.
 * Notes:
 * ***********************************/
month::month(char letter1, char letter2, char letter3)
{
    setCurrentMonth(letter1,letter2,letter3);
    //jan feb mar apr may jun jul aug sep oct nov dec

    //possibly use nested switch cases to do this one
    // case j
    //      case a
    //      case u
    //          case l
    //          case n


    //Or have an array of strings jan-dec and convert the 3 letters into a cstring,then use strchr to compare for a match.
    //The returned position would be the number of the month.


    //sets the month using the first 3 letters in the name of the month as 3 arguments
}

/***********************************
 * Function: month
 * Purpose: creates a new object using the user's input as the month number
 * Parameters:a integer
 * Returns:nothing
 * Summary:
 * Notes:
 * ***********************************/
month::month(int monthNumber)
{

    currentMonth=monthNumber;

}

/***********************************
 * Function:
 * Purpose:
 * Parameters:
 * Returns:
 * Summary:
 * Notes:
 * ***********************************/
month::~month()
{

}

/***********************************
 * Function: setCurrentMonth
 * Purpose: sets the month to what the user specifies
 * Parameters: a integer representing what month it is
 * Returns: nothing
 * Summary:
 * Notes:
 * ***********************************/
void month::setCurrentMonth(int monthNumber)
{
    currentMonth=monthNumber;
}

/***********************************
 * Function:setCurrentMonth
 * Purpose: sets current monht number using 3 characters
 * Parameters:3 characters
 * Returns:nothing
 * Summary: Takes 3 chars from user, then converts all to lowercase, then combines the letters into a string, then compares the string to a string array
 *          that contains all the months. The position the string is equal to the other string is the month number we want, but +1 cuz 0 based.
 * Notes: Need something to deal with the letters not being found in the months string array.
 * ***********************************/
void month::setCurrentMonth(char letter1, char letter2, char letter3)
{
    tolower(letter1); //converts all the user's letters to lowercase
    tolower(letter2);
    tolower(letter3);

    string letters;

    letters+=letter1; //converts user's letters to a string
    letters+=letter2;
    letters+=letter3;

    currentMonth=findMonth(letters);


}
int month::findMonth(string month)
{
    for (int i=0;i<11;i++) //cycles thru all the months (jan-dec)
    {
        if(months[i]==month) //NEED SOMETHING TO CHECK FOR IF NOT FOUND
        {
            return i+1; //+1 cuz 0 based
        }
    }
    return 0;
}

/***********************************
 * Function: getMonthNumber
 * Purpose: accessor for the number of the month
 * Parameters: none
 * Returns: the number of the month
 * Summary:
 * Notes:
 * ***********************************/
int month::getMonthNumber()
{
    return currentMonth;
}

/***********************************
 * Function: getMonthName
 * Purpose: converts a number to a month name
 * Parameters: a integer
 * Returns: the name of the month represented by that number
 * Summary: using a switch case and the number of the month, returns a string of the month's name
 * Notes:
 * ***********************************/
string month::getMonthName()
{
    if (currentMonth>=1 && currentMonth<=12)
        return months[currentMonth-1];

    else return "Enter 1-12";

    //    switch (currentMonth)
    //    {
    //    case (1):
    //        return "Jan";
    //        break;

    //    case (2):
    //        return "Feb";
    //        break;

    //    case (3):
    //        return "Mar";
    //        break;

    //    case (4):
    //        return "Apr";
    //        break;

    //    case (5):
    //        return "May";
    //        break;

    //    case (6):
    //        return "Jun";
    //        break;

    //    case (7):
    //        return "Jul";
    //        break;

    //    case (8):
    //        return "Aug";
    //        break;

    //    case (9):
    //        return "Sep";
    //        break;

    //    case (10):
    //        return "Oct";
    //        break;

    //    case (11):
    //        return "Nov";
    //        break;

    //    case (12):
    //        return "Dec";
    //        break;

    //    default:
    //        return "Please enter 1-12...";
    //        break;

    //    }

}

/***********************************
 * Function: printMonth
 * Purpose: prints out the month in letters and numbers
 * Parameters: none
 * Returns: nothing
 * Summary: cout the variable and uses the getMonthName() function to cout the name.
 * Notes:
 * ***********************************/
void month::printMonth()
{
    cout<<"It is month number "<<currentMonth<<", "<<getMonthName();
}
