#pragma once
class Array
{

	int size;
	int* arr;
public:
	explicit Array(int size = 10); // конструктор который будет вызыватьс€ €вно
	//Array(int size = 10); // конструктор который будет вызыватьс€ не€вно
	~Array();
	int getSize()const { return size; }
	int getAt(int index) const { return arr[index]; }
	void setAt(int index, int value) { arr[index] = value; }
	void display(int) const;
};

