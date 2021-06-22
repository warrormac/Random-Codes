#ifndef POINT_H
#define POINT_H
#include <iostream>

using namespace std;
template <typename T>
class Point1 {
    T x,y;
    public:
    Point1();
    Point1(T,T);
    Point1(Point1 &o);
    void offset(T,T);
    void set_x(T);
    void set_y(T);
    void print();
    T get_x();
    T get_y();
};


#endif // POINT_H
