// 230525_1
//
#include <iostream>
#include <time.h>
using namespace std;

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

//Алгоритм линейного поиска
int LinearSearch(int ar[], int arraySize, int key)
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

//Сортировка выбором
//Исх.: 4 9 7 6 2 3
//Шаг 0: 2 9 7 6 4 3
//Шаг 1: 2 3 7 6 4 9
//Шаг 2: 2 3 4 6 7 9
//Шаг 3: 2 3 4 6 7 9
//Шаг 4: 2 3 4 6 7 9
template <typename T>
void selectSort(T a[], int size)
{
	int i, j, k;
	T x;
	for (i = 0; i < size; i++)
	{
		k = i;
		x = a[i];
		for (j = i + 1; j < size; j++)
		{
			if (a[j] < x)
			{
				x = a[j];
				k = j;
			}
		}
		if (k != i)
		{
			a[k] = a[i];
			a[i] = x;
		}
	}
}

//Пузырьковая сортировка
//Исх.: 4 9 7 6 2 3
//Проход 0:
// 2 и 3 | 4 9 7 6 2 3
// 2 и 6 | 4 9 7 2 6 3
// 2 и 7 | 4 9 2 7 6 3
// 2 и 9 | 4 2 9 7 6 3
// 4 и 2 | 2 4 9 7 6 3
// Проход 1:
// 3 и 6 | 2 4 9 7 3 6
// 3 и 7 | 2 4 9 3 7 6
// 3 и 9 | 2 4 3 9 7 6
// 3 и 4 | 2 3 4 9 7 6
template <typename T>
void bubbleSort(T a[], int size)
{
	int k = size - 1;
	int lb = 1, ub = k;//нижняя и верхняя границы неотсортированной части массива
	int i, j;
	T x;

	do
	{
		for (j = ub; j > 0; j--)//проход снизу вверх
		{
			if (a[j - 1] > a[j])
			{
				x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;
				k = j;
			}
		}
		lb = k + 1;

		for (j = 1; j <= ub; j++)//проход сверху вниз
		{
			if (a[j - 1] > a[j])
			{
				x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;
				k = j;
			}
		}
		ub = k - 1;

	} while (lb < ub);

	/*for (i = 0; i < size; i++)//проход
	{
		swapped = false;
		for (j = size - 1; j > i; j--)
		{
			if (a[j - 1] > a[j])
			{
				swapped = true;
				x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;
			}
		}
		if (!swapped)
			break;
	}*/
}

//Сортировка вставками
//На i-м шаге
//<0> <1> <3> <4> 2 7 9
//a[0]..a[2] уже упорядочена
//2 < 4 | 0 1 3 2 4 7 9
//2 < 3 | 0 1 2 3 4 7 9
//2 > 1 | 0 1 2 3 4 7 9 //Вставка завершена

template <typename T>
void setMin(T a[], int size)
{
	T min = a[0];
	for (int i = 1; i < size; i++)
		if (a[i] < min)
			min = a[i];
	a[0] = min;
}

template <typename T>
void insertSortGuarded(T a[], int size)
{
	T x;
	int i, j;
	T backup = a[0];
	//Установка сторожевого элемента
	//Если есть заведомо известное значение, например, 0
	//можно написать a[0] = 0
	setMin(a, size);

	//непосредственно сортировка
	for (i = 0; i < size; i++)
	{
		x = a[i];
		for (j = i - 1; a[j] > x; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = x;
	}

	//Вставляем сохранённую а[0] на своё место
	for (j = 1; j < size && a[j] < backup; j++)
	{
		a[j - 1] = a[j];
	}
	a[j - 1] = backup;
}

template <typename T>
void insertSort(T a[], int size)
{
	T x;
	int i, j;

	for (i = 0; i < size; i++)
	{
		x = a[i];
		for (j = i - 1; j >= 0 && a[j] > x; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = x;
	}
}

//Пример для алгоритма линейного поиска
void searching()
{
	const int arraySize = 20;
	int a[arraySize];
	FillArray(a, arraySize);
	ShowArray(a, arraySize);

	int key, result;
	char userChoice;
	do
	{
		cout << "Enter number to search: ";
		cin >> key;
		result = LinearSearch(a, arraySize, key);
		if (result >= 0)
			cout << "Number " << key << " found at index " << result << endl;
		else
			cout << "Number " << key << " not found." << endl;

		cout << "Another number? y/n ";
		cin >> userChoice;
	} while (userChoice == 'y');
}


int main()
{
	srand(time(NULL));

	const int arraySize = 20;
	int a[arraySize];

	FillArray(a, arraySize);
	ShowArray(a, arraySize);
	cout << "Select sort: ";
	selectSort(a, arraySize);
	ShowArray(a, arraySize);

	FillArray(a, arraySize);
	ShowArray(a, arraySize);
	cout << "Bubble sort: ";
	bubbleSort(a, arraySize);
	ShowArray(a, arraySize);

	FillArray(a, arraySize);
	ShowArray(a, arraySize);
	cout << "Insert sort: ";
	insertSort(a, arraySize);
	ShowArray(a, arraySize);

	FillArray(a, arraySize);
	ShowArray(a, arraySize);
	cout << "Insert sort, guarded: ";
	insertSortGuarded(a, arraySize);
	ShowArray(a, arraySize);
}
/*Дан массив из 10 элементов
* Нужно написать функцию, котрая принимает три параметра
* universal_sort( T a[], int size, bool ascending = true)
* Усли ascending = true, сортировать по возрастанию.
* Усли нет то сортировать по убыванию.
* Можно использовать любой алгоритм.
*
*
*/