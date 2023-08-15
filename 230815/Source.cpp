#include "Header.h"
#include <iostream>

Vector2D::Vector2D(int x, int y) 
	: x{ pX }, y{ pY }
{}

void Vector2D::display() const
{
	std::cout << "(" << x << ", " << y << ")";
}
