﻿// 230518_4
// 
// Написать функцию, которая принимает на вход массив, его размер
// и, как необязательный параметр, логическую переменную.
// Если лог.пер.равна true, функция возвращает значение максимум массива
// иначе минимум
// По умолчанию функция должна находить максимум
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
void ShowArray(int ar[], int size) // функция вывода массива на экран
{
	cout << "Массив случайных чисел: " << "\n\n";
	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << " ";

	}
	cout << "\n";
}

int Func(int ar[], int size, bool a = true) // функция (см задание в шапке файла)
// задан параметр по умолчанию true, если функция должна находить максимум
{
	if (a == true)
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
	else
	{
		int min = ar[0];
		int index = 0;//особенность для минимума
		for (int i = 1; i < size; i++)//начали с 1 т.к. 0 элемент уже приняли за минимум
		{
			if (ar[i] < min)//это условие никогда не выполнится если 0 элемент = 0, поэтому index =0;
			{
				index = i;//новый индекс минимального элемента
				min = ar[i];//новый элемент, равный минимуму
			}

		}
		cout << "\nFound min=" << min << " at " << index + 1 << "\n";
		return index;

	}
	return 0;
}



int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	cout << "**********************************************************************************" << "\n";
	cout << "*   программа поиска максимума и минимума в массиве по логической переменной     *" << "\n";
	cout << "**********************************************************************************" << "\n";

	const int size = 10;
	int ar[size];
	//bool a;
	bool a = true;    //Если лог.пер.равна true, функция возвращает значение максимум массива (по умолчанию)
	//bool a = false; //иначе минимум
	
	FillArray(ar, size);
	ShowArray(ar, size);
	Func(ar, size); // функция с параметром по умолчанию True, то есть максимум в данном случае
	//Func(ar, size, false); // функция выведет минимум, т.к. параметр задан false


	return 0;
}

