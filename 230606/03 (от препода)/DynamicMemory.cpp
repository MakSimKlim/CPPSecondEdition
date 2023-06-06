#include <iostream>
#include <time.h>
#include "ArrayStuff.h"
using namespace std;

void newdelete()
{
	//указатель_на_тип = new имя_типа (Инициализатор)
	int* ip = new int;//создаётся безымянный динамический объект

	//int* other = ip;

	*ip = 78;
	cout << *ip << endl;
	int i = 0;
	ip = &i;//доступ к объекту можно потерять

	int* ip2 = new int(3);
	cout << *ip2;

	int Size;
	cin >> Size;
	double* mas = new double[Size];
	mas[0] = 0.5;

	if (ip) {
		delete ip;
		ip = nullptr;
	}
	//Если выделили динамически память, с помощью слова delete её нужно очистить
	delete ip2;
	delete[] mas;
}

template <typename T>
void unite(T* a, int sizeA, T* b, int sizeB, T* c);

void UniteArrays()
{
	int sizeA, sizeB;
	cout << "Enter sizes: ";
	cin >> sizeA >> sizeB;
	int* a = new int[sizeA];
	int* b = new int[sizeB];
	FillArray(a, sizeA);
	cout << "A: ";
	ShowArray(a, sizeA);
	FillArray(b, sizeB);
	cout << "B: ";
	for (int i = 0; i < sizeB; i++)
		cout << b[i] << " ";
	cout << endl;


	int* c = new int[sizeA + sizeB];
	unite(a, sizeA, b, sizeB, c);
	ShowArray(c, sizeA + sizeB);
	delete[] a, b, c;
}

template <typename T>
T* append(T* a, int& size, T toAdd)
{
	T* newAr = new T[size + 1];
	for (int i = 0; i < size; i++)
		newAr[i] = a[i];
	newAr[size] = toAdd;
	delete[] a;
	a = newAr;
	size++;
	return newAr;
}

template <typename T> T* deleteNegatives(T* a, int size, int& newSize);

template <typename T> void addBlockToEnd(T*& a, int& size, T* toAdd, int sizeToAdd);

template <typename T> void insertAt(T*& a, int& size, T toAdd, int addIndex);

void AddToEnd()
{
	int sizeA;
	cout << "Enter size: ";
	cin >> sizeA;
	int* a = new int[sizeA];	
	FillArray(a, sizeA);
	cout << "A: ";
	ShowArray(a, sizeA);

	int toAdd;
	cout << "Enter element to add: ";
	cin >> toAdd;
	a = append(a, sizeA, toAdd);
	ShowArray(a, sizeA);
}

void DeleteNegatives()
{
	int sizeA;
	cout << "Enter size: ";
	cin >> sizeA;
	int* a = new int[sizeA];
	FillArray(a, sizeA, -100, 100);
	cout << "A: ";
	ShowArray(a, sizeA);

	int newSize;
	int* a_p = deleteNegatives(a, sizeA, newSize);
	ShowArray(a_p, newSize);
}

void AddBlockToEnd()
{
	int sizeA;
	cout << "Enter size: ";
	cin >> sizeA;
	int* a = new int[sizeA];
	FillArray(a, sizeA);
	cout << "A: ";
	ShowArray(a, sizeA);

	const int sizeToAdd = 3;
	int b[sizeToAdd];
	FillArray(b, sizeToAdd);
	cout << "Add: ";
	ShowArray(b, sizeToAdd);

	addBlockToEnd(a, sizeA, b, sizeToAdd);
	cout << "New A: ";
	ShowArray(a, sizeA);
}

void AddElementAt()
{
	int sizeA;
	cout << "Enter size: ";
	cin >> sizeA;
	int* a = new int[sizeA];
	FillArray(a, sizeA);
	cout << "A: ";
	ShowArray(a, sizeA);

	int toAdd, indexToAdd;
	cout << "Enter element to add: ";
	cin >> toAdd;
	cout << "Enter index at which to add: ";
	cin >> indexToAdd;

	insertAt(a, sizeA, toAdd, indexToAdd);
	cout << "New A: ";
	ShowArray(a, sizeA);
}

int main()
{
	srand(time(NULL));
	AddElementAt();
} 
/*
* Даны два массива A и B размеров sizeA и sizeB. 
* Создать массив минимального возможного размера, в котором будут элементы
* обоих массивов.
*/
template <typename T>
void unite(T* a, int sizeA, T* b, int sizeB, T* c)
{
	for (int i = 0; i < sizeA; i++)
		c[i] = a[i];
	for (int i = 0; i < sizeB; i++)
		c[sizeA + i] = b[i];
}
/*
* Написать функцию, которая получает указатель на динамический массив и его размер.
* Функция должна удалить из массива все отрицательные числа и вернуть 
* указатель на новый динамический массив
*/
template <typename T>
T* deleteNegatives(T* a, int size, int& newSize) 
{
	int amountOfNeg = 0;
	for (int i = 0; i < size; i++)
		amountOfNeg += a[i] < 0 ? 1 : 0;
	newSize = size - amountOfNeg;
	T* newAr = new T[newSize];
	int k = 0;
	for (int i = 0; i < size; i++)
		if (a[i] >= 0)
			newAr[k++] = a[i];
	return newAr;
}
/*
*  Создать функцию, позволяющую добавлять блок элементов в конец массива
*/
template <typename T>
void addBlockToEnd(T*& a, int& size, T* toAdd, int sizeToAdd)
{
	T* newAr = new int[size + sizeToAdd];
	for (int i = 0; i < size; i++)
		newAr[i] = a[i];
	for (int i = 0; i < sizeToAdd; i++)
		newAr[i + size] = toAdd[i];
	delete[] a;
	a = newAr;
	size += sizeToAdd;
}

/*
* Создать функцию, позволяющую добавлять новый элемент на указанный индекс массива.
*/
template <typename T> void insertAt(T*& a, int& size, T toAdd, int addIndex)
{
	T* newAr = new int[size + 1];
	for (int i = 0; i < addIndex; i++)
		newAr[i] = a[i];
	newAr[addIndex] = toAdd;
	for (int i = addIndex; i < size; i++)
		newAr[i + 1] = a[i];
	delete[] a;
	a = newAr;
	size++;
}