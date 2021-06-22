#include<iostream>

using namespace std;

int tabulacion(int x,int y,int p)
{
    while (p>=1)
    {
        y=(x/p)%10;
        cout<<y;
        cout<<"    ";
        p=p/10;
    }

}

int main ()
{
    int a,b,d;
    cout<<"ingrese su numero:";cin>>a;
    d=10000;
        tabulacion(a,b,d);
}
