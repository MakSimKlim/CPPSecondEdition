﻿// Airplane_class
// 
// Создайте класс Airplane, он содержит номер рейса и количество пассажиров.
// Перегрузите операторы сравнения (сравнивайте по количеству пассажиров)
// создайте ему конструкторы копирования и перемещения,
// а также перегрузку для оператора копир. и перем. присваивания
//
//  
// https://codepal.ai/code-generator/query/69iYuoEo/function-cpp-airplane-class
// https://metanit.com/cpp/tutorial/5.17.php
// https://metanit.com/cpp/tutorial/14.2.php

#include <iostream>

using namespace std;

class Airplane
{
public:
	// обычный конструктор 
	Airplane(string numFlights, int numPassengers)
	{
		NumberFlights = numFlights;
		NumberPassengers = numPassengers;
	}

	// Перегрузка оператора сравнения (сравнивает по количеству пассажиров на рейсах)
	bool operator>(const Airplane& f)
	{
		return NumberPassengers > f.NumberPassengers;
	}

	// перегрузка оператора копирования
	bool operator=(const Airplane& a)
	{
		cout << "перегрузка оператора копирования";
		return NumberPassengers = a.NumberPassengers;
	}
	// перегрузка оператора перемещения
	bool operator=(Airplane&& m)
	{
		cout << "перегрузка оператора перемещения";
		return NumberPassengers = m.NumberPassengers;
	}



	// конструктор копирования
	// По умолчанию компилятор при компиляции классов генерирует специальный конструктор - 
	// конструктор копирования, который позволяет создать объект на основе другого объекта 
	// (по сути копирует объект). Конструктор копирования по умолчанию копирует значения 
	// полей объекта, в новый объект, эти значения можно модифицировать
	Airplane(const Airplane& copy)
	{
		NumberFlights = copy.NumberFlights;
		NumberPassengers = copy.NumberPassengers + 10; // +10 для примера увеличивает кол-во пассажиров на рейсе на 10
		cout << "Применён конструктор копирования" << endl;

	}

	// конструктор перемещения
	// представляет альтернативу конструктору копирования в тех ситуациях, 
	// когда надо сделать копию объекта, но копирование данных нежелательно - 
	// вместо копирования данных они просто перемещаются из одной копии объекта в другую
	// Чтобы указатель перемещаемого объекта moved перестал указывать на эту область памяти, 
	// и соответственно чтобы в деструкторе объекта moved не было ее освобождения, передаем указателю значение nullptr.
	// В приведенной выше общей форме используется ключевое слово noexcept. Этот спецификатор указывает, 
	// что наша функция (конструктор переноса) не генерирует (не выбрасывает) исключение или аварийно завершает свою работу.
	Airplane(Airplane&& moved) noexcept
	{
		NumberFlights = moved.NumberFlights;      // перемещаем кол-во пассажиров
		NumberPassengers = moved.NumberPassengers;// перемещаем номер рейса
		cout << "Применён конструктор перемещения" << endl;
		
		//moved.NumberFlights = nullptr;
		//moved.NumberPassengers = 0;
	}
		
		
	

	// метод вывода информации о рейсах в консоль
	void print()
	{
		cout << "Номер рейса: " << NumberFlights << "\tКол-во пассажиров: " << NumberPassengers << endl;
	}

	//// Деструктор
	~Airplane()
	{	};

private:

	string NumberFlights;
	int NumberPassengers;

};


int main()
{
	setlocale(LC_ALL, "Rus");

	// Создание двух рейсов (f) - Название рейса - Кол-во пассажиров
	Airplane f1("Su 1093", 125);// рейс Челябинск - Москва
	Airplane f2("Dp 550", 130); // рейс Челябинск - Санкт-Петербург
	// вывод информации о рейсах:
	f1.print();
	f2.print();

	// Сравннение рейсов по возможному количеству пассажиров на борту
	if (f1 > f2)
	{
		cout << "Рейс Su 1093 может взять на борт больше пассажиров" << endl;
	}
	else
	{
		cout << "Рейс Dp 550 может взять на борт больше пассажиров" << endl;
	}

	cout << endl;
	// Создание объектов f3 f4 на основе объектов f1 f2 через конструктор копирования
	Airplane f3{ f1 };
	Airplane f4{ f2 };
	// вывод информации о рейсах:
	f3.print();
	f4.print();


	cout << endl;
	//// Создание объектов f5 f6 на основе объектов f1 f2 через конструктор перемещения
	Airplane f5 = move(f1);
	Airplane f6 = move(f2);
	// вывод информации о рейсах:
	f5.print();
	f6.print();

	// проверка о срабатывании оператора перемещения, исходник =0
	cout << endl;
	cout << "проверка о срабатывании оператора перемещения, исходник =0" << endl;
	cout << "size f1 = " << sizeof f1 << "; size f5= " << sizeof f5 << endl;
	cout << "size f2 = " << sizeof f2 << "; size f6= " << sizeof f6 << endl << endl;

	// перегрузка оператора копирования
	f3 = f1;
	cout << endl;
	f4 = f2;
	cout << endl << endl;

	// перегрузка оператора перемещения
	f5 = move(f1);
	cout << endl;
	f6 = move(f2);
	cout << endl << endl;

	return 0;
}
