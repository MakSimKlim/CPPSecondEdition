// 230529_алгоритм двоичного поиска (Бинарный поиск)
//
// Для неупорядоченных данных эффективен алгоритм линейного поиска
//  
// Двоичный (Бинарный ) поиск эффективен для упорядоченных данных (найти льва в пустыне)
// Работает только из предположения, что массив упорядочен!!!
//
// Теория двоичного поиска:
// мы знаем левую и правую границы элемента и начинаем анализ среднего элемента
// если он больше искомого - снижаем верхнюю границу до среднего
// если элемент меньше среднего, то сдвигаем границу выше, сужая область поиска вдвое


#include <iostream>

#define SIZE 10 // директива препроцессора

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

// функция быстрой сортировки
template <typename T>
void QuickSort(T a[], int N)
{
	// a[] - сортируемый массив
	// N - индекс последнего элемента
	int i = 0, j = N;
	// temp - временный элемент для обмена, р - опорный элемент (середина отрезкеа N)
	T temp, p;
	p = a[N / 2]; // N/2 - т.к. p  - середина отрезка N

	do // условие выхода из цикла
	{
		while (a[i] < p) i++; // идем к концу массива
		while (a[j] > p) j--; // идем к началу массива
		if (i <= j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++; j--;//чтобы не исключать опорный элемент
		}
	} while (i <= j);

	//если еще есть что-то сортировать
	if (j > 0) QuickSort(a, j);
	//если еще есть что-то сортировать
	if (N > i) QuickSort(a + i, N - i);//адрес а сместили на адрес i элемента; N-i - длина массива; опорный элемент - середина N-i

}

// алгоритм бинарного поиска (без рекурсии)
template <typename T>
int BinarySearch(T a[], int Lb, int Ub, T key)
{
	int M;
	while (1)
	{
		M = (Lb + Ub) / 2;
		if (key < a[M])
		{
			Ub = M - 1;
		}
		else if (key > a[M])
		{
			Lb = M + 1;
		}
		else
			return M;
		if (Lb > Ub)
		{
			return -1;// -1  традиционный сигнал, что элемент не найден
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	// создание массива
	int ar[SIZE];
	FillArray(ar, SIZE);
	ShowArray(ar, SIZE);

	// быстрая сортировка
	QuickSort(ar, SIZE - 1);
	cout << "Sorted: " << "\n";
	ShowArray(ar, SIZE);

	int k;
	cout << "Please enter number to search: "<< "\n";
	cin >> k;
	int i = BinarySearch(ar, 0, SIZE - 1, k);
	if ( i >= 0)
	{
		cout << "Key: " << k << " found at position " << i + 1 << "\n";
	}
	else
	{
		cout << "Key: " << k << " not found " << "\n";
	}
	return 0;
}