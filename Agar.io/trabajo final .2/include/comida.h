#ifndef COMIDA_H
#define COMIDA_H
#include "base.h"

class comida:public base
{
    public:
        comida();

        comida(int, int, double);
        ~comida();

    private:
        int x, y;
        int dx, dy;
        int playerid;
};

#endif // COMIDA_H
