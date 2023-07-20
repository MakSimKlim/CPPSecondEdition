#include <iostream>
#include "Array.h"
using namespace std;

class Date
{
	int day;
	int month;
	int year;
public:
	Date(int dayP, int monthP, int yearP): day {dayP}, month{monthP}, year{yearP}
	{}

	Date(int year) : Date{ 1, 1, year }
	{}

	friend void displayDate(Date date);
};

void displayDate(Date date)
{
	cout << date.day << "." << date.month << "." << date.year << endl;
}

Date baseDate()
{
	return 2000;
}

void int_to_dates()
{
	displayDate(2020);
	Date date = 2010;
	displayDate(date);
	Date bDate = baseDate();
	displayDate(bDate);
}

void display(const Array& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		arr.display(i);
	}
}

int main()
{
	int size = 4;
	Array ar(size);
	Array ar2{ size };
	Array ar3 = Array(size);
	for (int i = 0; i < size; i++)
	{
		ar.setAt(i, size - i);
	}
	display(ar);
	cout << "\nFor 3\n";
	display(3);
	return 0;
}