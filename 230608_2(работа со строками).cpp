// 230608_2(работа со строками)
//
// строковые массивы
// 

#include <iostream>
#include <cstdio> // для fgets
#include <string.h>

using namespace std;

void Strings()
{
    //Строковая константа - пос-ть из 0 или больше символов
// " " //кавычки ограничивают строковую константу (обозначение для компилятора начала и конца константы)
// но массив символов не всегда является строкой
// а строка всегда является массивом сиволов
// массив символов { 'C','a','t','\0' }; - строка
// массив символов { 'C', 'a', 't' }; - не строка
// 
// "Character string" - строковая константа
// 'C' 'h' 'a' 'r' 'a' 'c' 't' 'e' 'r' ' ' 's' 't' 'r' 'i' 'n' 'g' '\0' - в таком виде она хранится в памяти
// '\0' - нулевой символ конца строки всегда используется для отметки конца строки и никогда не выводится
// за ним строки больше нет (это не число ноль).
// когда строка хранится как массив, количество ячеек памяти больше всегда на 1 символ (один символ всегда для нулевого символа)
// 
// важно не путать строку из одного символа и один символ, это разные вещи
// "X" - строка хранится в памяти как 'X' '\0'
// 'x' - символ хранится в памяти как 'x'
// " " - обозначение строки
// ' ' - обозначение символа
// 
// "" - такая строка хранится в памяти как символ '\0'

    //char* L;// строковый массив


    // способы инициализации массивов символов

    // первый способ через массив символов (очень громоздкий способ)
    char S1[4] = { 'C','a','t','\0' }; // ноль символ !!! обязателен
    for (int i = 0; i < 4; i++)
    {
        cout << S1[i];
    }
    cout << endl;

    // второй способ через строковую константу (в этом особенность символьных массивов)
    char S2[] = "Cat"; // инициализация строковой константой, аналогичная запись через символы
    cout << S2 << endl;
}

// пример со строками
const char* month_name(int);// прототип функции имени месяца
const int n = 15; // глобальная переменная

void Month()
{
    //// cin применять нельзя, можно пользоваться *fgets (stdin - поток ввода с клавиатуры для строк)
//const char* message;
//message = "Hello";
//cout << message << endl;

//const char* message;
//char msg1[] = "Hello";
//char* ptc = msg1;
//cout << message << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Month number: " << i;
        cout << " - " << month_name(i) << endl;
    }
}

void strlen()
{
    // подсчет количества символов в строке
    const char* c = "And old string...";
    int len = strlen(c); // без учета нулевого символа
    cout << len << endl;
}

const int MAXLEN = 256; // ограничение длины строки до 255 символов, +1 для нулевого символа

void more_lines()
{
    char s[MAXLEN]; // массив символов
    char s1[MAXLEN];

    //char* s1; // если нужно, если необходимо приравнять массивы записью s1 = s - вариант для неправильного способа
    cout << "Enter string: ";
    fgets(s, MAXLEN, stdin);// особенность fgets - enter добавляется в конец строки как символ, поэтому нужно обрезать строку в конце
    s[strlen(s) - 1] = '\0';
    cout << "String: " << s << endl;
    cout << "Length: " << strlen(s) << endl;

    ////неправильный способ
    //s1 = s; // неправильная запись, если s1 не указатель, т.к. здесь мы приравниваем адрес к строке
    //s[0] = 'R';
    //cout << s1 << endl;

    // правильный способ
    // копирует s в s1
    memcpy(s1, s, MAXLEN);// куда копируем, что копируем, ограничение по длине
    s[0] = 'R';
    s1[1] = 'A';
    cout << s1 << " " << s << endl;

    //Конкатенация (соедиение строк) строчек. Нужно помнить что предел строки 256
    strcat_s(s1, s);
    cout << s1 << endl;

    //конкатенация с ограниечением длины строки
    strncat_s(s1, s, MAXLEN - strlen(s));
    cout << s1 << endl;

}

void concat()
{
    // запись ФИО

    char fam[128]; // фамилия
    char nm[128];  // имя
    char ptnm[128]; // отчество

    cout << "Enter surname:";
    fgets(fam, 128, stdin);
    fam[strlen(fam) - 1] = '\0';

    cout << "Enter name:";
    fgets(nm, 128, stdin);
    nm[strlen(nm) - 1] = '\0';

    cout << "Enter patronym:";
    fgets(ptnm, 128, stdin);
    ptnm[strlen(ptnm) - 1] = '\0';

    char rez[128 * 3 + 3];
    memcpy(rez, fam, 128);
    strcat_s(rez, " ");
    strcat_s(rez, nm);
    strcat_s(rez, " ");
    strcat_s(rez, ptnm);

    cout << rez << endl;


}

int main()
{
    char filename[256];
    cout << "Enter filename: " << endl;
    fgets(filename, 256, stdin);
    filename[strlen(filename) - 1] = '\0';
    cout << "\nFilename is " << filename << endl;
    if (strchr(filename, '.'))
    {
        cout << "File has extension "<< strchr(filename, '.') + 1 << endl;
    }
    else
        strncat_s(filename, ".TXT", 256);
    cout << "File name now is " << filename << endl;

}
 const char* month_name(int k) // прототипированная функция для примера с месяцами
{// static чтобы не создавалась каждый раз
    static const char* name[] = {"none", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return (k < 1 || k > 12) ? name[0] : name[k];
}
