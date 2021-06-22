#ifndef POINTARRAY_H
#define POINTARRAY_H

#include "Point.h"

template <typename U>
class PointArray {
public:
	PointArray();
	PointArray(const U pts[], const int size);
	PointArray(PointArray &o);

	~PointArray();

	int getSize();
	void clear();
	void print();
	void push_back(const U &p);
	void insert(const int, const U &p);
	void remove(const int);

protected:

private:
	int size;
	U *points;
	void resize(int);

};

#endif // POINTARRAY_H
