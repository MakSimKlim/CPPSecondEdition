﻿// 230629_1 препроцессор продолжение.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

//еще операторы препроцессора
// 
// #line 100 "File"//позволяет изменить номер строчки, в данном случае после 6 будет 100 строка, "File" - имя строчки
////#error директива вызова синтаксической ошибки вручную
//
//#pragma // у нее очень много применений
//
//#pragma once // проверяет был ли подключен файл другим include? то второй раз подключаться не будет, чтобы не было переопределения и ошибки
//
//#define MKSTR(s) #s // #s - оператор внутри  define, берет параметр справа и заключает в кавычки, переводя его в строчку
//
//#define CONCAT(a,b) a##b // опереатор конконтинации, берет и соединяет два элемента (два куска текста)
//
// #include <iostream> - вставляет содержимое файла iostream целиком в программу
//
// #include "Header.h" // из-за "" программа сначала ищет в той же папке где cpp, если не обнаружен, тогда include идет смотреть в папку со стандартными библиотеками
//
//




int main()
{


}
