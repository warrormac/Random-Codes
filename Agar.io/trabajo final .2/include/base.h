#ifndef BASE_H
#define BASE_H

//#include <allegro.h>
//#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//using namespace std;


class base
{
    public:
        base();
        base(int, int, double);
        virtual ~base();
        virtual int check_collide(base *);
        virtual int collides_with(base *);
        virtual void cal_area();
        virtual void cal_radius();
        double radius;
        double area;
        virtual void setradius(double r){this->radius=r;}
        virtual void setarea(double a){this->area=a;}
        virtual void setx(int x){this->x=x;}
        virtual void sety(int y){this->y=y;}
        virtual void setdx(int dx){this->dx=dx;}
        virtual void setdy(int dy){this->dy=dy;}
        virtual void setplayerid(int id){this->playerid=id;}
        virtual double getradius(){return radius;}
        virtual double getarea(){return area;}
        virtual int getx(){return x;}
        virtual int gety(){return y;}
        virtual int getdx(){return dx;}
        virtual int getdy(){return dy;}
        virtual int getplayerid(){return playerid;}

        /*
        friend base* operator/(base *a, base *b)
        {
            base *temp = a;
            temp->setradius(b->getradius());
            return temp;
        }*/

        base operator/(base a){
            this->setradius(a.getradius()/2);
            return *this;
        }


    private:
        int x, y;
        int dx, dy;
        int playerid;
};

#endif // BASE_H
