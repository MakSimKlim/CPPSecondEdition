#include "NumberStorage.h"

NumberStorage::NumberStorage(uint32_t elementCountP) :
	storage{ new int[elementCountP] },
	elementCount{ elementCountP }
{
	uint32_t used{ elementCount * sizeof(int) };
	usedMemory += used;
	std::cout << used << " bytes of additional memory used. Total: ";
	showTotalMemory();

	for (int i = 0; i < elementCount; i++)
	{
		storage[i] = rand() % 100;
	}
}

void NumberStorage::show()
{
	for (int i = 0; i < elementCount; i++)
	{
		std::cout << storage[i] << " ";
	}
	std::cout << "\n";
}

NumberStorage::~NumberStorage()
{
	uint32_t freed{elementCount * sizeof(int)};
	delete[] storage;
	usedMemory -= freed;
	std::cout << "Freed " << freed << " bytes." << " Total used: ";
	showTotalMemory();
}

uint32_t NumberStorage::getTotalMemory()
{
	return usedMemory;
}

void NumberStorage::showTotalMemory()
{
	std::cout << usedMemory << " bytes"<< std::endl;
}

uint32_t NumberStorage::usedMemory{ 0 };