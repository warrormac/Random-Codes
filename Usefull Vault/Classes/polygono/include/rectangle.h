#include "polygon.h"
#ifndef RECTANGEL_H
#define RECTANGEL_H


class rectangle:public polygon
{

    public:

        rectangle(int p, int q):polygon(p,q){};


        int area();

};

#endif // RECTANGEL_H
