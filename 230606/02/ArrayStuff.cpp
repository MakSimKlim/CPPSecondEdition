#include <iostream>
#include <time.h>
using namespace std;

int RandInt(int min, int max)
{
	return min + rand() % (max - min) + 1;
}

void FillArray(int* ar, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		ar[i] = RandInt(-100, 100);
	}
}

void ShowArray(int* ar, int size)
{
	for (int i = 0; i < size; i++)
		cout << ar[i] << " ";
	cout << endl;
}