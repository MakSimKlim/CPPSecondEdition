// Airplane_class
// 
 //Создайте класс Airplane, он содержит номер рейса и количество пассажиров.
 //Перегрузите операторы сравнения (сравнивайте по количеству пассажиров)
 //создайте ему конструкторы копирования и перемещения,
 //а также перегрузку для оператора копир. и перем. присваивания
//
//  
// https://codepal.ai/code-generator/query/69iYuoEo/function-cpp-airplane-class
// https://metanit.com/cpp/tutorial/5.17.php
// https://metanit.com/cpp/tutorial/14.2.php

#include <iostream>

using namespace std;

class Airplane
{
private:

	string NumberFlights;
	int NumberPassengers;

public:
	// конструктор по умолчанию * принрудительно не существует
	Airplane() = delete;

	// конструктор с параметрами
	Airplane(string numFlights, int numPassengers)
	{
		NumberFlights = numFlights;
		NumberPassengers = numPassengers;
		cout << "Применён конструктор с параметрами" << endl;

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
		cout << "Применён конструктор копирования с модификацией параметров" << endl;

	}

	// конструктор перемещения
	// представляет альтернативу конструктору копирования в тех ситуациях, 
	// когда надо сделать копию объекта, но копирование данных нежелательно - 
	// вместо копирования данных они просто перемещаются из одной копии объекта в другую
	// Чтобы указатель перемещаемого объекта moved перестал указывать на эту область памяти, 
	// и соответственно чтобы в деструкторе объекта moved не было ее освобождения, передаем указателю значение nullptr.
	Airplane(Airplane&& moved)
	{
		NumberFlights = moved.NumberFlights;      // перемещаем кол-во пассажиров
		NumberPassengers = moved.NumberPassengers;// перемещаем номер рейса
		moved.NumberFlights.clear();                    // метод для очистки строк string
		moved.NumberPassengers = 0;
		cout << "Применён конструктор перемещения" << endl;

	}

	// Перегрузка операторов сравнения (сравнивает по количеству пассажиров на рейсах)
	// =, < , >, >=, <=, !=
	// 
	// 
	// (больше)
	bool operator>(const Airplane& f)
	{
		return NumberPassengers > f.NumberPassengers;
	}
	// (меньше)
	bool operator<(const Airplane& f)
	{
		return NumberPassengers < f.NumberPassengers;
	}
	// (равно)
	bool operator==(const Airplane& f)
	{
		return NumberPassengers == f.NumberPassengers;
	}


	// перегрузка Оператора копирования присваивания
	Airplane& operator=(const Airplane& f)
	{
		if (this != &f)
		{
			NumberFlights = f.NumberFlights;
			NumberPassengers = f.NumberPassengers;
		}
		return *this;
	}

	// перегрузка Оператора перемещения присваивания
	Airplane& operator=(Airplane&& moved) noexcept
	{
		if (this != &moved)
		{
			NumberFlights = moved.NumberFlights);
			NumberPassengers = moved.NumberPassengers);
			moved.NumberFlights.clear();
			moved.NumberPassengers = 0;
		}
		return *this;
	}

	// Деструктор
	~Airplane()
	{

	}

	// метод вывода информации о рейсах в консоль
	void print()
	{
		cout << "Номер рейса: " << NumberFlights << "\tКол-во пассажиров: " << NumberPassengers << endl;
	}


};


int main()
{
	setlocale(LC_ALL, "Rus");

	// Создание двух рейсов через конструктор с параметрами (f) - Название рейса - Кол-во пассажиров
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
	else if (f1 < f2)
	{
		cout << "Рейс Dp 550 может взять на борт больше пассажиров" << endl;
	}
	else
	{
		cout << "Рейс Dp 550 может взять на борт столько же пассажиров сколько рейс Su 1093" << endl;
	}

	cout << endl;
	// Создание объектов f3 f4 на основе объектов f1 f2 через конструктор копирования
	Airplane f3{ f1 };
	Airplane f4{ f2 };
	// вывод информации о рейсах:
	f3.print();
	f4.print();


	cout << endl;
	// Создание объектов f5 f6 на основе объектов f1 f2 через конструктор перемещения
	Airplane f5 = move(f1);
	Airplane f6 = move(f2);
	// вывод информации о рейсах:
	f5.print();
	f6.print();

	cout << endl;
	cout << "Проверка, что перемещение удалось f1, f2 после перемещения:" << endl;
	f1.print();
	f2.print();

	return 0;
}

