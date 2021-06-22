#include <iostream>

using namespace std;

int pot(int x, int y)
{
    int r;
    if (y==0)
        r=1;
    if (y>0)
        r=x*pot(x,y-1);
    return r;

}
int main()
{
    int a,b,c;
    cin>>a;
    cin>>b;
    c=pot(a,b);
    cout<<c;
}
