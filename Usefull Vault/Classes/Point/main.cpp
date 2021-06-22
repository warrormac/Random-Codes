#include <iostream>
#include "Point.h"
#include "PointArray.h"


using namespace std;



int main() {
    Point p(1, 3);
	Point q(3, 3);
	Point r(3, 1);
	Point arr[] = {p,q,r};
	PointArray<Point> pa2(arr, 3);
	PointArray<Point> pa = pa2;

	cout << "main array of ArrayPoint" << endl;
	pa.print();
	cout << endl << endl;

	cout << "pusb_back" << endl;
	pa.push_back(r);
	pa.print();


	cout << "insert" << endl;
	pa.insert(1, p);
	pa.print();

	cout << "remove" << endl;
	pa.remove(0);
	pa.print();


	return 0;
}
