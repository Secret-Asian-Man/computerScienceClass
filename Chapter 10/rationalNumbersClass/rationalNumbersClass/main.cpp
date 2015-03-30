/***********************************
 * Project: Chapter 10/11, Question 10/5.
 * Author: David Wu
 * Purpose: does math to ratios
 * Notes: Need to put in user inputs.
 *        Need to put in << and >> operators.
 * ***********************************/
#include <iostream>
#include "rationalnumbers.h"

using namespace std;

//void display(rationalNumbers ratio1,rationalNumbers ratio2, rationalNumbers result);

int main()
{
    rationalNumbers ratio1(2,3);
    rationalNumbers ratio2;
    rationalNumbers result;

    char command;
    bool run=true;

    cout<<"Ratio 1: ";
    cin>>ratio1;

    cout<<"Ratio 2: ";
    cin>>ratio2;

    while (run)
    {
        cout<<"Ratio 1 (1), Ratio 2 (2), add (+), subtract (-), multiply (*), divide (/), exit (x)"<<endl;
        cout<<"Input command: ";
        cin>>command;

        switch (command)
        {
        case '1':
            cout<<"Ratio 1: ";
            cin>>ratio1; //using overload operators
            cout<<endl;
            break;

        case '2':
            cout<<"Ratio 2: ";
            cin>>ratio2; //using overload operators
            break;

        case '+':
            result=ratio1+ratio2; //using overload operators
            cout<<result<<endl<<endl;
            break;

        case '-':
            result=ratio1-ratio2;//using overload operators
            cout<<result<<endl<<endl;
            break;

        case '*':
            result=ratio1*ratio2;//using overload operators
            cout<<result<<endl<<endl;
            break;

        case '/':
            result=ratio1/ratio2;//using overload operators
            cout<<result<<endl<<endl;
            break;

        case 'x':
            run=false;
            break;

        default:
            cout<<"invalid input..."<<endl;

        }



    }









    //    ratio2.setBoth(1,2);
    //    display(ratio1, ratio2, result);

    //    cout<<"add"<<endl;
    //    result=ratio1+ratio2; //by using the "operator" syntax, I can do this instead of result=add(ratio1,ratio2)
    //    display(ratio1, ratio2, result);

    //    cout<<"subtract"<<endl;
    //    result=ratio1-ratio2;
    //    display(ratio1, ratio2, result);

    //    cout<<"multiply"<<endl;
    //    result=ratio1*ratio2;
    //    display(ratio1, ratio2, result);

    //    cout<<"divide"<<endl;
    //    result=ratio1/ratio2;
    //    display(ratio1, ratio2, result);


}
///***********************************
// * Function: display
// * Purpose: displays numerators and denominators for bor ratios, and the result for dubugging
// * Parameters: 3 objects
// * Returns: nothing
// * Summary: using the printBoth() function for all the objects, outputs debugging info.
// * Notes:
// * ***********************************/
//void display(rationalNumbers ratio1,rationalNumbers ratio2, rationalNumbers result)
//{
//    cout<<"ratio1: "; ratio1.printBoth();
//    cout<<endl;
//    cout<<"ratio2: "; ratio2.printBoth();
//    cout<<endl;
//    cout<<"result: "; result.printBoth();
//    cout<<endl;

//    cout<<endl<<endl<<endl;
//}


