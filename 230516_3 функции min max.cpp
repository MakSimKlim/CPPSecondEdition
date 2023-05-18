// 230516_3
// 
// Написать функции, определяющие минимум и максимум (значение и номер)
// элементов передаваемого ей массива
//

#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

int RandInt(int min, int max) // функция рандомных чисел
{
    return min + rand() % (max - min) + 1;
}
void FillArray(int ar[], int size) // функция заполнения массива рандомными числами от 1 до 100
{
	for (int i = 0; i < size; i++)
	{
		ar[i] = RandInt(1, 100);
	}
}

int Max(int ar[], int size)
{
	int max = 0;
	int index;//особенность для максимума
	for (int i = 1; i < size; i++)//начали с 1 т.к. 0 элемент уже приняли за минимум
	{
		if (ar[i] > max)//это условие всегда выполнится хотя бы один раз, т.к. хотя бы один элемент будет максимальным, поэтому index ни к чему изначально не приравнивается
		{
			index = i;
			max = ar[i];
		}
		
	}
	cout << "\nFound max=" << max << " at " << index + 1 << "\n";
	return index;
}

int Min(int ar[], int size)
{
	int min = ar[0];
	int index = 0;//особенность для минимума
	for (int i = 1; i < size; i++)//начали с 1 т.к. 0 элемент уже приняли за минимум
	{
		if (ar[i]<min)//это условие никогда не выполнится если 0 элемент = 0, поэтому index =0;
		{
			index = i;//новый индекс минимального элемента
			min = ar[i];//новый элемент, равный минимуму
		}

	}
	cout << "\nFound min=" << min << " at " << index + 1 << "\n";
	return index;
}


int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	cout << "**************************************************************" << "\n";
	cout << "*           программа определяющая максимум и минимум        *" << "\n";
	cout << "**************************************************************" << "\n";
	
	const int size = 10;
	int ar[size];
	FillArray(ar, size);
	//вывод массива на экран
	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << " ";
	}
	cout << "\n";
	Max(ar, size);
	Min(ar, size);
	cout << "\n";

	int b[size];
	FillArray(b, size);
	//вывод массива на экран
	for (int i = 0; i < size; i++)
	{
		cout << b[i] << " ";
	}
	cout << "\n";
	Max(b, size);
	Min(b, size);

}

