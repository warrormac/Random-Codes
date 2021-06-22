#include <iostream>

using namespace std;

bool perfectos(int a)
{
    int b=1,c=0;

    while (b<a)
    {
        if(a%b==0)
        {
            c+=b;
        }
        b++;

    }
    if (c==a)
        return 1;
    else
        return 0;
}

int suma(int b[], int z)
{
    int a=0,c=0;
    while (a<z)
    {
        c+=b[a];
        a++;
    }
    cout<<"la suma es: "<<c;

}


int menor(int b[], int z)
{
    int a,c=1,d=0;
    while (z>d)
    {
        if (c==z)
        {
            d++;
            c=1;
        }
        if (b[d]>b[c])
        {
            a=b[c];
            b[c]=b[d];
            b[d]=a;
        }
        else c++;
    }
    cout<<b[0];
}


int perfectos (int b[],int z)
{
    int a,c=0, x=0;
    bool d;
    cout<<"el arreglo tiene ";
    while (c<z)
    {
        a=b[c];
        d=perfectos(a);

        if (d==1)
        {
            x++;
        }
        c++;
    }
    if (x>1)
        cout<<x<<" numeros perfectos";
    else cout<<x<<" perfectos";

}



int ascendente(int b[],int z)
{
    int a,c=0,x=1;
    while (c<z)
    {
        while (x<z)
        {
            if (b[c]>b[x])
            {
                a=b[c];
                b[c]=b[x];
                b[x]=a;
            }

            x++;
        }
         c++;
         x=c+1;

    }
    for (int i=0;i<z;i++)
            cout<<b[i];

}

int descencente(int b[],int z)
{
    int a,c=0,x=1;
    while (c<z)
    {
        while (x<z)
        {
            if (b[c]<b[x])
            {
                a=b[c];
                b[c]=b[x];
                b[x]=a;
            }

            x++;
        }
         c++;
         x=c+1;

    }
    for (int i=0;i<z;i++)
            cout<<b[i];

}
int inv(int b[], int z)
{
    int a,c=0,x,y;
    y=z-1;

        while (c<z/2)
        {
            x=b[c];
            b[c]=b[y];
            b[y]=x;
            y--;
            c++;
        }
        for (int i=0;i<z;i++)
            cout<<b[i];

}

int main()
{
    int a,b=0,c,d=0;
    cout<<"ingrese el tamaño";
    cin>>a;
    int r[a];
    while (d<a)
    {
        cout<<"ingrese su numero: ";
        cin>>c;
        r[d]=c;
        d++;
    }
    //suma(r,a);
    //menor(r,a);
    //perfectos(r,a);
    //ascendente(r,a);
    descencente(r,a);
    //inv(r,a);
}
