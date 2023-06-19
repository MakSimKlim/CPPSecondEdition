﻿// 230619_1
// 
// указатели (конструкция, которая хранит в себе адрес некой переменной, которую можно передавать, модифициировать и .т.д.)
// 
// указатели на функции
// 
// каждая ффункция - набор инструкций, котор хранися в памяти, у этого места есть адрес, к нему можно получить доступ и работать с ним через указатель
// 
// имя функции, тип функции, параметры - определение функции в с++
// 
// 
//

#include <iostream>
using namespace std;

int myF(char c)
{
	return (int)c;
}

void F1()
{
	cout << "F1\n";
}
void F2()
{
	cout << "F2\n";
}
char F1(char)
{

}
char F2(char)
{

}
void F3(char)
{

}
int* F4(char*)
{

}



int main()
{
	setlocale(LC_ALL, "Rus");
  
	//myF();
	cout << myF << endl; // адрес функции
	int (*fptr) (char);// так объявляется указатель на функцию  (*fptr)


	void(*ptr)();
	ptr = F2;
	(*ptr)();//разыменование указателя на функцию
	// *ptr() - ошибка т.к. сначала вызовется несуществующая ptr(), а затем будет разыменован её результат
	ptr = F1;
	(*ptr)();
	ptr();

	//=================================================================

	char(*ptr1)(int);
	char(*ptr2)(int);
	void(*ptr3)(float);


	pt1 = F1;//ошибка несоответствия сигнатур
	pt2 = F3;//ошибка несоответствия типов
	pt1 = F4;//несоответствие типов
	pt1 = F2;
	pt2 = pt1;
	char c = (*pt1)(44);
	c = (*pt2)('\t');





	return 0;


}

