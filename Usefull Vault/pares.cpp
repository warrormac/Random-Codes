#include <iostream>

using namespace std;

int main()
{
    int a,b=0;
    cin>>a;

    while(b<a-1)
    {
        b+=2;
        cout<<b;
       if (b<a-1 && b>=1)
            cout<<",";

    }

}
