#include <iostream>

using namespace std;

bool mayor(int x)
{
    if (x>17)
        return true;
    return false;
}
int main()
{
	int a;
	cout<<"ingrese su valor: ";
	cin>>a;
    mayor(a);
}
