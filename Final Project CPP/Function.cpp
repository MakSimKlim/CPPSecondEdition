#include <iostream>
#include <cstdlib> // ��� exit()
using namespace std;


void ViewNameProgram()
{
    cout << "*************************************************************************************" << endl;
    cout << "*                ��������� ���������� '���� ������' beta version 0.1                *" << endl;
    cout << "*************************************************************************************" << endl;
    
    system("pause");

    system("cls");
}

void EndOfProgram()
{
    cout << "������� �� ��������" << endl;
}

void MenuOfProgram()
{
    int choice = 0;
    cout << R"(
               �������� ����� ����:

               1 - ������� ���� � ��������������� ������
               2 - �������� � ���� ������������� �����
               3 - ������� ���� � ������������� �������
               4 - ������� ���� � ������������� ������� � ������������ ���
               5 - �����)"<< endl;
   
    cin >> choice;
    while (choice < 1 || choice > 5)
    {
        
        cout << "������� �������� ��������!" << endl;
        cout << "�������� ����� ���� ��� ���: " << endl;
        cin >> choice;
        cout << "\033[9;1H" << endl; // ������ ������������������ ��� ��������� ����� ������
    }
   

    switch (choice)
    {
    case 1:
        system("cls");
        cout << "������ ����� ���� ����� 1" << endl;
        system("pause");
        break;
    case 2:
        system("cls");
        cout << "������ ����� ���� ����� 2" << endl;
        system("pause");
        break;
    case 3:
        system("cls");
        cout << "������ ����� ���� ����� 3" << endl;
        system("pause");
        break;
    case 4:
        system("cls");
        cout << "������ ����� ���� ����� 4" << endl;
        system("pause");
        break;
    default:
        system("cls");
        cout << "������� �� ��������! ����� ��������!" << endl;
        //system("pause");
        exit(0); // ����� �� �������
    }


}