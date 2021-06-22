#ifndef POINTARRAY_H
#define POINTARRAY_H

#include "Point.h"
template <typename P>
class PointArray
{
public:
	PointArray()
	{
    this->size = 0;
    this->points = new P[size];
    }

	PointArray(const P pts[], const int size) {
    this->size = size;
    this->points = new P[size];
    for(int i = 0; i < size; i++)
        points[i] = pts[i];
}

	PointArray(PointArray &o) {
    this->size = o.size;
    this->points = new P[size];
    for(int i = 0; i < size; i++)
        points[i] = o.points[i];
}
	~PointArray() {
        delete[] points;
}

    void resize(int newSize) {
	P *pts = new P[newSize];
	int minsize = (newSize > size) ? size : newSize;
    for(int i = 0; i < minsize; i++)
        pts[i] = points[i];
	delete[] points;
	size = newSize;
	points = pts;
}
	void print() {
	for(int i = 0; i < size; i++)
		points[i].print();
}
	int getSize() {
    return size;
}


	void clear() {
	resize(0);
}

	void push_back(const P &p) {
	resize(size+1);
	points[size-1] = p;
}
	void insert(const int pos, const P &p) {
	resize(size+1);
    for(int i = size-1; i < pos; i--)
        points[i] = points[i-1];
	points[pos] = p;
}

	void remove(const int pos) {
	for (int y = pos; y < size - 1; y++) {
		points[y - 1] = points[y];
	}
	size--;
	resize(size);
}
private:
	int size;
	P *points;

};

#endif // POINTARRAY_H
