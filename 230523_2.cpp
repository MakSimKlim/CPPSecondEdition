// 230523_2
//
// Найти максимум трёхмерного массива с использованием шаблона

#include <iostream>
#include <Windows.h>
#include <math.h>
#define CUBE_SIZE 3 //вместо записи: const int cube_size = 10;

using namespace std;

template <typename T>
T maxIn3D(T ar[][CUBE_SIZE][CUBE_SIZE])
{
	int max = ar[0][0][0];
	for (int i = 0; i < CUBE_SIZE; i++)// цикл с нуля, т.к. начинаем с нулевого элемента
	{
		for (int j = 0; j < CUBE_SIZE; j++)
		{
			for (int k = 0; k < CUBE_SIZE; k++)
			{
				if (max < ar[i][j][k])
				{
					max = ar[i][j][k];
				}
			}
		}
	}
	return max;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int cube [CUBE_SIZE][CUBE_SIZE][CUBE_SIZE] = {
		{ {1,2,3} , {4,5,6} , {7,8,9} } , 
		{ {10,11,12} , {13,14,15} , {16,17,18} } , 
		{ {19,20,21} , {22,23,24} , {25,26,27} } 
	};

	cout << "Max of cube: " << maxIn3D(cube) << "\n";


	return 0;
}
