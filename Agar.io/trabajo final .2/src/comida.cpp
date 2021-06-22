#include "comida.h"

comida::comida()
{
    this->x = 0;
    this->y = 0;
    this->dx = 0;
    this->dy = 0;
    this->radius = rand() % 5;
    this->playerid = 0;

    this->cal_area ();
}

comida::comida(int a, int b, double c):base( a,b, rand() % 5)
{
    //dtor
}

comida::~comida()
{
    //dtor
}
