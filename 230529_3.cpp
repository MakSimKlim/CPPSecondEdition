// 230529_3
//
// 1).Функция принимает на вход символ и число
// затем выводится указанный символ в одну линию указанное число раз
// Решить функцию рекурсивно.
// Например OutputSymbol('*', 5)
// выведет
// *****
// 2). Пользователь вводит числа a , b. Найти сумму диапазона используя ркекурсию


#include <iostream>

#define SIZE 5 // директива препроцессора

using namespace std;


// 1) первый вариант решения
//template <typename T>
//T OutputSymbol(T a, int n)
//{
//	cout << a;
//	if (n < 1)
//	    return 0;
//	else if (n == 1) // границы рекурсии (иначе будет бесконечный цикл и стэк переполнится)
//	{
//		return 1;//вызов рекурсии остальных значений вне границ рекурсии
//	}
//	else
//	{
//		n--;
//		return OutputSymbol(a, n);
//	}
//
//}

// 1) второй вариант решения
//void OutputSymbol(char sym, int number)
//{
//
//	if (number > 0)
//	{
//		cout << sym;
//		OutputSymbol(sym, number - 1);
//	}
//	else
//		cout << endl;
//
//}
// 
// 2)
int OutputSumm(int a, int b)
{
	if (a==b)
	{
		return b;
	}
	else
	{
		return a + OutputSumm(a + 1, b);
	}
}


int main()
{
	setlocale(LC_ALL, "Rus");
	
	//OutputSymbol('*', 5);

	int a, b;

	cout << "Введите числа диапазона:" << "\n";
	cin >> a >> b;

	OutputSumm(a,b);

	return 0;
}