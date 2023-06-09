﻿// 230605_1 (продолжение указатели)
//
// константный указатель,  указатель на константу, константный указатель константы
//
// константный указатель - указ, знач котор нельзя менять после инициализации, он должен быть всегда !! инициализирован
// у него можно поменять только значение, но нельзя поменять переменную, на которую он указыват

#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	// константный указатель (нельзя изменить куда он указывает, но можно изменить хранящееся по адресу значение)
	int i = 10;
	int* const a = &i;
	//int* const a; // ошибочная запись, т.к. нужна инициализация
	int i2 = 10;
	//a = &i2;// показывает ошибку, т.к. указатель константный (см. определение выше)

	int i = 10;
	int* const p = &i;
	cout << i << endl;
	i = 9;
	cout << i << endl;
	*p = 56;
	cout << i << endl;

	// указатели на констатну (через него нельзя изменить значение, на которое он указывает, но можно изменить куда он указывает)
	const int* pc;
	int b = 73;
	pc = &b;
	cout << *pc << endl;
	b = 12;
	cout << *pc << endl;
	// *pc = 99; // запись неверная для указателя на константу
	int d = 34;
	pc = &d;
	cout << *pc << endl;

	// константный указатель константы (с ним ничего нельзя сделать, только прочитать значение переменной)
	const int* const ptr = &k;



	return 0;
}

