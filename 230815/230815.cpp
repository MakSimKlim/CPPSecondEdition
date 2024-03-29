﻿// 230815 Ключевое слово delete 
//
// Для специальных методов компилятор генертрует версии по умолчанию
//  - конструктор по умолчанию
//  - конструктор копирования
//  - консструктор перемещения
//  - оператор копирующего присваивания
//  - оператор перемещающего присваивания
//  - деструктор
//
// Автоматическая генерация происходит не всегда:
//  - Если опредеелен любой конструктор, конструктор по умолчанию не генерируется
//  - Если явно определен конструктор перемещения или опереатор перем.присваивания
// то конструктор копирования и оператор копирующего присваивания не генерируется
//  - Если явно определены конструктор копирования, оператор копирующего присваивания,
// конструктор перемещения, оператор перем.присваивания или деструктор,
// то конструктор перемещения и оператор перем. присваивания не генерируется
//  - Вышеуказанное характерно и для наследования в классах

#include "Source.cpp"
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    Vector2D v0;
    v0.setX(10.2).setY(34.5);// неявное проеобразование double в int возможно только без ключевого слова delete 
                             // delete в Header запрещает преобразование int в double 
                             // поэтому теперь возникает ошибка
    v0.display();
    cout << "\n";

    Vector2D v1{ 6,7 };
    cout << "\n";
    
    return 0;
}

