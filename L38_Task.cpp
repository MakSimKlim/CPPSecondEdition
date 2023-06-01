#include <iostream>
#include <time.h>
using namespace std;

template <class T>
void QuickSort(T a[], int N)
{
	//a[] - сортируемый массив
	//N - индекс последнего элемента
	int i = 0, j = N;
	//temp - временный элемент для обмена, p - опорный элемент
	T temp, p;
	p = a[N / 2];

	do
	{
		while (a[i] < p) i++;
		while (a[j] > p) j--;
		if (i <= j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++; j--;
		}
	} while (i <= j);

	if (j > 0) QuickSort(a, j);
	if (N > i) QuickSort(a + i, N - i);
}

int RandInt(int min, int max)
{
	return min + rand() % (max - min) + 1;
}

void FillArray(int ar[], int size)
{
	for (int i = 0; i < size; i++)
	{
		ar[i] = RandInt(1, 100);
	}
}

void ShowArray(int ar[], int size)
{
	for (int i = 0; i < size; i++)
		cout << ar[i] << " ";
	cout << endl;
}

template <typename T>
void Swap(T* px, T* py)
{
	T temp;
	temp = *px;
	*px = *py;
	*py = temp;
}

void SwapOddsAndEvens(int* pa, int size)
{
	for(int i = 0; i < size - 1; i+=2, pa+=2)
	{
		Swap(pa, pa + 1);
	}
}

void UniteArrays(int* A, int* B, int N, int M, int* C)
{
	int j = 0, i = 0;
	while(i < N && j < M)
	{		
		if (*(A + i) < *(B + j)) {
			*C = *(A + i);
			i++;
		}
		else{
			*C = *(B + j);
			j++;
		}
		C++;
	}
	for (; i < N; i++, C++)
		*C = *(A + i);
	for (; j < M; j++, C++)
		*C = *(B + j);
}

int main()
{
	srand(time(NULL));
	const int N = 11;
	int a[N];
	FillArray(a, N);
	QuickSort(a, N - 1);
	cout << "A: ";
	ShowArray(a, N); cout << endl;
	
	const int M = 10;
	int b[M];
	FillArray(b, M);
	QuickSort(b, M - 1);
	cout << "B: ";
	ShowArray(b, M); cout << endl;

	int c[N + M];
	UniteArrays(a, b, N, M, c);
	cout << "C: ";
	ShowArray(c, N + M);
}

/*
* Дан массив целых чисел. Используя синтаксис указателей
* поменять местами элементы с чётными и нечётными индексами.
* 
* (Например, {1, 2, 3, 4} сделать {2, 1, 4, 3})
*/

/*
* Дано два массива, упорядоченных по возрастанию, размером M и N
* Создать третий массив размера M+N, который будет содержать элементы первых двух массивов,
* и также будет отсортирован по возрастанию.
*/