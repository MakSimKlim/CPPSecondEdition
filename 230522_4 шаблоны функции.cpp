// 230522_4 шаблоны функции
//
// код шаблонной функции генерируется в момент вызова, если уже такой тип данных есть, создается копия функции
// если в функцию передается два одинаковых типа данных
// в шаблоне всегда один из аргументов быть типа Т


#include <iostream>
#include <Windows.h>
#include <math.h>

#define SIZE 5


using namespace std;

//создание экземпляра шаблона функции
template <typename T> // template - шаблон с обстрактным параметром типа Т
T t_max_el(int n, T ar[]) // функция нахождения максимума
{
    T res = ar[0];
    for (int i = 0; i < n; i++)
    {
        if (res < ar[i])
            res = ar[i];
    }
    return res;
}

template <typename T> // template - шаблон с обстрактным параметром типа Т
T MaxOfTwo(T a, T b)
{
    return a > b ? a : b;
}

// перегрузка функции шаблоном
template <typename T1 , typename T2> // template - шаблон с обстрактным параметром типа Т
T1  MaxOfTwo(T1 a, T2 b)
{
    return a > b ? a : b;
}

// перегрузка функции шаблона явными объявлениями 
template <typename T1, typename T2> // template - шаблон с обстрактным параметром типа Т
char MaxOfTwo (T1 a, T2 b)
{
    return a > b ? a : b;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a[SIZE] = { 1,2,4,5,6 }; // будет смотреть по аргументам функции
    int b[SIZE] = { 4,5,6,7,8 };// будет смотреть по аргументам функции
    double a_b[SIZE] = { 0.1, 0.02, 0.03, 0.004, 0.6 };// будет смотреть по аргументам функции
    cout << t_max_el(SIZE, a) << "\n";// скомпилятор создает  новую функцию, в которой вместо Т подставляет нужный тип данных на основе существующего шаблона
    cout << t_max_el(SIZE, b) << "\n";//
    cout << t_max_el(SIZE, a_b) << "\n";//


    cout << MaxOfTwo(4, 6) << "\n"; 
    cout << MaxOfTwo(4.5, 6.3) << "\n";
    //cout << MaxOfTwo(4, 6.3) << "\n"; //работает когда есть шаблон с разными типами данных, плюс добавлена перегрузка шаблона, также происходит преобразование double в int
    cout << MaxOfTwo('a', 'b') << "\n"; // перегрузка яdysvb типами параметров


    return 0;
}
