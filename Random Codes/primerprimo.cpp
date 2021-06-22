#include <iostream>

using namespace std;

int main() {
	int a, n, d, b;
	int p;
	
	cout<<"Inrgrese su numero: ";
	cin>>a;
	b=1;
	n = 2;
	while (a > b) {
		
		
		p = 1;
		for (d = 2; d < n; ++d) {
			if (n % d==0) {
				p = 0;
				cout<<n<<"es el primer numero que no cumple";
				
			}
		}
		if (p==0)
			break;
		n++;
		b++;
	}
	
	cout<<"\n";
}
