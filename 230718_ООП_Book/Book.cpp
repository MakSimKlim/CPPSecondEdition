#include "Book.h"

int Book::bookCount{ 0 };


Book::Book(const char* nameA, const char* titleB, int yearP, int pageN) :
	nameAuthor{ new char[strlen(nameA) + 1] },
	titleBook{ new char[strlen(titleB) + 1] },
	yearPrint{ yearP },
	pageNumber{ pageN }
{
	memcpy_s(nameAuthor, strlen(nameA) + 1, nameA, strlen(nameA) + 1);
	memcpy_s(titleBook, strlen(titleB) + 1, titleB, strlen(titleB) + 1);
	bookCount++;
};


Book::Book(const char* nameA, const char* titleB):
	Book{ nameA, titleB, 0, 0 }
{};

Book::Book(const char* nameA):
	Book{ nameA , "" ,0, 0}
{};
Book::Book() :
	Book{"","",0,0}
{};

Book::~Book()
{
	bookCount--;
};
