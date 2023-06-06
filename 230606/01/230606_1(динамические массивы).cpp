// 230606_1(динамические массивы)
//
// new - оператор который позволяет динамически выделить память на этапе выполнения программы
// ему нужно только указать указатель на тип

#include <iostream>
#include "ArrayStuff.h"

using namespace std;

void newdelete()
{
	// указатель_на_тип = new имя_типа (инициализатор) // инициализатор необязателен
	int* ip = new int; // к безымянному объекту можно обратиться только через указатели

	int* other = ip;

	*ip = 78;
	cout << *ip;
	int i = 0;
	ip = &i; // доступ к объекту можно потерять
	// объект будет существовать до конца программы, но мы потеряли к нему доступ (мусор), он занимает место в памяти
	// это одна из разновидностей утечки памяти

	int* ip2 = new int(3);
	cout << "\nip2\n" << ip2;
	cout << endl;

	// выделение динамической памяти для массивов
	int Size;
	cin >> Size;
	double* mas = new double[Size];
	mas[0] = 0.5;

	// очищение памяти лучше делать так, чтобы не удалить случайно несколько раз удаленный указатель, а это неопределенность, т.е. ПЛОХО
	if (ip)
	{
		delete ip;
		ip = nullptr;
	}
	// на каждый new нужен свой delete 

	// нехорошее очищение памяти, может возникнуть неопределенность, если случайно удалить удаленное
	delete ip;
	delete ip2;
	delete[] mas;



}

//// шаблон функции для добавления элемента в массив 
//template <typename T>
//void append(T*& a, int& size, T toAdd)
//{
//	T* newAr = new T[size + 1];
//	for (int i = 0; i < size; i++)
//	{
//		newAr[i] = a[i];
//	}
//	newAr[size] = toAdd;
//	delete[] a;
//	a = newAr;
//	size++;
//}
//
//// функция добавления элемента в массив
//void AddToEnd()
//{
//	int sizeA;
//	cout << "Enter size2: ";
//	cin >> sizeA;
//	int* a = new int[sizeA];
//	FillArray(a, sizeA);
//	cout << "A=";
//	ShowArray(a, sizeA);
//
//	int toAdd;
//	cout << "Enter element to add: ";
//
//	// недописана
//
//}

int main()
{
	setlocale(LC_ALL, "Rus");

	int size;
	int* dar;

	cout << "Enter size: ";
	cin >> size;

	dar = new int[size];
	FillArray(dar, size);
	ShowArray(dar, size);
	delete[] dar;
	cout << endl;


	// Даны два массива А и В размеров sizeA и sizeB
	//Создать массив минимального возможного размера, в котором будут элементы обоих массивов

	int const sizeA = 5;
	int const sizeB = 7;
	int arr[sizeA];
	int brr[sizeB];
	FillArray(arr, sizeA);
	ShowArray(arr, sizeA);
	cout << endl;
	FillArray(brr, sizeB);
	ShowArray(brr, sizeB);
	cout << endl;

	int sizeAB = sizeA + sizeB;
	int* abrr;
	abrr = new int [sizeAB];

	for (int i = 0; i < sizeA; i++)
	{
		abrr[i] = arr[i];
	}
	for (int i = 0; i < sizeB; i++)
	{
		abrr[sizeA + i] = brr[i];
	}
	ShowArray(abrr, sizeAB);
	delete[] abrr;
	cout << endl;


	//AddtoEnd();


	return 0;
}

