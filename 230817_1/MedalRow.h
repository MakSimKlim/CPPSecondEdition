#pragma once
#include <iostream>
#include <cassert>
class MedalRow
{
	char oblast[5];
	int medals[3];
public:
	static const int GOLD{ 0 };
	static const int SILVER{ 1 };
	static const int BRONZE{ 2 };

	MedalRow(const char* oblastP, const int* medalsP)
	{
		memcpy_s(oblast, 5, oblastP ? oblastP : "NONE", 5);
		for (int i{ 0 }; i < 3; ++i)
		{
			medals[i] = medalsP ? medalsP[i] : 0;
		}
	}

	MedalRow() : MedalRow(nullptr, nullptr) {};

	MedalRow& setOblast(const char* oblastP)
	{
		if (oblastP)
		{
			memcpy_s(oblast, 5, oblastP, 5);
		}
		return *this;
	}

	const char* getOblast() const { return oblast; }

	int& operator[](int index)
	{
		assert((index >= 0 and index < 3) and "Index out of range!");
		return medals[index];
	}

	int operator[](int index) const
	{
		assert((index >= 0 and index < 3) and "Index out of range!");
		return medals[index];
	}

	void print() const
	{
		std::cout << "[" << oblast << "]-(";
		for (int i{ 0 }; i < 3; ++i)
		{
			std::cout << medals[i];
			if (i < 2) std::cout << "\t";
		}
		std::cout << " )\n";
	}
};

