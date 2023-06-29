#include <iostream>
#include <cstdlib> // для exit()
using namespace std;


void ViewNameProgram()
{
    cout << "*************************************************************************************" << endl;
    cout << "*                Программа шифрования 'ШИФР ЦЕЗАРЯ' beta version 0.1                *" << endl;
    cout << "*************************************************************************************" << endl;
    
    system("pause");

    system("cls");
}

void EndOfProgram()
{
    cout << "Спасибо за внимание" << endl;
}

void MenuOfProgram()
{
    int choice = 0;
    cout << R"(
               Выберите пункт меню:

               1 - выбрать файл с незашифрованным файлом
               2 - записать в файл зашифрованный текст
               3 - открыть файл с зашифрованным текстом
               4 - открыть файл с зашифрованным текстом и расшифровать его
               5 - выход)"<< endl;
   
    cin >> choice;
    while (choice < 1 || choice > 5)
    {
        
        cout << "Введено неверное значение!" << endl;
        cout << "Выберите пункт меню ещё раз: " << endl;
        cin >> choice;
        cout << "\033[9;1H" << endl; // эскейп последовательность для затирания части экрана
    }
   

    switch (choice)
    {
    case 1:
        system("cls");
        cout << "выбран пункт меню номер 1" << endl;
        system("pause");
        break;
    case 2:
        system("cls");
        cout << "выбран пункт меню номер 2" << endl;
        system("pause");
        break;
    case 3:
        system("cls");
        cout << "выбран пункт меню номер 3" << endl;
        system("pause");
        break;
    case 4:
        system("cls");
        cout << "выбран пункт меню номер 4" << endl;
        system("pause");
        break;
    default:
        system("cls");
        cout << "Спасибо за внимание! Всего хорошего!" << endl;
        //system("pause");
        exit(0); // выход из консоли
    }


}