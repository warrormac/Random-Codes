#include "Point.h"
#include <iostream>

using namespace std;

template<typename T>
Point1<T>::Point1():x(0),y(0){}
template<typename T>
Point1<T>::Point1(T x1,T y1):x(x1),y(y1){}
template<typename T>
Point1<T>::Point1(Point1 &o):x(o.x),y(o.y){}
template<typename T>
void Point1<T>::offset(T offset_x,T offset_y){
    this->x=offset_x;
    this->y=offset_y;
}
template<typename T>
void Point1<T>::set_x(T x){
    this->x=x;
}
template<typename T>
void Point1<T>::set_y(T y){
    this->y=y;
}
template<typename T>
void Point1<T>::print(){
    std::cout<<"("<<x<<","<<y<<")"<<std::endl;
}
template<typename T>
T Point1<T>::get_x(){
    return x;
}
template<typename T>
T Point1<T>::get_y(){
    return y;
}
