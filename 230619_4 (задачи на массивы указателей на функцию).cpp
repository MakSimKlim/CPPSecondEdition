// 230619_4 (задачи на массивы указателей на функцию)
//
// Программа хранит динамический одномерный массив.
//В программе есть функции,  которые
// - добавляет элемент по указанному индексу,
// - удаляет элемент  по указанному индексу,
// - выводит элемент по указанному индексу
// Реализовать меню, где пользователь выбирает эти действия
// Использовать механизм указателей на функции



#include <iostream>
using namespace std;

void addElem(int* index)
{
	cout << "Adding element "<< index << "\n";
}
void delElem(int* index)
{
	cout << "Deleting element " << index << "\n";
}
void viewElem(int* index)
{
	cout << "Viewing element " << index << "\n";
}
void exitProg(int* index)
{
    exit;
}


int main()
{
    void(*menuActs[4])(int*) = { addElem, delElem, viewElem, exitProg }; // общий массив для всех функций (т.к. у них одинаковая конструкция)

    int userChoice;

    int indexNumber[100];

    cout << "1 - Add\n";
    cout << "2 - Delete\n";
    cout << "3 - View\n";
    cout << "4 - Exit\n";
    do
    {
        do
        {
            cout << ">";
            cin >> userChoice;

        } while (userChoice < 1 || userChoice >4);

        if (userChoice != 4)
        {
            cout << "Enter index number: ";
            cin >> *indexNumber;// !! не считывает пробелы !!+
        }
        (*menuActs[userChoice - 1])(indexNumber); // вместо перебора SWITCHом
    } while (userChoice != 4);
    return 0;
}

