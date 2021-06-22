#include "Point.h"

using namespace std;


template<typename T>
Point<T>::Point() :x(0), y(0) {}
template<typename T>
Point<T>::Point(T x1, T y1) : x(x1), y(y1) {}
template<typename T>
Point<T>::Point(Point &o) : x(o.x), y(o.y) {}
template<typename T>
void Point<T>::offset(T offset_x, T offset_y) {
	this->x = offset_x;
	this->y = offset_y;
}
template<typename T>
void Point<T>::set_x(T x) {
	this->x = x;
}
template<typename T>
void Point<T>::set_y(T y) {
	this->y = y;
}
template<typename T>
void Point<T>::print() {
	std::cout << "(" << x << "," << y << ")" << std::endl;
}
template<typename T>
T Point<T>::get_x() {
	return x;
}
template<typename T>
T Point<T>::get_y() {
	return y;
}
