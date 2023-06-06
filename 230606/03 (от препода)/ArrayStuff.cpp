#include <iostream>
#include <time.h>
using namespace std;

int RandInt(int min, int max)
{
	return min + rand() % (max - min) + 1;
}

void FillArray(int* ar, int size, int min = 1, int max = 100)
{	
	for (int i = 0; i < size; i++)
	{
		ar[i] = RandInt(min, max);
	}
}

void ShowArray(int* ar, int size)
{
	for (int i = 0; i < size; i++)
		cout << ar[i] << " ";
	cout << endl;
}