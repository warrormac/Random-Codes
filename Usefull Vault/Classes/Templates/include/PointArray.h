#ifndef POINTARRAY_H
#define POINTARRAY_H

#include "Point.h"
template<typename TP>
class PointArray
{
    public:
        PointArray();
        PointArray(const Point1<TP> pts[],const int size);
        PointArray(PointArray &o);
        ~PointArray();
        void print();
        void clear();
        void push_back(const Point1<TP> &p);
        void insert(const int,const Point1<TP> &p);
        void remove(const int);
        int getSize();

    private:
        int size;

        Point1<TP> *points;
        void resize(int);
};
#endif // POINTARRAY_H
