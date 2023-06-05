#include <iostream>
using namespace std;

void constpointers()
{
	int i = 10;
	// онстантный указатель
	//Ќельз€ изменить куда он указывает
	int* const p = &i;
	cout << i << endl;
	i = 9;
	cout << i << endl;
	//Ќо можно изменить хран€щеес€ по адресу значение
	*p = 56;
	cout << i << endl;

	//”казатель на константу
	//Ќельз€ изменить значение через него
	const int* pa;
	int a = 73;
	pa = &a;
	cout << *pa << endl;
	a = 12;
	cout << *pa << endl;
	int b = 34;
	//Ќо можно изменить куда он указывает
	pa = &b;
	cout << *pa << endl;
	//*pa = 99;

	// онстантный указатель на константу
	//“олько считывает из значени€, которым инициализирован
	const int* const ptr = &a;
	cout << *ptr << endl;
}