#pragma once

class Vector2D
{
	int x;
	int y;
	

public:
	Vector2D() = default;
	Vector2D(int, int);

	Vector2D& setX(int pX) { x = pX; return *this; }
	Vector2D& setY(int pY) { y = pY; return *this; }

	Vector2D& setX(double pX) = delete; // ��������� ������� �������������� �� ��������� int � double ��-�� ����� delete  
	Vector2D& setY(double pY) = delete; // ��������� ������� �������������� �� ��������� int � double ��-�� ����� delete  

	
	void display() const;
};
