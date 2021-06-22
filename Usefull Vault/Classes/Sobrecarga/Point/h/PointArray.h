#ifndef POINTARRAY_H
#define POINTARRAY_H

#include <iostream>
#include "Point.h"

template <typename P>
class PointArray;

template <typename P>
PointArray<P>& operator+(const PointArray<P> &m, const PointArray<P> &o) { //aqui estoy sobre cargando el operador + 
	PointArray<P> r = m;
	for (int j = 0; j < o.getSize(); j++) {
		r.push_back(o.points[j]); //ingrese los elemntos del array2 al final del array1
	}
	return r;
}

template <typename P>
class PointArray
{
public:
	PointArray();
	PointArray(const P pts[], const int size);
	PointArray(const PointArray &o);
	~PointArray();
	void print();
	void clear();
	void push_back(const P &p);
	void insert(const int, const P &p);
	void remove(const int);
	int getSize() const;
	const Point<P> retornarElemento(int posicion) const;
	friend PointArray<P>& operator+<>(const PointArray<P> &m, const PointArray<P> &o);
	void stream( int); // esto es para el .txt


private:
	int size;
	P *points;
	void resize(int);
};






#endif // POINTARRAY_H
