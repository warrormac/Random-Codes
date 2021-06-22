#include <iostream>
#include "base.h"

using namespace std;

//float M_PI = 3.1415;

base::base()
{
    this->x = 0;
    this->y = 0;
    this->dx = 0;
    this->dy = 0;
    this->radius = 8.0;
    this->playerid = 0;

    this->cal_area ();
}

base::base(int x, int y, double r)
{
    this->x = x;
    this->y = y;
    this->dx = 0;
    this->dy = 0;
    this->radius = r;
    this->playerid = 0;

    this->cal_area();
}



int base::check_collide(base *obj)
{
    if( (obj->getx() - obj->getradius()) > (this->getx() + this->getradius() ) ) return 0;
    if( (obj->getx() + obj->getradius()) < (this->getx() - this->getradius() ) ) return 0;
    if( (obj->gety() - obj->getradius()) > (this->gety() + this->getradius() ) ) return 0;
    if( (obj->gety() + obj->getradius()) < (this->gety() - this->getradius() ) ) return 0;
    int xx = abs( this->getx()-obj->getx());
    int yy = abs( this->gety()-obj->gety());
    double d = xx*xx + yy*yy;
    if( d <= ((this->getradius() + obj->getradius()) * (this->getradius() + obj->getradius()) ) )
    {
        //this->cal_area();
        return 1;
    }
    return 0;
}

int base::collides_with(base *obj)
{
    if(this->check_collide(obj))
    {
        int xx = abs( this->getx()-obj->getx());
        int yy = abs( this->gety()-obj->gety());
        double d = (sqrt((xx*xx) + (yy*yy)));
        base *menor = this;
        base *mayor = obj;
        if(this->getradius() > obj->getradius())
        {
            menor = obj;
            mayor = this;
        }
        double oldarea=menor->getarea();
        double overlap=( menor->getradius() + mayor->getradius() - d );
        if( overlap < 0)    overlap = 0;

        menor->setradius( menor->getradius()-overlap );
        if(menor->getradius() < 0.5 )
        {
            menor->setradius(0.0);
            menor->setarea(0);
        }
        else menor->cal_area();

        mayor->setarea( mayor->getarea() + oldarea - menor->getarea() );
        mayor->cal_radius();
        return 1;
    }
    return 0;
}


void base::cal_area()
{
    this->area = 3.1415 * this->radius * this->radius;
}


void base::cal_radius()
{
    this->radius = sqrt(this->area/3.1415) ;
}


base::~base()
{
    //dtor
}
