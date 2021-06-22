#include <iostream>

using namespace std;

bool primo(int x, int y)
{
    int z;
    if (x%y==0)
        {
            z=1;
        }
         if (z==1){
            y=x;
            return 0;
        }
}
int main()
{
    int a,b,c,d;
    cout<<"ingrese su numero:";
    cin>>a;
    d=0;
    b=2;
    c=2;
    while (b<a)
    {

        d=primo(a,b);

        b=b+1;


    }
    if (d)
        {
            cout<<b;cout<<" si es primo\n";
        }

}
