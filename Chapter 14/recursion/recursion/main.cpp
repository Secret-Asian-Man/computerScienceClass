//NOTE: For each function, write a comment that describes the purpose of the function. Trace the execution of each function on paper.

//01. Print an integer vertically.
//02. Count up to a number (one on each line)
//03. Count down to a number.
//04. Count down to 1, then count up
//05. Hip Hip Hurrah!! (int i) //this is the output for i=3
//06. n-1 Hips and a Hurrah
//07. Hurrah and then n-1 Hips
//08. n-1 Hips, Hurrah, then n-1 Hips
//09. n/2 Hips, Hurrah, then n/2 Hips
//10. n asterisks, a vertical bar, then n exclamation marks

#include <iostream>

using namespace std;

void R1(int i);
void R2(int i);
void R3(int i);
void R4(int i);
void R5(int i);
void R6(int i);
void R7(int i);
void R8(int i);
void R9(int i);
void R10(int i);


int main()
{
    int i=4;

    cout<< "printing "<<i<<endl;
    R10(i);


    cout<<endl;
    cout<<endl;
}

void R1(int i)
{
    if (i/10!=0)
    {
        R1(i/10);
    }
    cout<<i%10<<endl;


}

void R2(int i)
{
    if (i>0)
    {
        R2(i-1);
        cout<<i<<endl;
    }

}

void R3(int i)
{
    if (i>0)
    {
        cout<<i<<endl;
        R3(i-1);
    }


}
void R4(int i)
{
    if (i>0)
    {
        cout<<i<<endl;
        R4(i-1);
        cout<<i<<endl;

    }

}

void R5(int i)
{
    cout<<"hip"<<endl;

    if (i>1)
    {
        R5(i-1);
    }
    else
    cout<<"hoorah!"<<endl;

}

void R6(int i)
{
    cout<<"hip"<<endl;

    if (i>2)
    {
        R6(i-1);
    }
    else
    cout<<"hoorah!"<<endl;
}

void R7(int i)
{

    if (i<=1)
    {
        cout<<"hoorah!"<<endl;
    }


    if (i>1)
    {

        R7(i-1);
        cout<<"hip"<<endl;

    }

}

void R8(int i)
{
    cout<<"hip"<<endl;

    if (i>2)
    {
        R8(i-1);
    }
    else
    cout<<"hoorah!"<<endl;

    cout<<"hip"<<endl;

}

void R9(int i)
{
    cout<<"hip"<<endl;

    if (i>2)
    {
        R8(i/2);
    }
    else
    cout<<"hoorah!"<<endl;

    cout<<"hip"<<endl;

}

void R10(int i)
{
    cout<<","<<endl;
    if (i>0)
    {
        R10(i-1);
    }
    else
    {
        cout<<"|"<<endl;
    }
    cout<<","<<endl;


}


