// 230615_3 (задачи на структуры)
// 
// создайте структуру, описывающую простую дробь,
// Реализуйте арифметические операции с дробями:
// сумма
// разность
// умножение
// деление
// Учесть возможность сокращения дробей
//

#include <iostream>

using namespace std;

struct Fraction
{
	int num;
	int denum;
};

// функция НОД
int gcf(int a, int b)
{
	int res = min(a, b);
	
	while (res > 0)
	{
		if (a % res == 0 && b % res == 0)
		{
			break;
		}
		res--;

	}
	return res;
}

void ActionOnFraction(Fraction K, Fraction L)
{
	cout << "Для дробей " << K.num << "/" << K.denum << " и " << L.num << "/" << L.denum << endl;
	cout << "результат сложения равен: " << ((K.num * L.denum) + (K.denum * L.num)) << "/" << (K.denum * L.denum) << endl;
	cout << "результат вычитания равен: " << ((K.num * L.denum) - (K.denum * L.num)) << "/" << (K.denum * L.denum) << endl;
	cout << "результат умножения равен: " << (K.num * L.num) << "/" << (K.denum * L.denum) << endl;
	cout << "результат деления равен: " << (K.num * L.denum) << "/" << (K.denum * L.num) << endl;

	
}

int main()
{
	setlocale(LC_ALL, "Rus");

	Fraction M = { 38,45 };
	Fraction N = { 69,178 };

	ActionOnFraction(M, N);

	return 0;
}

