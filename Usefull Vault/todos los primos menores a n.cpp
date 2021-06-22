#include <iostream>

using namespace std;

long long prim(long long a, long long *ptr)
{
    long long d=0, b=2, c=2;
    while (b<a)
    {
        if (a%b==0)
            d=1;
        else
            d=0;
        b=b+1;

        if (d==1)
            break;
    }

    if (d==0)
        *ptr+=b;






}


long long cont(long long a)
{
    long long b=2,c=0,x=0;

    while (b<=a)
    {

        prim(b,&x);
        if (b<3)
            b++;
        else b+=2;
        //cout<<x;
    }
    cout<<"\nla sumatoria de todos los primos menores a 200000 es igual a: "<<x+1<<"\n";

}


int main()
{
    long long a=10;
    cont(a);

}
