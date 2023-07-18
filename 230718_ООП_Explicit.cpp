// 230718_ООП_Explicit
//
// неявное преобразование данных
// преобразование типов могут происходить между объектами класса
// 

#include <iostream>
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


int main()
{
    // ==============================================================
    a = 5;
    foo(5);
    float b = 50.2 / 2;// неявное преобразование данных

    //===============================================================

    displayDate(2020);
    Date date = 2010;
    displayDate(date);
    Date bDate = baseDate();
    displayDate(bDate);


    return 0;
}

