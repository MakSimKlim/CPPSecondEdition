// 230608_1
// 
//
// функция, удаляющая элемент на указанной позиции

#include <iostream>
#include <time.h>
#include "ArrayStuff.h"

using namespace std;

// шаблон функции для удаления элемента в массив 
template <typename T>
void DeleteAt(T*& a, int& size, int index)
{
	T* newAr = new T[size - 1];
	int k = 0;
	//for (int i = 0; i < size; i++)
	//{
	//	if(i != index)
	//	newAr[k++] = a[i];
	//}
	// второй вариант решения
	for (int i = 0; i < index; i++)
	{
		newAr[i] = a[i];
	}
	for (int i = index+1; i < size; i++)
	{
		newAr[i-1] = a[i];
	}
	delete[] a;
	a = newAr;
	size--; // т.к. размер нового а меньше на 1
}

// функция удаления элемента в массив
void DeleteElementAt()
{
	int sizeA;
	cout << "Enter size2: ";
	cin >> sizeA;
	int* a = new int[sizeA];
	FillArray(a, sizeA);
	cout << "A=";
	ShowArray(a, sizeA);

	DeleteAt(a, sizeA);
	int toAdd;
	cout << "Enter element to add: ";

	// недописана

}


int main()
{
   



}

