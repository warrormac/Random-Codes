#include <iostream>

using namespace std;

bool perf(int x)
{
    int y,r;
    y=1;
    while (y<x)
    {
        if (x%y==0)
            r=r+y;
         y++;
        if (r==x)
            return 1;

    }
}

int main()
{
        int a,b;
        cout<<"ingrese su valor:";
        cin>>a;
        b=perf(a);
        if (b)
            cout<<a<<" es numero perfecto";
}
