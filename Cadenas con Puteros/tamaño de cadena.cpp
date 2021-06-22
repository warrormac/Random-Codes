#include <iostream>

using namespace std;

int tam(char x[])
{
    int c=0;
    while (x[c]!='\0')
        c++;
    return c;
}
int main()
{
    char a[]={'1','2','3','\0'};
    char *ptr;
    int cont=0;
    ptr=&a[0];
    cont=tam(ptr);
    cout<<cont;
}
