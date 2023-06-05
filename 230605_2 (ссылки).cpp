// 230605_2 (ссылки)
//
// ссылочная переменная - всегда показывает на одну и ту же переменную (псевдоним переменной), в отличие от указателя
// int& l = a + 5;
// ссылке нельзя присвоить другое значение, объявив её один раз

#include <iostream>
using namespace std;

// c использованием указателя
void PSwap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// то же с применением ссылки
void RSwap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void foo(int* a, int* b)
{
	*a = 8;

}

void iref()
{
	int x = 10, y = 5;
foo(&x, &y);
cout << x << endl;

int a = 10;
// Ссылка на а
int& l = a;//ссылка
// int& l(a); // второй вариант записи


// ПРИМЕР НА ССЫЛКУ
int ivar = 1234;    // переменная
int* iptr = &ivar;  // указатель на ссылку переменной
int& iref = ivar;   // ссылка на переменную (псевдоним переменной)
int* p = &iref;     // указатель на ссылку переменной
cout << "ivar = " << ivar << endl;
cout << "*iptr = " << *iptr << endl;
cout << "iref = " << iref << endl;
cout << "*p = " << *p << endl;
// Одинн раз инициализировав ссылку , изменить куда она указывает нельзя
// изменение ссылки изменяют и оригинальные переменные
iref = a;
cout << ivar << endl;
// ссылки ВСЕГДА ссылаются на объект
// ссылка - псевдоним для переменной
// ссылки используются в основном для создания функций, которые возвращают несколько значений


}

void Swappers()
{
	int x = 5, y = 10;
	cout << "Pointer Swap: " << endl;
	cout << x << " " << y << endl;
	PSwap(&x, &y);
	cout << x << " " << y << endl;

	cout << "\n--------------------------------------\n\n";
	cout << "Ref Swap: " << endl;
	x = 7, y = 12;
	cout << x << " " << y << endl;
	RSwap(x, y);
	cout << x << " " << y << endl;

}

int& rf(int index);
int a[10][2];

void attToCall()
{
	int b;
	cout << "Fill array: ";
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << " element: ";
		cin >> b;
		a[i][0] = b;
		rf(i) = b + 1;
	}
	cout << "Show array: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << a[i][0] << "\t" << rf(i) << endl;
	}

}

int& rmax(int* ar, int size)
{
	int max = 0;
	for (int i = 1; i < size; i++)
	max = ar[i] > ar[max] ? i : max;
	return ar[max];
}

int main()
{
	const int size = 6;
	int a[] = { 56,75,123,4,67,87 };
	rmax(a, size) = 0;
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

}

int& rf(int index)
{
	return a[index][1];
}

