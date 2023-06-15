// 230615_2 (задачи на структуры)
// 
// 
// Создать структуру, описывающую точку(x , y) 
// Написать функцию, которая вычисляет расстояние между двумя такими точками - 
// (формула гипотенузы из теоремы Пифагора, гипотенуза - расстояние, разность координат - катеты треуголиника)
// с помощью этой структуры задайте две точки и выведите расстояние между ними
//

#include <iostream>
#include <math.h>

using namespace std;

struct Point
{
	double x;
	double y;
};

void Distance(Point C, Point D)
{
	double res = sqrt(pow((C.x - D.x), 2) + pow((C.y - D.y), 2));
	cout << "Расстояние между точками: " << res << endl;
}


int main()
{
	setlocale(LC_ALL, "Rus");

	Point A = { 0, 0 };
	Point B = { 0, 100 };

	Distance(A, B);

}

