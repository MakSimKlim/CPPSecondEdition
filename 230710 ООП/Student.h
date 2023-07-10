#pragma once
// ���� ������� ��� �������� � ������ ������, ��� �������� �������,
// ���������� ������ � Student.cpp ���� ���������� ������ ������ � ���������� Student::
const int maxNameLength = 100;
class Student
{
private:
	//�������� ������ (��������, ������ ��� ��� �� ��������, ��� ��������� � main, ����� �������� �������� ���):
	char name[maxNameLength];
	int amountLessons;
	bool* visits;      // ������������
	int* grades;       // ������
	void ShowGrades();
	void ShowVisits();

public:
	Student();
	Student(char name[], int amountLessons);
	float Average();// �������� ������, ����������� �� �����
	void Show();
	const char* GetName();// �������
	void SetName(const char*);//�������
};

