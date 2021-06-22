#include <iostream>

using namespace std;

int mayor(int x,int y, int z, int p)
{
   if (x>=y && x>=z && p==0){
        cout<<x<<" es el mayor";
        p=1;
    }


}

int menor(int x,int y, int z, int p)
{
   if (x<=y && x<=z && p==0){
        cout<<x<<" es el menor";
        p=1;
    }


}

int promedio(int x,int y, int z)
{
    cout<<((x*y*z)/3)<<" es el promedio";
}
int main()
{
    int a,b,c,d,p;
    cout<<"ingrese sus valores: ";cin>>a>>b>>c;
    d=0;
    p=0;

    while (p<=3)
    {
        if (p==1)
            mayor(a,b,c,d);
        if (p==2)
            mayor(b,a,c,d);
        if (p==3)
            mayor(c,a,b,d);
        p++;
    }
    p=0;
    cout<<"\n";
    while (p<=3)
    {
        if (p==1)
            menor(a,b,c,d);
        if (p==2)
            menor(b,a,c,d);
        if (p==3)
            menor(c,a,b,d);
        p++;
    }
    cout<<"\n";
    promedio(a,b,c);
}
