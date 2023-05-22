// 230522_1
//
// inline функция - встраиваемая функция (лучше использовать функции с небольшим кодом)
// 
// 
// компилятор при большом количестве строк в функции проигнорирует inline 
// рекурсивная функция тоже не может использовать inline (т.к. компилятор не будет знать как использовать inline )? поэтому оно игнорируется
// если несколько раз встречается в записи название функции, то inline будет игнорироваться
// если внутри функции есть хотя бы одно while, do...while, for, switch, if , то inline также игнорируется
// поэтому inline очень редко используется, т.к. много случаев, где его не имеет смысла применять


#include <iostream>
#include <Windows.h>
#include <math.h>

using namespace std;

inline float module(float x = 0, float y = 0)
{
    return sqrt(pow(x, 2) + pow(y, 2));
}

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    return 0;
}

