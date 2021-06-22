#include <iostream>

using namespace std;

int main()
{
    int a=3, b=5, c=1000,d=1,x=0,y=0;
    while (d<c)
    {
        if (d%a==0)
        {
            x+=d;
            cout<<x<<"\n";
        }
        if (d%b==0)
        {
            y+=d;
        }
        d++;
    }
    cout<<x+y;
}
