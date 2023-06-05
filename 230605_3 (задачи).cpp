// 230605_3 (задачи).cpp 
//
// Задача 1
// напишите функцию, которая найдет максимум, минимум и среднее одномерного массива.
// Тип возвращаемого у функции void. В функции не должно быть оператора вывода.
// Найдите максимум и минимум массива и поменяйте их местами

#include <iostream>
using namespace std;

int RandInt(int min, int max)
{
	return min + rand() % (max - min) + 1;
}

void FillArray(int ar[], int size)
{
	for (int i = 0; i < size; i++)
	{
		ar[i] = RandInt(1, 1000);
	}
}

void ShowArray(int ar[], int size)
{
	for (int i = 0; i < size; i++)
		cout << ar[i] << " ";
	cout << endl;
}

void MaxMinSredn(int* ar, int size)
{
	int max = 0;
	for (int i = 1; i < size; i++)
		max = ar[i] > ar[max] ? i : max;

	//cout<< "Max index: " << max << "\n";

	int t = max;
	max = *ar;
	*ar = t;

}


int main()
{
	const int size = 6;
	int a[size];
	RandInt(10, 100);
	FillArray(a, size);
	ShowArray(a, size);

	MaxMinSredn(a, size);


	cout << "Max index: " << *a;

}
