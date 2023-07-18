#pragma once
#include <iostream>

class Book
{
    char* nameAuthor[50];
    char* titleBook[100];
    int yearPrint;
    int pageNumber;

public:
    Book(const char* nameA, const char* titleB, int yearP, int pageN);

    Book(const char* nameA, const char* titleB );

    Book(const char* titleB);

    ~Book();

    void Show();



};
