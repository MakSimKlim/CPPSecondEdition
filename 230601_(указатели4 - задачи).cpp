// 230601_(указатели4 - задачи)
// 
// Дано два массива, упорядоченных по возрастанию, размером M и N
// Создать третий массив размером M+N, который будет содержать элементы первых двух массивов,
// и также будет отсортирован по возрастанию
//

#include <iostream>

#define SIZEM 8
#define SIZEN 10

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
	{
		cout << ar[i] << " ";
	}
	cout << endl;
}

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

int main()
{
	int arM[SIZEM];
	int arN[SIZEN];
	int arSum[SIZEM + SIZEN];

	FillArray(arM, SIZEM);
	cout << "First massive: " << "\n";
	QuickSort(arM, SIZEM-1);
	ShowArray(arM, SIZEM);

	FillArray(arN, SIZEN);
	cout << "Second massive: " << "\n";
	QuickSort(arN, SIZEN-1);
	ShowArray(arN, SIZEN);

	cout << "Third massive: " << "\n";

	for (int i = 0; i < SIZEM + SIZEN; i++)
	{
		if (arM[i] != 0)
		{
			arSum[i] = arN[i];

		}
		else
		{
			arSum[i] = arM[i];
		}

		cout << arSum[i] << " ";

	}

	//FillArray(arSum, SIZEM + SIZEN);
	//cout << "Third massive: " << "\n";
	//ShowArray(arSum, SIZEM + SIZEN);
}

