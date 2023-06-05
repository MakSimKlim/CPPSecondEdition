#include <iostream>
using namespace std;

void constpointers()
{
	int i = 10;
	//����������� ���������
	//������ �������� ���� �� ���������
	int* const p = &i;
	cout << i << endl;
	i = 9;
	cout << i << endl;
	//�� ����� �������� ���������� �� ������ ��������
	*p = 56;
	cout << i << endl;

	//��������� �� ���������
	//������ �������� �������� ����� ����
	const int* pa;
	int a = 73;
	pa = &a;
	cout << *pa << endl;
	a = 12;
	cout << *pa << endl;
	int b = 34;
	//�� ����� �������� ���� �� ���������
	pa = &b;
	cout << *pa << endl;
	//*pa = 99;

	//����������� ��������� �� ���������
	//������ ��������� �� ��������, ������� ���������������
	const int* const ptr = &a;
	cout << *ptr << endl;
}