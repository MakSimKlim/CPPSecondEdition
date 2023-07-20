#pragma once
#include <iostream>

class Book
{
    char* nameAuthor;
    char* titleBook;
    int yearPrint;
    int pageNumber;
    static int bookCount;

public:

    // конструкторы
    Book(const char* nameA, const char* titleB, int yearP, int pageN); // имя автора, название, год, кол-во страниц
    Book(const char* nameA, const char* titleB);                       // имя автораб название
    Book(const char* nameA);                                           // название
    Book();                                                            // конструктор по-умолчанию

    // сеттеры, геттеры имя автора
    char* GetNameAuthor()
    {
        return nameAuthor;
    };
    void SetNameAuthor(const char* nameA)
    {
        memcpy_s(nameAuthor, strlen(nameA) + 1, nameA, strlen(nameA) + 1);
    };
    // сеттеры, геттеры название книги
    char* GetTitleBook()
    {
        return titleBook;
    };
    void SetTitleBook(const char* titleB)
    {
        memcpy_s(titleBook, strlen(titleB) + 1, titleB, strlen(titleB) + 1);
    };
    // сеттеры, геттеры год издания
    int GetYearPrint()
    {
        return yearPrint;
    };
    void SetYearPrint(int yearP)
    {
       yearPrint = yearP;
    };
    // сеттеры, геттеры кол-во страниц
    int GetPageNumber()
    {
        return pageNumber;
    };
    void SetPageNumber(int pageN)
    {
        pageNumber = pageN;
    };

    static int GetCount()
    {
        return bookCount;
    }

    void print()
    {
        cout << "Book info : " << nameAuthor << titleBook << yearPrint << pageNumber;
    }

    ~Book();                                                        // деструктор

};
