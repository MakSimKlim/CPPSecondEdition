// 230523_1
//
// Перегруженные шаблоны функции для нахождения корней уровнения
// - линейного (a*x+b)...=> ... x=-b/a
// - квадратного (a*x^2 + b*x +с = 0)

#include <iostream>
#include <Windows.h>
#include <math.h>

using namespace std;

//перегруженные шаблоны
template <typename T>
void solve(T a, T b)// шаблон для решения линейного уравнения
{
	cout << "Solution for " << a << "x + " << b << " = 0:"<<"\n";
	cout <<"x= "<< -(b / a) << "\n";
}

template <typename T>
void solve(T a, T b, T c)// шаблон для решения квадратного уравнения
{
	cout << "Solution for " << a << "x^2 + " << b << "x + " << c << " = 0:"<<"\n";
	T D = pow(b, 2) - 4 * a * c;
	if (D < 0)
	{
		cout << "No solution"<<"\n";
		return; // функция прервется
	}
	if (D == 0)
	{
		cout <<"x= "<< - b / (2 * a) << "\n";
		return;
	}
	//третье условие можно писать без проверки этого условия, т.к. два условия уже проверены
	T x1 = (-b + sqrt(D)) / (2 * a);
	T x2 = (-b - sqrt(D)) / (2 * a);
	cout << "x1= " << x1 << "\n";
	cout << "x2= " << x2 << "\n";
}

int main()
{
	solve(3,4);
	solve(3.4,4.5);
	solve(3,-4,2);
	solve(1,-6,9);
	solve(1.0,-6.0, 9.0);
	solve(1,-4,-5);
	solve(1.0, -4.0, -5.0);

	return 0;
}

