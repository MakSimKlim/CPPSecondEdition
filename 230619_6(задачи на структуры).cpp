// 230619_6(задачи на структуры)
//
//Описать структуру прямоугольник
//Она содержит координаты верхнего левого угла (можно создать структуру координаты),
// ширину и высоту
// Написать функции
//  - Вывод координат всех углов
//  - Изменение ширины и высоты
//  - Перемещение прямоугольника
//

#include <iostream>
using namespace std;

struct Point
{
	double x;
	double y;
};

struct Rectangle
{
	Point first;
	double height;
	double width;
};

void Distance(Point C, Point D)
{
	double res = sqrt(pow((C.x - D.x), 2) + pow((C.y - D.y), 2));
	cout << "Расстояние между точками: " << res << endl;
}


int main()
{
	Rectangle A = { 0, 0, 10, 20 };



}

