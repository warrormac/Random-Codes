#include <iostream>

using namespace std;

int factorial(int x, int y, int z)
{
    for (y=1;y<=x;y++)
        {
            z=z*y;
        }
        cout<<z;

}
int main()
    {
        int a,b,c;
        cout<<"ingrese su numero:";
        cin>>a;
        c=1;
        factorial(a,b,c);

    }
