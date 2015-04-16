#include <iostream>

using namespace std;

void R1(int i);
void R2(int i);
int main()
{
    int i=5;

    R2(i);


}

void R1(int i)
{
    if (i>0)
    {
        R1(i-1);
    }
    cout<<i<<endl;
}

void R2(int i)
{
    if (i>0)
    {
        if (i>0)
        {
            R2(i-1);
           // cout<<i<<endl;
\
        }
        R2(i-1);
    }
    cout<<i<<" ";

}
