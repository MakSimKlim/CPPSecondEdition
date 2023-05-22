// 230522_6 заполнение массива перегрузкой

#include <iostream>
#include <Windows.h>
#include <math.h>

#define SIZE 15 // заменит size на число 15 в main - вариант объявления константы через макрос #define

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

template <typename T> // шаблон функции среднего арифметического массива
double average(T ar[], int size)
{
	T sum = 0;
	for (int i = 0; i < size; i++) // сумма элементов в массиве
	{
		sum += ar[i];
	}
	return (double)sum / size; // среднее арифметическое (сумма элементов деленная на количество элементов)
	// (double) говорим с++ чтобы он взял sum как double - вариант одноразового преобразования, чтобы отобразилось нецелое число
	// одноразовое преобразование - очень удобно в данном случае, чтобы вывести нецелое число
}

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	long a_i[5];
	fillArray(a_i, 5);
	showArray(a_i, 5);
	cout << average(a_i, 5) << "\n";

	double a_d[5];
	fillArray(a_i, 5);
	showArray(a_i, 5);
	cout << average(a_i, 5) << "\n";

	return 0;
}
