#include "DArray.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>

template<class T>
DArray<T>::DArray()
{
    list =0;
    size =0;
}
template<class T>
DArray<T>::DArray(const DArray& c)
{
    size = c.size;
    list = new T [size];
    for(int i=0;i<size;i++)
    list[i]=c.list[i];
}
template<class T>
DArray<T>::~DArray()
{
    delete[] list;
    list =0;
}

template<class T>
int DArray<T>::length()const
{
    return size;

}
template<class T>
void DArray<T>::push_front(const T v)
{
    DArray<T> copy =*this;
    delete[] list;
    list = new T[size+1];
    list[0] = v;

    for(int i=0;i<size;i++)
    list[i+1]=copy.list[i];
    size++;

}
template<class T>
void DArray<T>::push_back(const T v)
{
    DArray<T> copy =*this;
    delete[] list;
    list = new T[size+1];
    list[size] = v;

    for(int i=0;i<size;i++)
    list[i]=copy.list[i];
    size++;


}
template<class T>
DArray<T> DArray<T>::operator+(const DArray &_d)
{
    DArray<T> result = *this;

    for(int i = 0; i < _d.length(); i++)
    {
       bool add = true;

      for(int j = 0; j < size; j++)
     {
        if ( _d.list[i] == list[j] )
              add = false;
      }

      if ( add == true )
         result.push_back(_d.list[i]);
    }
    ofstream ofs("arrays.txt",ofstream::out);
    ofs<<result;
    ofs.close();
     ifstream arch;
     string texto;
    arch.open("arrays.txt",ios::in);
    while(!arch.eof())
    {
        getline(arch,texto);
        cout<<texto<<endl;
    }
    return result;

}

