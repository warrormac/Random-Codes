#include <iostream>

using namespace std;

int main()
{
	int a;
	cout<<"Ingresa el anio";
	cin>>a;
	if(a % 4 == 0 && (a % 100 != 0 || a % 400 == 0))
		cout<<a<<" es bisiesto ";
	else
		cout<<a<<" no es bisiesto ";
	
}
