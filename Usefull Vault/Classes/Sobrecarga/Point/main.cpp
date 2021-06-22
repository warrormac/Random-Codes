#include <iostream>
#include "Point.h"
#include "PointArray.h"
#include "src\PointArray.cpp"//esto es para que pueda tener .cpp con templates
#include "src\Point.cpp"

// Sobrecarga esta en el .h de PointArray  esta al inicio
//el .txt se trabaja en el PointArray.cpp es el ultimo metodo 
using namespace std;


int main() {
	Point<int> p(1, 2);
	Point<int> q(3, 4);
	Point<int> r(5, 6);

	Point<int> a(7, 8);
	Point<int> b(9, 1);
	Point<int> c(11, 12);

	Point<int> arr[] = { p,q,r }; //array 1
	int size1 = sizeof(arr) / sizeof(arr[0]); 

	Point<int> arr2[] = { a,b,c }; // array 2
	int size2 = sizeof(arr2) / sizeof(arr2[0]);

	PointArray<Point<int> >pa(arr, size1);
	PointArray<Point<int> >pa2(arr2, size2);

	PointArray<Point<int> >pa3 = (pa + pa2); // mi sobrecarga del operador +   aqui esta merging mis 2 arrays
	//pa.stream(pa3);

	pa3.print();

	pa.clear();
	pa.print();

	pa.push_back(p);
	pa.print();

}


