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
		
	}
	cout << endl;
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
// "тяжелые элементы " опускаются очень медленно - на один за один проход

template <typename T>
void bubbleSort(T a[], int size)
{
	bool swapped; // 1я оптимизация пузырьковой сортировки (был ли обмен элементов на проходе, изначально обменов не было)
	// если обменов не было, значит массив уже упорядочен
	int i, j;
	T x;
	for (i = 0; i < size; i++) // проходы
	{
		swapped = false;// 1я оптимизация пузырьковой сортировки
		for (j = size -1; j > i; j--) // начинаем с последнего элемента "size -1" до элемента "i", т.к. после него уже отсортировано и до 0 идти не имеет смысла
			// проход от превого элемента до текущего
			// если последний обмен на индексе К, то все предыдущие уже упорядочены и делать проходы уже не имеет смысла

		{
			if (a[j - 1] > a[j])
			{
				swapped = true;// 1я оптимизация пузырьковой сортировки
				x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;
			}
		}
		if (!swapped)// 1я оптимизация пузырьковой сортировки
			break;
	}
}
  //3 . Шейкерный обмен (оптимизированная пузырьковая сортировка)
template <typename T>
void bubbleSortOpt(T a[], int size)
{
	int k = size - 1;
	int lb = 1, ub = k; // нижняя и верхняя границы неотсортированной части массива
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
}

// 4. Сортировка вставками
// на 1-м шаге
// <0> <1> <3> <4> 2 7 9
// a[0]...a[2] уже упорядочено
// 2 < 4 | 0 1 3 2 4 7 9
// 2 < 3 | 0 1 2 3 4 7 9
// 2 > 1 | 0 1 2 3 4 7 9 // Вставка завершена

//============================================================================
// оптимизация алгоритма с  помощью сторожевого элемента

template <typename T>
void SetMin(T a[], int size)
{
	T min = a[0];
	for (int i = 1;i < size;i++)
	{
		if (a[i]<min)
		{
			min = a[i];
		}
		a[0] = min;
	}

}
template <typename T>
void insertSortGuarded(T a[], int size)
{
	T x;
	int i, j;
	T backup = a[0]; // - на первом месте стоит наименьший элемент
	//установка сторожкевого элемента
	//если есть заведомо известное значение например 0
	//можно написать a[0]=0
	setMin(a, size);

	//непосредственно сортировка
	for (i = 0; i < size; i++)
	{
		x = a[i];
			for (j = i - 1; a[j] > x; j--)// > - по возрастанию, < - по убыванию
			{
				a[j + 1] = a[j];
			}
		a[j + 1] = x;
	}
	// вставляем сохраненную a[0] на свое место
	for (j = 1; j < size && a[j] < backup; j++)
	{
		a[j - 1] = a[j];
	}
	a[j - 1] = backup;
}

//========================================================================
template <typename T>
void insertSort(T a[], int size)
{
	T x;
	int i, j;
	for (i = 0; i < size; i++)
	{
		x = a[i];
		for (j = i - 1; j >= 0 && a[j] > x; j--)// опускаемся вниз пока не достигнем последнего элемента или больше него, и сдвигаемся вправо
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = x;
	}
}

// пример для алгоритма линейного поиска
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
	cout << "Bubble sort optimizing: ";
	bubbleSortOpt(a, arraySize);
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
