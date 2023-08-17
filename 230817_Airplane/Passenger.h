#pragma once
#include <iostream>
#include "Airplane.h"

class Passenger
{
	char name[10];// имя
	int sit[200];// номер места
public:
	Passenger(const char* nameP, const int* sitP)
	{
		memcpy_s(name, 5, nameP ? nameP : "NONE", 10);
		for (int i{ 0 }; i < 200; ++i)
		{
			sit[i] = sitP ? sitP[i] : 0;
		}
	}

	Passenger() : Passenger(nullptr, nullptr) {};

	Passenger& setName(const char* nameP)
	{
		if (nameP)
		{
			memcpy_s(name, 10, nameP, 10);
		}
		return *this;
	}
	const char* getName() const { return name; }

};

