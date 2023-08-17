#pragma once
#include<iostream>
#include <cassert> // для assert - ключевое слово-макрос
#include <cassert>


class MedalRow
{
	// заводим 4 области
	char oblast[5]; // 5й символ для /0 - символ окончания строки
	int medals[3];

public:
	static const int GOLD{ 0 }; // static чтобы int не создавался для каждого экземпляра класса
	static const int SILVER{ 1 };
	static const int BRONZE{ 2 };

	MedalRow(const char* oblastP, const int* medalsP)
	{
		memcpy_s(oblast, 5, oblastP ? oblastP : "NONЕ", 5); // копируем из oblast в oblastP и проверяем на доступность
		for (int i{0}; i < 3; i++)
		{
			medals[i] = medalsP ? medalsP[i] : 0;
		}
	}

	// конструктор по умолчанию
	MedalRow() : MedalRow(nullptr, nullptr) {};

	MedalRow& setOblast(const char* oblastP)
	{
		if (oblastP)
		{
			memcpy_s(oblast, 5, oblastP, 5);
		}
		return *this;// чтобы делать цепочки
	}
	const char* getOblast() const { return oblast; }
	 
	// перегрузка []
	int& operator[](int index)
	{
		assert((index >= 0 and index < 3) and "Index is out of range!");// assert макрос проверяет условие на ложь
		return medals[index];
	}
	int operator[](int index) const
	{
		assert((index >= 0 and index < 3) and "Index is out of range!");// assert макрос проверяет условие на ложь
		return medals[index];
	}

	// метод вывода результатов
	void print() const
	{
		std::cout << "[" << oblast << "]-(";
		for (int i{ 0 }; i < 3; i++)
		{
			std::cout << medals[i];
			if (i < 2) std::cout << "\t";
		}
		std::cout << ")\n";
	}
};

