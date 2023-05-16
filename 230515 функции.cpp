// 230515
// 
// Функции 1 способ прописывания тип-имя-тело функции (всё над main)
// 
// Функции 2 способ прописывания - через прототип
//

#include <iostream>
#include <Windows.h>
#include <time.h>


using namespace std;

const int width = 10;//глобальные константы, в отличие от простых переменных можно так хранить


void Hello()
{
	cout << "Hello, World"<<"\n";
	return;                    //ничего не возвращает, но return можно писать, используется чтобы досрочно прекратить функцию
	//только для void можно не использовать return, в остальных функциях return нужен всегда
}

void Update()//ничего не возвращает
{


}

int GetNumber()
{
	cout << "Getting Number!";
	return 5;                  //здесь прерывается выполнение функции, после return происходит выход из функции
	cout << "Getting Number!"; //не выйдет на экран
}

// функция с параметрами
void StarLine(int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << '*';
	}
	cout << "\n";
}

// функция вывода символов
void SymbolLine(int count, char symbol)
{
	for (int i = 0; i < count; i++)
	{
		cout << symbol;
	}
	cout << "\n";
}


//передача по значениям 
int Count(int a, int b)//создаются новые переменные
{
	a = a * a;
	b = b * b;
	return a + b;
}

//внутри функции нельзя объявить функцию, но её можно вызвать
void Second()
{
	cout << "I'm SECOND!" << "\n";
}
void First() // здесь вызывается функция Second()
{
	cout << "Start First"<<"\n";
	Second();
	cout << "End First"<<"\n";
}

//функция вывода наибольшего значения
int Max(int a, int b)
{
	return a > b ? a : b;
}

void ShowArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << "\n";

}
//функция передачи массива
void Test(int arr[])
{
	arr[0] = 28;
}

//если в функции (int) - то кладется копия значения, но не с массивами, т.к. у массива передается адрес, а не значение!!
//поэтому, при передаче массива, при выходе из массива внутри функции значения в массиве остаются, т.к. это не копия а тот же самый массив!!!
//когда происходи передача перменной, сама переменная неизменяется, т.к. передается её копия в отличие от массива

int RandInt(int min, int max)
{
	return min + rand() % (max - min) + 1;
}
void InitArray(int arr[], int size)//когда объявляем функцию с аргументом в виде одинарного массива, то не обязательно прописывать кол-во строк и столбцов
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = RandInt(0, 100);
	}
}

//если работаем с двумерным массивом (количество столбцов должно быть всегда указано, строчек не важно)
void InitMatrix(int matrix[][width], int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; i++)
		{
			matrix[i][j] = RandInt(0, 20);

		}
	}
}

//Второй способ прописывания функции - прототип
void InitMatrix2(int matrix[][width], int height)// прототип функции

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Hello();

	cout << GetNumber() << "\n";
	cout << GetNumber() + 1 << "\n";

	StarLine(3);
	StarLine(5);

	cout << "\n";
	for (int i = 1; i < 5; i++)
	{
		StarLine(i);
	}

	cout << "\n";
	int a = 10;
	StarLine(a/2);

	cout << "\n";
	for (int i = 1; i < 5; i++)
	{
		SymbolLine(i, '@' + 1);// + 1 следующий символ по таблицам
	}

	cout << "\n";
	for (int i = 1; i < 5; i++)
	{
		SymbolLine(i, '#' + i);// + i следующий символ по таблицам 
	}

	cout << "\n";
	SymbolLine(5.5, '=');//выведет 5 знаков =

	cout << "\n";
	int x = 10, y = 5;
	cout << Count(6, 8) << "\n";
	cout << Count(x, y) << "\n";
	cout << x << " " << y << "\n";

	cout << "\n";
	First();//внутри функции объявлена функция Second
	Second();//функцию можно отдельно вызвать

	cout << "\n";
	cout << Max(3, 5) << "\n";

	//массив
	cout << "\n";
	int b = 1;
	cout << b << "\n";// вывод b

	const int size = 10;
	int arr[size] = { 1,2,3,4,5,6,7,8,9,0 };
	const int size2 = 12;
	int arr2[size2] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	cout << arr << "\n";//вывод адреса ячейки памяти массива!!!

	cout << "\n";
	ShowArray(arr, size);
	ShowArray(arr2, size2);

	cout << "\n";
	Test(arr);
	ShowArray(arr, size);

	cout << "\n";
	InitArray(arr,size);

	//объявление функции через прототип
	//const int height =5;
	//int matr[height][width]
	//	InitMatrix2

	return 0;

}

//функция с прототипом
void InitMatrix2(int matrix[][width], int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; i++)
		{
			matrix[i][j] = RandInt(0, 20);

		}
	}
}
