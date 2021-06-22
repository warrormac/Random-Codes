#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int tam(char x[],int y)
{
    for (;x[y]!='.';y++)
        ;
    return y;
}

int tam1(char x[],int y)
{
    int cont= 0;
    for (;x[y]!='e';y++)
        cont++;
    return cont;

}
int tam2(char x[],int y)
{
    if (x[y+1]=='-')
        return 0;
    else
        return 1;

}


int con(char *p,int cont) //hasta el . por def
{
    int z=0,y=1;
    int a;

    a=atoi(p);
    //cout<<a;
    return a;
}

int expo(char *p)
{
    int c;
    c=atoi(p);

    return c;
}

int resultado(float x, int y, int z)
{
    int c;
    if (y==0){
        z=z*(-1);
        while (z<0)
        {
            x=x*0.1;
            z++;
        }
    }
    else{
        while (z>0)
        {
            x=x/0.1;
            z--;
        }
    }

    cout<<x;
}

int main()
{
    char a[]={"1245.1e-3"};
    char *ptr;
    ptr=&a[0];
    int c,r,n,aa,m,exp,cont;
    float d,bb,cc;
    r=0;
    cont=0;

    c=tam(ptr,r); //calculo la cantidad de espacios antes del .


     d=atoi(a);//d Es todos los int antes del .
        //cout<<d;


    aa=d;
    n=c;
    //cout<<n<<"\n";
    while (c>0)
    {
        c=c/2;
        r++;
    }


    c=tam1(ptr,r+1); //int despues del . y antes del e
    n+=1;
    //cout<<n<<"b";
    d=con(ptr+(n),c);//los decimales
    //cout<<d;
    bb=d;
    c-=1;
    while (c>0)
    {
        bb=bb*0.1;
        c--;
    }



    cc=aa+bb;
    //cout<<cc;
    n+=1;

    m=tam2(ptr,n);//verifica si e s+ o -

    n+=2;//esta despues de simbolo

    exp=expo(ptr+n);
    //cout<<exp<<"\n";
    resultado(cc,m,exp);
}
