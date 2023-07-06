#include <iostream>
using namespace std;

// вариант записи студента на классах
// 

const int maxNameLength = 50;

class Student
{
private:
	//атрибуты класса:
	char name[maxNameLength];
	int amountLessons;
	bool* visits;      // посещаемость
	int* grades;       // оценки

public:
	// конструктор
	Student()
	{
		memcpy_s(Student::name, maxNameLength, "None", 5);
		Student::amountLessons = 0;
		Student::visits = new bool[0];
		Student::grades = new int[0];
	}
	// конструктор
	Student(char name[], int amountLessons)
	{
		memcpy_s(Student::name, maxNameLength, name, maxNameLength);// функция копирования памяти, присваивание строчек
		Student::amountLessons = amountLessons;
		Student::visits = new bool[amountLessons];
		Student::grades = new int[amountLessons];
		for (int i = 0; i < amountLessons; i++)
		{
			cout << "Lesson " << i + 1 << endl;
			cout << "Enter 0 if student skipped this lesson, and 1 if not: ";
			cin >> Student::visits[i];
			cout << "Enter grade for class" << i + 1 << ": ";
			cin >> Student::grades[i];
		}
	}
	// методы класса:
	float Average() // метод подсчета средней оценки
	{
		float sum = 0;
		for (int i = 0; i < Student::amountLessons; i++)
		{
			sum += Student::grades[i];
		}
		return sum / Student::amountLessons;
	}

	void Show() // метод вывода значений
	{
		cout << Student::name << ": ";
		Student::ShowGrades();
		cout << "\n\t";
		Student::ShowVisits();
		cout << "\n\n";
	}

private:
	void ShowGrades()
	{
		for (int i = 0; i < Student::amountLessons; i++)
		{
			cout << Student::grades[i] << " ";
		}
	}

	void ShowVisits()
	{
		for (int i = 0; i < Student::amountLessons; i++)
		{
			if (Student::visits[i])
			{
				cout << " ";
			}
			else
			{
				cout << "H";
			}
			cout << " ";
		}
	
	}
};


int main()
{
	setlocale(LC_ALL, "Rus");

	char name[] = "Antony";
	
	int amountClasses = 3;
	
	// st имя класса Student
	Student st = Student(name, amountClasses); // Student(name, amountClasses); - вызов конструктора класса
	//Student st{ name, amountClasses }; // вариант вызова конструктора класса
	
	st.Show(); // вызов метода Show от имени st
	cout << "Average grade: " << st.Average() << endl;// вызов метода Average от имени st
	
	return 0;
}
