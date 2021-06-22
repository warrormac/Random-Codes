#include <iostream>

using namespace std;

int comp(char *x,char *y,int *a,int *b)
{
    int c=0,d=0,e=0;
    while (c<=*a)
    {
        if (x[c]==y[d])
        {
            d+=1;
            if (d==*b)
                return 1;

        }
        c++;
    }
    return 0;
}

int main()
{
    char a[]={"hola mundo"};
    char b[]={"mun"};
    char *ptr=&a[0];
    char *ptr1=&b[0];
    int *s,*l;
    int tam1,tam2,fin;
    fin=0;
    tam1=sizeof(a)-1;
    tam2=sizeof(b)-1;
    s=&tam1;
    l=&tam2; 

    fin=comp(ptr,ptr1,s,l);
    cout<<fin;
}
