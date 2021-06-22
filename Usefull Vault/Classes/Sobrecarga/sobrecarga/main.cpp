#include <iostream>

#include "DArray.h"
#include "src\DArray.cpp"

int main()
{
	DArray<int> arr;
	DArray<int> arr1;

	for(int i = 0; i < 5; i++)
	{
		arr.push_back(i);
		arr1.push_front(10*i);
	}


	DArray<int> sum = arr + arr1;

	cout<<sum;

return 0;
}

