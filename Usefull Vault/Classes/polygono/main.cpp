#include "polygon.h"
#include "triangle.h"
#include "rectangle.h"
#include <iostream>

using namespace std;

int main()
{

    //polygon p(2,4);
    rectangle rec(3,4);

    triangle tri(2,4);
    //rec.areas();
    rec.printarea();
    cout<<"\n";
    tri.printarea();
    cout<<"\n";
    rectangle *ptr1;
    ptr1=&rec;
    ptr1->printarea();
    cout<<"\n";
    triangle *ptr=&tri;
    ptr->printarea();
}
