#pragma once
#include <iostream>

class Date
{
	uint16_t day;
	uint16_t month;
	uint16_t year;
	int& currentYear;
	const int baseYear;

public:
	Date(uint16_t, uint16_t, uint16_t, int);
	Date();
	Date& SetDay(uint16_t d) /*dayP, _day = day*/
	{
		if(d >= 1 && d <= 31)
			day = d;
		return *this;
	};
	uint16_t GetDay() const { return day; }
	uint16_t GetDay() { std::cout << "not const method "; return day; }

	Date& SetMonth(uint16_t m)
	{
		if(m >= 1 && m <= 12)
			month = m;
		return *this;
	};
	uint16_t GetMonth() { return month; }
	Date& SetYear(uint16_t y)
	{
		year = y;
		return *this;
	};
	uint16_t GetYear() { return year; }

	//Date* const this
	void print(/*Date* const this*/)
	{
		std::cout << /*this->*/day << "." << month << "." << year;
	}

	~Date();
};

