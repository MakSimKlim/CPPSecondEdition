// 230711_ООП_Инициализация.
//
// Использование неинициализированной переменной в компиляторе может вызывать ошибку (непредсказуемый результат)
//
// В классе каждое поле должно быть инициализировано!!!
//
// Наиболее предпочтительным инициализацией является список, напрмер  унифицированная инициализация списком : x{0}, y{0}
// таким способом при инициализации сразу кладется значение, что сокращает действия
// т.к. при обычной инициализации действия такие 
// создан класс (выделяется память) - созданы неинициализированные поля (заполнение мусором) - инициализация полей (заполнение нужными данными)
//
// поля класса инициализируются в порядке декларации!!!
//
// любое поле можно инициализировать сразу при его объявлении
//
// объявление (декларация) переменных - выделение памяти, инициализация - заполнение памяти данными!!!
//
// Если у класса есть конструктор, то инициализация должна быть в конструкторе, а не в декларации
// метод инициализации в декларации можно делать в маленьких классах, в которых нет конструктора
// сочетать инициализацию при декларации и в конструкторе нельзя, т.к. будет ошибка


#include <iostream>
using namespace std;

class Point // класс точка
{
public:

    //int x{0}; // инициализация сразу же после объявления
    //int y{0}; // инициализация сразу же после объявления
    int x;
    int y;


    //// конструктор без параметров - конструктор по умолчанию
    // Point() 
    // { 
    //    x = 0; y = 0; 
    //    cout << "Point Default Cotr\n";
    // }

    Point() : x{ 0 }, y{ 0 } {} // унифицированная инициализация списком : x{0}, y{0}

    
    Point(int pX, int pY) : x{ pX }, y{pY} // унифицированная инициализация списком : x{ pX }, y{pY} 
    {
        x = pX; y = pY; // самый простейший способ инициализации
        cout << "Point Parametrized Cotr\n";
    }

    int GetX() { return x; }
    int GetY() { return y; }

};

class Rectangle // класс прямоугольник 
{
    // декларация
    Point leftUpperCorner; // атрибут класса point
    int width;
    int height;

public:

    //Rectangle ()
    //{
    //    leftUpperCorner.x = 10;
    //    leftUpperCorner.y = 10;
    //    width = 0;
    //    height = 0;
    //    cout << "Rectangle Default Cotr\n";
    //}

    // унифицированная инициализация списком
    Rectangle():
    leftUpperCorner{10,10}, // Point(pX, pY) - унифицированная инициализация атрибута класса Point
    width{0},
    height{0}
    {
      cout << "Rectangle Default Cotr\n";
    }


    //Rectangle(int pX, int pY, int widthP, int heightP)
    //{
    //    leftUpperCorner.x = pX;
    //    leftUpperCorner.y = pY;
    //    width = widthP;
    //    height = heightP;
    //    cout << "Rectangle Parametrized Cotr\n";
    //}

    // унифицированная инициализация списком
    Rectangle(int pX, int pY, int widthP, int heightP) :
        leftUpperCorner{ pX, pY },
        width{ widthP },
        height{ heightP }
        {
        cout << "Rectangle Parametrized Cotr\n";
        }
};

class BadOrder
{
    // декларация
    int fieldOne;
    int fieldTwo;

public:
    BadOrder(int param):
    fieldTwo{ param },
    fieldOne{ fieldTwo + 10 }
    {
    }
    void print()
    {
        cout << fieldOne << " " << fieldTwo << endl;
    }

};

class GoodOrder
{
    // декларация
    int fieldOne;
    int fieldTwo;

public:
    GoodOrder(int param) :
        fieldOne{ param },
        fieldTwo{ fieldOne + 10 }
    {
    }
    void print()
    {
        cout << fieldOne << " " << fieldTwo << endl;
    }

};

void init_example() // теория об инициализации
{
 /*
int numbers[2];
numbers[0] += 2;
cout << numbers[0] << endl;
*/

// Виды инициализации:
// 1). Копирующая инициализация:
     int number = 0;
// 2). Прямая инициализация:
     int value(42);
// 3). Унифицированная инициализация: (применяется ко всем типам) - самая предпочтительная
     int size{33};

 //способы использования унифицированной инициализации:
 int answer{ 42 }; // переменная встроенного типа
 const float temp { 36.6 }; // константа
 int grades[4]{ 5, 4, 5, 3 }; // ождномерный массив
 int matrix[2][2]{ {5, 6}, {4, 7} }; // двумерный массив
 int* dataPtr{ nullptr }; // указатель 
 char* newStr{ new char[14] {"Hello world"} }; //строка
 int& reference{ answer }; //ссылка
// Point p{ 4,5 }; // структура 
// для класса - это аргументы для функции конструктора

}

int main()
{
    //Point p1; // заполняется конструктором по умолчанию (т.к. значения неинициализированы)
    //Point p2{ 42,33 };// создан класс (выделяется память) - созданы неинициализированные поля (заполнение мусором) - инициализация полей (заполнение нужными данными)
    //cout << p1.GetX() << ":" << p1.GetY() << endl;
    //cout << p2.GetX() << ":" << p2.GetY() << endl;

    //Rectangle rect1;
    //Rectangle rect2{ 56,29,10,5 };

    //BadOrder a{5};
    //GoodOrder b{5};
    //a.print();
    //b.print();

    Point p;
    cout << p.GetX() << " " << p.GetY() << endl;
    Point p2{ 45, 66 };
    cout << p2.GetX() << " " << p2.GetY() << endl;

    return 0;
}

