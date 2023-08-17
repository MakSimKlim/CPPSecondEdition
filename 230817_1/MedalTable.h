#pragma once
#include "MedalRow.h"

class MedalTable
{
public:
	static const int maxSize = 10;
private:
	MedalRow medalRows[maxSize];
	int size;
	int findOblast(const char* oblast) const
	{
		for (int i{ 0 }; i < size; i++)
		{
			if(strcmp(medalRows[i].getOblast(), oblast) == 0)
			{
				return i;
			}
		}
		return -1;
	}
public:
	MedalTable() : size{ 0 } {};
	MedalRow& operator[] (const char* oblast)
	{
		int index{ findOblast(oblast) };
		if (index == -1)
		{
			assert(size < MedalTable::maxSize and "Table is full!");
			index = size++;
			medalRows[index].setOblast(oblast);
		}
		return medalRows[index];
	}
	const MedalRow& operator[](const char* oblast) const
	{
		int index{ findOblast(oblast) };
		assert(index != -1 and "Oblast not found!");
		return medalRows[index];
	}

	void print() const
	{
		for (int i{ 0 }; i < size; i++)
		{
			medalRows[i].print();
		}
	}
};

