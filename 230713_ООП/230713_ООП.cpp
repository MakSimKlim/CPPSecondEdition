// 230713_ООП
//
// статические методы (их вызов аналогичен вызову статических полей)
// они должны использовать статические атрибуты класса

#include <iostream>
#include <time.h>
#include "Numberstorage.h"

using namespace std;

int main()
{
	srand(time(0));
	cout << "Memory used:" << Numberstorage::getTotalMemory() << " bytes. " << endl;
	const int count{5};
	Numberstorage pool [count]{ 1 + rand() % 16 ,1 + rand() % 16 ,1 + rand() % 16 ,1 + rand() % 16 ,1 + rand() % 16 };
	cout << "Currently Numberstorage occupes: ";
	Numberstorage::showTotalMemory(); // вызов статического метода
	
	for (int i = 0; i < count; i++)
	{
		pool[i].show();
	}

	return 0;
}

