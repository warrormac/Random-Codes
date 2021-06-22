#include <iostream>

using namespace std;


class ArreglaDinamicaInt{
    int tam;
    int *ptr;

public:
    ArreglaDinamicaInt (int tam1, int arr[])
        {
            this -> tam=tam1;
            this -> ptr= new int[tam1];
            for  (int i=0;i<=tam1;i++)
                ptr[i]=arr[i];
        }
    void mostrar()
    {
    for (int i=0;i<tam;i++)
        cout<<ptr[i]<<" ";
    }




    void insertar(int pos, int elem)
    {
        if (pos>=tam+1 || pos<0)
            ;


        else{
            int *ptr1=new int [tam++];
            for (int x=0;x<pos;x++)
            {
                ptr1[x]=ptr[x];
            }
            ptr1[pos]=elem;

            for (int i=pos;i<tam;i++)
            {
                ptr1[i+1]=ptr[i];
            }
            delete []ptr;
            ptr=ptr1;
        }

    }

    void insertarAtras(int eleme)
    {
        int x=0;
        int *ptr1=new int [tam++];
            for (;x<tam;x++)
            {
                ptr1[x]=ptr[x];
            }
            ptr1[x-1]=eleme;


            delete []ptr;
            ptr=ptr1;

    }

    void elim(int pos)
    {
        int x=0,y;
        int *ptr1 = new int [tam-1];

        if (pos>tam-1 || pos<0)
            ;
        else{

            while (x!=pos)
            {
                ptr1[x]=ptr[x];
                x++;
            }
            y=x;
            x++;

            while (x<tam-1)
            {
                ptr1[y]=ptr[x];
                x++;
                y++;
            }


            delete []ptr;
            tam=x;
            ptr=ptr1;
        }


    }


    void promedio()
    {
        int *ptr1= new int [1];
        ptr1[0]={0};
        for (int x=0;x<tam;x++)
        {
            ptr1[0]=ptr1[0]+ptr[x];
        }
        ptr1[0]=ptr1[0]/tam;
        delete ptr;
        tam=1;
        ptr=ptr1;
    }

    void ordeMayor()
    {
        int b=0;
        for (int x=0;x<tam;x++)
        {
            for (int i=x+1;i<tam;i++)
            {
                if (ptr[x]>ptr[i])
                {
                    b=ptr[x];
                    ptr[x]=ptr[i];
                    ptr[i]=b;
                }
            }
        }
    }

    void ordeMenor()
    {
        int b;
        for (int x=0;x<tam;x++)
        {
            for (int i=x+1;i<tam;i++)
            {
                if (ptr[x]<ptr[i])
                {
                    b=ptr[x];
                    ptr[x]=ptr[i];
                    ptr[i]=b;
                }
            }
        }
    }

    /*void primos()
    {
        int *ptr1 = new int [tam];
        int x=0,y,b,c=0,d;
        cout<<"h";

        cout<<"o";
        while (x<tam)
        {
            y=ptr[x];
            cout<<"l";
            while (b<y)
            {
                if (y%b==0)
                {
                    d=1;
                }
                if (d==1)
                    break;
                b=b+1;
                cout<<"a";
            }
            if (b==y-1)
            {
                ptr1[c]=y;
                c++;
            }
            b=2;
            x++;

        }
        //delete ptr;
        ptr=ptr1;
        tam=c;
    }*/


};


int main()
{

    int arr[]={10,11,47,1};

    ArreglaDinamicaInt b(4,arr);


   /* b.insertar(1,5);
    cout<<"insertar un elemento en dicha posicion ";
    b.mostrar();*/

    b.insertarAtras(9);
    cout<<"\ninsertar atras de la cadena ";
    b.mostrar();

    b.elim(1);
    cout<<"\nelimina un elemento ";
    b.mostrar();

    b.ordeMayor();
    cout<<"\nordena de mayor a menor ";
    b.mostrar();

    b.ordeMenor();
    cout<<"\noredenar de menor a mayor ";
    b.mostrar();

    /*b.primos();
    cout<<"h";
    b.mostrar();*/


    b.promedio();
    cout<<"\nel promedio es ";
    b.mostrar();

}
