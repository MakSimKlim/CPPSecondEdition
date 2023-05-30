// 230530_1
//
// дано натуральное число N (целое, и оно 0 и больше). Вычислить сумму его цифр

#include <iostream>

using namespace std;

unsigned int SumNatural(unsigned int a)
{
	if (a < 10)
		return a;
	else
		return a % 10 + SumNatural(a / 10);
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int a;
	cout << "Введите число:" << "\n";
	cin >> a;
	cout << "Сумма цифр натурального числа:" << SumNatural(a);
}

