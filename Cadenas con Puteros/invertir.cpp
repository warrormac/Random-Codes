#include <iostream>

using namespace std;

int tam(char x[])
{
    int c=0;
    while (x[c]!='\0')
        c++;
    return c;
}

char inv(char *x, int tam)
{
    char c;
    int t=0;
    char *m;
    m=&*(x+tam-1);
    int q;
    q=tam/2;
    while (q>0)
    {
        c=*x;
        *x=*m;
        *m=c;
        q--;
        x++;
        *m--;

    }


}
int main()
{
    char a[]={'a','b','c','d','\0'};
    char *ptr;
    int cont=0;
    ptr=&a[0];
    cont=tam(ptr);

    inv(ptr,cont);
    cout<<a;
}
