// 230718_ООП_Explicit
//
// неявное преобразование данных
// преобразование типов могут происходить между объектами класса
// 
// explicit - делает конструкторы явными, ставится только перед прототипом конструктора!!!

#include <iostream>
#include "Array.h"
using namespace std;

//==============================================================================

double a{ 10 };

float foo(long n)
{
    return 10.0;
}

//===============================================================================

class Date
{
    int day;
    int month;
    int year;
public:
    Date(int dayP, int monthP, int yearP) : day{ dayP }, month{ monthP }, year{ yearP }
    {}

    Date(int year) :Date{ 1,1,year }
    {}

    friend void displayDate(Date date);

};

void displayDate(Date date)
{
    cout << date.day << "." << date.month << "." << date.year << endl;
 
}

Date baseDate() // конструктор конвертер
{
    return 2000;
}

void int_to()
{
    // ==============================================================
    a = 5;
    foo(5);
    float b = 50 / 2;// неявное преобразование данных

    //===============================================================

    displayDate(2020);
    Date date = 2010;
    displayDate(date);
    Date bDate = baseDate();
    displayDate(bDate);

}

void display(const Array& arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        arr.display(i);
    }

}

int main()
{

    int size = 4;
    // 3 способа явной инициализации объекта
    Array ar(size);
    Array ar2{ size };
    Array ar3 = Array(size);

    for (int i = 0; i < size; i++)
    {
        ar.setAt(i, size - i);
    }
    display(ar);
    cout << "\nFor 3\n";
    //display(3);
    return 0;
}

