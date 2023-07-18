#include "Student.h"
#include "Date.h"

int Student::studentCount{ 0 };

Student::Student(const char* nameP, const char* secondNameP, const char* patronymP,	uint64_t phoneP, const char* cityP,	const char* facultyP, uint32_t groupP,
	Date birthDateP) :
	Name{new char[strlen(nameP) + 1]},
	SecondName{new char[strlen(secondNameP) + 1] },
	Patronym{ new char[strlen(patronymP) + 1] },
	Phone{phoneP},
	City{ new char[strlen(cityP) + 1] },
	Faculty{ new char[strlen(facultyP) + 1] },
	GroupNum { groupP }	
{
	memcpy_s(Name, strlen(nameP) + 1, nameP, strlen(nameP) + 1);
	memcpy_s(SecondName, strlen(secondNameP) + 1, secondNameP, strlen(secondNameP) + 1);
	memcpy_s(Patronym, strlen(patronymP) + 1, patronymP, strlen(patronymP) + 1);
	memcpy_s(City, strlen(cityP) + 1, cityP, strlen(cityP) + 1);
	memcpy_s(Faculty, strlen(facultyP) + 1, facultyP, strlen(facultyP) + 1);
	studentCount++;
};

Student::Student(const char* nameP,
	const char* secondNameP,
	const char* patronymP,
	const char* cityP,
	const char* facultyP,
	uint32_t groupP,
	Date birthDateP) :
	Student{nameP, secondNameP, patronymP, 0, cityP, facultyP, groupP, birthDateP}
{};

Student::Student(const char* nameP,
	const char* secondNameP,
	const char* patronymP,
	const char* cityP,
	uint32_t groupP,
	Date birthDateP) :
	Student{ nameP, secondNameP, patronymP, 0, cityP, "", groupP, birthDateP }
{};

Student::Student() :
	Student{ "", "", "", 0, "", "", 0, Date{} }
{};

Student::~Student()
{
	studentCount--;
};