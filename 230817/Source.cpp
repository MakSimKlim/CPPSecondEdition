#include <iostream>
#include "MedalRow.h"
#include "MedalTable.h"
// ���������� [] ���� ����������� �������� �� ������ � �������

using namespace std;

int main()
{
	MedalRow mr;
	mr.setOblast("CHEL");
	cout << "Oblast:" << mr.getOblast() << endl;
	mr[MedalRow::GOLD] = 3;
	mr[MedalRow::BRONZE] = 2;
	//mr[8] = 4; // ��������� assert, �.�. �������� ������� !!!


	MedalTable mt1;
	cout << "Medals Table 1\n";

	mt1["CHEL"][MedalRow::GOLD] = 5;
	mt1["CHEL"][MedalRow::SILVER] = 4;
	mt1["CHEL"][MedalRow::BRONZE] = 3;
	mt1["TYUM"][MedalRow::GOLD] = 3;
	mt1["TYUM"][MedalRow::BRONZE] = 6;
	mt1["EKAT"][MedalRow::GOLD] = 6;
	mt1["EKAT"][MedalRow::SILVER] = 3;
	mt1["EKAT"][MedalRow::BRONZE] = 2;

	mt1.print();

	const MedalTable mt2{ mt1 };// ����������� �� 1 �������
	cout << "Medals Table 2\n";
	mt2.print();
	//mt2["CHEL"].print(); // ���� �������� ������


	return 0;
}

