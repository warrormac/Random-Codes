#ifndef POINT_H
#define POINT_H

#include <iostream>

template <typename T>
class Point {
	T x, y;
public:
	Point();
	Point(T, T);
	Point(Point &o);
	void offset(T, T);
	void set_x(T);
	void set_y(T);
	void print();
	T get_x();
	T get_y();
};




#endif // POINT_H
