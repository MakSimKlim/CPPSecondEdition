// 230522_7 самостоятельно шаблоны функции
//
//
// Написать шаблон функции нахождения минимума в одномерном массиве
// Написать шаблон функции нахождения максимума в двумерном массиве
// Написать шаблон функции нахождения суммы всех элементов в двумерном массиве

#include <iostream>
#include <Windows.h>
#include <math.h>

#define SIZE 5

using namespace std;

long randLong(long start, long end)
{
	return start + rand() % (end - start) + 1;
}

double randDouble(double start, double end)
{
	double res = start + rand() % (int)(end - start) + 1;
	res += randLong(1, 1000) * 0.0001;
	return res;

}

void fillArray(long ar[], int size)
{
	for (int i = 0; i < size; i++)
	{
		ar[i] = randLong(1, 1000);
	}
}
void fillArray(double ar[], int size)
{
	for (int i = 0; i < size; i++)
	{
		ar[i] = randDouble(1, 100);
	}
}

template <typename T> 
void showArray(T ar[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << " ";
	}
	cout << "\n";
}

template <typename T> // шаблон функции нахождения минимума в одномерном массиве
double average(T ar[], int size)
{
	T res = ar[0];
	for (int i = 1; i < size; i++)
	{
		if ((a && ar[i] > res) || (!a && ar[i] < res))
		{
			res = ar[i];
		}
	}
	return res;
}
//template <typename T> // шаблон функции нахождения максимума в двумерном массиве
//double average(T ar[][SIZE], int size)
//{
//	T res = ar[0][0];
//	for (int i = 1; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			if ((a && ar[i][j] > res) || (!a && ar[i][j] < res))
//			{
//				res = ar[i][j];
//			}
//		}
//		
//	}
//	return res;
//}



int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	long a_i[5];
	fillArray(a_i, 5);
	showArray(a_i, 5);
	cout << average(a_i, 5) << "\n";

	double a_d[5];
	fillArray(a_d, 5);
	showArray(a_d, 5);
	cout << average(a_d, 5) << "\n";

	return 0;
}

