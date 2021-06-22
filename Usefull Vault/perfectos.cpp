#include <iostream>

using namespace std;

int main()
{
    int a,b=1,c=0;
    cout<<"ingrese su numero: ";
    cin>>a;
    while (b<a)
    {
        if(a%b==0)
        {
            c+=b;
        }
        b++;

    }
    if (c==a)
            cout<<"es perfecto";
    else
        cout<<"no es perfecto";
}
