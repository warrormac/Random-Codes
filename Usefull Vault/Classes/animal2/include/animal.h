#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>

using namespace std;

class Animal
{
    public:
        Animal(string n ,int p);
        void habla(void);
        Animal();

    protected:
        string nombre;
        int nroPatas;

};
#endif // ANIMAL_H
