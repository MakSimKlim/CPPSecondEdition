// 230619_3(массивы указателей на функцию)
//
//
// реализация МЕНЮ через массив функций
//

#include <iostream>
using namespace std;

void act1(char* name)
{
    cout << "Creating file..." << name << endl;
}
void act2(char* name)
{
    cout << "Deleting file..." << name << endl;
}
void act3(char* name)
{
    cout << "Reading file..." << name << endl;
}
void act4(char* name)
{
    cout << "Closing file..." << name << endl;
}



int main()
{
   // вариант использования массива указателей на функцию при создании меню
   // float(*ptrArray[4])(char);
   // float num = (*ptrArray[2])('0');

    // =========Menu=============
    void(*menuActs[4])(char*) = { act1, act2, act3, act4 }; // общий массив для всех функций (т.к. у них одинаковая конструкция)

    int userChoice;

    char fileName[30];
    cout << "1 - Create\n";
    cout << "2 - Delete\n";
    cout << "3 - Read\n";
    cout << "4 - Close\n";

    do 
    {
        do
        {
            cout << ">";
            cin >> userChoice;

        } while (userChoice <1 || userChoice >4);

        if (userChoice !=4)
        {
            cout << "Enter file name: ";
            cin >> fileName;// !! не считывает пробелы !!+
        }
        (*menuActs[userChoice - 1])(fileName); // вместо перебора SWITCHом
    } while (userChoice != 4);
    return 0;
}

