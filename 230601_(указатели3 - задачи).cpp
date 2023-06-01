// 230601_(указатели3 - задачи)
// Дан массив целых чисел. Используя синтаксис указателей поменять местами элементы с чётными и нечетными индексами
// например {1,2,3,4} сделать {2,1,4,3}

#include <iostream>
#define SIZE 8

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

template <typename T>
void Swap2(T* px, T* py)
{
	T temp;
	temp = *px;
	*px = *py;
	*py = temp;

}

void SwapOddsAndEvents(int* pa, int size)
{
	for (int i = 0; i < size -1; i+=2, pa+=2)//size -1 проверка условия до предпоследнего элемента, i+=2 это чётные индексы, pa+=2 указатели тоже сдвигаются на 2
	{
		Swap2(pa, pa + 1);
	}

}

int main()
{
	
	int ar[SIZE];
	
	FillArray(ar, SIZE);
	cout << "Before: " << "\n";
	ShowArray(ar, SIZE);
	SwapOddsAndEvents(ar, SIZE);
	cout << "After: " << "\n";
	ShowArray(ar, SIZE);
	cout << "\n";

	//ShowArray(ar, SIZE);

}

