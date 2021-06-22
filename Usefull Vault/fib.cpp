#include<iostream>

using namespace std;

int main ()
{
    int a,b,c,d;
    cout<<"ingrese su numero:";cin>>a;
    b=0;
    c=1;
    d=0;
    cout<<d<<":  "<<b<<"\n";
    d++;
    while(d<a)
    {
        b=c+b;
        cout<<d<<":  "<<b<<"\n";
        d++;
        c=c+b;
        cout<<d<<":  "<<c<<"\n";
         d++;
    }


}
