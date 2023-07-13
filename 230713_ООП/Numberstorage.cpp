#include "Numberstorage.h"

Numberstorage::Numberstorage(uint32_t elementCountP)

storage {new int[elementCountP] };

elementCount{ elementCountP }
	{
		uint32_t used{ elemebtCount * sizeof(int) };
		usedMemory += used;
		std::cout << used << "bytes of additional memory used. Total: " << std::endl;
		showTotalMemory();

	}

// ...

{
	uint32_t used{ elemebtCount * sizeof(int) };
	usedMemory -= freed;
	std::cout << "Freed" << freed<< "bytes. " << "Total used: " << std::endl;
	showTotalMemory();

}

uint32_t Numberstorage::getTotalMemory()
{
	return usedMemory;
}

void Numberstorage::showTotalMemory()
{
	std::cout << usedMemory << " bytes" << std::endl;
}

uint32_t Numberstorage::usedMemory{ 0 };
