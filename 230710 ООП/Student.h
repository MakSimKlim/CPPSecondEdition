#pragma once
// сюда выносим все атрибуты и методы класса, как описание клаасса,
// реализация класса в Student.cpp куда записываем только методы с приставкой Student::
const int maxNameLength = 100;
class Student
{
private:
	//атрибуты класса (описание, память под них не выделена, она выделится в main, когда атрибуты появятся там):
	char name[maxNameLength];
	int amountLessons;
	bool* visits;      // посещаемость
	int* grades;       // оценки
	void ShowGrades();
	void ShowVisits();

public:
	Student();
	Student(char name[], int amountLessons);
	float Average();// прототип метода, вынесенного за класс
	void Show();
	const char* GetName();// мутатор
	void SetName(const char*);//мутатор
};

