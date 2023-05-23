// 230523_3
//
//
// Алгоритмы поиска и сортировки
// сортировка- процесс упорядочивания данных

#include <iostream>
#include <Windows.h>
#include <math.h>
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
void ShowArray(int ar[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << " ";
		//cout << endl;
	}

}
int LinearSearch(int ar[], int arraySize, int key) // алгоритм линейного поиска
{
	for (int i = 0; i < arraySize; i++)
	{
		if (ar[i] == key)
		{
			return i;
		}
	}
	return -1;
}
// 1. сортировка выбором (начиная с нулевого элемента выбираем наименьший из элементов и сравниваем с выбранным на каждом шаге, доходя до конца массива)
// упорядоченность от a[0] до a[i]
// Исх.:  (4 9 7 6 2 3)
// Шаг 0: 2 (9 7 6 4 3)
// Шаг 1: 2 3 (7 6 4 9)
// Шаг 2: 2 3 4 (6 7 9) 
// Шаг 3: 2 3 4 6 (7 9)
// Шаг 4: 2 3 4 6 7 (9)

template <typename T>
void selectSort(T a[], int size)
{
	int i, j, k;
	T x; // для того чтобы менять местами переменные

	//конструкция для замены местами элементов массива
	//temp = a;
	//a = b;
	//b = temp;
 

	// алгоритм сортировки выбором

	for (i = 0; i < size; i++)// перебор всех элементов массива
	{
		k = i;//минимальный элемент 
		x = a[i];
		for ( j = i+1; j < size; j++) // проверяем оставшуюся часть массива т.е. с элемента i+1
		{
			if (a[j] < x)//сортировка по возрастанию
			//if (a[j] > x) // сортировка по убыванию
			{
				x = a[j];
				k = j;
				// из цикла выходим, зная минимальное число
			}
		}
		if (k != i)
		{
			a[k] = a[i];
			a[i] = x;
		}
	}
}
// 2. пузырьковая сортировка (замена местами элементов в паре, самые лёгкие поднимаются вверх) - в среднем быстрее сортировки выбором
// Исх.:     4 9 7 6 2 3
// Проход 0: 
// 2 и 3 | 4 9 7 6 2 3
// 2 и 6 | 4 9 7 2 6 3
// 2 и 7 | 4 9 2 7 6 3
// 2 и 9 | 4 2 9 7 6 3
// 2 и 4 | 2 4 9 7 6 3
// Проход 1: 
// 3 и 6 | 2 4 9 7 3 6
// 3 и 7 | 2 4 9 3 7 6
// 3 и 9 | 2 4 3 9 7 6
// 3 и 4 | 2 3 4 9 7 6
// и т.д.

template <typename T>
void bubbleSort(T a[], int size)
{
	bool swapped; // пузырьковой оптимизация сортировки
	int i, j;
	T x;
	for (i = 0; i < size; i++) // проходы
	{
		swapped = false;// пузырьковой оптимизация сортировки
		for (j = size -1; j > i; j--) // начинаем с последнего элемента "size -1" до элемента "i", т.к. после него уже отсортировано и до 0 идти не имеет смысла
		{
			if (a[j - 1] > a[j])
			{
				swapped = true;// пузырьковой оптимизация сортировки
				x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;
			}
		}
		if (!swapped)// пузырьковой оптимизация сортировки
			break;
	}
}



// пример для алгоритма линейного поиска
//void searching()
//{
//	int key, result;
//	char userChoice;
//	do
//	{
//		cout << "Enter number to search: " << "\n";
//		cin >> key;
//		result = LinearSearch(a, arraySize, key);
//		if (result > 0)
//		{
//			cout << "Number " << key << " find at Index " << result + 1 << "\n";
//		}
//		else
//		{
//			cout << "Number " << key << " not found " << "\n";
//		}
//		cout << "Another number? y/n: " << "\n";
//		cin >> userChoice;
//
//	} while (userChoice == 'y');
//
//
//
//}


int main()
{
	srand(time(NULL));

	const int arraySize = 20;
	int a[arraySize];

	FillArray(a, arraySize);
	ShowArray(a, arraySize);
	cout << "\nSelect sort" << "\n";
	selectSort(a, arraySize);
	ShowArray(a, arraySize);
	cout << endl;
	cout << endl;
	FillArray(a, arraySize);
	ShowArray(a, arraySize);
	cout << "\nBuble sort" << "\n";
	bubbleSort(a, arraySize);
	ShowArray(a, arraySize);
	cout << endl;
}
