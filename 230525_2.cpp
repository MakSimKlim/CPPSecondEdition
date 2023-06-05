﻿// 230525_2
// 
// Рекурсия!!!
//
// Рекурсия - это определение объекта через самого себя
// (когда функция вызывает саму себя)
// 
// некий цикл, где функция вызывает сама себя и так далее вглубь функции
// 
// void First()
// {}
// 
// void Second()
// {
//  First();
// }
// 
// int main()
// {
//  Second;
// }
// компилятор берет main кладет его на second, затем first (всё это стэк вызовов)
// очень большие данные делается традиционной сортировкой (пузырь, вставка и тд)
// быстрая сортирвоока лучший способ сортировки которым позуются сейчас везде
// 
// если на рекурсии нет остановки, то происходит переполнение стэка (stackoverflow) и крашится всё 
//
// любой алгоритм который решается рекурсивно, можно решить интеративно
// 
// рекурсия требует больше оперативной памяти,т.к. работает через стэк вызовов
// 
// рекурсию удобно применять к алгоритмам, которые очень громоздко записыватся интеративно
//
// если задача разбивается на много меньших задач, то лучше применять рекурсию
//
// оптимизация алгоритма нужна всегда
//
// алгоритм быстрой сортировки самый лучший и быстрый рекурсивный алгоритм, не может применяться только с большим кол-вом строк


#include <iostream>
using namespace std;

// N! = 1*2*3*...*N - факториал +

// можно определить факториал через факториал
// N!  = N * ( N - 1 )! - условие неопределенное, поэтому будет бесконечный цикл, нужно определенное условие
// 1! = 1 - определенное конкретное условие
// пример:
// 4! = 4 * 3! = 4 * 3 * 2! = 4 * 3 * 2 * 1! = 4 * 3 * 2 * 1 = 4 * 3 * 2 = 4 * 6 = 24

long Fact(long n) // long т.к факториал очень быстро растет
{
	// подсчёт количества вызова функций
	static int k;
	k++;
	// проверка на неправильное число
	if (n < 1)
		return 0;
	else if (n == 1) // границы рекурсии (иначе будет бесконечный цикл и стэк переполнится)
	{
		cout << "(" << k << ")"; // подсчёт количества вызова функций
		return 1; // факториал 1 равен 1
	}
	else
		return n * Fact(n-1);//вызов рекурсии остальных значений вне границ рекурсии
}

long Fact_It(long n)//решение факториала интеративным способом без рекурсии
{
	long f = 1;
		for (int i = 2; i <= n; i++)
		{
			f *= i;
		}
		return f;
}

long Sum(long n) // сумма чисел от 1 до заданного числа через рекурсию
{
	long s;
	cout << n << " ";
	if (n==1)
	{
		cout << "End ";
		return 1;
	}
	else
	{
		s = n + Sum(n - 1);
		cout << n << " ";
		return s;
	}
}

// рекурсивная функция степени числа
template <typename T>
T Step(T chislo, int stepen)
{
	int s;
	if (stepen == 0)
	{
		return 1;
	}
	else
	{
		s = chislo * Step(chislo,stepen-1);// степень числа - а в степени n это а умноженное на а в степени n-1
		return s;
	}
}
// рекурсивная функция степени числа (вариант записи функции степени числа)
template <typename T>
T Step2(T chislo, int stepen)
{
	int s;
	if (stepen == 0)
	{
		return 1;
	}
	else
	{
		if(stepen > 0)
		    return chislo * Step2(chislo, stepen - 1);// степень числа - а в степени n это а умноженное на а в степени n-1
		else
			return 1 / chislo * Step2(chislo, stepen + 1);
	}
}




int main()
{
	setlocale(LC_ALL, "Rus");
	
	cout << "10! = " << Fact(10) << "\n";
	cout << "10! = " << Fact_It(10) << "\n";
	cout<<"\nSum 10 = "<<Sum(10);

	cout << "2^5 = " << Step(2, 5) << "\n";
	cout << "2^5 = " << Step2(2, 5) << "\n";
	cout << "2^-5 = " << Step(2.0, -5) << "\n";

}