// 230606_2(задачи на динамический массив)
//
// 1). Написать функцию, которая получает указатель на динамический массив и его размер.
//     Функция должна удалить из массива все отрицательные числа и вернуть
//     указатель на новый динамический массив
// 
// 2). Создать функцию, позволяющую добавлять блок элементов в конец массива
// 
// 3). Создать функцию, позволяющую добавлять новый элемент на указанный индекс массива
//

#include <iostream>
#include <time.h>
#include "ArrayStuff.h"

using namespace std;



int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int size;
	cout << "Введите размер массива: " << "\n";
	cin >> size;
	int* dynArr = new int[size];
	FillArray(dynArr, size);
	ShowArray(dynArr, size);
	delete[] dynArr;
	cout << endl;




}

