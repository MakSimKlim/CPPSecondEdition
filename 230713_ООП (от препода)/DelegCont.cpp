#include <iostream>
#include "Point.h"
using namespace std;

class User
{
	char* name;
	uint16_t age; //������ integer, �� �������� 4 ����� (16 ���) �� ����� �����������
	uint32_t id; //�� �� �����, �� �������� 8 ���� (32 ����)
	//���� ����� uint8_t � uint64_t
public:
	User(const char* nameP, uint16_t ageP, uint32_t idP) :
		name{nameP ? new char[strlen(nameP) + 1] : nullptr },
		age{ ageP },
		id{ idP }
	{
		if(name)
			memcpy_s(name, strlen(nameP) + 1, nameP, strlen(nameP) + 1);
		cout << "Created full user" << endl;
	}

	User() : User{ nullptr, 0, 0 } { cout << "Created [empty user]" << endl; }

	User(const char* nameP) : User{ nameP, 0, 0 } {
		cout << "Created user with name " << name << endl;  
	}

	User(const char* nameP, uint16_t ageP) : User{ nameP, ageP, 0 } {
		cout << "Created user with name " << name << " and " << ageP << endl;
	}

	void show()
	{
		if (name)
			cout << name << ", " << age << " years old, UID=" << id << endl;
		else
			cout << "[empty user]" << endl;
	}

	~User()
	{
		delete[] name;
	}
};

void users()
{
	User nobody;
	nobody.show();

	User u1{ "Sidor" };
	u1.show();

	User u2{ "Adam", 25 };
	u2.show();

	User u3{ "Admin", 30, 1234567 };
	u3.show();
}

int main()
{
	Point p1{ 1, 1 };
	p1.maxX = 100;
	p1.maxY = 100;
	Point p2{ 2, 2 };

	p1.x = 4;
	p1.y = 6;	

	Point::maxX = 200;

	cout << p1.x << " " << p1.y << endl;
	cout << p2.x << " " << p2.y << endl;
	cout << p2.maxX << " " << p2.maxY << endl;
	return 0;
}