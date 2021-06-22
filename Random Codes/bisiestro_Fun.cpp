#include <iostream>

using namespace std;

bool bis(int x)
{
    if(x % 4 == 0 && (x % 100 != 0 || x % 400 == 0))
		return 1;
	return 0;

}
int main()
{
	int a;
	cout<<"Ingresa el anio";
	cin>>a;
	bis(a);


}
