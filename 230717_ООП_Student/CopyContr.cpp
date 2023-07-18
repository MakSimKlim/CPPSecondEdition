#include <iostream>
#include <time.h>
using namespace std;

class Fraction
{
	uint32_t numerator;
	uint32_t denominator;	
public:
	Fraction(uint32_t num, uint32_t denom):
		numerator {num}, denominator{denom}
	{
		cout << "Fraction constructed for " << this << "\n";
	}

	Fraction() : Fraction(1, 1) {}

	//<имя класса>(const <имя класса>& <имя параметра>)
	Fraction(const Fraction& obj):
		numerator{obj.numerator},
		denominator{obj.denominator}
	{
		cout << "Fraction copied for " << this << "\n";
	}

	void print()
	{
		cout << "(" << numerator << "/" << denominator << ")";
	}

	~Fraction(){ cout << "Fraction destroyed for " << this << "\n"; }
};

class DynArray {
	int* arr;
	int size;
public:
	DynArray(int sizeP) : arr{ new int[sizeP] {} }, size{ sizeP }
	{
		cout << "DynArr constructed for " << size << " elements at " << this << endl;
	}
	DynArray() : DynArray{ 5 } {};
	//DynArray(const DynArray& object) : arr{ object.arr }, size{ object.size }
	DynArray(const DynArray& object) : arr{ new int[object.size] {} }, size{ object.size }
	{
		for (int i = 0; i < size; i++)
			arr[i] = object.arr[i];
		cout << "DynArr copied at " << this << endl;
	}

	int getAt(int index) { return arr[index]; }
	void setAt(int index, int value) { arr[index] = value; }
	void print()
	{
		for (int i = 0; i < size; i++)
			cout << arr[i] << " ";
	}
	void randomize()
	{
		for (int i = 0; i < size; i++)
			arr[i] = rand() % 100;
	}

	~DynArray()
	{
		delete[] arr;
		cout << "DynArr destroyed at " << this << endl;
	}
};

void fraction()
{
	Fraction a{ 2, 3 };
	Fraction b;
	Fraction c{ a }; //c.numerator {a.numerator}, c.denominator{a.denominator};
	Fraction d{ Fraction(1, 4) };//происходит элизия и вызывается конструктор на строчке 9
	a.print(); cout << endl;
	b.print(); cout << endl;
	c.print(); cout << endl;
}

void foo(DynArray d)
{	
	//По возможности, избегайте копирования объектов
	//foo(const DynArray* d)
	//foo(const DynArray& d)
}

int main()
{
	srand(time(0));
	DynArray ar1{ 8 };
	ar1.randomize();
	cout << "Ar1: ";
	ar1.print(); cout << endl;	

	DynArray ar2{ ar1 };	
	ar1.setAt(0, 0);
	cout << "Ar1 with 0: ";
	ar1.print(); cout << endl;
	cout << "Ar2: ";
	ar2.print(); cout << endl;
	foo(ar2);//Здесь создаётся копия ar2 под названием d в функции foo
	return 0;
}