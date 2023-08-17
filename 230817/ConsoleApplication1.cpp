// 230823
// [] - оператор индексации (удобно для доступа к элементу массива), который можно перегрузить
// 


#include <iostream>
#include <cassert> // для assert - ключевое слово-макрос
using namespace std;

// перегрузка оператора [] синтаксис:
// ReturnType operator[](indexType index) const;
// ReturnType& operator[](indexType index);
// пример:
int& operator[](int); // индексировать можно хоть чем
int operator[](int) const;


// assert
int& Darray::operator[](int index)
{
	assert(index >= 0 and index < size and "Index is out of range!");// assert макрос проверяет условие на ложь
	return arr[index];
};
int DArray::operator[](int index) const
{
	assert(index >= 0 and index < size and "Index is out of range!");// assert макрос проверяет условие на ложь
	return arr[index];
};




int main()
{
	srand(time(0));
	Darray a{ 10 };
	a.randomize();
	a.print();
	cout << "\n" << a[0] << endl;
	cout << "\n" << a[-1] << endl; // assert выведет ошибку т.к.a < 0
	cout << "\n" << a[11] << endl; // assert выведет ошибку т.к.a > 10
	
    // вариант заполнения массива через функцию
	for (int i = 0; i < a.length(); i++)
	{
		cout << "a[" << i << "]" << a[i] << endl;
	}

	return 0;



}
