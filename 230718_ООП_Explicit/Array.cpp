#include <iostream>
#include "Array.h"

Array::Array(int sizeP) // ����������� ������� ��������� ��������� int
{
	this->size = sizeP; // � ������� ������
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