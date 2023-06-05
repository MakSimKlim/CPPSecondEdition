#include <iostream>
#include "ArrayStuff.h"
using namespace std;

void PSwap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void RSwap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void ivarf()
{
	int a = 10;
	//Ссылка на а
	int& l = a;
	//int& l(a);

	int ivar = 1234;
	int* iptr = &ivar;
	int& iref = ivar;
	int* p = &iref;

	cout << "ivar = " << ivar << endl;
	cout << "*iptr = " << *iptr << endl;
	cout << "iref = " << iref << endl;
	cout << "*p = " << *p << endl;
	//Один раз инициализировав ссылку, изменить куда она указывает нельзя
	//Изменения ссылки изменяют и оригинальную переменную
	iref = a;
	cout << ivar << endl;
}

void swappers()
{
	int x = 5, y = 10;
	cout << "Pointer Swap: \n";
	cout << x << " " << y << endl;
	PSwap(&x, &y);
	cout << x << " " << y << endl;

	cout << "\n-------------------------------------\n";
	cout << "Ref Swap: \n";
	x = 7, y = 12;
	cout << x << " " << y << endl;
	RSwap(x, y);
	cout << x << " " << y << endl;
}


int& rf(int index);
int a[10][2];

void attToCall()
{
	int b;
	cout << "Fill array: \n";
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << " element: ";
		cin >> b;
		a[i][0] = b;
		rf(i) = b + i;
	}
	cout << "Show array: " << endl;
	for (int i = 0; i < 10; i++)
		cout << a[i][0] << "\t" << rf(i) << endl;
}

int& rmax(int* ar, int size)
{
	int max = 0;
	for (int i = 1; i < size; i++)
		max = ar[i] > ar[max] ? i : max;
	return ar[max];
}

void replace_max()
{
	const int size = 6;
	int a[] = { 56, 75, 123, 4, 67, 87 };
	rmax(a, size) = 0;

	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
}






/*
* Напишите функцию, которая найдёт максимум, минимум и среднее
* одномерного массива. Тип возвращаемого у функции void,
* в функции не должно быть операторов вывода.
*/
template <typename T>
void MinMaxMean(T* a, int size, T& min, T& max, T& mean)
{
	double sum = a[0];
	max = a[0], min = a[0];
	for (int i = 1; i < size; i++)
	{
		sum += a[i];
		max = max < a[i] ? a[i] : max;
		/*if (max < a[i])
			max = a[i];
		else
			max = max;*/
		min = min > a[i] ? a[i] : min;
	}
	mean = sum / size;
}


int& rmin(int* ar, int size)
{
	int min = 0;
	for (int i = 1; i < size; i++)
		min = ar[i] < ar[min] ? i : min;
	return ar[min];
}

int main()
{
	const int size = 10;
	int a[size];
	FillArray(a, size);
	ShowArray(a, size);	cout << endl;
	int min, max, mean;
	MinMaxMean(a, size, min, max, mean);
	cout << "Min = " << min << "\nMax = " << max << "\nAverage: " << mean << endl;

	cout << "\nSwap min and max:\n";
	const int size2 = 6;
	FillArray(a, size2);
	ShowArray(a, size2);
	/*
	* Найдите максимум и минимум массива и поменяйте их местами.
	*/
	RSwap(rmin(a, size2), rmax(a, size2));
	ShowArray(a, size2); cout << endl;
}

int& rf(int index)
{
	return a[index][1];
}



