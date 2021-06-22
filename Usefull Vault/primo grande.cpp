#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    long long x=600851475143,d=2,r,c=2;
    while(d<x)
    {
        if (x%d==0)
        {
            r=d;
            //cout<<r<<" ";
            while (r%c!=0)
            {
                c++;
                if (c==r-1)
                {
                    cout<<r<<"\n";
                    c=2;
                    break;
                }
            }
        }
        d++;
    }
    cout<<r;
}
