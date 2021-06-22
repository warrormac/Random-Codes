#ifndef DARRAY_H
#define DARRAY_H


#include <iostream>
#include <cassert>
#include <string>
using namespace std;

template<class T>
class DArray
{
	T* list;
	int size;

public:
	DArray();
	DArray(const DArray<T>&);
	~DArray();
	const DArray<T>& operator=(const DArray&);

	int length() const;

	void push_front(const T);
	void push_back(const T);
	void erase(const int);



	DArray<T> operator+(const DArray&) ;


	friend ostream& operator<<(ostream &o, const DArray<T>& _d)
	{
		if ( _d.size == 0 )
		{
			cout<<"()";
			return o;
		}

		for(int i = 0; i < _d.size-1; i++)
			cout<<_d.list[i]<<", ";
		cout<<_d.list[_d.size-1];

		return o;
	}
};
#endif // DARRAY_H
