#include <iostream>
#include "Array.h"

Array::Array(int sizeP) // конструктор который принимает единичный int
{
	this->size = sizeP; // и создает массив
	arr = new int[size];
}

Array::~Array()
{
	delete[] arr;

}
//void Array::display() const
//{
//	for (int i = 0; i < size; i++)
//	{
//		std::cout << arr[i] << " ";
//	}
//	std::cout << std::endl;
//
//}

void Array::display(int i) const
{
	std::cout << arr[i] << std::endl;
}