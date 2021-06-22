#include <iostream>

using namespace std;


int per(int a)
{
    int b=1,c=0;

    while (b<a)
    {
        if(a%b==0)
        {
            c+=b;
        }
        b++;

    }
    if (c==a)
            cout<<c<<"\n";

}


int main()
{
    int a,b=1;
    cin>>a;
    while (b<=a)
    {
        per(b);
        b++;

    }

}
