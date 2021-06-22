#ifndef INICIA_H_INCLUDED
#define INICIA_H_INCLUDED
#include <allegro.h>
#include <iostream>
#include <typeinfo>
#include "base.h"
using namespace std;


template <class A>
class inicia
{
    public:
        static inicia * instancia()
        {
            if(!_instancia)
                _instancia = new inicia;

            return _instancia;
        }

        int audio(int, int, A*);
        ~inicia();
    private:
        inicia<A>();
        static inicia *_instancia;

};

//template class inicia<int>;
template class inicia<MIDI>;
template class inicia<SAMPLE>;
#endif // INICIA_H_INCLUDED
