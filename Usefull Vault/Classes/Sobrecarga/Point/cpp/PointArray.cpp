#include "PointArray.h"
#include <iostream>

using namespace std;

template <typename P>
PointArray<P>::PointArray() {
	this->size = 0;
	points = new P [size];
}
template <typename P>
PointArray<P>::PointArray(const P pts[], const int size) {
	this->size = size;
	points = new P [size];
	for (int y = 0; y < size; y++)
		points[y] = pts[y];
}
template <typename P>
PointArray<P>::PointArray(const PointArray<P> &o) {
	this->size = o.size;
	points = new P [size];
	for (int y = 0; y < size; y++)
		points[y] = o.points[y];
}
template <typename P>
PointArray<P>::~PointArray() {
	delete[] points;
}
template <typename P>
void PointArray<P>::resize(int newsize) {
	P *ptr = new P [newsize];
	int minsize = (newsize > size) ? size : newsize;
	for (int y = 0; y < minsize; y++)
		ptr[y] = points[y];
	delete[] points;
	size = newsize;
	points = ptr;
}
template<typename P>
void PointArray<P>::print() {
	for (int y = 0; y < size; y++)
		points[y].print();
}
template<typename P>
void PointArray<P>::clear() {
	resize(0);
}
template<typename P>
void PointArray<P>::push_back(const P &p) {
	resize(size + 1);
	points[size - 1] = p;
}
template<typename P>
void PointArray<P>::insert(const int pos, const P &p) {
	resize(size + 1);
	for (int y = (size - 1); pos - 1 < y; y--)
		points[y] = points[y - 1];
	points[pos - 1] = p;
}
template<typename P>
void PointArray<P>::remove(const int pos) {
	for (int y = pos - 1; y < size - 1; y++)
		points[y] = points[y + 1];
	size--;
	resize(size);
}
template<typename P>
int PointArray<P>::getSize() const {
	return size;
}

template<typename P>
const Point<P> PointArray<P>::retornarElemento(int posicion) const {
	return points[posicion];
}
/*template<typename P>
void stream(int x) //Aqui estoy crean el .txt que recibe en nuevo array (array1 + array2)
{
    ofstream ofs("arrays.txt",ofstream::out);// aqui lo ingreso al .txt 
    ofs<<x;
    ofs.close();
     ifstream arch;
     string texto;
    arch.open("arrays.txt",ios::in); //aqui abro el .txt que contiene el array 3(array1  +  array2) 
    while(!arch.eof())
    {
        getline(arch,texto);
        cout<<texto<<endl;
    }
}*/
