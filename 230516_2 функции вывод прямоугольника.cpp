// 230516_2
//
//написать функцию, выводящую на экран прямоугольник с высотой N и шириной R

#include <iostream>
#include <Windows.h>

using namespace std;

//функция для прямоугольника из символов
void SymbolPryam(int height, int width, char symbol)
{
	for (int a = 0; a < height; a++)
	{
		for (int b = 0; b < width; b++)
		{
			cout << symbol;
		}
		cout << "\n";
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "**************************************************************" << "\n";
	cout << "*            программа вывода на экран прямоугольника        *" << "\n";
	cout << "**************************************************************" << "\n";

	int n = 0, k = 0;
	char s;
	cout << "Введите высоту N: " << "\n";
	cin >> n;
	cout << "Введите ширину K: " << "\n";
	cin >> k;
	cout << "Введите символ для заполнения: " << "\n";
	cin >> s;
	cout << "Получился такой прямоугольник: " << "\n";

	SymbolPryam(n,k,s);

	return 0;

}

