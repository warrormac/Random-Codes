#include <iostream>

using namespace std;

int bt(int x, int y)
{
    x^=y^=x^=y;
    cout<<x<<"\n";
    cout<<y<<"\n";
}

int swp(int x, int y)
{
    swap(x,y);
    cout<<x<<"\n";
    cout<<y<<"\n";
}
int main()
{
    int a,b;
    cout<<"ingrese sus valores: ";
    cin>>a;cin>>b;
    cout<<"intercambion con bitwaise:\n";
    bt(a,b);
    cout<<"intercambion sin bitwaise:\n";
    swp(a,b);
}
w
