#include <iostream>

using namespace std;

int tam(char x[])
{
    int c=0;
    while (x[c]!='\0')
        c++;
    return c;
}

char inter(char **a, char **b, int tam1 , int tam2)
{

    while (tam2>=0)
    {
        **a=**b;
        tam2--;
        *a=*a+1;
        *b=*b+1;
    }
    return **a;
}

int main()
{
    int cont=0,cont1;
    char a[]={};
    char b[]={'p','q','\0'};
    char *x=&a[0];
    char *y=&b[0];
    cont=tam(x);
    cont1=tam(y);
    inter(&x,&y,cont,cont1);
    x=&a[0];
    cout<<x;
}
