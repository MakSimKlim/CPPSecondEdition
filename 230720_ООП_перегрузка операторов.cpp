// 230720_ООП_перегрузка операторов
//
// оператор - символ
// - арифметические: + - / * ++ --
// - отношения: == |= < > <= >=
// - логические: && || !
// - побитовые: & | ^ ~ << >>
// - присваивания: = += -= *= /= %= <<= >>= &= ^= |=
// - прочие: sizeof ?: , . -> cast &(ссылка) *(указатель) 
// 
// то что слева и справа - называется операнды:
// - унарные: ++a, a++, -a
// - бинарные: a + b
// - тернарный: a ? b : c
//
// в зависимости к какой из групп относится перегружаемый оператор способы перегрузки:
//  - метод класса
//  - дружественная функция
//  - глобальная функция
// 
// operator - перегрузка оператора
// перегрузить можно только указанные операторы, новые создавать нельзя
// приоритеты уже определены в с++
// перегрузка не может изменить число операндов (например + нельзя сделать для трех операндов)
// каждый оператор перегружается отдельно
//
// если перегрузка существует для типов данных, то компилятор преобразует их
//

#include <iostream>
using namespace std;

class Name
{
	char* firstName;
	char* secondName;

	void SetCharArray(char*& dest, const char* source)
	{
		int strSize = strlen(source) + 1;
		dest = new char[strSize];
		strcpy_s(dest, strSize, source);
	}

	void remove()
	{
		if (firstName != nullptr)
		{
			delete[] firstName;
		}
		if (secondName != nullptr)
		{
			delete[] secondName;
		}
	}


public:

};


class Point
{
	double x;
	double y;

public:


	Point(double X, double Y) :x{ X }, y{ Y }
	{};
	Point() :Point(0, 0) {};

	void display()const
	{
		cout << "(" << x << ", " << y << ")";
	}
	// для операторов сравнения
	float length() const
	{
		return sqrt(this->x * this->x + this ->y * this->y);
	}

	// дружественные функции
	friend Point operator+(const Point& point1, const Point& point2)
    {
	return Point(point1.x + point2.x, point1.y + point2.y);
    }

    friend Point operator-(const Point& point)
    {
	return Point(-point.x, -point.y);
    }
	// бинарные операторы лучше перегружать через дружественные методы (p4)
	friend Point operator*(int mult, const Point& point)
	{
		return Point(point.x * mult, point.y * mult);
	}

	// перегрузка методом класса (левый операнд должен быть текущий экземпляр класса)
	
	Point operator*(const Point& point2)
	{
		return Point(this->x * point2.x, this->y * point2.y);
	}
	// если не текущий экзепляр класса, то так
	Point operator-()
	{
		return Point(-this->x, -this->y);
	}

	// дружественные функции через статические
	// const чтобы присваиваемая операция была всегда справа
	friend const Point operator+(const Point& point1, const Point& point2)
	{
		return Point::add(point1, point2);
	}
	friend const Point operator-(const Point& point1, const Point& point2)
	{
		return Point::sudstract(point1, point2);
	}
	friend const Point operator*(const Point& point1, const Point& point2)
	{
		return Point::mult(point1, point2);
	}
	friend const Point operator/(const Point& point1, const Point& point2)
	{
		return Point::divide(point1, point2);
	}

	// статические функции
	static const Point add(const Point& p1, const Point& p2)
	{
		return Point(p1.x + p2.x, p1.y + p2.y);
	}
	static const Point sudstract(const Point& p1, const Point& p2)
	{
		return Point(p1.x - p2.x, p1.y - p2.y);
	}
	static const Point mult(const Point& p1, const Point& p2)
	{
		return Point(p1.x * p2.x, p1.y * p2.y);
	}
	static const Point divide(const Point& p1, const Point& p2)
	{
		return Point(p1.x / p2.x, p1.y / p2.y);
	}

	// перегрузка оператора сложения + для класса Point
// описание поведения операторов через глобальные функции
// только для public!! доступ только через friend 
// если x y в паблике, то можно записать так без friend
//Point operator+(const Point& point1, const Point& point2)
//{
//	return Point(point1.x + point2.x, point1.y + point2.y);
//}
//
//Point operator-(const Point& point)
//{
//	return Point(-point.x, -point.y);
//}


//friend - доступ к скрытым данным



	// перегрузка инкремента и дикремента
	// перегрузка префиксной формы 
	Point& operator++()
	{
		++x; ++y; return *this;
	}
	Point& operator--()
	{
		--x; --y; return *this;
	}
	// перегрузка постфиксной формы
	const Point operator++(int)
	{
		Point point{ x,y };
		++(*this);
		return point;
	}
	const Point operator--(int)
	{
		Point point{ x,y };
		--(*this);
		return point;
	}
	// операторы срванения и логические орператоры пергружаются как дружественные функции
	friend bool operator==(const Point& p1, const Point& p2)
	{
		return p1.x == p2.x && p1.y == p2.y;
	}
	friend bool operator!=(const Point& p1, const Point& p2)
	{
		return p1.x != p2.x || p1.y != p2.y;
	}
	friend bool operator>(const Point& p1, const Point& p2)
	{
		return p1.length() > p2.length();
	}
	friend bool operator<(const Point& p1, const Point& p2)
	{
		return p1.length() < p2.length();
	}

	// опереации ввода/вывода в поток (также данные можно вывести в файл)
	friend ostream& operator<<(ostream& output, const Point& point)
	{
		output << "(" << point.x << ", " << point.y << ")";
		return output;
	}
	//  из потока
	friend istream& operator>>(istream& input, Point& point)
	{
		input >> point.x;
		input.ignore(1);
		input >> point.y;
	}
	// перегрузка оператора присваивания
	// похож на конструктор копирования
	

	
};




int main()
{
	int a = 5 + 6;// встроенный тип данных в с++ (доп перегрузка не нужна)
	int b = a / 4;// встроенный тип данных в с++ (доп перегрузка не нужна)
	Point p1{ 1,1 };
	Point p2{ 2,2 };
	Point p3 = p1 + p2;
	Point p4 = 4 * p2;
	//Point p5 = p3 * 5;
	p3.display();
	p3 = -p3;
	p3.display();

	// цепочка
	cout << p1 + p2 + p3 << endl;
	cout << ++(++p1);
	// передача в поток (iostream содержит 2 потока  cin cout)
	cout << p1 << "+" << p2 << "+" << p3 << endl;

	return 0;
}

