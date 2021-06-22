#include <iostream>

using namespace std;

int palindrome(int x)
{
    if (x/10000%10==x%10 && (x/1000)%10 && (x%100)/10 )
    {
       cout<<x<<" si es palindrome";
    }
    else
        cout<<"no es palindrome";
}
int main()
{
    int a,b;
    cout<<"ingrese su numero: ";cin>>a;
    palindrome(a);
}
