#include "Array.h"
Array::Array(int sizeP)
{
	this->size = sizeP;
	arr = new int[size];
}

Array::~Array()
{
	delete[] arr;
}

void Array::display(int i) const
{
	std::cout << arr[i] << std::endl;
}