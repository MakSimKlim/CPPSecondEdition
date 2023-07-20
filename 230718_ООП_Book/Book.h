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

    // ������������
    Book(const char* nameA, const char* titleB, int yearP, int pageN); // ��� ������, ��������, ���, ���-�� �������
    Book(const char* nameA, const char* titleB);                       // ��� ������� ��������
    Book(const char* nameA);                                           // ��������
    Book();                                                            // ����������� ��-���������

    // �������, ������� ��� ������
    char* GetNameAuthor()
    {
        return nameAuthor;
    };
    void SetNameAuthor(const char* nameA)
    {
        memcpy_s(nameAuthor, strlen(nameA) + 1, nameA, strlen(nameA) + 1);
    };
    // �������, ������� �������� �����
    char* GetTitleBook()
    {
        return titleBook;
    };
    void SetTitleBook(const char* titleB)
    {
        memcpy_s(titleBook, strlen(titleB) + 1, titleB, strlen(titleB) + 1);
    };
    // �������, ������� ��� �������
    int GetYearPrint()
    {
        return yearPrint;
    };
    void SetYearPrint(int yearP)
    {
       yearPrint = yearP;
    };
    // �������, ������� ���-�� �������
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

    ~Book();                                                        // ����������

};
