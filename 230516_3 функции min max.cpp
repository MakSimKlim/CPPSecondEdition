// 230516_3
// 
// Написать функции, определяющие минимум и максимум (значение и номер)
// элементов передаваемого ей массива
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

int Max(int ar[], int size)
{
	int max = 0;
	int index;
	for (int i = 0; i < size; i++)
	{
		if
		index = i;
		max = ar[i];
	}

}


int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	cout << "**************************************************************" << "\n";
	cout << "*           программа определяющая максимум и минимум        *" << "\n";
	cout << "**************************************************************" << "\n";
	
	const int size = 10;
	int ar[size];
	FillArray(ar, size);





}

