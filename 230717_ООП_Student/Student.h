#pragma once
#include <iostream>

/*
* Реализуйте класс “Студент”. Необходимо хранить в переменных-членах класса:
	ФИО,
	дату рождения (для неё надо создать отдельный класс "Дата"),
	контактный телефон,
	город,
	факультет,
	номер группы.
* Реализуйте функции-члены класса для ввода данных, вывода данных,
* реализуйте set и get функции для доступа к отдельным переменным-членам.
* Реализуйте ряд конструкторов с использованием делегирования конструкторов.
* Заведите статические поля и методы, которые отслеживают количество студентов.
*/

class Student
{
	char* Name;
	char* SecondName;
	char* Patronym;
	uint64_t Phone;
	char* City;
	char* Faculty;
	uint32_t GroupNum;
	Date Birthdate;
	static int studentCount;
public:
	Student(const char* nameP,
		const char* secondNameP,
		const char* patronymP,
		uint64_t phoneP,
		const char* cityP,
		const char* facultyP,
		uint32_t groupP,
		Date birthDateP);

	Student(const char* nameP,
		const char* secondNameP,
		const char* patronymP,
		const char* cityP,
		const char* facultyP,
		uint32_t groupP,
		Date birthDateP);

	Student(const char* nameP,
		const char* secondNameP,
		const char* patronymP,
		const char* cityP,
		uint32_t groupP,
		Date birthDateP);

	Student();

	int GetCount() {
		return studentCount;
	};

	char* GetName()
	{
		return Name;
	};
	void SetName(const char* nameP)
	{
		memcpy_s(Name, strlen(nameP) + 1, nameP, strlen(nameP) + 1);
	};

	char* GetSecondName()
	{
		return SecondName;
	};
	void SetSecondName(const char* secondNameP)
	{
		memcpy_s(SecondName, strlen(secondNameP) + 1, secondNameP, strlen(secondNameP) + 1);
	};

	char* GetPatronym()
	{
		return Patronym;
	};
	void SetPatronym(const char* patronymP)
	{
		memcpy_s(Patronym, strlen(patronymP) + 1, patronymP, strlen(patronymP) + 1);
	};

	char* GetCity()
	{
		return City;
	};
	void SetCity(const char* cityP)
	{
		memcpy_s(City, strlen(cityP) + 1, cityP, strlen(cityP) + 1);
	};

	char* GetFaculty()
	{
		return Faculty;
	};
	void SetCity(const char* facultyP)
	{
		memcpy_s(Faculty, strlen(facultyP) + 1, facultyP, strlen(facultyP) + 1);
	};

	void SetPhone(uint64_t phoneP)
	{
		Phone = phoneP;
	}
	uint64_t GetPhone()
	{
		return Phone;
	}

	void SetBirthDate(Date dateP)
	{
		Birthdate = dateP;
	}
	void SetBirthDate(uint8_t dayP, uint8_t monthP, uint16_t yearP)
	{
		Birthdate = Date{dayP, monthP, yearP};
	}
	Date GetBirthDate()
	{
		return Birthdate;
	}

	static int GetCount()
	{
		return studentCount;
	}

	~Student();
};

