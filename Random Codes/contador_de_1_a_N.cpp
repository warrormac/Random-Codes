#include <iostream>

using namespace std;

int contador(int x,int y)
{
    while (y<x)
	{
		cout<<y; cout<<", ";
		y++;
	}
	cout<<x;
}

int main()
{
	int a,b,c;
	cout<<"ingrese su numero:"; cin>>a;
	b=1;
	contador(a,b);
}
