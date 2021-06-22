#ifndef POINT_H
#define POINT_H
#include <iostream>


using namespace std;
template <typename T, typename U>
class Point
{
    public:
		Point() {
			x = 0;
			y = 0;
		}
		Point(T xh, T yh) {
			x = xh;
			y = yh;
		}
		Point(Point &o) {
			x = o.x;
			y = o.y;
		}

		void offset(T nx, T ny) {
			x += nx;
			y += ny;
		}
		void print() {
			std::cout << "(" << x << ", " << y << ")" << std::endl;
		}
		U getX() {
			return x;
		}
		U getY() {
			return y;
		}
		void setX(U x) {
			this->x = x;
		}
		void setY(U y) {
			this->y = y;
		}

    private:
        U x, y;
};

#endif // POINT_H
