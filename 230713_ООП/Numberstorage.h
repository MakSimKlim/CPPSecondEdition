#pragma once
#include <iostream>

class Numberstorage
{
	int* storage;
	uint32_t elementCount;
	static uint32_t usedMemory;

public:
	Numberstorage(uint32_t elementCountP);
	void show();
	~Numberstorage();

	static void showTotalMemory();
	static uint32_t getTotalMemory();


};

