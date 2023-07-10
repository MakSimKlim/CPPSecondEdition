#include "Student.h"
#include <iostream>

using namespace std;

// класс вынесен в несколько файлов с помощью добавления нового элемента "класс"

//float Student::Average() // вынесенный метод за класс
//{
//	float sum = 0;
//	for (int i = 0; i < Student::amountLessons; i++)
//	{
//		sum += Student::grades[i];
//	}
//	return sum / Student::amountLessons;
//}
//

int main()
{
	setlocale(LC_ALL, "Rus");

	char name[] = "Antony";
	
	int amountClasses = 3;
	
	// st имя класса Student
	Student st = Student(name, amountClasses); // Student(name, amountClasses); - вызов конструктора класса
	//Student st{ name, amountClasses }; // вариант записи вызова конструктора класса
	
	st.Show(); // вызов метода Show от имени st
	cout << "Average grade: " << st.Average() << endl;// вызов метода Average от имени st

	cout << st.GetName() << endl;// метод смены имени с помощью мутатора
	char name2[] = "Mary";
	st.SetName(name2);
	st.Show();
	
	return 0;
}
