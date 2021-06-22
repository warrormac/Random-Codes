#include <iostream>
#ifndef POLYGON_H
#define POLYGON_H

using namespace std;

class polygon
{
protected:
        int width, height;
public:
        polygon(int a, int b):width(a),height(b){};
        virtual int area()=0;
        void printarea()
        {
            cout<<this->area();
        }



};

#endif // POLYGON_H
