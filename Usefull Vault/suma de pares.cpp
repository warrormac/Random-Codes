#include <iostream>

using namespace std;


bool prim(int a )
{
    int d=0, b=2, c=2;
    while (b<a)
    {
        if (a%b==0)
        {
            d=1;
        }
         if (d==1){
            b=a;
            return false;
        }


        b=b+1;


    }
    if (d==0)
        {
            return true;
        }

}

int multi(int a)
{
    int b=2,c=0,d=0;

    while (b<a)
    {
        if (a%b==0)
            c=prim(b);
            //cout<<c<<"\n";
        if (c==1)
        {
            d+=b;
            //cout<<d<<"\n";
            c=0;
        }
        b++;
    }
    d+=1;
    cout<<d;
}

int main()
{
    int b,c,d,z;
    int a=2000000;

    multi(a);



}




