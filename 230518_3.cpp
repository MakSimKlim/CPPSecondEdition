// 230518_3
// 
// Написать функцию, возвращающую количество простых чисел в 
// передаваемом массиве
// 
// bool IsPrime(int a)
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
		ar[i] = RandInt(1, 1000);
	}
}
bool IsPrime(int a) // функция проверки числа на простое
{    //return прерывает выполнение функции
	 //если между 2 и половиной числа найден еще какой-то делитель, то оно не является простым
	if (a<=1)
	{
		return false;//если а<=1, то else не нужен, выполнение прекращается return  и следующий for не выполнится
	}
	for (int i = 2; i < a/2; i++) //начинается с 2 тк все числа делятся на 1, и его не надо проверять
	{
		if (a % i == 0)
			return false;
	}
	cout << "Простое число: " << a << "\n";
	return true;//не найден ни один делитель , значит это простое число
}
int GetAmountOfPrimes(int ar[], int size)//функция получения количества простых чисел
{
	int res = 0;
	for (int i = 0; i < size; i++)
	{
		//if (IsPrime(ar[i]) == true) - излишне писать, т.к. IsPrime(ar[i]) и так true
		//if (!IsPrime(ar[i])) - посчитает Не простые числа, т.к поменяет true на false
		if (IsPrime(ar[i]))
		{
			res++;
		}
	}
	cout << "Простых чисел в данном массиве: " << res << "\n";
	return res;
}



int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	cout << "**********************************************************************************" << "\n";
	cout << "*   программа возвращающая количество простых чисел в передаваемом массиве       *" << "\n";
	cout << "**********************************************************************************" << "\n";

	const int size = 100;
	int ar[size];
	FillArray(ar, size);
	//вывод массива на экран
	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << " ";
	}
	cout << "\n";

	GetAmountOfPrimes(ar, size);


}

