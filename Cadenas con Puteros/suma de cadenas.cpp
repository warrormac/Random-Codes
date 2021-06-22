#include <iostream>

using namespace std;



int len(int x[])
{
    int cont=0;
    for (int y=0;x[y]!='\0';y++)
        cont=cont+1;
    return cont;
}


int sum(int *x,int *y)
{
    int z=0;
    int *ptr=&z;
    int cont=0;
    int *ptr1=&cont;
    while (*ptr1<=*y)
    {
        *ptr=*ptr+x[*ptr1];
        *ptr1=*ptr1+1;
    }
    return *ptr;
}

int suma(int *x, int *cont){
	if (*cont==1){
		return x[0];
	}
	else
		return x[*cont-1]+sum(x,cont-3);
}

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10};
    int leng=0;
    int *ptr,*ptr1;
    ptr=&leng;ptr1=&a[0];
    *ptr=len(a);
    cout<<"el tamaño de la lista es de:"<<*ptr<<"\n\n";
    cout<<suma(ptr1,ptr);
}
