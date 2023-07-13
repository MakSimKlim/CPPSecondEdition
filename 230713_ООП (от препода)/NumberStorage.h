#pragma once
#include <iostream>

class NumberStorage
{
	int* storage;
	uint32_t elementCount;
	static uint32_t usedMemory;

public:
	NumberStorage(uint32_t elementCountP);	
	void show();
	~NumberStorage();

	static void showTotalMemory();
	static uint32_t getTotalMemory();
};

