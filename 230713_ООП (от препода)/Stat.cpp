#include <iostream>
#include <time.h>
#include "NumberStorage.h"
using namespace std;

int main()
{
	srand(time(0));
	cout << "Memory used: " << NumberStorage::getTotalMemory() << " bytes." << endl;
	const int count{ 5 };
	NumberStorage pool[count]{ 1+rand() % 16, 1 + rand() % 16, 1 + rand() % 16, 1 + rand() % 16, 1 + rand() % 16 };
	cout << "Currently, NumberStorage occupies: ";
	NumberStorage::showTotalMemory();

	for (int i = 0; i < count; i++)
	{
		pool[i].show();
	}

	return 0;
}