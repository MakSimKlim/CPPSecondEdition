// 230615_1
//
// enum
//
// структура (тип данных, котор сост из нескольких типов - переменных)
// структуры можно 

#include <iostream>

using namespace std;

struct date
{ // память под это не выделяется, т.к. ни одна переменная еще не объявлена, это произойдет только в main
    int day;
    int month;
    int year;
    int weekday;
    char month[15];
} x, y, z; // x, y, z - переменные которые тоже принадлежат структуре, т.к. стоят до знака ";"

// анонимныей enum
enum {Single, Married} status;// status - переменная которая принадлежат структуре, т.к. стоят до знака ";"

struct person
{
    char name[100];
    char address[100];
    int zipcode[6];
    int inn[20];
    int salary;
    date dirthdate;
    date hiredate;

};

void Primer()
{
    date newDate = { 1,5,1983,5,"May" };
    cout << &newDate << endl;
    cout << newDate.month << endl;

    // переменная myDirthday с типом date
    date myDirthday = { 20,7,1981,1,"July" };//date - тип данных // инициализация элементов структуры
    cout << "===My Birthday===" << endl;
    cout << "Day:" << myDirthday.day << endl; // myDirthday - имя переменной, day - элемент структуры
    //cout << "Month:" << myDirthday.month_name << endl; // обращение к элементу структуры
    cout << "Year:" << myDirthday.year << endl;

    cout << "===Your Birthday===" << endl;
    date yourBirthday;
    cout << "Day:" << endl;
    cin >> yourBirthday.day;
    cout << "Month:" << endl;
    //cin >> yourBirthday.month_name;
    cout << "Year:" << endl;
    cin >> yourBirthday.year;


}

void showDate(date d)
{
    cout << d.day << " " << d.month << " " << d.year << endl;// доступ к элементу структуры через переменную
};

date getDate() //вернуть дату
{
    date res;
    cout << "Day:" << endl;
    cin >> res.day;
    cout << "Month:" << endl;
    cin >> res.month;
    cout << "Year:" << endl;
    cin >> res.year;
    return res;
}

bool isLeapYear(int year)
{
    if (year % 4 != 0 || year % 100 == 0 || year % 400 == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// анонимная структура
struct
{
    int x;
    int* y;
} *p;

struct Test
{
    char ch;
    int i;
};


int main()
{
    setlocale(LC_ALL, "Rus");

    date bdate = {5, 10, 5, 1990,"May" };
    date hdate = {5, 5, 5, 2020,"March" };
    person Nick = { "Nick","Chelyabinsk, Truda, 10", {0,0,0,0,0,0}, {}, 50000, bdate, hdate };
    cout << Nick.dirthdate.month << endl;
    cout << Nick.hiredate.month << endl;

    date d = { 2,10,5,1974,"April" };
    date d2;
    date* pd = nullptr;
    pd = &d;
    
    // способы доступа к элементам структуры
    cout << d.day << " " << d.month << " " << d.year << endl;// доступ к элементу структуры через переменную
    cout << pd->day << " " << pd->month << " " << pd->year << endl;// доступ к элементу структуры через указатель ->
    cout << (*pd).day << " " << (*pd).month << " " << (*pd).year << endl;// доступ к элементу структуры через разименовывание указателя

    d2 = d; // копирование 
    cout << d2.day << " " << d2.month << " " << d2.year << endl;// доступ к элементу структуры через переменную

    showDate(d);//в качестве функции
   
    d2 = getDate();
    showDate(d2);
    

    cout << isLeapYear(d.year) << endl;
    

    cout << (++p)->x;
    cout << (p++)->x;
    cout << *p->y;
    cout << *p->y++;
    cout << p++->y;
    cout << (*(*p).y)++;



    int a;
    char b;
    double c;
    int* p;
    cout << sizeof(5) << endl; //sizeof - опереатор который содержит размер
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(c) << endl;
    cout << sizeof(p) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(int*) << endl;


    Test d = { '#', 78 };
    cout << sizeof(d.ch) << " " << sizeof(d.i) << endl;
    cout << sizeof(Test) << " " << sizeof(d)<< endl;


    return 0;
}

