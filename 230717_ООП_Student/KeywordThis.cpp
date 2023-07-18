#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
	Date d1{ 24, 9, 2001 };
	Date d2{ 12, 4, 2008 };
	
	d1.print(); cout << endl;
	d2.print(); cout << endl;

	return 0;
}