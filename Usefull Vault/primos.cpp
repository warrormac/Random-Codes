#include <iostream>

using namespace std;

bool primo(int x)
{
    int y=2;
    while (y<x)
    {
        if (x%y==0)
            return 0;
        y++;
    }
    return 1;
}

int main()
{
    int a,d,c;
    cout<<"ingrese su numero:";cin>>a;
    d=primo(a);
    if (d)
        cout<<a<<" es primo\n";

    for (int p=1;p<a;p++)
    {
        c=primo(p);
        if (c)
        cout<<p<<" es primo\n";
    }
}
