#include <iostream>
#include "Student.h"

using namespace std;

// ���������� ������ Student ���� ���������� ������ ������ � ���������� Student::
// !!! ����������� - ��� ���� ����� ������  !!!

    // ����������� (�����)
    Student::Student()
	{
		memcpy_s(Student::name, maxNameLength, "None", 5);
		Student::amountLessons = 0;
		Student::visits = new bool[0];
		Student::grades = new int[0];
	}

	// ����������� (�����)
    Student::Student(char name[], int amountLessons)
	{
		memcpy_s(Student::name, maxNameLength, name, maxNameLength);// ������� ����������� ������, ������������ �������
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

	// ����� �������� ������� ������
	float Student::Average()// �������� ������, ����������� �� �����
	{
		float sum = 0;
		for (int i = 0; i < Student::amountLessons; i++)
		{
			sum += Student::grades[i];
		}
		return sum / Student::amountLessons;
	}

	// ����� ������ ��������
	void Student::Show()
	{
		cout << Student::name << ": ";
		Student::ShowGrades();
		cout << "\n\t";
		Student::ShowVisits();
		cout << "\n\n";
	}

	// ������� (�����������)
	const char* Student::GetName()
	{
		return name;
	}

	// ������� (�����������)
	void Student::SetName(const char* studentName)
	{
		memcpy_s(name, maxNameLength, studentName, maxNameLength);
	}

	//����� ������ ������
	void Student::ShowGrades()
	{
		for (int i = 0; i < Student::amountLessons; i++)
		{
			cout << Student::grades[i] << " ";
		}
	}

	// ����� ������ ������������
	void Student::ShowVisits()
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


