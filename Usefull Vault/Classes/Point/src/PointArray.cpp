#include "PointArray.h"
#include <iostream>

using namespace std;

template <typename U>
PointArray<U>::PointArray()
{
	this->size = 0;
	this->points = new U[size];
}

template <typename U>
PointArray<U>::PointArray( U pts[], int size)
{
	this->size = size;
	this->points = new U[size];
	for (int i = 0; i < size; i++) {
		points[i] = pts[i];
	}
}

template <typename U>
PointArray<U>::PointArray(PointArray &o)
{
	this->size = o.size;
	this->points = new U[size];
	for (int i = 0; i < size; i++) {
		points[i] = o.points[i];
	}
}

template <typename U>
void PointArray<U>::resize(int newSize)
{
	U *pts = new U[newSize];
	int minsize = (newSize > size) ? size : newSize;
	for (int i = 0; i < minsize; i++) {
		pts[i] = points[i];
	}
	U *sss = points;
	points = pts;
	delete[] sss;
	size = newSize;
}

template <typename U>
int PointArray<U>::getSize()
{
	return size;
}

template <typename U>
void PointArray<U>::clear()
{
	resize(0);
}

template <typename U>
void PointArray<U>::print()
{
	for (int i = 0; i < size; i++) {
		points[i].print();
	}
}

template <typename U>
void PointArray<U>::push_back(const U &p)
{
	resize(size + 1);
	points[size - 1] = p;
}

template <typename U>
void PointArray<U>::insert(const int pos, const U & p)
{
	resize(size + 1);
	U *pts = new U[size];
	int w = 0;
	for (int i = 0; i < size; i++) {
		if (i == pos) {
			pts[i] = p;
			continue;
		}
		pts[i] = points[w];
		w++;
	}

	U *sss = points;
	points = pts;
	delete[] sss;
}

template <typename U>
void PointArray<U>::remove(const int pos)
{
	U *pts = new U[size-1];
	int w = 0;
	for (int i = 0; i < size; i++) {
		if (i == pos) continue;
		pts[w] = points[i];
		w++;
	}

	U *sss = points;
	points = pts;
	delete[] sss;
	size--;
}

template <typename U>
PointArray<U>::~PointArray()
{
	delete[] points;
}

template class PointArray<double>;
template class PointArray<int>;
template class PointArray<Point>;
