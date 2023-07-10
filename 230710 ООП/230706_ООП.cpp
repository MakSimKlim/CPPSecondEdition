﻿// 230706_ООП
// Объект ООП - это экземпляр класса
// ООП - описание какого-то объекта, который имеет какие-то свойства, которые его описывают и методы, которые он умеет производить
// объекты взаимодействуют друг с другом с помощью методов.
// отличие от процедурного программирования (функции - это процедуры) в правилах написания ООП программ
// 
// ==============================================================================================================================================================================
// 
// принципы ООП:
// полиморфизм, наследование, инкапсуляция
//
// Инкапсуляция - св-во класса, по которому детали реализации класса недоступны для других частей системы
// мы знаем, что получим в итоге, но не знаем как это работает (скрытие методы)
// программа разбивается на модули (мы не знаем из чего они состоят) - экземпляры (объекты класса)
// может быть несколько объектов одного типа, которые не мешают друг другу (никак не влияют на друг друга)
// public, private - методы класса (private - это инкапсуляция). Сокрытие деталей
// 
// Наследование - вид отношений между классами, при котором один класс, повторяет структуру и поведение другого класса или классов
// Есть родительский класс от него производный (дочерний или подкласс), который наследует реализацию от родительского
// он можкет добавить свои методы или измненить существующие от родителького.
// особенность наследования - повторное использование кода от родительского класса
// (например транспорт - родительский класс. Лодка, машина, самолет - дочерний класс, имеют общие атрибуты и методы )
// но при этом они отличаются дополнительными особенными методами, например лодка может попасть только в места где есть реки (вода)
// следовательно класс лодки помимо основных атрибутов будет дополнена информацией по ограничению движения по воде к определенным населенным пунктам
// То же самое и с самолетом и машиной. Т.О. наследники могут дополнять родительский класс
// Пример наследования: наследование от класса Табуретка с методом сидеть, дочерний класс стул наследует метод сидеть, но добавляет свой - облокатиться на спинку
// Изменив родительский класс, изменятся и все наследники класса (основное преимущество наследования). Наследование одного класса от другого
// 
// Полиморфизм - происходит от наследования и поддерживает инкапсуляцию
// возможность применения одноименных методов в одном или нескольких классах, которые являются наследниками базового класса
// Пример: реализация Урона в играх (все персонажи наследуются от класса персонаж, они все могут получать урон). например разные персонажи с разными методами и свойствами
// имеют общее Здоровье и есть метод Урон, который по разному наносится урон (разные реализации метода получить урон, для всех вызывается одинаковый метод получить урон)
// Позволяет использовать наследников класса, вызывая одинаковые мотоды.
// 
// ==============================================================================================================================================================================
// 
// Класс и объект.
// В ООП: все переменные  - экземляры (объекты) класса
// класс - комбинация известных типов переменных
// класс - шаблон для создания объекта класса
// 
 // 
 /*
 Синтаксис:

  class имя_класса
  {
      модификаторы доступа:
      public: (доступ откуда угодно для кого угодно), 
      private: (доступ закрыт для всех, даже для наследников, доступ есть только внутри класса), 
      protected: (доступ открыт только для наследников (для них доступ как public))
	 !без модификатора - атрибуты по умолчанию будут в private

      Здесь же находятся атрибуты (переменные или поля) класса

      тип_поля имя_поля;

  }x; // x - можно создать дефолтный объект класса таким образом, который может быть записан по принципу как в структурах после скобок до ;
 
  имя_класса имя_переменной(атрибута) // это запись экземпляра класса

  доступ к атрибутам объекта:
  имя_объекта.название_поля


 */
// классы всегда перед main()
// можно включать классы с помощью #include<...> 
// по умолчанию всё, что не имеет отношения к взаимодействию, должно быть скрыто, поэтому по умолчанию присваивается объектам private
// всё что под модификатором после : и до следующего модификатора или до конца функции - действует для этого модификатора доступа
// конструктор всегда должен быть public
// Внутри методов можно обращаться не только к создаваемым переменным, но и к атрибутам их собственного класса через :: (название_класса::) чтобы не возникала двусмысленность 
// ==============================================================================================================================================================================
//
// ключевое слово inline рекомендует произвести процедуру встраивания куска кода (не работает на ыункциях с рекурсией, т.к. рекурсивная функция не может превратиться в встроенную)
// функция внутри класса становится inline
// как правило инлайн (встроенными) оставляют мутаторы и абсцессоры, все остальное выносят за класс
// 
// в структуре всё по умолчанию - public, в классе - private. Это главное их отличие
// ==============================================================================================================================================================================
//
// КОНСТРУКТОР - метод
//

#include <iostream>
using namespace std;

// вариант записи  на структурах

struct Student
{
	char name[50];     // имя
	int amountLessons; // количество уроков
    int* grades;       // оценки
	bool* visits;      // посещаемость
};


Student createStudent(char name[], int amountLessons)
{
	Student res;
	memcpy_s(res.name, 50, name, 50);
	res.amountLessons = amountLessons;
	for (int i = 0; i < amountLessons; i++)
	{
		cout << "Lesson " << i + 1 << endl;
		cout << "Enter 0 if student skipped this lesson, and 1 if not: ";
		cin >> res.visits[i];
		cout << "Enter grade for class" << i + 1 << ": ";
		cin >> res.grades[i];
	}
	return res;
}

float average(Student s)// функция вычисления средней оценки
{
	float sum = 0;
	for (int i = 0; i < s.amountLessons; i++)
	{
		sum += s.grades[i];
	}
	return sum / s.amountLessons;
}

void show(Student s)// функция вывода значений
{
	cout << s.name << ": ";
	for (int i = 0; i < s.amountLessons; i++)
	{
		cout << s.grades[i] << " ";
	}
	cout << "\n\t";
	for (int i = 0; i < s.amountLessons; i++)
	{
		if (s.visits[i])
		{
			cout << " ";
		}
		else
		{
			cout << "H";
		}
		cout << " ";
	}
	cout << "\n\n";
}

int main()
{  
	setlocale(LC_ALL, "Rus");





	return 0;
}

