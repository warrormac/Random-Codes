#include <iostream>
#include "Point.h"
#include "PointArray.h"
#include "src\Point.cpp"
#include "src\PointArray.cpp"

using namespace std;

int main()
{
    Point1<double> a(1.1,2.2);
    Point1<int> p(1,10);
    Point1<int> q(2,20);
    Point1<int> r(3,30);

    Point1<char> s('a','b');
    Point1<char> s1('c','d');
    Point1<char> s2('e','f');


    Point1<int> arr[]={p,q,r};
    int size=sizeof(arr)/sizeof(arr[0]);
    PointArray<int> pa2(arr,size);
    PointArray<int> pa=pa2;


    pa.push_back(p);
    pa.print();
    cout<<"\n";


    cout<<"\n";


    Point1<char> arr1[]={s,s1,s2};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    PointArray<char> cha(arr1,size);
    PointArray<char> cha1=cha;
    cha1.print();
    cout<<"\n";
    cha1.clear();
    cha1.insert(1,s1);
    cha1.print();


    return 0;
}



