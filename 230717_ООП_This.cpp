// 230717_ООП_This
// 
// Память выделяется под методы 1 раз
// Память под поля выделяется столько раз, сколько их вызовут
// 
// this - указывается на сам объект, который вызывается
// 
// this->day в каждом методе можно указывать на поля экземпляра 
// можно и без this , т.к. он неявный
// 
// this нужен например когда название параметра функции и поля класса совпадают 
// 
// лучше их одинаково не называть, например
// 
// dayP ( _day ) - параметр функции
// day - поле класса
// поэтому this можно не использовать
//
// еще одно применение this - для создания цепочек вызовов
// вместо d.SetDay(), d.SetMonth(), d.SetYear(), ...  d.SetDay(),SetMonth(),SetYear(),, т.к. this использовали в сеттере на return *this
//
// ещё способ применения
// 
// cout <<"Date constructured for " << this << "\n";
// 
// =======================================================================
// 
// конструктор копирования - неявный конструктор, который создает новый экземпляр класса
// создается автоматически, берет все поля экземпляра и побитово копирует новые поля
// 
// чтобы определить его явно нужно прописать через const
// 
// ======================================================================
// 
// анонимный экземпляр - переменные или объекты, которым не присваивается имя
// создание анонимного объекта, назвается ЭЛИЗИЯ
//


#include <iostream>
#include <time.h>

using namespace std;

//класс дроби
class Fraction
{
    int numerator;
    int denominator;

public:

    Fraction(int num, int denom) :
        numerator{ num }, denominator{ denom }
    {
        cout << "Fraction constructed for " << this << "\n";

    };

    Fraction() : Fraction(1, 1) {}


    // явное определение конструктора копирования
    // без этой записи он работает неявно в main: Fraction c{ a }; 
    // Fraction(Fraction obj) - недопустима язапись, чтобы избежать бесконечной рекурсии, поэтому &, и обязательно const 
    // т.к. конструктор не может изменять объект класса, на который указывает ссылка!!!
    // инициализация конструктора копирования без const и & недопустима!!! ВСЕГДА ТОЛЬКО ТАКОЙ ЗАГОЛОВОК
    Fraction(const Fraction& obj) :
        numerator{ obj.numerator },
        denominator{obj.denominator }
    {
        cout << "Fraction copoied for" << this << "\n";
    }

    void print()
    {
        cout << "(" << numerator << "/" << denominator << ")";
    }


    ~Fraction() { cout << "Fraction destroyed for " << this << "\n"; }

};

void fraction()
{
    Fraction a{ 2,3 };
    Fraction b;
    Fraction c{ a }; // используется конструктор копирования c. numerator {}
    Fraction d{ Fraction(1,4) }; // Fraction(1,4) - анонимный экземплря класса, существует он только в этой строчке, компилятор вызывает похожий конструктор в данном случае как для "а"
    // произошла ЭЛИЗИЯ и вызывается конструктор

    a.print(); cout << endl;
    b.print(); cout << endl;
    c.print(); cout << endl;

}


class DynArray
{
    int* arr;
    int size;
public:
    DynArray(int sizeP) :arr{ new int[sizeP] }, size{ sizeP }
    {
        cout << "DynArr constructed for" << size << "elements" << this << endl;
    }
    DynArray() : DynArray{ 5 } {};
    //DynArray(const DynArray& obj) : arr{ obj.arr }, size{ obj.size }// поведение по умолчанию, нужен конструктор копирования, т.к. возникала ошибка при удалении деструктором
    DynArray(const DynArray& obj) : arr{ new int[obj.size] {} }, size{ obj.size } // теперь два разных массива с одинаковыми значениями, поэтому ошибки нет при деструкторе
    {

        for (int i = 0; i < size; i++)
        {
            arr[i] = obj.arr[i];
        }
        cout << "DynArr copied at" << this << endl;

    }
    int getAt(int index) { return arr[index]; }
    void setAt(int index, int value) { arr[index] = value; }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
    void randomize()
    {
    
    
    }


    ~DynArray()
    {
        cout << "DynArr destroyed" << this << endl;
    }

};

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    DynArray ar1{ 8 };
    ar1.randomize();
    cout << "Ar1: ";
    ar1.print(); cout << endl;

    DynArray ar2{ ar1 };
    cout << "Ar2: ";
    ar2.print(); cout << endl;


    return 0;
        
}

