// 230522_3
// 
// Перегрузка функции - несколько функций с одинаковым именем, но с разными параметрами при соответсвующем объявлении и аргументах
// код в перегруженных функция может быть абсолютно разным , но с одним именем
// различает только по аргументам функции
// 
// У перегруженных функций пожет быть разное количество параметров!!!
// 
#include <iostream>
#include <Windows.h>
#include <math.h>

#define SIZE 10

using namespace std;

long max_el(int n , int ar[]) // функция нахождения максимума
{
    int res = ar[0];
    cout << "Я работаю для int" << "\n";
    for (int i = 0; i < n; i++)
    {
        if (res < ar[i])
            res = ar[i];
    }
    return res;
}
long max_el(int n, long ar[]) // функция нахождения максимума
{
    long res = ar[0];
    for (int i = 0; i < n; i++)
    {
        if (res < ar[i])
            res = ar[i];
    }
    return res;
}
long max_el(int n, double ar[]) // функция нахождения максимума
{
    double res = ar[0];
    cout << "Я работаю для double" << "\n";
    for (int i = 0; i < n; i++)
    {
        if (res < ar[i])
            res = ar[i];
    }
    return res;
}

// перегрузка делается как по количеству так и по типу параметров
double multy(double x)
{
    return x * x * x;
}
double multy(double x, double y)
{
    return x * y * y;
}
double multy(double x, double y, double z)
{
    return x * y * z;
}
double multy(int x, int y)
{
    return x * y * y;
}

// перегрузка функции похожа на параметры по умолчанию
// будет ошибка, т.к. в перегрузке функции не желательно использовать параметры по умолчанию
double multy(double x, double y, double z, double d = 1)
{
    return x * y * z * d;
}


int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a[SIZE] = { 1,2,4,5,6,7,1 }; // будет смотреть по аргументам функции
    double a_b[SIZE] = { 0.1, 0.02, 0.03, 0.004, 0.6 };// будет смотреть по аргументам функции
    long long a_l[SIZE] = { 0.1,0.02,0.03,0.004,5.6 };// будет смотреть по аргументам функции
    cout << max_el(SIZE, a) << "\n";//максимум для int 
    cout << max_el(SIZE, a_b) << "\n";//максимум для double 
    //cout << max_el(SIZE, a_l) << "\n";// будет ошибка, т.к. функция с такими типами аргументов отсутствует!!!
    //если перегружается функция, то это делается для всех возможных типов значений, чтобы не было ошибок


    //
    cout<< multy(4.5, 6.7) << "\n";
    cout << multy(3.5) << "\n";
    cout << multy(4.5, 6.7, 2.3) << "\n"; // ошибка т.к. возникла неоднозначность из - за использования значения по умолчанию


    return 0;
}
